/***********************************************************************
 * @file    : 2.pointer_operation_compare.cpp
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
  int a = 10, *pa = &a, *paa = &a;
  double b = 1.1, *pb = &b;
  char c = '@', *pc = &c;

  printf("---------------------最初的值-----------------------------\n");
  printf("a: %d, b: %f, c: %c\n", a, b, c);
  printf("&a: %p, &b: %p, &c: %p\n", &a, &b, &c);
  printf("pa: %p, pb: %p, pc: %p\n", pa, pb, pc);
  printf("*pa: %d, *pb: %f, *pc: %c\n", *pa, *pb, *pc);
  if (pa == paa) {
    printf("pa == paa\n");
  } else {
    printf("pa!= paa\n");
  }

  printf("---------------------指针相加-----------------------------\n");
  pa += 1;
  pb += 1;
  pc += 1;
  printf("a: %d, b: %f, c: %c\n", a, b, c);
  printf("&a: %p, &b: %p, &c: %p\n", &a, &b, &c);
  printf("pa: %p, pb: %p, pc: %p\n", pa, pb, pc);
  printf("*pa: %d, *pb: %f, *pc: %c\n", *pa, *pb, *pc);
  if (pa == paa) {
    printf("pa == paa\n");
  } else {
    printf("pa!= paa\n");
  }

  printf("---------------------指针自加-----------------------------\n");
  pa = &a;
  pb = &b;
  pc = &c;

  (pa++);
  (pb++);
  (pc++);
  printf("a: %d, b: %f, c: %c\n", a, b, c);
  printf("&a: %p, &b: %p, &c: %p\n", &a, &b, &c);
  printf("pa: %p, pb: %p, pc: %p\n", pa, pb, pc);
  printf("*pa: %d, *pb: %f, *pc: %c\n", *pa, *pb, *pc);
  if (pa == paa) {
    printf("pa == paa\n");
  } else {
    printf("pa!= paa\n");
  }

  return 0;
}