/***********************************************************************
 * @file    : datatype_and_output_format.cpp
 * @brief   : header file
 * @history :
 * @date    : 2024-11-06
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

  int a = 26;

  printf("a: %d\n", a);
  printf("a: %x\n", a);
  printf("a: %X\n", a);
  printf("a: %o\n", a);

  double pi = 3.1415926;
  printf("pi: %f\n", pi);
  printf("pi: %.2f\n", pi);
  printf("pi: %e\n", pi);

  char ch = 'A';
  char str[] = "hello, world";
  printf("ch: %c\n", ch);
  printf("str: %s\n", str);

  int *ptr_a = &a;
  printf("address a:%p\n", ptr_a);

  int num = 42;

  // 宽度控制
  printf("[%5d]\n", num);  // 右对齐，宽度5
  printf("[%-5d]\n", num); // 左对齐，宽度5
  printf("[%05d]\n", num); // 用0填充，宽度5
                           // 添加正号
  printf("%+d\n", num);    // 输出：+42
  // 空格占位符
  printf("% d\n", num); // 正数前加空格
  // 显示十六进制前缀
  printf("%#x\n", num); // 输出：0x2a
  printf("%#X\n", num); // 输出：0X2A
  // 显示八进制前缀
  printf("%#o\n", num); // 输出：052

  // 浮点数控制
  printf("[%8.2f]\n", pi);  // 总宽度8，2位小数
  printf("[%-8.2f]\n", pi); // 左对齐，总宽度8，2位小数

  // 字符串宽度控制
  printf("[%10s]\n", "Hello");  // 右对齐，宽度10
  printf("[%-10s]\n", "Hello"); // 左对齐，宽度10

  // 表格式输出
  printf("%-10s %-8s %s\n", "Name", "Age", "City");
  printf("%-10s %-8d %s\n", "John", 25, "New York");
  printf("%-10s %-8d %s\n", "Mary", 30, "London");

  // 数值格式化
  num = 12345;
  printf("十进制：%-8d\n", num);
  printf("十六进制：%#-8x\n", num);
  printf("八进制：%#-8o\n", num);

  // 浮点数精度控制
  double value = 123.456789;
  printf("默认：%f\n", value);
  printf("两位小数：%.2f\n", value);
  printf("科学计数：%e\n", value);

  return 0;
}
