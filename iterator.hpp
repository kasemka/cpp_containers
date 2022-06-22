#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <memory>
#include "tree.hpp"
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
			T base() const  { return _elem; }



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



	template< class T, class U, class Compare>
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
			T _iter;
			Compare _comp;

		public:
			mapIterator(T val = nullptr) : _iter(val){};
			
			~mapIterator(){};

			T base(){ return _iter; }			

			reference operator*() const {return _iter->key;}
			pointer operator->() const {return &(_iter->key);}

			iterator_type min(iterator_type x)
			{
				while (x->left->isNil != true)
					x = x->left;
				return (x);
			}

			iterator_type max(iterator_type x)
			{
				while (x->right->isNil != true)
					x = x->right;
				return (x);
			}

			iterator_type next(){
				iterator_type y;
				
				if (_iter->right->isNil == false)
					return(min(_iter->right));
				y = _iter->parent;
				while (y->isNil == false && _iter == y->right){ // for cas if y is right kid of it's parent
					_iter = y;
					y = y->parent;
				}
				return (y);
			}

			iterator_type prev(){
				iterator_type y;

				if (_iter->isNil == true || _iter->left->isNil == false)
					return(max(_iter->left));
				y = _iter->parent;
				while (y->isNil == false && _iter == y->left){ // for cas if y is left kid of it's parent
					_iter = y;
					y = y->parent;
				}
				return (y);
			}

			mapIterator& operator++() {
				_iter = next();
				return (*this);
			}

			mapIterator operator++(int){ 
				mapIterator tem(*this);
				++(*this);
				return tem;
			}	
			mapIterator& operator--() {
				_iter = prev();
				return *this; 
				
			};

			mapIterator operator--(int){
				mapIterator tem(*this);
				--(*this);
				return tem;
			}

			friend
			bool operator==(const mapIterator& x, const mapIterator& y)
			{return x._iter == y._iter;};

			friend
			bool operator!=(const mapIterator& x, const mapIterator& y)
			{return x._iter != y._iter;};





	};

}

#endif
