/***********************************************************************
 * @file    : 1.pointer_revise_data.cpp
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
  int a = 10, b = 20, c = 30;
  int *p_a = &a;
  int *p_b = &b;
  int *p_c = &c;

  printf("------------原始值-------------------\n");

  printf("a: %d, b: %d, c: %d\n", a, b, c);
  printf("&a: %p, &b: %p, &c: %p\n", &a, &b, &c);
  printf("p_a: %p, p_b: %p, p_c: %p\n", p_a, p_b, p_c);
  printf("*p_a: %d, *p_b: %d, *p_c: %d\n", *p_a, *p_b, *p_c);
  printf("&p_a: %p, &p_b: %p, &p_c: %p\n", &p_a, &p_b, &p_c);

  printf("-------------------------------\n");
  printf(
      "1. 通过*p_a = b修改指针的值，导致原始的值被修改，但是地址不变，等价于 "
      "`a=b;`的赋值\n");
  *p_a = b;
  printf("a: %d, b: %d, c: %d\n", a, b, c);
  printf("&a: %p, &b: %p, &c: %p\n", &a, &b, &c);
  printf("p_a: %p, p_b: %p, p_c: %p\n", p_a, p_b, p_c);
  printf("*p_a: %d, *p_b: %d, *p_c: %d\n", *p_a, *p_b, *p_c);
  printf("&p_a: %p, &p_b: %p, &p_c: %p\n", &p_a, &p_b, &p_c);

  printf("-------------------------------\n");
  printf("2. 通过p_a = "
         "p_b，只是修改了指针的指向，a,b,c的值不变，但是p_a指向了b的值，p_"
         "a本身的地址不变(如果有二级指针指向他，二级指针的值不变)\n");
  a = 10;
  p_a = p_b;
  printf("a: %d, b: %d, c: %d\n", a, b, c);
  printf("&a: %p, &b: %p, &c: %p\n", &a, &b, &c);
  printf("p_a: %p, p_b: %p, p_c: %p\n", p_a, p_b, p_c);
  printf("*p_a: %d, *p_b: %d, *p_c: %d\n", *p_a, *p_b, *p_c);
  printf("&p_a: %p, &p_b: %p, &p_c: %p\n", &p_a, &p_b, &p_c);

  return 0;
}