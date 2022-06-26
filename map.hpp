#ifndef MAP_HPP
#define MAP_HPP


#include <iostream> 
#include <memory> 
#include <functional>
#include "utils.hpp"
#include "iterator.hpp"
#include "tree.hpp"
 
namespace ft 
{ 

	// template <class _Tp>
	// struct less 
	// {
	// 	bool operator()(const _Tp& _x, const _Tp& _y) const 
	// 	{
	// 		return _x < _y;
	// 	} 
	// };


	// template <class Type> struct rebind {
	// typedef allocator<Type> other;};

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{

	public:
		// types:
		typedef Key																					key_type;
		typedef T																					mapped_type;
		typedef ft::pair<const key_type, mapped_type>												value_type;
		typedef Compare																				key_compare; //это тип структуры
		typedef Allocator																			allocator_type;
		typedef typename Allocator::reference														reference;
		typedef typename Allocator::const_reference													const_reference;
		typedef typename Allocator::pointer															pointer;
		typedef typename Allocator::const_pointer													const_pointer;
		typedef typename Allocator::size_type														size_type;
		typedef typename Allocator::difference_type													difference_type;

		typedef typename ft::mapIterator<node<value_type>*, value_type>					iterator;
		typedef typename ft::mapIterator<const node<value_type>*, const value_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>														reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>												const_reverse_iterator;

	public:
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{ 
			friend class map;
		protected:
			Compare comp;				
			value_compare(Compare c) : comp(c) {} //конструктор 

		public:
			bool operator() (const value_type& x, const value_type& y) const
			{ return comp(x.first, y.first); }
		};

		// construct:
	private:
		typedef typename Allocator::template rebind< node<value_type> >::other		allocatorNode;
		Compare _comp; //создание структуры	
		ft::tree<value_type, allocatorNode, value_compare> _tree;

	public:

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
			_comp(comp), _tree(value_compare(comp)) {};
	

		template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): 
			_comp(comp), _tree(value_compare(comp))
		{ insert(first, last);};


		map(const map& x):_comp(x._comp), _tree(value_compare(x._comp)){
			_tree = x._tree;
			// insert(x.begin(), x.end());
		};

		map &operator=(const map& x) {
			if (this != & x){		
				if (size() > 0)
					_tree.clear();
				_comp = x._comp;
				_tree = x._tree;
				// insert(x.begin(), x.end());
			}
			return *this;
		};

		~map(){	};


		// Iterators
		iterator begin() { return iterator(_tree.begin()); };
		const_iterator begin() const { return const_iterator(_tree.begin()); };			
		iterator end()  { return iterator(_tree.end()); };
		const_iterator end() const { return const_iterator(_tree.end()); };

		reverse_iterator rbegin() { return reverse_iterator(iterator(_tree.end()));};
		const_reverse_iterator rbegin() const  { return const_reverse_iterator(const_iterator(_tree.end()));};
		reverse_iterator rend()  { return reverse_iterator(iterator(_tree.begin()));};
		const_reverse_iterator rend() const { return const_reverse_iterator(const_iterator(_tree.begin()));};


		// Capacity
		bool empty() const { return (_tree.size() ? false : true); };
		size_type size() const {return _tree.size();}
		size_type max_size() const { return (allocatorNode().max_size());};


		// Element access
		mapped_type& operator[] (const key_type& k)	{
			iterator tmp = this->find(k);

			if (tmp == this->end())
				insert(ft::make_pair(k, mapped_type()));
			tmp = this->find(k);
			return ((*tmp).second);
		}

		mapped_type& at (const key_type& k){
			iterator tmp = this->find(k);

			if (tmp == this->end())
				throw std::out_of_range("");
			return ((*tmp).second);
		}
		
		const mapped_type& at (const key_type& k) const {
			iterator tmp = this->find(k);

			if (tmp == this->end())
				throw std::out_of_range("");
			return ((*tmp).second);
		}

		// Modifiers
		ft::pair<iterator,bool> insert(const value_type& v) { return (_tree.insertNode(v)); }

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last){
			while (first != last){
				_tree.insertNode(value_type(first->first, first->second));
				++first;}
		}

		iterator insert (iterator position, const value_type& val){
			(void)position;		
			return (iterator(_tree.insertNode(val).first));
		}

		void erase (iterator position)	{ _tree.rbTreeDelete(position.base());}
		
		size_type erase (const key_type& k){
			node<value_type>* rmNode = _tree.treeSearch(k);
			if (rmNode != end()){
				_tree.rbTreeDelete(rmNode);
				return 1;}
			else
				return 0;
		}

		void erase (iterator first, iterator last)
		{
			iterator it = first;

			while (first != last){
				it = first.next();
				_tree.rbTreeDelete(first.base());
				first = it;}
		}

		void swap (map& x){	
			// ft::tree<value_type, key_compare, allocatorNode> _treeTmp(x._tree);
			
			std::swap(x, *this);
			// std::swap(x._tree, this->_tree);

		}

		void clear(){ _tree.clear();}





		// Lookup
		iterator find (const key_type& k) {	return (iterator(_tree.treeSearch(k)));	}

		const_iterator find (const key_type& k) const {	return const_iterator(iterator(_tree.treeSearch(k)));	}


		size_type count (const key_type& k) const {
			if (find(k) == end())
				return 0;
			return 1; };


		iterator lower_bound (const key_type& k) { 
			return (_tree.lower_bound(k)); };

		const_iterator lower_bound (const key_type& k) const {};

		allocator_type get_allocator() const { return allocator_type(_tree._alloc());};

		// Observers
		key_compare key_comp() const{ return (_comp); }; //возвращает компаратор типа, переданнного как шаблон в мапу

		value_compare value_comp() const { return value_compare(key_comp()); } 

		// Non-member functions:

		friend bool	operator == (const map& x, const map& y){	return (x._tree == y._tree); };

		friend bool	operator != (const map& x, const map& y){	return !(x == y); };

		friend bool	operator < (const map& x, const map& y){ 
			
			const_iterator itx = x.begin();
			const_iterator ity = y.begin();			

			const_iterator itx_end = x.end();
			const_iterator ity_end = y.end();

			while (itx != itx_end && ity != ity_end) {
				if (itx->first != ity->first)
					return (itx->first < ity->first);
				else if (itx->second != ity->second)
					return (itx->second < ity->second);
				++itx;
				++ity;
			}
			if (x.size() < y.size())
				return true;
			return false; 

		 };


		friend bool	operator > (const map& x, const map& y){ return (y < x); };

		friend bool	operator <= (const map& x, const map& y){ return !( y < x); };
		
		friend bool	operator >= (const map& x, const map& y){ return !(x < y); };

		//print tree
		void printTree(){ _tree.printTree(); }

	};

}

#endif

// Some of the commonly used functions offered by Maps:
// map.insert(): This function inserts the element with a particular/specific key to the existing map.
// map.begin(): It returns an iterator element that points to the first element of the map.
// map.end(): It returns an iterator element that points to the last element of the map.
// map.size(): It returns the number of key-value pairs in the map.
// map.empty(): It checks whether the map is empty or not.