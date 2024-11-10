/***********************************************************************
 * @file    : 8.pointer_and_array_2.cpp
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
  // 初始化测试数组
  int arr[5] = {99, 2, 3, 4, 5};
  printf("Original array: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n\n");

  // 测试 *p++
  printf("Testing *p++:\n");
  int *p1 = arr; // 指向第一个元素
  printf("Before: *p1 = %d, p1 points to arr[%lld]\n", *p1, (p1 - arr));
  int value1 = *p1++; // 先取值，后移动指针，表达式的结果是一个数值
  printf("After: value = %d, *p1 = %d, p1 points to arr[%lld]\n", value1, *p1,
         p1 - arr);
  printf("\n");

  // 测试 *++p
  printf("Testing *++p:\n");
  int *p2 = arr;
  printf("Before: *p2 = %d, p2 points to arr[%lld]\n", *p2, p2 - arr);
  int value2 = *++p2; // 先移动指针，后取值，表达式的结果是一个数值
  printf("After: value = %d, *p2 = %d, p2 points to arr[%lld]\n", value2, *p2,
         p2 - arr);
  printf("\n");

  // 测试 (*p)++ 这一步会修改原始数组的值
  printf("Testing (*p)++:\n");
  int *p3 = arr;
  printf("Before: *p3 = %d, p3 points to arr[%lld]\n", *p3, p3 - arr);
  int value3 = (*p3)++; // 先取值，后增加元素的值
  printf("After: value = %d, *p3 = %d, p3 points to arr[%lld]\n", value3, *p3,
         p3 - arr);
  printf("\n");

  // 打印最终数组状态
  printf("Final array: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}