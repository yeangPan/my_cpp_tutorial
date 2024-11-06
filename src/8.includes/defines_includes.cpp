/***********************************************************************
 * @file    : defines_includes.cpp
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

#include <cstdio>

int main() {
  printf("date:%s\n", __DATE__);
  printf("time:%s\n", __TIME__);
  printf("file:%s\n", __FILE__);
  printf("line:%d\n", __LINE__);
  printf("func:%s\n", __func__);
  printf("cpp_version:%ld\n", __cplusplus);
  return 0;
}