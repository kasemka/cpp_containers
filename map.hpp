#ifndef MAP_HPP
#define MAP_HPP


#include <iostream> 
#include <memory> 
#include "utils.hpp"
#include "iterator.hpp"
 
namespace ft 
{ 

	template <class _Tp>
	struct less 
	{
		bool operator()(const _Tp& __x, const _Tp& __y) const 
		{
			return __x < __y;
		} 
	};

	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{

		public:
			// types:
			typedef Key											key_type;
			typedef T 											mapped_type;
			// typedef pair<const key_type, mapped_type> 			value_type;
			// typedef Compare 									key_compare;
			// typedef Allocator 									allocator_type;
			// typedef typename allocator_type::reference 			reference;
			// typedef typename allocator_type::const_reference	const_reference;
			// typedef typename allocator_type::pointer 			pointer;
			// typedef typename allocator_type::const_pointer 		const_pointer;
			// typedef typename allocator_type::size_type 			size_type;
			// typedef typename allocator_type::difference_type	difference_type;

			// typedef implementation-defined 						iterator;
			// typedef implementation-defined 						const_iterator;
			// typedef std::reverse_iterator<iterator>				reverse_iterator;
			// typedef std::reverse_iterator<const_iterator> 		const_reverse_iterator;


			class value_compare : public binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					key_compare comp;
					value_compare(key_compare c);

				public:
					bool operator()(const value_type& x, const value_type& y) const;
			};

			// construct/copy/destroy:
			map()
				noexcept(
					is_nothrow_default_constructible<allocator_type>::value &&
					is_nothrow_default_constructible<key_compare>::value &&
					is_nothrow_copy_constructible<key_compare>::value);
			explicit map(const key_compare& comp);
			map(const key_compare& comp, const allocator_type& a);
			template <class InputIterator>
				map(InputIterator first, InputIterator last, const key_compare& comp = key_compare());
			
			// template <class InputIterator>
			// 	map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& a);
			map(const map& m);
			map(map&& m)
				noexcept(is_nothrow_move_constructible<allocator_type>::value &&
					is_nothrow_move_constructible<key_compare>::value);
			explicit map(const allocator_type& a);
			map(const map& m, const allocator_type& a);
			map(map&& m, const allocator_type& a);
			map(initializer_list<value_type> il, const key_compare& comp = key_compare());
			map(initializer_list<value_type> il, const key_compare& comp, const allocator_type& a);
			template <class InputIterator>
				map(InputIterator first, InputIterator last, const allocator_type& a)
					: map(first, last, Compare(), a) {}  // C++14
			map(initializer_list<value_type> il, const allocator_type& a)
				: map(il, Compare(), a) {}  // C++14
			~map();

			map& operator=(const map& m);
			map& operator=(map&& m)
				noexcept(
					allocator_type::propagate_on_container_move_assignment::value &&
					is_nothrow_move_assignable<allocator_type>::value &&
					is_nothrow_move_assignable<key_compare>::value);
			map& operator=(initializer_list<value_type> il);

			// iterators:
				iterator begin() noexcept;
			const_iterator begin() const noexcept;
				iterator end() noexcept;
			const_iterator end()   const noexcept;

				reverse_iterator rbegin() noexcept;
			const_reverse_iterator rbegin() const noexcept;
				reverse_iterator rend() noexcept;
			const_reverse_iterator rend()   const noexcept;

			const_iterator         cbegin()  const noexcept;
			const_iterator         cend()    const noexcept;
			const_reverse_iterator crbegin() const noexcept;
			const_reverse_iterator crend()   const noexcept;

			// capacity:
			bool      empty()    const noexcept;
			size_type size()     const noexcept;
			size_type max_size() const noexcept;

			// element access:
			mapped_type& operator[](const key_type& k);
			mapped_type& operator[](key_type&& k);

				mapped_type& at(const key_type& k);
			const mapped_type& at(const key_type& k) const;

			// modifiers:
			template <class... Args>
				pair<iterator, bool> emplace(Args&&... args);
			template <class... Args>
				iterator emplace_hint(const_iterator position, Args&&... args);
			pair<iterator, bool> insert(const value_type& v);

			template <class P>
			pair<iterator, bool> insert(P&& p);

			iterator insert(const_iterator position, const value_type& v);

			template <class P>
				iterator insert(const_iterator position, P&& p);
			template <class InputIterator>
				void insert(InputIterator first, InputIterator last);
			void insert(initializer_list<value_type> il);




			iterator  erase(const_iterator position);

			size_type erase(const key_type& k);
			iterator  erase(const_iterator first, const_iterator last);

			void clear() noexcept;



			// observers:
			allocator_type get_allocator() const noexcept;
			key_compare    key_comp()      const;
			value_compare  value_comp()    const;

			// map operations:
				iterator find(const key_type& k);
			const_iterator find(const key_type& k) const;


			size_type      count(const key_type& k) const;
				iterator lower_bound(const key_type& k);
			const_iterator lower_bound(const key_type& k) const;


				iterator upper_bound(const key_type& k);
			const_iterator upper_bound(const key_type& k) const;


			pair<iterator,iterator>             equal_range(const key_type& k);
			pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
				
		};

		template <class Key, class T, class Compare, class Allocator>
		bool
		operator==(const map<Key, T, Compare, Allocator>& x,
				const map<Key, T, Compare, Allocator>& y);

		template <class Key, class T, class Compare, class Allocator>
		bool
		operator< (const map<Key, T, Compare, Allocator>& x,
				const map<Key, T, Compare, Allocator>& y);

		template <class Key, class T, class Compare, class Allocator>
		bool
		operator!=(const map<Key, T, Compare, Allocator>& x,
				const map<Key, T, Compare, Allocator>& y);

		template <class Key, class T, class Compare, class Allocator>
		bool
		operator> (const map<Key, T, Compare, Allocator>& x,
				const map<Key, T, Compare, Allocator>& y);

		template <class Key, class T, class Compare, class Allocator>
		bool
		operator>=(const map<Key, T, Compare, Allocator>& x,
				const map<Key, T, Compare, Allocator>& y);

		template <class Key, class T, class Compare, class Allocator>
		bool
		operator<=(const map<Key, T, Compare, Allocator>& x,
				const map<Key, T, Compare, Allocator>& y);

		// specialized algorithms:
		template <class Key, class T, class Compare, class Allocator>
		void swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y)
			noexcept(noexcept(x.swap(y)));

}

#endif

// Some of the commonly used functions offered by Maps:
// map.insert(): This function inserts the element with a particular/specific key to the existing map.
// map.begin(): It returns an iterator element that points to the first element of the map.
// map.end(): It returns an iterator element that points to the last element of the map.
// map.size(): It returns the number of key-value pairs in the map.
// map.empty(): It checks whether the map is empty or not.