#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <string>
#include <memory>
// #include <vector>
#include <iostream>
#include <unistd.h>
#include "iterator.hpp"
#include "utils.hpp"
#include <algorithm>


// class Iterator

namespace ft
{
	template<typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T															value_type;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef T*															pointer;
			typedef const T*													const_pointer;
			typedef iteratorVector<value_type*>									iterator;
			typedef iteratorVector<const value_type*>							const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			
			typedef typename iteratorVector<value_type*>::difference_type		difference_type;
			typedef size_t														size_type;


		public:
		
			explicit vector (const allocator_type& alloc = allocator_type()):_alloc(alloc), _p(0),  _size(0), _capacity(0) {};

			explicit vector (size_type _n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _p(0),  _size(0), _capacity(0) {
				this->assign(_n, val);
			};
			
			
			template <class InIter> 
			vector (InIter first, InIter last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InIter>::value, InIter>::type =0) :_alloc(alloc), _p(0),  _size(0), _capacity(0)
			{
				this->assign(first, last);
			};
		
			vector (const vector& x)
			{
				*this = x;
				// std::cout<<"vector copy constructor called"<<std::endl;
				
			};
			
			vector &operator=(const vector& x)
			{
			
				//add iterator later
				if (this != &x)
				{
					// _alloc = x._alloc;
					_size = x._size;
					_capacity = x._capacity;
					_p = _alloc.allocate(_capacity);

					for (size_type i = 0; i < _size; ++i)
						_alloc.construct(_p + i, *(x._p + i));
				}
				return (*this);
			};
			
			~vector(){
				clear();
				if (_capacity>0)
					_alloc.deallocate(_p, _capacity);
				
			};


			//Capacity:
			size_type size() const
			{
				return _size;
			}
			size_type max_size() const { return (allocator_type().max_size()); }
			void resize (size_type n, value_type val = value_type())
			{
				if (_capacity < n)
					reserve(_capacity*2);
				for (; _size < n; _size++)
					_alloc.construct(_p + _size, val);
				for (; _size > n;)
					this->pop_back();
			}
			size_type capacity() const { return _capacity; }
			bool empty() const { return (_size > 0 ? false : true); }
			void reserve (size_type n)
			{
				
				if (n > this->max_size() || n <= _capacity)
					return ;

				pointer		_oldp = _p;
				size_type	_oldcap = _capacity;

				_capacity = n;
				_p = _alloc.allocate(_capacity);
			
				
				if (_oldcap > 0){
					for (size_type i = 0; i < _size; ++i)
						_alloc.construct(_p + i, *(_oldp + i));
					for (size_type i = 0; i < _size; ++i)
						_alloc.destroy(_oldp + i);
					_alloc.deallocate(_oldp, _oldcap);
				}
				
				
				
			}
		
			// Modifiers:
			template <class InIter>
			void assign (InIter first, InIter last, typename ft::enable_if<!ft::is_integral<InIter>::value, InIter>::type* = 0)
			{
				this->clear();
				_size = last - first;
			
				// this->reserve(_size);
				if (_capacity < _size)
				{
					if (_capacity > 0)
						_alloc.deallocate(_p, _capacity);
					_capacity = _size;
					_p = _alloc.allocate(_capacity);
				}
				
				for (int i = 0;	first != last; ++first){
					_alloc.construct(_p + i, *first);
					i++;
				}
			}

			void assign (size_type n, const value_type& val)
			{
				clear();
				_size = n;

				// reserve(_size);
				if (_capacity < _size)
				{
					if (_capacity > 0)
						_alloc.deallocate(_p, _capacity);
					_capacity = _size;
					_p = _alloc.allocate(_capacity);
				}

				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(_p + i, val);
			}

			void push_back (const value_type& val)
			{
				size_type n;

				if (_size == _capacity)
				{
					if (_size == 0)
						n = 1;
					else 
						n = _capacity * 2;
					reserve(n);
				}
				_alloc.construct(_p + _size, val);
				++_size;
				
			}
			
			void pop_back()
			{
				_size--;
				_alloc.destroy(_p + _size);
			}

			iterator insert (iterator position, const value_type& val)
			{
				int ind = position - this->begin();
				insert(position, 1, val);

				return (this->begin() + ind);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				if (position < this->begin() || position >= this->end())
					return ;

				int			indexPos = position - this->begin();	
				pointer		_oldp = _p;
				size_type	_oldcap = _capacity;
				size_t		_oldsize = _size;
		
				_size += n; 
		
				if (_capacity < _size)
				{
					_capacity = _size * 2;
					_p = _alloc.allocate(_capacity);
				}

				int pIndex = _size - 1;
				int oIndex = _oldsize - 1;


				while (iterator(_oldp + oIndex) >= position)
					_p[pIndex--] = _oldp[oIndex--];

				
				while (pIndex >= 0 || pIndex >= indexPos)
					_p[pIndex--] = val;

		
				if (_oldcap < _capacity)
				{
					for (int i = 0; i < indexPos; ++i)
						_p[i] = _oldp[i];

					for (size_type i = 0; i < _oldsize; ++i)
						_alloc.destroy(_oldp + i);
					_alloc.deallocate(_oldp, _oldcap);
				}
			}

			template <class InIter>
			void insert (iterator position, InIter first, InIter last, typename ft::enable_if<!ft::is_integral<InIter>::value, InIter>::type* = 0)
			{
				if (position < this->begin() || position >= this->end())
					return ;

				int			indexPos = position - this->begin();
				pointer		_oldp = _p;
				size_type	_oldcap = _capacity;
				size_t		_oldsize = _size;
				
				int			n = last - first;

				_size += n; 

				if (_capacity < _size)
				{
					_capacity = _size * 2;
					_p = _alloc.allocate(_capacity);
				}

				int pIndex = _size - 1;
				int oIndex = _oldsize - 1;

				while (iterator(_oldp + oIndex) >= position)
					_p[pIndex--] = _oldp[oIndex--];

				
				while (pIndex >= 0 || pIndex >= indexPos)
				{
					_p[pIndex--] = *last;
					last--;
				}

				if (_oldcap < _capacity)
				{
					for (int i = 0; i < indexPos; ++i)
						_p[i] = _oldp[i];

					for (size_type i = 0; i < _oldsize; ++i)
						_alloc.destroy(_oldp + i);
					_alloc.deallocate(_oldp, _oldcap);
				}

			}

			iterator erase (iterator position)
			{
				if (position < this->begin() || position >= this->end())
					throw std::out_of_range("Vector");
				
				unsigned long posInd = position - this->begin();
				unsigned long posInd2 = posInd;
				--_size;

				while (posInd < _size)
				{
					_alloc.destroy(_p + posInd);
					_p[posInd] = _p[posInd + 1];
					++posInd;
				};
				_alloc.destroy(_p + posInd);
				return (_p + posInd2); //check later 
			}

			iterator erase (iterator first, iterator last)
			{
				if (first < this->begin() || first >= this->end() || last < this->begin() || last >= this->end())
					throw std::out_of_range("Vector");

				unsigned long indFirst = first - this->begin();
				unsigned long indFirstOld = indFirst;
				unsigned long indLast = last - this->begin();

				// unsigned long posInd2 = posInd;
				

				while (indFirst < _size)
				{
					_alloc.destroy(_p + indFirst);
					if (indLast < _size)
					{
						_p[indFirst] = _p[indLast];
						++indLast;
					}
					++indFirst;
				};
				
				_alloc.destroy(_p + indFirst);
				_size = _size - (last -first);
				return (_p + indFirstOld ); //check later 
			}

			void swap (vector& x)
			{
				vector<T, Alloc> tmp = x;
				x = *this;
				*this = tmp;
				// std::swap(*this, x);
			}
			void clear() {
				
				for (; _size > 0; --_size)
					_alloc.destroy(_p +_size - 1); 
			}
			
			
			// Element access:
			const_reference operator[] (size_type n) const { return(_p[n]); }
			reference operator[] (size_type n) { return(_p[n]); }
			reference at (size_type n){
				if (_size > 0)
					return(_p[n]);
				else 
					throw std::invalid_argument("");
				//intVector2.at(0): zsh: abort      ./a.out | 
				// zsh: done       cat -e
			}

			const_reference at (size_type n) const {
				if (_size > 0)
					return(_p[n]);
				else 
					throw std::invalid_argument("");
			}
			reference front(){
				// if (_size > 0)
				return _p[0];
				
				// else underfined behaviour 
				//
			}
			const_reference front() const
			{
				// if (_size > 0)
				return _p[0];
				// else underfined behaviour 
				//
			}
			reference back(){
				// if (_size > 0)
					return _p[_size - 1];
				// else
				// 	throw;
				// else 
				// throw std::invalid_argument("");
				// else underfined behaviour 
				//
			}
			const_reference back() const
			{
				// if (_size > 0)
					return _p[_size - 1];
				// else 
				// 	throw ;
			}

			// Iterators:
			iterator begin(){ return (_p); };
			const_iterator begin() const { return (_p); }
			iterator end(){ return (_p + _size); }
			const_iterator end() const{ return (_p + _size);}
			reverse_iterator rbegin(){return reverse_iterator(end());};
			const_reverse_iterator rbegin() const {return const_reverse_iterator(end());};
			reverse_iterator rend(){return reverse_iterator(begin());};
			const_reverse_iterator rend() const {return const_reverse_iterator(begin());};

			// Allocator:
			allocator_type get_allocator() const {}

			// Non-member function overloads
			template <class TF, class AllocF>
			friend bool operator== (const vector<TF,AllocF>& lhs, const vector<TF,AllocF>& rhs);
			
			template <class TF, class AllocF>
			friend bool operator!= (const vector<TF, AllocF>& lhs, const vector<TF, AllocF>& rhs);
				
			template <class TF, class AllocF>
			friend bool operator<  (const vector<TF,AllocF>& lhs, const vector<TF,AllocF>& rhs);
				
			template <class TF, class AllocF>
			friend bool operator<= (const vector<TF,AllocF>& lhs, const vector<TF,AllocF>& rhs);
				
			template <class TF, class AllocF>
			friend bool operator>  (const vector<TF,AllocF>& lhs, const vector<TF,AllocF>& rhs);
				
			template <class TF, class AllocF>
			friend bool operator>= (const vector<TF,AllocF>& lhs, const vector<TF,AllocF>& rhs);

			template <class TF, class AllocF>
			friend void swap (vector<TF, AllocF>& x, vector<TF, AllocF>& y);


		private:
			allocator_type	_alloc;
			pointer			_p;
			size_type		_size;
			size_type		_capacity;
	};



