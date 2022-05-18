// #include "stack.hpp"
// #include <iostream>
// #include <deque>
// #include <stack>
// #include <queue>

// int main()
// {

// 	ft::stack<int> s;
// 	s.push(30);
// 	s.push(40);
// 	s.push(50);
// 	s.push(60);

// 	std::cout << "The top of the stack contains " << s.top() << std::endl;
// 	s.pop();
// 	std::cout << "The top of the stack after performing pop operation: " << s.top() << std::endl;
// 	std::cout << "Printing all elements of the stack" << std::endl;

// 	while (!s.empty()){
// 		std::cout << s.top() << " ";
// 		s.pop();
// 	}

// 	ft::stack<int> i(s);
// 	std::cout<<"\ni == s : " << (i==s) <<std::endl;
// 	ft::stack<int> u;
// 	u = s;

// 	u.pop();
// 	u.pop();
// 	std::cout<<"u == s : " << (u==s) <<std::endl;

// 	std::deque<int> mydeque(3,100);          // deque with 3 elements
// 	std::vector<int> myvector(2,200);        // vector with 2 elements

// 	ft::stack<int> first;                    // empty stack


// 	ft::stack<int, std::deque<int> > second(mydeque);         // stack initialized to copy of deque

// 	ft::stack<int> third;  // empty stack using vector
// 	ft::stack<int> fourth (myvector);

// 	std::cout << "size of first: " << first.size() << '\n';
// 	std::cout << "size of second: " << second.size() << '\n';
// 	std::cout << "size of third: " << third.size() << '\n';
// 	std::cout << "size of fourth: " << fourth.size() << '\n';

// 	ft::stack<int, std::queue<int> > v66;



// 	std::deque<int> _c;
// 	const std::deque<int> &ctnr = std::deque<int>();
// 	_c = ctnr;

// 	return (0);
// }
