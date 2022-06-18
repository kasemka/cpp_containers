#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <memory>
// #include <iterator>
#include "utils.hpp"


namespace ft
{
	struct random_access_iterator_tag {};
	struct bidirectional_iterator_tag {};

	// iterator traits
	// iterator_traits<Iterator> will only have the nested types if Iterator::iterator_category exists.
	template< class T >
	struct iterator_traits
	{
		typedef typename T::difference_type		difference_type;
		typedef typename T::value_type			value_type;
		typedef typename T::pointer				pointer;
		typedef typename T::reference 			reference;
		typedef typename T::iterator_category	iterator_category;
	};

	template< class T >
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef ft::random_access_iterator_tag		iterator_category;
	};
	
	template< class T >
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef ft::random_access_iterator_tag		iterator_category;
	};

// iterator
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
  	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};


	template< class T >
	struct iteratorVector : ft::iterator<typename ft::iterator_traits<T>::iterator_category, typename ft::iterator_traits<T>::value_type >
	{
		public:
			typedef T iterator_type;
			
			iteratorVector():_elem(0){};
			iteratorVector(typename iteratorVector::pointer const &vecPoint):_elem(vecPoint){};

			template <class _Up>
			iteratorVector(const iteratorVector<_Up>& __u, typename std::enable_if<std::is_convertible<_Up, iterator_type>::value>::type* = 0): _elem(__u.base()){};

			~iteratorVector() {};
			// T base() const  { return _elem; }



			iteratorVector &operator=(iteratorVector const &cp){
				if (this != &cp)
					this->_elem =cp._elem;
				return (*this);
			};





			// iterator_type base() const {return _elem;}
			
			typename iteratorVector::reference operator*(void) const { return (*_elem); };
			typename iteratorVector::pointer operator->(void) const { return &(*_elem); };

			typename iteratorVector::reference operator[](unsigned int ind) const { return *(_elem + ind); };

			iteratorVector &operator++(){ _elem++; return (*this);};
			iteratorVector operator++(int){ iteratorVector temp = *this; ++*this; return temp; };
			iteratorVector &operator--(){ _elem--; return (*this);};
			iteratorVector operator--(int){ iteratorVector temp = *this; --*this; return temp; };

			iteratorVector &operator+=(int num){ _elem = _elem + num; return (*this);}
			iteratorVector &operator-=(int num){ _elem = _elem - num; return (*this);}
			
			iteratorVector operator+(int num) const { return (iteratorVector(_elem + num)); }
			iteratorVector operator-(int num) const { return (iteratorVector(_elem - num)); }
			int operator-(iteratorVector const &it) const { return (this->_elem - it._elem); };
			int operator+(iteratorVector const &it) const { return (this->_elem + it._elem); };

			bool operator!=(iteratorVector const &it) const {return (_elem != it._elem);};
			bool operator==(iteratorVector const &it) const {return (_elem == it._elem);};
			bool operator>=(iteratorVector const &it) const {return (_elem >= it._elem);};
			bool operator<=(iteratorVector const &it) const {return (_elem <= it._elem);};
			bool operator>(iteratorVector const &it) const {return (_elem > it._elem);};
			bool operator<(iteratorVector const &it) const {return (_elem < it._elem);};
		
		private:
			iterator_type _elem;
	};


	template< class T >
	struct reverse_iterator
	{
		private:
			T _elem;

		public:
			typedef T			iterator_type;
			typedef typename	iterator_traits<T>::difference_type		difference_type;
			typedef typename	iterator_traits<T>::value_type			value_type;
			typedef typename	iterator_traits<T>::pointer				pointer;
			typedef typename	iterator_traits<T>::reference 			reference;
			typedef typename	iterator_traits<T>::iterator_category	iterator_category;



			reverse_iterator():_elem(){};
			explicit reverse_iterator(iterator_type iter) : _elem(iter){};
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it): _elem(rev_it.base()){};
			template <class Iter>
			reverse_iterator& operator=(const reverse_iterator<Iter>& rev_it) { _elem = rev_it.base(); return *this; }



			iterator_type base() const {return _elem;};
			
			reference operator*(void) const { iterator_type tmp = _elem; return *--tmp; };
			pointer operator->() const {return &(operator*());};

			reverse_iterator& operator++() {--_elem; return *this;};
			reverse_iterator operator++(int) {reverse_iterator tmp(*this); --_elem; return tmp;};
			reverse_iterator& operator--() {++_elem; return *this;};
			reverse_iterator operator--(int) {reverse_iterator tmp(*this); ++_elem; return tmp;};

			reverse_iterator  operator+ (difference_type n) const {return reverse_iterator(_elem - n);};
			reverse_iterator& operator+=(difference_type n) {_elem -= n; return *this;};
			reverse_iterator  operator- (difference_type n) const {return reverse_iterator(_elem + n);};
			reverse_iterator& operator-=(difference_type n) {_elem += n; return *this;};
			reverse_iterator::reference operator[](difference_type n) const {return *(*this + n);};

			bool operator!=(reverse_iterator const &it) const {return (_elem != it._elem);};
			bool operator==(reverse_iterator const &it) const {return (_elem == it._elem);};
			bool operator>=(reverse_iterator const &it) const {return (_elem >= it._elem);};
			bool operator<=(reverse_iterator const &it) const {return (_elem <= it._elem);};
			bool operator>(reverse_iterator const &it) const {return (_elem > it._elem);};
			bool operator<(reverse_iterator const &it) const {return (_elem < it._elem);};
	};



	template< class T, class U>
	struct mapIterator
	{	
		public:
			typedef T							iterator_type;
			typedef U 							value_type;
			typedef U& 							reference;
			typedef U* 							pointer;
			typedef const U& 					const_reference;
			typedef const U* 					const_pointer;
			typedef bidirectional_iterator_tag	iterator_category;
			typedef ptrdiff_t					difference_type;


		private:
			T __iter;

		public:
			mapIterator(T iter = nullptr): __iter(iter) {};
			~mapIterator(){};

			reference operator*() const {return *(__iter->key);}
			pointer operator->() const {return __iter->key;}

			mapIterator& operator++() {++__iter; return *this;};
			mapIterator operator++(int){ 
				mapIterator tem(*this);
				++(*this);
				return tem;
			}	
			mapIterator& operator--() {--__iter; return *this;};
			mapIterator operator--(int){
				mapIterator tem(*this);
				--(*this);
				return tem;
			}
			
			friend
			bool operator==(const mapIterator& x, const mapIterator& y)
			{return x.__iter == y.__iter;};

			friend
			bool operator!=(const mapIterator& x, const mapIterator& y)
			{return x.__iter != y.__iter;};





	};

}

#endif
