#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"
#include <deque>

namespace ft
{
	template<typename T, typename Container = ft::vector<T> >
	class stack
	{
		public:
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type 		size_type;
		typedef Container 							container_type;

		private:
		Container	_c;

		public:
		
		explicit stack (const container_type& ctnr = container_type()): _c(ctnr){}; //создание нового объекта референса  = вызов конструктора, если аргумент пустой
	
		virtual ~stack(){};

		bool empty() const
		{
			return (_c.empty());
		}
		
		size_t size() const
		{
			return (_c.size());
		}
		
		T &top()
		{
			return (_c.back());
		}
		
		const T &top() const
		{
			return (_c.back());
		}
		
		void push(const T &val)
		{
			_c.push_back(val);
		}

		void pop()
		{
			_c.pop_back();
		}

		template<typename Tn, typename Cont>
		friend bool operator==( const ft::stack< Tn, Cont > & lhs, const ft::stack< Tn,Cont > & rhs );
		
		template<typename Tn, typename Cont>
		friend bool operator!=( const ft::stack<Tn,Cont>& lhs, const ft::stack<Tn,Cont>& rhs );
			
		template<typename Tn, typename Cont>
		friend bool operator<(  const ft::stack<Tn,Cont>& lhs, const ft::stack<Tn,Cont>& rhs );
			
		template<typename Tn, typename Cont>
		friend bool operator<=(  const ft::stack<Tn,Cont>& lhs, const ft::stack<Tn,Cont>& rhs);
			
		template<typename Tn, typename Cont>
		friend bool operator>(  const ft::stack<Tn,Cont>& lhs, const ft::stack<Tn,Cont>& rhs );

		template<typename Tn, typename Cont>
		friend bool operator>=(  const ft::stack<Tn,Cont>& lhs, const ft::stack<Tn,Cont>& rhs);
	};
	

	template<typename Tn, typename Cont>
	bool operator==(  const ft::stack<Tn,Cont>& lhs, const ft::stack<Tn,Cont>& rhs ){
			return (lhs._c == rhs._c);
		}
	template<typename Tn, typename Cont>
	bool operator!=(  const ft::stack<Tn,Cont>& lhs, const ft::stack<Tn,Cont>& rhs ){
		return (lhs._c != rhs._c);
	}
		
	template<typename Tn, typename Cont>
	 bool operator<(  const ft::stack<Tn,Cont>& lhs, const ft::stack<Tn,Cont>& rhs ){
		return (lhs._c < rhs._c);
	}
		
	template<typename Tn, typename Cont>
	bool operator<=(  const ft::stack<Tn,Cont>& lhs, const ft::stack<Tn,Cont>& rhs){
		return (lhs._c <= rhs._c);
	}
		
	template<typename Tn, typename Cont>
	bool operator>(  const ft::stack<Tn,Cont>& lhs, const ft::stack<Tn,Cont>& rhs ){
		return (lhs._c > rhs._c);
	}

	template<typename Tn, typename Cont>
	bool operator>=(  const ft::stack<Tn,Cont>& lhs, const ft::stack<Tn,Cont>& rhs ){
		return (lhs._c >= rhs._c);
	}


}

#endif

// push(value): This method pushes the element in the stack.
// pop(): This method deletes the top element of the stack.
// top(): This method returns the value of the last element entered in the stack.
// size(): This method returns the size of the stack.
// empty(): This method checks whether the stack is empty or not.



