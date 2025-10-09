#include <iostream>

int a,b;

int mult(int a, int b)
{
  if(b == 0) {
    // do something
    return 0;
  } else {
    // do some other things
    return 0;
  }
}

int main()
{
  std::cin >> a >> b;

  std::cout << mult(a,b) << std::endl;
}