/***********************************************************************
 * @file    : condition_self_add.cpp
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
#include <iostream>
#include <stdio.h>

int main(int argc, const char **argv) {
  printf("the current parameter nums:%d\n", argc);
  for (int i = 0; i < argc; i++) {
    printf("the %d parameter:%s\n", i, argv[i]);
  }

  printf("----------------------------------\n");

  int a = 1;
  if (a--) {
    std::cout << "True" << std::endl;
    std::cout << "a: " << a << std::endl;
    if (a++) {
      std::cout << "False" << std::endl;
      std::cout << "a: " << a << std::endl;
    }
  }

  return 0;
}