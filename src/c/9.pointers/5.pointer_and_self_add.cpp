/***********************************************************************
 * @file    : 5.pointer_and_self_add.cpp
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

int main(int argc, const char **argv) {
  printf("current parameter nums:%d\n", argc);
  for (int i = 0; i < argc; i++) {
    printf("parameter %d: %s\n", i, argv[i]);
  }

  printf("----------------------------------\n");

  int a[] = {1, 2, 3, 4, 5};
  int *p = a;
  int *q = p++;

  printf("a: %p\n", a);
  printf("&a: %p\n", &a);
  printf("&a[0]: %p\n", &a[0]);
  printf("p: %p, *p:%d\n", p, *p);
  printf("q: %p, *q:%d\n", q, *q);

  return 0;
}