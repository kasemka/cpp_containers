#include <iostream>
#include "vector.hpp"
#include <vector>
#include <string>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define SHALLOW "\033[0m"

using namespace std;

int main(){
	/****************************************************/
	/*             reverse iterator check               */
	/****************************************************/

	std::cout<< SHALLOW << "reverse iterator check" <<std::endl;
	
	vector<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);
	typedef vector<int>::iterator iter_type;
	iter_type from (myvector.begin()); 
	iter_type until (myvector.end());
	reverse_iterator<iter_type> rev_until (from);
	reverse_iterator<iter_type> rev_from (until); 


	std::cout << *rev_until<<std::endl;
	std::cout << *rev_from<<std::endl;

	std::cout << "myvector:";
	while (rev_from != rev_until)
		std::cout << ' ' << *rev_from++;
	std::cout << '\n';
	
	// std::cout << *myvector.rend()<<std::endl;
	std::cout << *(myvector.rend() - 1)<<std::endl;
	std::cout << *myvector.rend()<<std::endl;

	/***************************************************/
	/*              const iterator check               */
	/***************************************************/

	ft::vector <int> m;
    m.push_back(5);
    ft::vector<int>::iterator it = m.begin();
    ft::vector<int>::const_iterator itc = m.end();
	itc = it;
    // it = itc; 
	return 0;

}