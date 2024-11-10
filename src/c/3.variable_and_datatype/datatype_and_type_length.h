/***********************************************************************
 * @file    : datatype_and_type_length.h
 * @brief   : header file
 * @history :
 * @date    : 2024-11-06
 * @version : v1.1
 * @author  : pyang
 * @contact : yeangPan@outlook.com
 * @desc    : None
 *
 * Copyright (c) 2024 Yang Pan
 * Licensed under the Apache License, Version 2.0.
 ***********************************************************************/

#ifndef MY_CPP_TUTORIAL_DATATYPE_AND_TYPE_LENGTH_H
#define MY_CPP_TUTORIAL_DATATYPE_AND_TYPE_LENGTH_H
#pragma once

#include <iomanip> // 为了使用 setw
#include <iostream>
#include <limits>
#include <string>
#include <type_traits>
#include <typeinfo>

template <typename T> void typeinfo() {
  std::cout.clear();

  // 获取类型名称
  std::string tname;
  if constexpr (std::is_same_v<T, bool>) {
    tname = "bool";
  } else if constexpr (std::is_same_v<T, char>) {
    tname = "char";
  } else if constexpr (std::is_same_v<T, signed char>) {
    tname = "signed char";
  } else if constexpr (std::is_same_v<T, unsigned char>) {
    tname = "unsigned char";
  } else if constexpr (std::is_same_v<T, short>) {
    tname = "short";
  } else if constexpr (std::is_same_v<T, unsigned short>) {
    tname = "unsigned short";
  } else if constexpr (std::is_same_v<T, int>) {
    tname = "int";
  } else if constexpr (std::is_same_v<T, unsigned int>) {
    tname = "unsigned int";
  } else if constexpr (std::is_same_v<T, long>) {
    tname = "long";
  } else if constexpr (std::is_same_v<T, unsigned long>) {
    tname = "unsigned long";
  } else if constexpr (std::is_same_v<T, long long>) {
    tname = "long long";
  } else if constexpr (std::is_same_v<T, unsigned long long>) {
    tname = "unsigned long long";
  } else if constexpr (std::is_same_v<T, float>) {
    tname = "float";
  } else if constexpr (std::is_same_v<T, double>) {
    tname = "double";
  } else if constexpr (std::is_same_v<T, long double>) {
    tname = "long double";
  } else if constexpr (std::is_same_v<T, size_t>) {
    tname = "size_t";
  } else {
    tname = typeid(T).name();
  }

  // 打印分隔线
  std::cout << std::string(50, '-') << "\n";

  // 基本信息
  std::cout << std::left << std::setw(15) << "Type:" << tname << "\n";
  std::cout << std::left << std::setw(15) << "Size:" << sizeof(T) << " bytes\n";
  std::cout << std::left << std::setw(15) << "Range:";

  // 范围信息
  if constexpr (std::is_same_v<T, char>) {
    std::cout << "[" << static_cast<int>(std::numeric_limits<T>::min()) << ", "
              << static_cast<int>(std::numeric_limits<T>::max()) << "]\n";
  } else if constexpr (std::is_floating_point_v<T>) {
    std::cout << std::scientific;
    std::cout << "[" << std::numeric_limits<T>::lowest() << ", "
              << std::numeric_limits<T>::max() << "]\n";
    std::cout << std::left << std::setw(15)
              << "Min positive:" << std::numeric_limits<T>::min() << "\n";
    std::cout << std::left << std::setw(15)
              << "Epsilon:" << std::numeric_limits<T>::epsilon() << "\n";
    std::cout << std::boolalpha;
    std::cout << std::left << std::setw(15)
              << "Has infinity:" << std::numeric_limits<T>::has_infinity
              << "\n";
    std::cout << std::left << std::setw(15)
              << "Has NaN:" << std::numeric_limits<T>::has_quiet_NaN << "\n";
    std::cout << std::left << std::setw(15)
              << "Digits10:" << std::numeric_limits<T>::digits10 << "\n";
    std::cout << std::defaultfloat << std::noboolalpha;
  } else {
    std::cout << "[" << std::numeric_limits<T>::min() << ", "
              << std::numeric_limits<T>::max() << "]\n";
  }

  // 确保输出完成
  std::cout.flush();
}

#endif // MY_CPP_TUTORIAL_DATATYPE_AND_TYPE_LENGTH_H