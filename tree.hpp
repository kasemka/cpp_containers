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
		bool isNil; // 
		struct node* parent;
		struct node* left;
		struct node* right;

		T key;
		node():color(BLACK), isNil(1),parent(0), left(0), right(0){}; //for nil
		node(T pair):color(RED), isNil(0), parent(0), left(0), right(0), key(pair){};
		node(const node &other): 
		color(other.color), isNil(other.isNil), parent(other.parent), left(other.left), right(other.right), key(other.key) {};

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
				while (tmp->left != _nil)
					tmp = tmp->left;
				return (tmp);
			}

			node<value_type>* end(void){
				node<value_type>* tmp = _root;
				while (tmp != _nil)
					tmp = tmp->right;
				return (tmp);
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
				printTree();
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
				if (x->parent == _nil){
					_root = y;
					_nil->left = _root;} // ???????????????????????????????????????/////					
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
				if (x->parent == _nil){
					_root = y;
					_nil->left = _root;} // ???????????????????????????????????????/////
				else if (x == x->parent->left)
					x->parent->left = y;
				else x->parent->right = y;
				y->left = x;
				x->parent = y;
			}

			void transplant(node<value_type> *u, node<value_type> *v)
			{
				if (u->parent == _nil){
					_root = v;
					_nil->left = _root;} // ???????????????????????????????????????/////
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}

			node<value_type> *treeMin(node<value_type> *x)
			{
				while (x->left != _nil)
					x = x->left;
				return (x);
			}

			void deleteFixup(node<value_type> *x){
				node<value_type> *w;

				while (x != _root && x->color == BLACK){
					if (x == x->parent->left){
						w = x->parent->right;
						if (w->color == RED){
							w->color = BLACK;
							x->parent->color = RED;
							leftRotate(x->parent);
							w = x->parent->right; }
						if (w->left->color == BLACK && w->right->color == BLACK){
							w->color = RED;
							x = x->parent; }
						else {
							if (w->right->color == BLACK) {
								w->left->color = BLACK;
								w->color = RED;
								rightRotate(w);
								w = x->parent->right; }
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->right->color = BLACK;
							leftRotate(x->parent);
							x = _root;
						}		
					}
					else {
						w = x->parent->left;
						if (w->color == RED){
							w->color = BLACK;
							x->parent->color = RED;
							rightRotate(x->parent);
							w = x->parent->left; }
						if (w->right->color == BLACK && w->left->color == BLACK){
							w->color = RED;
							x = x->parent; }
						else {
							if (w->left->color == BLACK) {
								w->right->color = BLACK;
								w->color = RED;
								leftRotate(w);
								w = x->parent->left; }
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->left->color = BLACK;
							rightRotate(x->parent);
							x = _root;}
					}
				}
				x->color = BLACK;
			}
			
			void rbTreeDelete(node<value_type> *z)
			{
				node<value_type> 	*x;
				node<value_type> 	*y = z;
				int 				yOriginalColor = y->color;


				if (z->left == _nil){
					x = z->right; 
					transplant(z, z->right); }
				else if (z->right == _nil) {
					x = z->left; 
					transplant(z, z->left);}
				else {
					y = treeMin(z->right);
					yOriginalColor = y->color;
					x = y->right;
					if (y->parent == z)
						x->parent = y;
					else{
						transplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;}
					transplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color; }
				if (yOriginalColor == BLACK)
					deleteFixup(x);
				_alloc.destroy(z);
				_alloc.deallocate(z, sizeof(node<value_type>));

			}

			// tree &operator++(node<value_type> *_iter)
			// {
			// 	if (_iter->right->isNil){
			// 		if (_iter == _iter->parent->left)
			// 			_iter = _iter->parent;
			// 		else
			// 			_iter = _iter->parent->parent;
			// 	}
			// 	else {
			// 		_iter = _iter->right;
			// 		while (_iter->left->isNil == false)
			// 			_iter = _iter->left;

			// 		// std::cout << _iter->isNil <<"-is nil, key="<<_iter->key.first<<std::endl;
			// 		// std::cout << _iter->right->isNil <<"-is nil, key="<<_iter->right->key.first<<std::endl;
					
			// 	}
			// }

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

			
			void printTree(){
				printBT("", _root, false);
			}
			
	
	};
	 

}

#endif