	template <class TF, class AllocF>
	bool operator== (const vector<TF,AllocF>& lhs, const vector<TF,AllocF>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		// return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));

		int size = lhs.size();
		for (int i = 0; i < size; ++i)
		{
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}
	
	template <class TF, class AllocF>
	bool operator != (const vector<TF, AllocF>& lhs, const vector<TF, AllocF>& rhs){ return !(lhs == rhs); }
		
	template <class TF, class AllocF>
	bool operator < (const vector<TF,AllocF>& lhs, const vector<TF,AllocF>& rhs){ 
		int size = lhs.size();
		if (size > rhs.size())
			size = rhs.size();
		for (int i = 0; i < size; ++i)
		{
			if (lhs[i] != rhs[i])
				return lhs[i] < rhs[i];
		}
		if (lhs.size() < rhs.size())
			return true;
		return (false); 
		
	}
		
	template <class TF, class AllocF>
	bool operator <= (const vector<TF,AllocF>& lhs, const vector<TF,AllocF>& rhs){ return !(rhs < lhs); }
		
	template <class TF, class AllocF>
	bool operator > (const vector<TF,AllocF>& lhs, const vector<TF,AllocF>& rhs){ return (rhs < lhs); }
		
	template <class TF, class AllocF>
	bool operator >= (const vector<TF,AllocF>& lhs, const vector<TF,AllocF>& rhs){ return !(lhs < rhs); }

	template <class TF, class AllocF>
	void swap (vector<TF, AllocF>& x, vector<TF, AllocF>& y)
	{
		//add iterator later???
		vector<TF, AllocF> tmp = x;
		x = y;
		y = tmp;

	}
}


// Non-member function overloads




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




