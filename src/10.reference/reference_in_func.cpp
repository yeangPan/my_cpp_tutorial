/***********************************************************************
 * @file    : reference_in_func.cpp
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
#include <string>

void solve(int &m) { m = 15; }

int main(int argc, const char **argv) {
  std::cout << "the current parameter nums:" << argc << std::endl;
  for (int i = 0; i < argc; i++) {
    std::cout << "the " << i << "th parameter is:" << argv[i] << std::endl;
  }
  std::cout << "the end of main" << std::endl;
  std::cout << std::string(80, '-') << std::endl;

  int n = 10;
  solve(n);
  std::cout << "n:" << n << std::endl;

  int a = 2, b = 3;
  std::cout << "b/a:" << (b / a) * 1.0 << std::endl;

  return 0;
}