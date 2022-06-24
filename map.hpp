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
			typedef Compare																				key_compare;
			typedef Allocator																			allocator_type;
			typedef typename Allocator::reference														reference;
			typedef typename Allocator::const_reference													const_reference;
			typedef typename Allocator::pointer															pointer;
			typedef typename Allocator::const_pointer													const_pointer;
			typedef typename Allocator::size_type														size_type;
			typedef typename Allocator::difference_type													difference_type;

			typedef typename ft::mapIterator<node<value_type>*, value_type, Compare>					iterator;
			typedef typename ft::mapIterator<const node<value_type>*, const value_type, Compare>		const_iterator;
			// typedef ft::reverse_iterator<iterator>														reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>												const_reverse_iterator;


		private:
			typedef typename Allocator::template rebind< node<value_type> >::other		allocatorNode;
			Compare _comp; //создание структуры
			Allocator _alloc;			
			ft::tree<value_type, key_compare, allocatorNode> _tree;

		public:
			class value_compare : std::binary_function<value_type, value_type, bool>
			{ 
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {} 
				public:
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

			// construct:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
				_comp(comp), _alloc(alloc), _tree(ft::tree<value_type, key_compare, allocatorNode>()){};
		

			template <class InputIterator>
				map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): 
				_comp(comp), _alloc(alloc), _tree(ft::tree<value_type, key_compare, allocatorNode>())
			{ insert(first, last);};


			map(const map& x):_comp(x._comp), _alloc(x._alloc), _tree(ft::tree<value_type, key_compare, allocatorNode>()){
				insert(x.begin(), x.end());
			};

			map &operator=(const map& x) {
				if (this != & x){		
					if (size() > 0)
						_tree.clear();
					_alloc = x._alloc;
					_comp = x._comp;
					_tree = x._tree;
					// insert(x.begin(), x.end());

				}
				return *this;
			};

			~map(){
			};

	
			// // iterators:
			iterator begin() { return iterator(_tree.begin()); };

			const_iterator begin() const { return const_iterator(_tree.begin()); };			

			iterator end()  { return iterator(_tree.end()); };

			const_iterator end() const { return const_iterator(_tree.end()); };




			// Modifiers
			ft::pair<iterator,bool> insert(const value_type& v) { 
				return (_tree.insertNode(v)); 
			}


			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				while (first != last){
					_tree.insertNode(value_type(first->first, first->second));
					++first;
				}
			}





			// iterator insert (iterator position, const value_type& val);


			void erase (iterator position)
			{ 
			// 	std::cout<<"first "<<position->first<<std::endl;
			// 	std::cout<<"root "<<_tree.root()<<std::endl;
				_tree.rbTreeDelete(position.base()); 
				// std::cout<<"first after erase "<<position->first<<std::endl;
				// std::cout<<"root after erase "<<_tree.root()<<std::endl;
				}
			

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
					first = it;
				}
			}

			void swap (map& x){
				std::swap(_tree, x._tree);
			}

			void clear(){
				_tree.clear();
			}

			iterator find (const key_type& k) {
				return (iterator(_tree.treeSearch(k)));
			}

			size_type count (const key_type& k) const {
				if (find(k) != end())
					return 1;
				return 0;
			};

			// const_iterator find (const key_type& k) const {

			// }
			//remove it later
			void printTree()
			{
				_tree.printTree();
				
			}



			//capacity
			bool empty() const { return (_tree.size() ? false : true); };
			size_type size() const {return _tree.size();}
			size_type max_size() const { return (allocatorNode().max_size());};


			

		};

		
		// friend bool	operator==(const map& x, const map& y){

		// };

		// friend bool	operator<(const map& x, const map& y){
		// 	int size = x.size();
		// 	if (size > y.size())
		// 		size = y.size();
		// 	for (int i = 0; i < size; ++i)
		// 	{
		// 		if (x[i] != y[i])
		// 			return x[i] < y[i];
		// 	}
		// 	if (x.size() < y.size())
		// 		return true;
		// 	return (false); 
		// };

		// friend bool	operator!=(const map& x, const map& y){};

		// friend bool	operator>(const map& x, const map& y){};

		// friend bool	operator<=(const map& x, const map& y){};
		
		// friend bool	operator>=(const map& x, const map& y){};



}

#endif

// Some of the commonly used functions offered by Maps:
// map.insert(): This function inserts the element with a particular/specific key to the existing map.
// map.begin(): It returns an iterator element that points to the first element of the map.
// map.end(): It returns an iterator element that points to the last element of the map.
// map.size(): It returns the number of key-value pairs in the map.
// map.empty(): It checks whether the map is empty or not.