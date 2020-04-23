
#include <iostream>
#include <string>
#include <vector>

int print_int_vector(std::vector<int> ivec)
{
	for (std::vector<int>::size_type ix = 0, j = 0; ix != ivec.size(); ++ix, ++j)
	{
		std::cout << ivec[ix] << " "; //加空格！
	}
	std::cout << std::endl;
	return 0;
}

int main()
{
  // Vector<类型>标识符(最大容量,初始所有值)
  std::vector<int> ivec(10, 68);
  print_int_vector(ivec);
  // reset all the elements in ivec to 0
  /*
          // 使用下标
  for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ++ix)
  {
          ivec[ix] = 0;
  }
  */
  // equivalent loop using iterators to reset all the elements in ivec to 0
  for (std::vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	  *iter = 0; // set element to which iter refers to 0
  print_int_vector(ivec);
  return 0;
}
