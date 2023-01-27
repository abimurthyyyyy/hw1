#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;
	list.push_back("oldfront");
	list.push_back("oldback");
std::cout <<  list.get(0) << " " << list.get(1) << std::endl;
// prints:l
std::cout << list.size() << std::endl;  // prints 3 since there are 3 strings stored
list.pop_front();
list.push_front("newfront");
std::cout <<  list.get(0) << " " << list.get(1) << std::endl;
list.pop_back();
	list.push_front("cloudfront");
	std::cout <<  list.get(0) << " " << list.get(1) << std::endl;
	list.pop_back();
		std::cout <<  list.get(0) << std::endl;
		list.pop_front();
		list.push_front("newback");
		std::cout <<  list.get(0) << std::endl;

}
