#include <iostream>
#include "vector.hpp"
#include <vector>
#include <string>

// #if 1
// 	namespace ft = std;
// #endif

int main()
{
	//empty vector
	ft::vector<std::string> myVector;
	std::allocator<int> alloc;
	
	ft::vector<int> myVector2(2, 55);
	std::vector<int> Vector2(2, 55);
	
	std::cout<<"size of my Vector2: "<<myVector2.size()<<std::endl;
	std::cout<<"size of std Vector2: "<<Vector2.size()<<std::endl;
	// std::cout<<"capacity of my Vector2: "<<myVector2.capacity()<<std::endl;
	
	std::cout<<"max size of my Vector2: "<<myVector2.max_size()<<std::endl;
	std::cout<<"max size of std Vector2: "<<Vector2.max_size()<<std::endl;
	
	std::cout<<"std my Vector2 is empty: "<<myVector2.empty()<<std::endl;
	std::cout<<"std Vector2 is empty: "<<Vector2.empty()<<std::endl;
	
	// myVector2.pop_back();
	// myVector2.pop_back();
	Vector2.pop_back();
	Vector2.pop_back();

	std::cout<<"my Vector2 is empty: "<<myVector2.empty()<<std::endl;
	std::cout<<"std Vector2 is empty: "<<Vector2.empty()<<std::endl;


	//√4611686018427387903 = 2147483648
	ft::vector<std::string> s1;
	std::vector<std::string> s2;
	std::cout<<"max size ft::vector string = "<<s1.max_size()<<std::endl;
	std::cout<<"max size std::vector string = "<<s2.max_size()<<std::endl;

	Vector2.push_back(4);
	Vector2.push_back(3);
	std::cout<<"size of std Vector2: "<<Vector2.size()<<std::endl;
	std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;

	Vector2.resize(1);
	std::cout<<"size of std Vector2: "<<Vector2.size()<<std::endl;
	std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;
	std::cout<<"top of std Vector2: "<<Vector2.back()<<std::endl;

	Vector2.resize(11);
	std::cout<<"size of std Vector2: "<<Vector2.size()<<std::endl;
	std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;
	std::cout<<"top of std Vector2: "<<Vector2.back()<<std::endl;
	return (0);
}	   
