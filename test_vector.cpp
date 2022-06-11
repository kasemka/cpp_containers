#include <iostream>
#include "vector.hpp"
#include <vector>
#include <string>

#define GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[1;31m"
#define SHALLOW "\033[0m"


template < class T >
void print_all(T & my)
{
    std::cout << "vector contains:";
    std::cout << GREEN;
    for(size_t i = 0; i < my.size(); ++ i)
        std::cout << " " <<  my[i] ;
    std::cout<<SHALLOW;
    std::cout << RED;
    std::cout << " | | ";
    for(size_t i = my.size(); i < my.capacity(); ++ i)
        std::cout << " " <<  my[i] ;
    std::cout<<SHALLOW;
    std::cout << std::endl;
}

int main()
{
	// ft::vector <int> z;
    // for(int i = 0; i < 5; ++i)
    // {
    //     std::cout << "capacity: " << z.capacity() << std::endl;
    //     std::cout << "size: " << z.size() << std::endl;
    //     z.push_back(5);
	// 	std::cout<< "pushed back 5" << std::endl;
    //     print_all(z);
        
    // }
	// for (int i = 0; i < 5; ++i)
	// {
	// 	z.pop_back();
	// }
	// std::cout << "capacity: " << z.capacity() << std::endl;
	// std::cout << "size: " << z.size() << std::endl << std::endl;



	// ft::vector<std::string> myVector;
	// std::allocator<int> alloc;
	
	// ft::vector<std::string> myVector2;
	// std::vector<std::string> Vector2;
	// std::cout<<"size of my Vector2: "<<myVector2.size()<<std::endl;
	// std::cout<<"size of std Vector2: "<<Vector2.size()<<std::endl;
	// std::cout<<"capacity of my Vector2: "<<myVector2.capacity()<<std::endl;
	// std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;
	// std::cout << std::endl;
	
	// myVector2.resize(15);
	// Vector2.resize(15);
	// std::cout<<"size resize(0) of my Vector2: "<<myVector2.size()<<std::endl;
	// std::cout<<"size resize(0) of std Vector2: "<<Vector2.size()<<std::endl;
	// std::cout<<"capacity of my Vector2: "<<myVector2.capacity()<<std::endl;
	// std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;
	// std::cout <<std::endl;
	
	// myVector2.reserve(13);
	// Vector2.reserve(13);
	// std::cout<<"size after reserve(10) of my Vector2: "<<myVector2.size()<<std::endl;
	// std::cout<<"size after reserve(10) of std Vector2: "<<Vector2.size()<<std::endl;
	// std::cout<<"capacity of my Vector2: "<<myVector2.capacity()<<std::endl;
	// std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;
	// std::cout << std::endl;

	// for (int i = 0; i<11; ++i)
	// 	myVector2.push_back("sasf");
	// for (int i = 0; i<11; ++i)
	// 	Vector2.push_back("sasf");


	// std::cout<<"size after push_back of my Vector2: "<<myVector2.size()<<std::endl;
	// std::cout<<"size after push_back of std Vector2: "<<Vector2.size()<<std::endl;
	// std::cout<<"capacity after push_back of my Vector2: "<<myVector2.capacity()<<std::endl;
	// std::cout<<"capacity after push_back of std Vector2: "<<Vector2.capacity()<<std::endl;


	// std::cout<<"max size of my Vector2: "<<myVector2.max_size()<<std::endl;
	// std::cout<<"max size of std Vector2: "<<Vector2.max_size()<<std::endl;
	// std::cout << std::endl;
	
	// std::cout<<"std my Vector2 is empty: "<<myVector2.empty()<<std::endl;
	// std::cout<<"std Vector2 is empty: "<<Vector2.empty()<<std::endl;
	// std::cout << std::endl;
	
	// myVector2.pop_back();
	// myVector2.pop_back();
	// Vector2.pop_back();
	// Vector2.pop_back();
	

	// std::cout<<"my Vector2 is empty: "<<myVector2.empty()<<std::endl;
	// std::cout<<"std Vector2 is empty: "<<Vector2.empty()<<std::endl;
	// std::cout << std::endl;


	// //√4611686018427387903 = 2147483648
	// ft::vector<std::string> s1;
	// std::vector<std::string> s2;
	// std::cout<<"max size ft::vector string = "<<s1.max_size()<<std::endl;
	// std::cout<<"max size std::vector string = "<<s2.max_size()<<std::endl;
	// std::cout << std::endl;

	// myVector2.push_back("4");
	// Vector2.push_back("4");
	// std::cout<<"size of ft myVector2: "<<myVector2.size()<<std::endl;
	// std::cout<<"size of std Vector2: "<<Vector2.size()<<std::endl;
	// std::cout<<"capacity of ft myVector2: "<<myVector2.capacity()<<std::endl;
	// std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;
	// std::cout << std::endl;

	
	// myVector2.resize(4);
	// Vector2.resize(4);
	// std::cout<<"size of ft myVector2 after resize(4): "<<myVector2.size()<<std::endl;
	// std::cout<<"size of std Vector2 after resize(4): "<<Vector2.size()<<std::endl;
	// std::cout<<"capacity of ft myVector2 after resize(4): "<<myVector2.capacity()<<std::endl;
	// std::cout<<"capacity of std Vector2 after resize(4): "<<Vector2.capacity()<<std::endl;

	// std::cout<<"top of ft myVector2: "<<myVector2.back()<<std::endl;
	// std::cout<<"top of std Vector2: "<<Vector2.back()<<std::endl;
	// // for (int i = 0; i < 4; ++i)
	// // 	std::cout<<Vector2[i]<<std::endl;
	// std::cout << std::endl;


	// myVector2.back() = "88";
	// Vector2.back() = "88";
	// std::cout<<"top of ft myVector2 after .back() = 88: "<<myVector2.back()<<std::endl;
	// std::cout<<"top of std Vector2 after .back() = 88: "<<Vector2.back()<<std::endl;
	// std::cout << std::endl;

	// ft::vector<std::string> const myConstVec2(3, "33");
	// std::vector<std::string> const constVec2(3, "33");
	// // myConstVec2.back() = "88";
	// // constVec2.back() = "88"; //cant use for const
	// std::cout<<"top of ft myConstVec2 after .back()"<<myConstVec2.back()<<std::endl;
	// std::cout<<"top of std constVec2 after .back() "<<constVec2.back()<<std::endl;
	// std::cout << std::endl;



	// myVector2.resize(0);
	// Vector2.resize(0);
	// std::cout<<"size of ft myVector2: "<<myVector2.size()<<std::endl;
	// std::cout<<"size of std Vector2: "<<Vector2.size()<<std::endl;
	// std::cout<<"capacity of ft myVector2: "<<myVector2.capacity()<<std::endl;
	// std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;
	// std::cout<<"top of ft myVector2: "<<myVector2.back()<<std::endl;
	// std::cout<<"top of std Vector2: "<<Vector2.back()<<std::endl;
	// std::cout << std::endl;


	
	// ft::vector<int> myIntVector2;
	// std::vector<int> intVector2;

	// for (int i = 1; i< 10 ; i++)
	// {
	// 	myIntVector2.push_back(i*2);
	// 	intVector2.push_back(i*2);
	// }
	// std::cout<<"size of ft myIntVector2: "<<myIntVector2.size()<<std::endl;
	// std::cout<<"size of std intVector2: "<<intVector2.size()<<std::endl;
	// std::cout<<"capacity of ft myIntVector2: "<<myIntVector2.capacity()<<std::endl;
	// std::cout<<"capacity of std intVector2: "<<intVector2.capacity()<<std::endl;


	// std::cout<<"front of ft myIntVector2: "<<myIntVector2.front()<<std::endl;
	// std::cout<<"front of std intVector2: "<<intVector2.front()<<std::endl;
	
	// myIntVector2.resize(0);
	// intVector2.resize(0);
	// std::cout<<"size of ft myIntVector2: "<<myIntVector2.size()<<std::endl;
	// std::cout<<"size of std intVector2: "<<intVector2.size()<<std::endl;
	// std::cout<<"capacity of ft myIntVector2: "<<myIntVector2.capacity()<<std::endl;
	// std::cout<<"capacity of std intVector2: "<<intVector2.capacity()<<std::endl;


	// std::cout<<"front of ft myIntVector2: "<<myIntVector2.front()<<std::endl;
	// std::cout<<"front of std intVector2: "<<intVector2.front()<<std::endl;

	// for (int i = 1; i< 10 ; i++)
	// {
	// 	myIntVector2.push_back(i*2);
	// 	intVector2.push_back(i*2);
	// }

	// for (int i = 0 ; i< myIntVector2.size(); ++i)
	// {
	// 	std::cout << "myIntVector2.at("<<i<<"): "<< myIntVector2.at(i)<<std::endl;
	// 	std::cout << "intVector2.at("<<i<<"): "<< intVector2.at(i)<<std::endl;
	// 	myIntVector2.at(i) = myIntVector2.at(i) / 2 *3;
	// 	intVector2.at(i) = intVector2.at(i) / 2 *3;
	
	// }
	// std::cout<< std::endl;

	// for (int i = 0 ; i< myIntVector2.size(); ++i)
	// {
	// 	std::cout << "new myIntVector2.at("<<i<<"): "<< myIntVector2.at(i)<<std::endl;
	// 	std::cout << "new intVector2.at("<<i<<"): "<< intVector2.at(i)<<std::endl;
	// }

	// myIntVector2.resize(0);
	// intVector2.resize(0);
	// for (int i = 0 ; i< myIntVector2.size(); ++i)
	// {
	// 	std::cout << "myIntVector2.at("<<i<<"): "<< myIntVector2.at(i)<<std::endl;
	// 	std::cout << "intVector2.at("<<i<<"): "<< intVector2.at(i)<<std::endl;
	
	// }
	// std::cout<<"!size of ft myIntVector2: "<<myIntVector2.size()<<std::endl;
	// std::cout<<"!size of std intVector2: "<<intVector2.size()<<std::endl;
	// std::cout<<"!capacity of ft myIntVector2: "<<myIntVector2.capacity()<<std::endl;
	// std::cout<<"!capacity of std intVector2: "<<intVector2.capacity()<<std::endl;

	
	// for (int i = 0; i< 3 ; i++)
	// {
	// 	myIntVector2.push_back(i);
	// 	intVector2.push_back(i);
	// }


	// ft::vector<int> myIntVector3 = myIntVector2;
	// std::vector<int> intVector3 = intVector2;
	// std::cout<<"size of ft myIntVector2: "<<myIntVector3.size()<<std::endl;
	// std::cout<<"capacity of std myIntVector3: "<<myIntVector3.capacity()<<std::endl;
	//  std::cout<<"size of ft intVector3: "<<intVector3.size()<<std::endl;
	// std::cout<<"capacity of std intVector3: "<<intVector3.capacity()<<std::endl;


	// for (int i = 0; i< 3 ; i++)
	// {
	// 	std::cout << "myIntVector3 cont 3 elem: "<<"elem "<< i <<" = "<<myIntVector3[i]<<std::endl;
	// 	std::cout << "intVector3 cont 3 elem: "<<"elem "<< i <<" = "<<intVector3[i]<<std::endl;
		
	// }


	// ft::vector<int> myVec1;
	// std::vector<int> vec1;

	// for (int i = 0; i< 9; ++i)
	// {
	// 	myVec1.push_back(i);
	// 	vec1.push_back(i);
	// }

	// ft::vector<int> myVec2;
	// std::vector<int> vec2;

	// std::cout<<"size of std myVec1 before swap: "<<myVec1.size()<<std::endl;
	// std::cout<<"size of std vec1 before swap: "<<vec1.size()<<std::endl;

	// std::cout<<"capacity of std myVec1 before swap: "<<myVec1.capacity()<<std::endl;
	// std::cout<<"capacity of std vec1 before swap: "<<vec1.capacity()<<std::endl;

	// std::cout<<"size of std myVec2 before swap: "<<myVec2.size()<<std::endl;
	// std::cout<<"size of std vec2 before swap: "<<vec2.size()<<std::endl;
	
	// std::cout<<"capacity of std myVec2 before swap: "<<myVec2.capacity()<<std::endl;
	// std::cout<<"capacity of std vec2 before swap: "<<vec2.capacity()<<std::endl;

	// ft::swap(myVec1, myVec2);
	// std::swap(vec1, vec2);
	// myVec1.swap(myVec2);
	// vec1.swap(vec2);

	// std::cout<<"size of std myVec1 before swap: "<<myVec1.size()<<std::endl;
	// std::cout<<"size of std vec1 before swap: "<<vec1.size()<<std::endl;

	// std::cout<<"capacity of std myVec1 before swap: "<<myVec1.capacity()<<std::endl;
	// std::cout<<"capacity of std vec1 before swap: "<<vec1.capacity()<<std::endl;

	// std::cout<<"size of std myVec2 before swap: "<<myVec2.size()<<std::endl;
	// std::cout<<"size of std vec2 before swap: "<<vec2.size()<<std::endl;
	
	// std::cout<<"capacity of std myVec2 before swap: "<<myVec2.capacity()<<std::endl;
	// std::cout<<"capacity of std vec2 before swap: "<<vec2.capacity()<<std::endl;
	




	return (0);
}	   

