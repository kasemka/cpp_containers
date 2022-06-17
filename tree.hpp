#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include "utils.hpp"

#define BLACK 0
#define RED 1


// nil (Latin "nihil") means "nothing" or the absence of something
// black and red tree, black=0, red=1
// isNull is leaf, all leaves are nills (NULL)
namespace ft
{
	template<class T>
	struct node
	{
		int color;
		int isNill; // 
		struct node* parent;
		struct node* left;
		struct node* right;
		T key;
		node():color(BLACK), parent(this), left(this), right(this){};
		node(T pair):color(RED), isNill(1), parent(this), left(0), right(0), key(pair){};
		node(const node &other): 
		color(other.color), isNill(other.isNill), parent(other.parent), left(other.left), right(other.right), key(other.key) {};

	};



	template <class _Tp, class _Compare, class _Allocator>
	class tree
	{
		public:
			typedef _Tp 				value_type;
			typedef _Compare 			value_compare;
			typedef _Allocator 			allocator_type;

			

		private:
			_Allocator					_alloc;
			_Compare					_compare;
			
			node<value_type>* 			_nil;
			node<value_type>* 			_root;
			size_t						_size; //include nil

		public:
			tree():_size(0){
				_nil = _alloc.allocate(1);
				_alloc.construct(_nil, node<value_type>());
				_root = _nil;
			};
			
			~tree(){};

			node<value_type>* begin(){return _nil;};

			ft::pair<node<value_type>*, bool> insertNode(const value_type& val)
			{
				node<value_type>* x = _root;
				node<value_type>* y = _nil;
				
				while (x != _nil)
				{
					y = x;
					if (x->key.first == val.first)
						return (ft::make_pair(x, false));
					if (_compare(val.first, x->key.first))
						x = x->left;
					else
						x = x->right;
				}
				node<value_type>* newNode = _alloc.allocate(1);
				_alloc.construct(newNode, ft::node<value_type>(val));
				newNode->parent = y;
				if (y == _nil)
				{
					_root = newNode;
					_nil->left = _root; // !!!! _nil->right = _root;
				}
				else if (_compare(val.first, y->key.first))
					y->left = newNode;
				else
					y->right = newNode;
				newNode->left = newNode->right = _nil;
				// newNode->color = RED;
				insertFix(newNode);
				return (ft::make_pair(newNode, false));

			}
			
			void insertFix(node<value_type> newNode)
			{
				while (newNode->color == RED) // 1 is red
				{
					if (newNode->parent == newNode->parent->parent)
				}
				

			}

			void printTree()
			{
				// int i = 0;
				// while (i< _size)
				// {
					
					std::cout <<"root : "<< _root->color << std::endl;
					std::cout <<"nil : "<< _root->left->color << std::endl;

				// }
				
			}

			
	
	};
	 

}

#endif