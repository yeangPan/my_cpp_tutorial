/***********************************************************************
 * @file    : 3.pointer_array.cpp
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

#include <stdio.h>

int main() {
  int a[] = {10, 20, 30, 40, 50};
  int *p = a;

  int n = sizeof(a) / sizeof(int);

  printf("--------------原始值-------------------\n");
  printf("p:%p\n", p);
  printf("&a:%p\n", &a);

  for (int i = 0; i < n; i++) {
    printf("a[%d]:%d,", i, a[i]);
    printf("&a[%d]:%p\n", i, &a[i]);
  }

  printf("通过*p对数组访问只能取出第一个元素\n");
  printf("*p:%d\n", *p);
  printf("*p++:%d,a[0]:%d\n", *p++, a[0]);
  p = a; // 重置指针
  printf("*(p++):%d,a[0]:%d\n", *(p++), a[0]);
  p = a; // 重置指针
  printf("*++p:%d,a[0]:%d\n", *++p, a[0]);
  p = a; // 重置指针
  printf("++*p:%d,a[0]:%d\n", ++*p, a[0]);
  printf("a[0]:%d\n", a[0]);
  printf("---------------使用指针及其偏移量访问------------------\n");
  p = a; // 重置指针
  for (int i = 0; i < n; i++) {
    printf("a[%d]:%d\n", i, *(p + i));
  }

  printf("---------------使用指针下标访问------------------\n");
  p = a; // 重置指针
  for (int i = 0; i < n; i++) {
    printf("a[%d]:%d\n", i, p[i]);
  }

  printf("---------------使用数组名及偏移量访问------------------\n");
  p = a; // 重置指针
  for (int i = 0; i < n; i++) {
    printf("a[%d]:%d\n", i, *(a + i));
  }

  printf("---------------使用数组下标访问------------------\n");
  p = a; // 重置指针
  for (int i = 0; i < n; i++) {
    printf("a[%d]:%d\n", i, a[i]);
  }

  return 0;
}