/***********************************************************************
 * @file    : 7.pointer_and_array.cpp
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

#include <cstdio>
int main() {

  int a[5] = {1, 2, 3, 4, 5};

  int size = sizeof(a) / sizeof(int);

  printf("size:%d\n", size);
  // for (int i = 0; i < size; i++) {
  //   printf("a[%d]:%d\n", i, a[i]);
  // }

  int *pa = &a[2];
  printf("*pa:%d\n", *pa);
  pa = &a[2];
  printf("*++pa:%d\n", *++pa);
  pa = &a[2];
  printf("(*pa)++:%d\n", (*pa)++);

  int *p = (int *)(&a + 1);
  printf("%d %d\n", *(a + 1), *(p - 1));
  return 0;
}