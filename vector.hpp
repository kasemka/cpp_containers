#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <string>
#include <memory>
#include <vector>
#include <iostream>

// namespace ft
// {
// template<bool Cond, class l = void>
// struct enable_if
// {

// };

// template<class T>
// struct enable_if<true, T>
// {
// 	typedef T type;
// };

// }

// template<typename T>
// class Allocator: 
// {
// 	allocator<T> myAlloc;
// 	size_t _size;
// 	public:
// 	Allocator(const size_t &size = 10): _size(size){
// 		return (myAlloc.allocate(10));
// 	};


// };


namespace ft
{
	template<typename T, typename allocator_type = std::allocator<T> >
	class vector
	{
		public:
		typedef T									value_type;
		// typedef Alloc								allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef size_t										size_type;
		// typedef value_type iterator



		private:

		allocator_type	_alloc;
		size_type		_size;
		size_type		_capacity;
		// value_type		*_name;
		pointer			_p;
		
		

		public:
		// (1) empty container constructor (default constructor)
		explicit vector (const allocator_type& alloc = allocator_type()):
		_alloc(alloc), _size(0), _p(0)
		{
			std::cout<<"empty vector constructor called"<<std::endl;
		};

		//(2) fill constructor
		// Constructs a container with n elements. Each element is a copy of val.
		explicit vector (size_type _n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
		_alloc(alloc), _size(_n), _capacity(_n)
		{

			_p = _alloc.allocate(_capacity);
			for (int i = 0; i < _n; ++i)
			{
				_alloc.construct(_p + i, val);
			}
			std::cout<<"vector with n elements constructor called"<<std::endl;
		};


		// range constructor
		// Constructs a container with as many elements as the range [first,last), 
		// with each element constructed from its corresponding element in that range, in the same order.
		// template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

		// copy constructor
		vector (const vector& x)
		{
			*this = x;
			std::cout<<"vector copy constructor called"<<std::endl;
			
		};
		

		~vector()
		{
			
			if (_p)
			{
				for (size_t i = 0; i<_size; i++)
					_alloc.destroy(_p + i);
				_alloc.deallocate(_p, _capacity);
			}
		};


		size_type size() const
		{
			return _size;
		}
		size_type max_size() const
		{
			return (allocator_type().max_size());
		}
		
		// void resize (size_type n, value_type val = value_type())
		// {
		// 	if ()
		// }
		size_type capacity() const
		{
			return _capacity;
		}

		bool empty() const
		{
			
			return (_size > 0 ? false : true);
		}

		void reserve (size_type n);
	
		

		// allocator_type get_allocator() const
		// {
			
		// }
		



	};
}


#endif


// push_back(value): This method appends the data to the vector.
// pop_back(): This method removes the last element from the vector.
// insert(index, value): This method inserts new elements before the element at the specified position.
// size(): This method returns the size of the vector.
// empty(): This method checks whether the vector is empty or not.
// front(): This method returns the first value of the vector.
// back(): The back method returns the last value of the vector.
// at(index): This method returns the value at the specified position.
// erase(index): The erase method removes elements from the given index.
// clear(): This method clears all the items in the vector.
// begin(): It returns an iterator element which points to the first element of the vector.
// end(): It returns an iterator element which points to the last element of the vector.
// swap(): Swaps the two input vectors.




