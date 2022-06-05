#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <memory>
#include <iterator>


namespace ft
{
	struct random_access_iterator_tag {};
	// iterator traits
	// iterator_traits<Iterator> will only have the nested types if Iterator::iterator_category
	//    exists.  Else iterator_traits<Iterator> will be an empty class.  This is a
	//    conforming extension which allows some programs to compile and behave as
	//    the client expects instead of failing at compile time.
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
		typedef T iterator_type;
		
		iteratorVector():_elem(0){};
		iteratorVector(typename iteratorVector::pointer const &vecPoint):_elem(vecPoint){};
		iteratorVector(iteratorVector const &cp){ *this = cp;}; //add enable if ???
		// template <class _Up>
		// iteratorVector(const iteratorVector<_Up>& __u, typename std::enable_if<std::is_convertible<_Up, iterator_type>::value>::type* = 0): _elem(__u.base()){};

		iteratorVector &operator=(iteratorVector const &cp){
			if (this != &cp)
				this->_elem =cp._elem;
			return (*this);
		};


		iterator_type base() const {return _elem;}
		
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

	
}

#endif
