#ifndef TREE_HPP
#define TREE_HPP

#include <memory>



// nil (Latin "nihil") means "nothing" or the absence of something
// black and red tree
namespace ft
{
	template<class T>
	struct node
	{
		int color;
		int NIL; // 
		struct node *parent;
		struct node *left;
		struct node *right;
		T* key;

	};
		



	template <class _Tp, class _Compare, class _Allocator>
	class tree
	{
		public:
			typedef _Tp 				value_type;
			typedef _Compare 			value_compare;
			typedef _Allocator 			allocator_type;

		private:
			_Allocator								_alloc;
			_Compare								_compare;
			// typename allocator_type::pointer		_begin_node;
			// typename allocator_type::pointer		_end_node;
			node<value_type>* _begin_node;
			node<value_type>* _end_node;

		public:
			tree(){
				_begin_node = _alloc.allocate(0);
			};
			
			// ~tree(){};
	
	};
	 

}

#endif