/***********************************************************************
 * @file    : pointer_and_func.cpp
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

void func(int *a) {
  static int b = 3;
  *a += b;
  b++;
}

int main() {
  int k = 2;
  func(&k);
  printf("k: %d\n", k);

  func(&k);
  printf("k: %d\n", k);
  return 0;
}