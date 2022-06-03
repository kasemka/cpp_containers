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
		iteratorVector():elem(0){};
		iteratorVector(typename iteratorVector::pointer const &vecPoint):elem(vecPoint){}
		iteratorVector(iteratorVector const &cp){ *this = cp;};
		iteratorVector &operator=(iteratorVector const &cp){
			if (this != &cp)
				this->elem =cp.elem;
			return (*this);
		};
		
		
		bool operator!=(iteratorVector const &it){return (elem != it.elem);};
		bool operator==(iteratorVector const &it){return (elem == it.elem);};

		typename iteratorVector::reference operator*(void) const{return (*elem);};
		typename iteratorVector::pointer operator->(void) const{return &(*elem);};

		iteratorVector &operator++(){ elem++; return (*this);};
		iteratorVector operator++(int){ iteratorVector temp = *this; ++*this; return temp;};
		iteratorVector &operator--(){ elem--; return (*this);};
		iteratorVector operator--(int){ iteratorVector temp = *this; --*this; return temp;};

		iteratorVector &operator+=(int num){ elem = elem + num; return (*this);}
		iteratorVector &operator-=(int num){ elem = elem - num; return (*this);}
		
		iteratorVector operator+(int num){ return (iteratorVector(this->elem + num));}
		iteratorVector operator-(int num){ return (iteratorVector(this->elem + num));}


		private:
			typename iteratorVector::pointer elem;
	};

	
}

#endif
