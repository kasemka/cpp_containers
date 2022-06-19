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
		node():color(BLACK), isNill(1),parent(this), left(this), right(this){}; //for nil
		node(T pair):color(RED), isNill(0), parent(this), left(0), right(0), key(pair){};
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

			node<value_type>* begin(void){
				node<value_type>* tmp = _root;
				while (tmp != _nil)
					tmp = tmp->left;
				return (tmp->parent);
			}

			node<value_type>* end(void){
				node<value_type>* tmp = _root;
				while (tmp != _nil)
					tmp = tmp->right;
				return (tmp->parent);
			}
			
			
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
					_root->parent = _nil; //different from algor
					_nil->left = _root;} // !!!! _nil->right = _root;
				else if (_compare(val.first, y->key.first))
					y->left = newNode;
				else
					y->right = newNode;
				newNode->left = newNode->right = _nil;
				newNode->color = RED;
				insertFixup(newNode);
				++_size;
				std::cout<<newNode->key.first <<" was added:\n";
				printBT();
				std::cout<<std::endl;
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
						else {
							if (z == z->parent->right){ //y is black case, triangle relationship
								z = z->parent;
								leftRotate(z);}
							z->parent->color = BLACK;
							z->parent->parent->color = RED;
							rightRotate(z->parent->parent);}
					}
					else {
						y = z->parent->parent->left;
						if (y->color == RED){ // y (uncle) is red case
							z->parent->color = BLACK;
							y->color = BLACK;
							z->parent->parent->color = RED;
							z = z->parent->parent;}
						else {
							if (z == z->parent->left){ //y is black case, triangle relationship
								z = z->parent;
								rightRotate(z);}
							z->parent->color = BLACK;
							z->parent->parent->color = RED;
							leftRotate(z->parent->parent);}
					}
				}
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



			void printBT(const std::string& prefix, const node<value_type>* nodeV, bool isLeft)
			{
					std::cout << prefix;

					std::cout << (isLeft ? "├──" : "└──" );
					
					if (nodeV == _nil){
						std::cout <<"\033[0;36m"<< "nil" << "\033[0m"<<std::endl;
						return ;
					}
					// print the value of the node
					if (nodeV->color == 0)
						std::cout <<"\033[0;36m"<< nodeV->key.first<<"\033[0m"<<std::endl;
					else
						std::cout <<"\033[0;31m"<< nodeV->key.first << "\033[0m"<<std::endl;
					printBT( prefix + (isLeft ? "│   " : "    "), nodeV->left, true);
					printBT( prefix + (isLeft ? "│   " : "    "), nodeV->right, false);
	
				
			}
			void printBT(){
				printBT("", _root, false);
			}
	
	};
	 

}

#endif