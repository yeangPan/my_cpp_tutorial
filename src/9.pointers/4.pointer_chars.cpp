/***********************************************************************
 * @file    : 4.pointer_chars.cpp
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

#include <cstdio>
#include <cstring>

int main() {
  const char *str1 = "hello from str1";
  char str2[] = "hello from str2";
  int len1 = strlen(str1);
  int len2 = strlen(str2);

  for (int i = 0; i < len1; i++) {
    printf("%c", str1[i]);
  }

  printf("\n");

  for (int i = 0; i < len2; i++) {
    printf("%c", str2[i]);
  }

  printf("\n");

  str2[1] = 'C';

  printf("-------------------------------------\n");

  for (int i = 0; i < len1; i++) {
    printf("%c", str1[i]);
  }

  printf("\n");

  for (int i = 0; i < len2; i++) {
    printf("%c", str2[i]);
  }

  printf("\n");

  return 0;
}