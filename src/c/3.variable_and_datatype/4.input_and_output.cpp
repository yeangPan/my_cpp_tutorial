/***********************************************************************
 * @file    : 4.input_and_output.cpp
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

#include <stdio.h>

int main() {

  int a, b;

  printf("number:");
  scanf_s("%d", &a);
  printf("number:");
  scanf_s("%d", &b);

  int c;
  c = a + b;
  printf("c:%d\n", c);

  return 0;
}