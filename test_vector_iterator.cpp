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
	/***************************************************/
	/*              new vector creation                */
	/***************************************************/
	ft::vector<int> nums1;
	std::vector<int> nums2;

	int j = 10;
	for (int i = 0; i<5; ++i)
	{
		nums1.push_back(++j);
		nums2.push_back(j);
	}

	std::cout<< SHALLOW << "constructor creation FT" <<std::endl;
	for (ft::vector<int>::iterator it = nums1.begin(); it!=nums1.end(); it++)
		std::cout<< YELLOW <<*it<<" ";
	std::cout<<std::endl;

	std::cout<< SHALLOW << "constructor creation STD" <<std::endl;
	for (std::vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it)
		std::cout<< GREEN<<*it<<" ";
	std::cout<<std::endl;

	std::cout<<std::endl;
	
	/***************************************************/
	/*             constructor with iter               */
	/***************************************************/
	std::cout<< SHALLOW << "constructor with iter FT" <<std::endl;
	ft::vector<int> nums1Clone(nums1.begin(), nums1.end());
	for (ft::vector<int>::iterator it = nums1Clone.begin(); it != nums1Clone.end(); ++it)
		std::cout<< YELLOW <<*it<<std::endl;

	std::cout<< SHALLOW << "constructor with iter STD" <<std::endl;
	std::vector<int> nums2Clone(nums2.begin(), nums2.end());	
	for (std::vector<int>::iterator it = nums2Clone.begin(); it != nums2Clone.end(); ++it)
		std::cout<<GREEN<<*it<<std::endl;

	std::cout<<std::endl;

	/******************************************/
	/*             assign check               */
	/******************************************/

	std::cout<< SHALLOW << "assign check FT" <<std::endl;

	ft::vector<int> firstF;
	ft::vector<int> secondF;
	ft::vector<int> thirdF;

	firstF.assign (7,100);             // 7 ints with a value of 100

	ft::vector<int>::iterator itF;
	itF=firstF.begin()+1;
	secondF.assign(itF,firstF.end()-1); // the 5 central values of first
	int myintsF[] = {1776,7,4};
	thirdF.assign (myintsF,myintsF+3);   // assigning from array.

	std::cout<<YELLOW << "Size of first: " << int (firstF.size()) <<", capacity " <<(firstF.capacity()) << '\n';
	std::cout<<YELLOW << "Size of second: " << int (secondF.size()) <<", capacity " <<(secondF.capacity())  << '\n';
	std::cout<<YELLOW<< "Size of third: " << int (thirdF.size()) <<", capacity " <<(thirdF.capacity())  << '\n';
	firstF.assign(1, 0);
	std::cout<<YELLOW << "Size of first: " << int (firstF.size()) <<", capacity " <<(firstF.capacity()) << '\n';


	std::cout<< SHALLOW << "assign check STD" <<std::endl;

	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100
	std::vector<int>::iterator it;
	it=first.begin()+1;
	second.assign (it,first.end()-1); // the 5 central values of first
	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout<<GREEN << "Size of first: " << int (first.size()) <<", capacity " <<(first.capacity()) << '\n';
	std::cout<<GREEN << "Size of second: " << int (second.size()) <<", capacity " <<(second.capacity())  << '\n';
	std::cout<<GREEN<< "Size of third: " << int (third.size()) <<", capacity " <<(third.capacity())  << '\n';
	first.assign(1, 0);
	std::cout<<GREEN << "Size of first: " << int (first.size()) <<", capacity " <<(first.capacity()) << '\n';

	/******************************************/
	/*             insert check               */
	/******************************************/

	ft::vector<int> num1(2, 100);
	ft::vector<int>::iterator iter = num1.begin();

	// ft::vector<int> num2(3, 300);
	num1.insert(iter, 1000);

	for (ft::vector<int>::iterator b = num1.begin(); b!=num1.end();++b)
		std::cout<<*b<<std::endl;


	std::vector<int> num1s(2, 100);
	std::vector<int>::iterator iters = num1s.begin();

	// ft::vector<int> num2(3, 300);
	num1s.insert(iters, 1000);

	for (std::vector<int>::iterator b = num1s.begin(); b!=num1s.end();++b)
		std::cout<<*b<<std::endl;


	return (0);
}

