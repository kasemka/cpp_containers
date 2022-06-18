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
		node():color(BLACK), parent(this), left(this), right(this){}; //for nil
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
				
				while (x != _nil){
					y = x;
					if (x->key.first == val.first)
						return (ft::make_pair(x, false));
					if (_compare(val.first, x->key.first))
						x = x->left;
					else
						x = x->right;}
				node<value_type>* newNode = _alloc.allocate(1);
				_alloc.construct(newNode, ft::node<value_type>(val));
				newNode->parent = y;
				if (y == _nil){
					_root = newNode;
					_nil->left = _root;} // !!!! _nil->right = _root;
				else if (_compare(val.first, y->key.first))
					y->left = newNode;
				else
					y->right = newNode;
				newNode->left = newNode->right = _nil;
				// newNode->color = RED;
				insertFixup(newNode);
				return (ft::make_pair(newNode, true));

			}
			
			void insertFixup(node<value_type> *z)
			{
				node<value_type>* y;
				while (z->parent->color == RED){ // parent is red 
					if (z->parent == z->parent->parent->left){ // z parent is left child
						y = z->parent->parent->right;
						if (y->color == RED){ // y is red case
							z->parent->color = BLACK;
							y->color = BLACK;
							z->parent->parent->color = RED;
							z = z->parent->parent;}
						else if (z == z->parent->right){ //y is black case, triangle relationship
							z = z->parent;
							leftRotate(z);}
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						rightRotate(z->parent->parent);}
					else {
						y = z->parent->parent->left;
						if (y->color == RED){ // y is red case
							z->parent->color = BLACK;
							y->color = BLACK;
							z->parent->parent->color = RED;
							z = z->parent->parent;}
						else if (z == z->parent->left){ //y is black case, triangle relationship
							z = z->parent;
							rightRotate(z);}
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						leftRotate(z->parent->parent);}}
				_root->color = BLACK; // case 0
			}

			void rightRotate(node<value_type> *x)
			{
				node<value_type>* y = x->left;
				x->left = y->right;
				if (y->right != _nil)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == _nil)
					_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else x->parent->left = y;
				y->right = x;
				x->parent = y;
				
			}

			void leftRotate(node<value_type> *x)
			{	
				node<value_type>* y = x->right;
				x->right = y->left;
				if (y->left != _nil)
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == _nil)
					_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else x->parent->right = y;
				y->left = x;
				x->parent = y;
			}



			void printTree()
			{
				// int i = 0;
				// while (i< _size)
				// {
					
					std::cout <<"root : "<< _root->color << "  "<< _root->key.first <<std::endl;
					std::cout <<"_root->left: "<< _root->left->color<< "  "<< _root->left->key.first << std::endl;
					std::cout <<"_root->right: "<< _root->right->color<< "  "<< _root->right->key.first << std::endl;
					std::cout <<"_root->left->left: "<< _root->left->left->color<< "  "<< _root->left->left->key.first << std::endl;
					std::cout <<"_root->left->right: "<< _root->left->right->color<<"  "<< _root->left->right->key.first << std::endl;

				// }
				
			}

			
	
	};
	 

}

#endif