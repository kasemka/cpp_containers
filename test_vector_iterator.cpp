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
	ft::vector<int> nums1;
	std::vector<int> nums2;

	int j = 10;
	for (int i = 0; i<5; ++i)
	{
		nums1.push_back(++j);
		nums2.push_back(j);
	}

	// ft::vector<int>::iterator it = nums1.begin();
	// std::cout<< YELLOW << *it <<std::endl;

	int u =0;
	
	std::cout<< "end () = " << *(nums1.end()) <<std::endl;
	for (ft::vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++)
	{	
		
		std::cout<< YELLOW <<*it<<std::endl;
		if (u++ == 10)
			break;
	}
	for (std::vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it)
		std::cout<< GREEN<<*it<<std::endl;

	std::cout<<std::endl;

	
	ft::vector<int> nums1Clone(nums1.begin(), nums1.begin()[2]);
	// for (std::vector<int>::iterator it = nums1Clone.begin(); it != nums1Clone.end(); ++it)
	// {
	// 	std::cout<< YELLOW <<*it<<std::endl;
	// }


	std::vector<int> nums2Clone(nums2.begin(), nums2.begin()+2);
	for (std::vector<int>::iterator it = nums2Clone.begin(); it != nums2Clone.end(); ++it)
	{
		std::cout<<GREEN<<*it<<std::endl;
	}
	std::cout<<std::endl;
	

	return (0);
}	   

