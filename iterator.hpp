#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <memory>
#include "random_access_iterator_tag.hpp"

namespace ft
{
	
	// iterator
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
  	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};


	// iterator traits
	template< class Iter >
	struct iterator_traits
	{
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference 			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template< class T >
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef random_access_iterator_tag<T>	iterator_category;
	};
	
	template< class T >
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		// typedef ft::random_access_iterator_tag	iterator_category;
	};



	// template< typename T >
	// class random_access_iterator_tag
	// {
	// 	public:
	// 	// typedef T         value_type;
	// 	// typedef Distance  difference_type;
  	// 	typedef T* pointer;
	// 	typedef T& reference;
	// 	// typedef Category  iterator_category;
	// 	typedef typename std::allocator<T> ::pointer		pointer2;
		
		
	// 	public:
	// 	random_access_iterator_tag():elem(0)
	// 	{};

	// 	private:
	// 	pointer elem;

	// 	public:

	// 	random_access_iterator_tag &operator=(const random_access_iterator_tag &cp)
	// 	{
	// 		elem = cp;
	// 	}
		
	// 	reference operator*(void) const
	// 	{

	// 		return (*elem);
	// 	}

	// 	random_access_iterator_tag (pointer2 const &vecPoint)
	// 	{
	// 		elem = vecPoint;
	// 	}

	// 	// Point& operator++();       // Prefix increment operator.
	// 	// Point operator++(int);     // Postfix increment operator.

	// 	random_access_iterator_tag &operator++()
	// 	{
	// 		elem++;
	// 		return (*this);
	// 	}
	// 	random_access_iterator_tag operator++(int)
	// 	{
	// 		random_access_iterator_tag temp = *this;
	// 		++*this;
	// 		return temp;
	// 	}

	// 	// bool operator!=(pointer2 const &vecPoint)
	// 	// {
	// 	// 	return (*elem != *vecPoint);
	// 	// }

	// 	// bool operator!=(pointer const &cp)
	// 	// {
	// 	// 	return (*elem != *(cp.elem));
	// 	// }

	
	// 	bool operator !=(random_access_iterator_tag const &cp)
	// 	{
	// 		// std::cout<<"i ma here\n";
	// 		return (elem != cp.elem);
	// 	}

	// 	// random_access_iterator_tag &operator==(const random_access_iterator_tag &cp)
	// 	// {
	// 	// 	return (*elem == *elem);
	// 	// }
	// 	// random_access_iterator_tag operator!=(const random_access_iterator_tag &cp)
	// 	// {
	// 	// 	return (*elem != *elem);
	// 	// }
	// 	// random_access_iterator_tag &operator>=(const random_access_iterator_tag &cp)
	// 	// {
	// 	// 	return (*elem >= *elem);
	// 	// }
	// 	// random_access_iterator_tag &operator<=(const random_access_iterator_tag &cp)
	// 	// {
	// 	// 	return (*elem <= *elem);
	// 	// }
	// 	// random_access_iterator_tag &operator>(const random_access_iterator_tag &cp)
	// 	// {
	// 	// 	return (*elem > *elem);
	// 	// }
	// 	// random_access_iterator_tag &operator<(const random_access_iterator_tag &cp)
	// 	// {
	// 	// 	return (*elem < *elem);
	// 	// }
	// };

	
}

#endif
