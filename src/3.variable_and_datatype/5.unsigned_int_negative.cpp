/***********************************************************************
 * @file    : 5.unsigned_int_negative.cpp
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
  unsigned int i = -1;
  if (i < 0) {
    printf("i is a negative number\n");
  } else {
    printf("i is a positive number\n");
  }

  printf("i:%u\n", i);

  return 0;
}