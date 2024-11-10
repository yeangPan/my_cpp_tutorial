/***********************************************************************
 * @file    : 1.memory_modeling.cpp
 * @brief   : header file
 * @history :
 * @date    : 2024-11-08
 * @version : v1.1
 * @author  : pyang
 * @contact : yeangPan@outlook.com
 * @desc    : None
 *
 * Copyright (c) 2024 Yang Pan
 * Licensed under the Apache License, Version 2.0.
 ***********************************************************************/

#include <cstddef>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX // 防止 Windows 头文件定义 min/max 宏
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define _WIN32_WINNT 0x0600 // 指定 Windows 版本
#include <SDKDDKVer.h>      // Windows 版本定义
#include <Windows.h>
#include <psapi.h>
#include <windef.h> // Windows 基本类型定义

#else
#include <fstream>
#include <sstream>
#include <sys/types.h>
#include <unistd.h>
#endif

struct MemoryRegion {
  size_t start;
  size_t end;
  std::string permissions;
  std::string type;
  size_t size;
};

class MemoryMapper {
public:
  std::vector<MemoryRegion> regions;
  void printRegion(const MemoryRegion &region) {
    std::cout << std::hex << std::uppercase << "0x" << std::setw(16)
              << std::setfill('0') << region.start << " - 0x" << std::setw(16)
              << std::setfill('0') << region.end << " " << std::setw(4)
              << std::left << region.permissions << " " << std::setw(15)
              << std::left << region.type << " Size: " << std::dec
              << (region.size / 1024) << " KB" << std::endl;
  }

#ifdef _WIN32

  void getWindowsMemoryMap() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    // 打印系统信息
    std::cout << "System Info:" << std::endl;
    std::cout << "Minimum Application Address: 0x" << std::hex
              << (size_t)sysInfo.lpMinimumApplicationAddress << std::endl;
    std::cout << "Maximum Application Address: 0x" << std::hex
              << (size_t)sysInfo.lpMaximumApplicationAddress << std::endl;
    std::cout << std::string(80, '-') << std::endl;

    MEMORY_BASIC_INFORMATION memInfo;
    char *addr = (char *)sysInfo.lpMinimumApplicationAddress;
    while (addr < (char *)sysInfo.lpMaximumApplicationAddress) {
      if (VirtualQuery(addr, &memInfo, sizeof(memInfo)) != 0) {
        if (memInfo.State != MEM_FREE) {
          MemoryRegion region;
          region.start = (size_t)memInfo.BaseAddress;
          region.end = (size_t)memInfo.BaseAddress + memInfo.RegionSize;
          region.size = memInfo.RegionSize;

          // 获取权限
          if (memInfo.Protect & PAGE_READONLY) {
            region.permissions = "r--";
          } else if (memInfo.Protect & PAGE_READWRITE) {
            region.permissions = "rw-";
          } else if (memInfo.Protect & PAGE_EXECUTE) {
            region.permissions = "--x";
          } else if (memInfo.Protect & PAGE_EXECUTE_READ) {
            region.permissions = "r-x";
          } else if (memInfo.Protect & PAGE_EXECUTE_READWRITE) {
            region.permissions = "rwx";
          } else {
            region.permissions = "---"; // 没有权限
          }

          // 获取类型
          if (memInfo.Type == MEM_IMAGE) {
            if (memInfo.Protect &
                (PAGE_EXECUTE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE)) {
              region.type = "Code"; // 可执行代码段
            } else if (memInfo.Protect & PAGE_READONLY) {
              region.type = "Constants"; // 常量数据
            } else {
              region.type = "Data"; // 普通数据
            }
          } else if (memInfo.Type == MEM_MAPPED) {
            region.type = "Mapped";
          } else if (memInfo.Type == MEM_PRIVATE) {
            if (memInfo.Protect & PAGE_READWRITE) {
              // 修改栈区判断逻辑，使用相对于最大地址的偏移
              if ((char *)memInfo.BaseAddress >=
                  ((char *)sysInfo.lpMaximumApplicationAddress -
                   (8 * 1024 * 1024))) {
                region.type = "Stack";
              }
              // 修改堆区判断逻辑，使用相对于最小地址的偏移
              else if ((char *)memInfo.BaseAddress <=
                       ((char *)sysInfo.lpMinimumApplicationAddress +
                        (1024 * 1024 * 1024))) {
                region.type = "Heap";
              } else {
                region.type = "Private";
              }
            } else {
              region.type = "Private";
            }
          }
          regions.push_back(region);
        }
        addr += memInfo.RegionSize;
      } else {
        addr += sysInfo.dwPageSize;
      }
    }
  }

#else
  std::string determine_region_type(const std::string line,
                                    const std::string perms) {

    if (line.find("[stack]") != std::string::npos)
      return "Stack";
    if (line.find("[heap]") != std::string::npos)
      return "Heap";
    if (perms == "r-xp")
      return "Code";
    if (perms == "r--p")
      return "Constants";
    if (perms == "rw-p") {
      if (line.find(".data") != std::string::npos)
        return "Data";
      if (line.find(".bss") != std::string::npos)
        return "BSS";
    }
    if (line.find(".so") != std::string::npos)
      return "Shared Library";
    return "Other";
  }

  void getLinuxMemoryMap() {
    std::ifstream maps("/proc/self/maps");
    std::string line;
    while (std::getline(maps, line)) {
      MemoryRegion region;
      std::string addrRange, perms;
      std::istringstream iss(line);

      iss >> addrRange >> perms;
      sscanf(addrRange.c_str(), "%lx-%lx", &region.start, &region.end);
      region.permissions = perms;
      region.type = determine_region_type(line, perms);
      region.size = region.end - region.start;

      regions.push_back(region);
    }

#endif

  void printMemoryMap() {
    std::cout << "Process Memory Map:" << std::endl;
    std::cout << std::string(80, '-') << std::endl;

    // 定义要显示的区域类型顺序
    std::vector<std::string> types = {
        "Code",  "Constants",      "Data",   "BSS",     "Heap",
        "Stack", "Shared Library", "Mapped", "Private", "Other"};

    for (const auto &type : types) {
      bool found = false;
      for (const auto &region : regions) {
        if (region.type == type) {
          if (!found) {
            std::cout << "\n" << type << " Regions:" << std::endl;
            std::cout << std::string(40, '-') << std::endl;
            found = true;
          }
          printRegion(region);
        }
      }
    }
  }
};

int main() {
  MemoryMapper mapper;
#ifdef _WIN32
  mapper.getWindowsMemoryMap();
#else
    mapper.getLinuxMemoryMap();
#endif
  mapper.printMemoryMap();
  return 0;
}