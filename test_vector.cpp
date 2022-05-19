#include <iostream>
#include "vector.hpp"
#include <vector>
#include <string>

#define GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[1;31m"
#define SHALLOW "\033[0m"
// #if 1
// 	namespace ft = std;
// #endif

// class A 
// {
// 	public:
// 		int _a;
// 		A(){ std::cout << "constructor called" << std::endl; };
// 		~A() { std::cout << "destructor called" << std::endl;};
// 		A(int a):_a(a){}
		

// };


// int main()
// {
// 	{
// 		std::cout << std::endl;
// 		ft::vector<A> v(5);
// 		std::cout << std::endl;

// 		// std::cout << std::endl;
// 		// std::vector<A> v1(5);
// 		// std::cout << std::endl;

// 	}
// }

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
	ft::vector <int> z;
    for(int i = 0; i < 3; ++i)
    {
        std::cout << "capacity: " << z.capacity() << std::endl;
        std::cout << "size: " << z.size() << std::endl;
        z.push_back(5);
        print_all(z);
        std::cout << "capacity: " << z.capacity() << std::endl;
        std::cout << "size: " << z.size() << std::endl << std::endl;
    }

/*	empty vector
	ft::vector<std::string> myVector;
	std::allocator<int> alloc;
	
	ft::vector<std::string> myVector2;
	std::vector<std::string> Vector2;
	std::cout<<"size of my Vector2: "<<myVector2.size()<<std::endl;
	std::cout<<"size of std Vector2: "<<Vector2.size()<<std::endl;
	std::cout<<"capacity of my Vector2: "<<myVector2.capacity()<<std::endl;
	std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;
	std::cout << std::endl;
	
	myVector2.resize(15);
	Vector2.resize(15);
	std::cout<<"size resize(0) of my Vector2: "<<myVector2.size()<<std::endl;
	std::cout<<"size resize(0) of std Vector2: "<<Vector2.size()<<std::endl;
	std::cout<<"capacity of my Vector2: "<<myVector2.capacity()<<std::endl;
	std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;
	std::cout <<std::endl;
	
	// myVector2.reserve(13);
	// Vector2.reserve(13);
	std::cout<<"size after reserve(10) of my Vector2: "<<myVector2.size()<<std::endl;
	std::cout<<"size after reserve(10) of std Vector2: "<<Vector2.size()<<std::endl;
	std::cout<<"capacity of my Vector2: "<<myVector2.capacity()<<std::endl;
	std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;
	std::cout << std::endl;

	for (int i = 0; i<11; ++i)
		myVector2.push_back("sasf");
	for (int i = 0; i<11; ++i)
		Vector2.push_back("sasf");


	std::cout<<"size after push_back of my Vector2: "<<myVector2.size()<<std::endl;
	std::cout<<"size after push_back of std Vector2: "<<Vector2.size()<<std::endl;
	std::cout<<"capacity after push_back of my Vector2: "<<myVector2.capacity()<<std::endl;
	std::cout<<"capacity after push_back of std Vector2: "<<Vector2.capacity()<<std::endl;





	// std::cout<<"max size of my Vector2: "<<myVector2.max_size()<<std::endl;
	// std::cout<<"max size of std Vector2: "<<Vector2.max_size()<<std::endl;
	// std::cout << std::endl;
	
	// std::cout<<"std my Vector2 is empty: "<<myVector2.empty()<<std::endl;
	// std::cout<<"std Vector2 is empty: "<<Vector2.empty()<<std::endl;
	// std::cout << std::endl;
	
	// // myVector2.pop_back();
	// // myVector2.pop_back();
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

	// Vector2.push_back(4);
	// Vector2.push_back(3);
	// std::cout<<"size of std Vector2: "<<Vector2.size()<<std::endl;
	// std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;
	// std::cout << std::endl;

	// Vector2.resize(4);
	// std::cout<<"size of std Vector2: "<<Vector2.size()<<std::endl;
	// std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;
	// std::cout<<"top of std Vector2: "<<Vector2.back()<<std::endl;
	// for (int i = 0; i < 4; ++i)
	// 	std::cout<<Vector2[i]<<std::endl;
	// std::cout << std::endl;

	// Vector2.resize(11);
	// std::cout<<"size of std Vector2: "<<Vector2.size()<<std::endl;
	// std::cout<<"capacity of std Vector2: "<<Vector2.capacity()<<std::endl;
	// std::cout<<"top of std Vector2: "<<Vector2.back()<<std::endl;
	// std::cout << std::endl;

	// while (1)
	// {}
*/	
	return (0);
}	   

