/***********************************************************************
 * @file    : 9.string_array_string_const.cpp
 * @brief   : header file
 * @history :
 * @date    : 2024-11-10
 * @version : v1.1
 * @author  : pyang
 * @contact : yeangPan@outlook.com
 * @desc    : None
 *
 * Copyright (c) 2024 Yang Pan
 * Licensed under the Apache License, Version 2.0.
 ***********************************************************************/

#include <stdio.h>

int main() {
  char str1[] = "http://c.biancheng.net";
  const char *str2 = "http://c.biancheng.net";

  str1[0] = 'C';
  // str2[0] = 'C';

  printf("str1: %s\n", str1);
  printf("str2: %s\n", str2);

  return 0;
}