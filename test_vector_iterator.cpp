#include <iostream>
#include "vector.hpp"
#include <vector>
#include <string>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
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
	// /***************************************************/
	// /*              new vector creation                */
	// /***************************************************/
	// ft::vector<int> nums1;
	// std::vector<int> nums2;

	// int j = 10;
	// for (int i = 0; i<5; ++i)
	// {
	// 	nums1.push_back(++j);
	// 	nums2.push_back(j);
	// }

	// std::cout<< SHALLOW << "constructor creation FT" <<std::endl;
	// for (ft::vector<int>::iterator it = nums1.begin(); it!=nums1.end(); it++)
	// 	std::cout<< YELLOW <<*it<<" ";
	// std::cout<<std::endl;

	// std::cout<< SHALLOW << "constructor creation STD" <<std::endl;
	// for (std::vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it)
	// 	std::cout<< GREEN<<*it<<" ";
	// std::cout<<std::endl;

	// std::cout<<std::endl;
	
	// /***************************************************/
	// /*             constructor with iter               */
	// /***************************************************/
	// std::cout<< SHALLOW << "constructor with iter FT" <<std::endl;
	// ft::vector<int> nums1Clone(nums1.begin(), nums1.end());
	// for (ft::vector<int>::iterator it = nums1Clone.begin(); it != nums1Clone.end(); ++it)
	// 	std::cout<< YELLOW <<*it<<std::endl;

	// std::cout<< SHALLOW << "constructor with iter STD" <<std::endl;
	// std::vector<int> nums2Clone(nums2.begin(), nums2.end());	
	// for (std::vector<int>::iterator it = nums2Clone.begin(); it != nums2Clone.end(); ++it)
	// 	std::cout<<GREEN<<*it<<std::endl;

	// std::cout<<std::endl;

	// /******************************************/
	// /*             assign check               */
	// /******************************************/

	// std::cout<< SHALLOW << "assign check FT" <<std::endl;

	// ft::vector<int> firstF;
	// ft::vector<int> secondF;
	// ft::vector<int> thirdF;

	// firstF.assign (7,100);             // 7 ints with a value of 100

	// ft::vector<int>::iterator itF;
	// itF=firstF.begin()+1;
	// secondF.assign(itF,firstF.end()-1); // the 5 central values of first
	// int myintsF[] = {1776,7,4};
	// thirdF.assign (myintsF,myintsF+3);   // assigning from array.

	// std::cout<<YELLOW << "Size of first: " << int (firstF.size()) <<", capacity " <<(firstF.capacity()) << '\n';
	// std::cout<<YELLOW << "Size of second: " << int (secondF.size()) <<", capacity " <<(secondF.capacity())  << '\n';
	// std::cout<<YELLOW<< "Size of third: " << int (thirdF.size()) <<", capacity " <<(thirdF.capacity())  << '\n';
	// firstF.assign(1, 0);
	// std::cout<<YELLOW << "Size of first: " << int (firstF.size()) <<", capacity " <<(firstF.capacity()) << '\n';


	// std::cout<< SHALLOW << "assign check STD" <<std::endl;

	// std::vector<int> first;
	// std::vector<int> second;
	// std::vector<int> third;

	// first.assign (7,100);             // 7 ints with a value of 100
	// std::vector<int>::iterator it;
	// it=first.begin()+1;
	// second.assign (it,first.end()-1); // the 5 central values of first
	// int myints[] = {1776,7,4};
	// third.assign (myints,myints+3);   // assigning from array.

	// std::cout<<GREEN << "Size of first: " << int (first.size()) <<", capacity " <<(first.capacity()) << '\n';
	// std::cout<<GREEN << "Size of second: " << int (second.size()) <<", capacity " <<(second.capacity())  << '\n';
	// std::cout<<GREEN<< "Size of third: " << int (third.size()) <<", capacity " <<(third.capacity())  << '\n';
	// first.assign(1, 0);
	// std::cout<<GREEN << "Size of first: " << int (first.size()) <<", capacity " <<(first.capacity()) << '\n';

	// std::cout <<std::endl;
	/******************************************/
	/*             insert check               */
	/******************************************/

	std::cout<< SHALLOW << "insert check FT" <<std::endl;
	ft::vector<int> numVecFt(1, 100);
	numVecFt.push_back(200);
	numVecFt.push_back(300);
	ft::vector<int>::iterator iter = numVecFt.begin();
	ft::vector<int>::iterator iter2 = numVecFt.end();

	numVecFt.insert(iter, 1000);
	std::cout<<YELLOW << "Size of ft numVecFt: " << int (numVecFt.size()) <<", capacity " <<(numVecFt.capacity()) << '\n';
	numVecFt.insert(iter2, 1000);

	for (ft::vector<int>::iterator b = numVecFt.begin(); b!=numVecFt.end();++b)
		std::cout<<YELLOW<<*b<<std::endl;
	std::cout<<YELLOW << "Size of ft numVecFt: " << int (numVecFt.size()) <<", capacity " <<(numVecFt.capacity()) << '\n';
	numVecFt.pop_back();
	numVecFt.pop_back();
	numVecFt.pop_back();
	numVecFt.pop_back();
	for (ft::vector<int>::iterator b = numVecFt.begin(); b!=numVecFt.end();++b)
		std::cout<<YELLOW<<*b<<std::endl;
	std::cout<<YELLOW << "Size of ft numVecFt: " << int (numVecFt.size()) <<", capacity " <<(numVecFt.capacity()) << '\n';
	

	std::cout<< SHALLOW << "insert check STD" <<std::endl;
	std::vector<int> numVecStd(1, 100);
	numVecStd.push_back(200);
	numVecStd.push_back(300);
	std::vector<int>::iterator iters = numVecStd.begin();
	std::vector<int>::iterator iters2 = numVecStd.end();


	numVecStd.insert(iters, 1000);
	std::cout<<GREEN << "Size of std numVecStd: " << int (numVecStd.size()) <<", capacity " <<(numVecStd.capacity()) << '\n';
	numVecStd.insert(iters2, 1000);

	for (std::vector<int>::iterator b = numVecStd.begin(); b!=numVecStd.end();++b)
		std::cout<<GREEN <<*b<<std::endl;
	std::cout<<GREEN << "Size of std numVecStd: " << int (numVecStd.size()) <<", capacity " <<(numVecStd.capacity()) << '\n';
	numVecStd.pop_back();
	numVecStd.pop_back();
	numVecStd.pop_back();
	numVecStd.pop_back();
	for (std::vector<int>::iterator b = numVecStd.begin(); b!=numVecStd.end();++b)
		std::cout<<GREEN <<*b<<std::endl;
	std::cout<<GREEN << "Size of std numVecStd: " << int (numVecStd.size()) <<", capacity " <<(numVecStd.capacity()) << '\n';


	/***********************************************/
	/*             insert iter check               */
	/***********************************************/

	// std::cout<< SHALLOW << "insert check FT" <<std::endl;
	// ft::vector<int> numVecFt3(1, 100);
	// numVecFt3.push_back(200);
	// numVecFt3.push_back(300);
	// ft::vector<int>::iterator iter = numVecFt3.begin();
	// ft::vector<int>::iterator iter2 = numVecFt3.end();

	// numVecFt3.insert(iter, 1000);
	// std::cout<<YELLOW << "Size of ft numVecFt: " << int (numVecFt3.size()) <<", capacity " <<(numVecFt3.capacity()) << '\n';
	// numVecFt3.insert(iter2, 1000);

	// for (ft::vector<int>::iterator b = numVecFt3.begin(); b!=numVecFt3.end();++b)
	// 	std::cout<<YELLOW<<*b<<std::endl;
	// std::cout<<YELLOW << "Size of ft numVecFt: " << int (numVecFt3.size()) <<", capacity " <<(numVecFt3.capacity()) << '\n';
	// numVecFt3.pop_back();
	// numVecFt3.pop_back();
	// numVecFt3.pop_back();
	// numVecFt3.pop_back();
	// for (ft::vector<int>::iterator b = numVecFt3.begin(); b!=numVecFt3.end();++b)
	// 	std::cout<<YELLOW<<*b<<std::endl;
	// std::cout<<YELLOW << "Size of ft numVecFt: " << int (numVecFt3.size()) <<", capacity " <<(numVecFt3.capacity()) << '\n';
	

	
	
	



	// /******************************************/
	// /*             erase check                */
	// /******************************************/

	// std::cout<< SHALLOW << "erase check FT" <<std::endl;
	// ft::vector<int>::iterator begN = numVecFt.begin();
	// // ft::vector<int>::iterator endN = numVecFt.end();

	// std::cout<<YELLOW << "before erase ft numVecFt " << int (numVecFt.size()) <<", capacity " <<(numVecFt.capacity()) << '\n';
	// numVecFt.erase(begN);
	// // numVecFt.erase(endN);
	// std::cout<<YELLOW << "after erase ft numVecFt " << int (numVecFt.size()) <<", capacity " <<(numVecFt.capacity()) << '\n';
	// for (ft::vector<int>::iterator b = numVecFt.begin(); b!=numVecFt.end();++b)
	// 	std::cout<<YELLOW<<*b<<std::endl;


	// std::cout<< SHALLOW << "erase check STD" <<std::endl;
	// std::vector<int>::iterator begNs = numVecStd.begin();
	// // std::vector<int>::iterator endNs = numVecStd.end();

	// std::cout<<GREEN << "before erase STD numVecStd " << int (numVecStd.size()) <<", capacity " <<(numVecStd.capacity()) << '\n';
	// numVecStd.erase(begNs);
	// // numVecStd.erase(endNs);
	// std::cout<<GREEN << "after erase STD numVecStd " << int (numVecStd.size()) <<", capacity " <<(numVecStd.capacity()) << '\n';
	// for (std::vector<int>::iterator b = numVecStd.begin(); b!=numVecStd.end();++b)
	// 	std::cout<<GREEN<<*b<<std::endl;

	// // /******************************************/
	// // /*             erase2 check               */
	// // /******************************************/

	// std::cout<< SHALLOW << "erase check FT" <<std::endl;
	// std::cout<<YELLOW << "before erase ft numVecFt " << int (numVecFt.size()) <<", capacity " <<(numVecFt.capacity()) << '\n';
	// numVecFt.erase(numVecFt.begin(), numVecFt.begin()+2);

	// std::cout<<YELLOW << "after erase ft numVecFt " << int (numVecFt.size()) <<", capacity " <<(numVecFt.capacity()) << '\n';
	// for (ft::vector<int>::iterator b = numVecFt.begin(); b!=numVecFt.end();++b)
	// 	std::cout<<YELLOW<<*b<<std::endl;

	// std::cout<< SHALLOW << "erase check STD" <<std::endl;
	// std::cout<<GREEN << "before erase STD numVecStd " << int (numVecStd.size()) <<", capacity " <<(numVecStd.capacity()) << '\n';
	// numVecStd.erase(numVecStd.begin(), numVecStd.begin()+2);
	// // numVecStd.erase(endNs);
	// std::cout<<GREEN << "after erase STD numVecStd " << int (numVecStd.size()) <<", capacity " <<(numVecStd.capacity()) << '\n';
	// for (std::vector<int>::iterator b = numVecStd.begin(); b!=numVecStd.end();++b)
	// 	std::cout<<GREEN<<*b<<std::endl;

	// /********************************************/
	// /*             operator check               */
	// /********************************************/

	// ft::vector<int> foo1 (3,100);   // three ints with a value of 100
	// ft::vector<int> bar1 (2,200);
	// std::cout<< SHALLOW << " operator check FT" <<std::endl;
	// std::cout<< YELLOW << "foo1 (3,100) > bar1 (2,200) : " << (foo1 > bar1) <<std::endl;
	// std::cout<< YELLOW << "foo1 (3,100) >= bar1 (2,200) : " << (foo1 >= bar1) <<std::endl;
	// std::cout<< YELLOW << "foo1 (3,100) == bar1 (2,200) : " << (foo1 == bar1) <<std::endl;
	// std::cout<< YELLOW << "foo1 (3,100) =< bar1 (2,200) : " << (foo1 <= bar1) <<std::endl;
	// std::cout<< YELLOW << "foo1 (3,100) < bar1 (2,200) : " << (foo1 < bar1) <<std::endl;


	// std::cout<< SHALLOW << " operator check STD" <<std::endl;
	// std::vector<int> foo2 (3,100);   // three ints with a value of 100
	// std::vector<int> bar2 (2,200);
	// std::cout<< GREEN << "foo2 (3,100) > bar2 (2,200) : " << (foo2 > bar2) <<std::endl;
	// std::cout<< GREEN << "foo2 (3,100) >= bar2 (2,200) : " << (foo2 >= bar2) <<std::endl;
	// std::cout<< GREEN << "foo2 (3,100) == bar2 (2,200) : " << (foo2 == bar2) <<std::endl;
	// std::cout<< GREEN << "foo2 (3,100) =< bar2 (2,200) : " << (foo2 <= bar2) <<std::endl;
	// std::cout<< GREEN << "foo2 (3,100) < bar2 (2,200) : " << (foo2 < bar2) <<std::endl;


	return (0);
}

