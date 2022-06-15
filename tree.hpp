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
			_Allocator _alloc;


			node *_begin_node;
			node *_end_node;

			tree():_alloc(){
				_alloc.construct();
			};
			~tree(){};
	
	};
	 

}

#endif