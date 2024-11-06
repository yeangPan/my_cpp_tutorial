/***********************************************************************
 * @file    : 2.datatype_and_type_length.cpp
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

#include "datatype_and_type_length.h"

int main() {
  typeinfo<bool>();
  typeinfo<char>();
  typeinfo<signed char>();
  typeinfo<unsigned char>();
  typeinfo<short>();
  typeinfo<unsigned short>();
  typeinfo<int>();
  typeinfo<unsigned int>();
  typeinfo<long>();
  typeinfo<unsigned long>();
  typeinfo<long long>();
  typeinfo<unsigned long long>();
  typeinfo<float>();
  typeinfo<double>();
  typeinfo<long double>();
  typeinfo<size_t>();
  return 0;
}
