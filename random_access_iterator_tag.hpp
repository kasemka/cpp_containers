#ifndef RANDOM_ACCESS_ITERATOR_TAG_HPP
#define RANDOM_ACCESS_ITERATOR_TAG_HPP

#include <iostream>
#include <memory>

namespace ft
{

	template<typename T>
	class random_access_iterator_tag
	{
		public:
		// typedef T         value_type;
		// typedef Distance  difference_type;
  		typedef T* pointer;
		typedef T& reference;
		// typedef Category  iterator_category;
		typedef typename std::allocator<T> ::pointer		pointer2;
		
		
		public:
		random_access_iterator_tag():elem(0)
		{};

		private:
		pointer elem;

		public:

		random_access_iterator_tag &operator=(const random_access_iterator_tag &cp)
		{
			elem = cp;
		}
		
		reference operator*(void) const
		{

			return (*elem);
		}

		random_access_iterator_tag (pointer2 const &vecPoint)
		{
			elem = vecPoint;
		}

		// Point& operator++();       // Prefix increment operator.
		// Point operator++(int);     // Postfix increment operator.

		random_access_iterator_tag &operator++()
		{
			elem++;
			return (*this);
		}
		random_access_iterator_tag operator++(int)
		{
			random_access_iterator_tag temp = *this;
			++*this;
			return temp;
		}

		// bool operator!=(pointer2 const &vecPoint)
		// {
		// 	return (*elem != *vecPoint);
		// }

		// bool operator!=(pointer const &cp)
		// {
		// 	return (*elem != *(cp.elem));
		// }

	
		bool operator !=(random_access_iterator_tag const &cp)
		{
			// std::cout<<"i ma here\n";
			return (elem != cp.elem);
		}

/*		random_access_iterator_tag &operator==(const random_access_iterator_tag &cp)
		{
			return (*elem == *elem);
		}
		random_access_iterator_tag operator!=(const random_access_iterator_tag &cp)
		{
			return (*elem != *elem);
		}
		random_access_iterator_tag &operator>=(const random_access_iterator_tag &cp)
		{
			return (*elem >= *elem);
		}
		random_access_iterator_tag &operator<=(const random_access_iterator_tag &cp)
		{
			return (*elem <= *elem);
		}
		random_access_iterator_tag &operator>(const random_access_iterator_tag &cp)
		{
			return (*elem > *elem);
		}
		random_access_iterator_tag &operator<(const random_access_iterator_tag &cp)
		{
			return (*elem < *elem);
		}

*/

	};

	
	// size_t distance(){
	// 	return 
	// }
	
}

#endif
