#include <iostream>
#include <map>
#include "map.hpp"

#include <unistd.h>
#include <string>

// #include "map.hpp"

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define REDd "\033[0;31m"
#define SHALLOW "\033[0m"


using namespace ft;

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

int main ()
{
	map<int, int> stdMap;

	stdMap.insert(pair<int, int>(1, 100)); 
	stdMap.insert(pair<int, int>(2, 200));
	stdMap.erase(stdMap.begin());
	stdMap.erase(stdMap.begin());
	stdMap.insert(pair<int, int>(3, 300)); 
	stdMap.insert(pair<int, int>(4, 400)); 
	stdMap.insert(pair<int, int>(5, 500)); 
	stdMap.insert(pair<int, int>(6, 600)); 
	// std::cout<<"!!!!!!!!!!erase = " <<(stdMap.erase(11)) <<std::endl;
	stdMap.insert(pair<int, int>(7, 700)); 
	stdMap.insert(pair<int, int>(8, 800));
	stdMap.insert(pair<int, int>(9, 900)); 
	// // stdMap.insert(pair<int, int>(0, 0));
	// // // stdMap.erase(stdMap.end());
	//  stdMap.printTree();

	for (map<int, int>::iterator it = stdMap.begin(); it != stdMap.end(); ++it)
		std::cout << it->first <<" " << it ->second << std::endl;

	// *********** check const ******************
	// map<int, int>::const_iterator itc = stdMap.begin();
	// map<int, int>::iterator it = stdMap.begin();
	// it = itc;
	// itc = it;
	
	// if (itc == it)
	// 	std::cout<<"yes"<<std::endl;


	return 0;
}

