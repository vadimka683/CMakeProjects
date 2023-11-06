// Copyright 2022 Marina Usova

#include <iostream>
#include "../lib_example/example.h"
#include "../lib_stack/stack.h"
int main() {
  int a = 1, b = 4; 
  float result;
  bool success = false;

  try {
	  result = division(a, b);
	  success = true;
  } catch (std::exception err) {
	  std::cerr << err.what() << std::endl;
  }
  if (success) { printf("%d / %d = %.2f\n", a, b, result); success = false; }

  a = 1; b = 0;

  try {
	  result = division(a, b);
	  success = true;
  } catch (std::exception err) {
	  std::cerr << err.what() << std::endl;
  }
  if (success) { printf("%d / %d = %.2f\n", a, b, result); success = false; }

  ExampleClass<int> obj(10);
  obj.setRandValues(-50, 30);
  std::cout << obj << std::endl;
  Stack<int> test(10);
  test.push(5);
  test.push(6);
  test.push(7);
  test.pop();
  test.print();
  return 0;
}
