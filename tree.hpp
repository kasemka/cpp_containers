#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include "utils.hpp"
#include "iterator.hpp"

#define BLACK 0
#define RED 1


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

		T keyValue; // allocates with notes
		node():color(BLACK), isNil(1),parent(0), left(0), right(0){}; //for nil
		node(T pair):color(RED), isNil(0), parent(0), left(0), right(0), keyValue(pair){};
		node(const node &other): 
		color(other.color), isNil(other.isNil), parent(other.parent), left(other.left), right(other.right), keyValue(other.keyValue) {};

		~node(){};
	};



	template <class Pair, class Allocator, class Compare >
	class tree
	{
	public:
		typedef Pair																		value_type;
		typedef Compare 																	key_compare;
		typedef Allocator 																	allocator_type;
		typedef typename value_type::first_type												key_type;
		typedef typename value_type::second_type											mapped_type;
		typedef typename ft::mapIterator<node<value_type>*, value_type>						iterator;
		// typedef Allocator::
		

	private:
		key_compare					_compare;	
		node<value_type>* 			_nil;
		node<value_type>* 			_root;
		size_t						_size; //excludes nil

	public:
		Allocator					_alloc;

	public:
		tree(const key_compare &comp):_size(0), _compare(comp){
			_nil = _alloc.allocate(1);
			_alloc.construct(_nil, node<value_type>());
			_nil->left = _nil->right = _nil->parent = _nil;
			_root = _nil;
		};		
		tree(const tree& copy){	*this = copy;};
		tree &operator=(const tree& copy){
			if (this != &copy){
				clear();
				
				iterator first = copy.begin();
				iterator last = copy.end();
				while(first!= last){
					insertNode(*first);
					first++;}				 
			}
			return *this;

		}

		~tree(){ clearAll(); };

		// key_type root() { return _root->keyValue.first;}

		void destroy(node<value_type>* nd)
		{
			if (nd != _nil)
			{
				destroy(nd->left);
				destroy(nd->right);
				_alloc.destroy(nd);
				_alloc.deallocate(nd, sizeof(node<value_type>));
			}
		}

		void clear(void) {
			destroy(_root);
			_size = 0;
			_nil->left = _nil->right = _nil->parent = _nil;
			_root = _nil;

		}

		void clearAll(void)
		{
			clear();
			_alloc.destroy(_nil);
			_alloc.deallocate(_nil, sizeof(ft::node<value_type>));

		}

		node<value_type>* begin(void) const {
			node<value_type>* tmp = min(_root);
			return (tmp);
		}

		node<value_type>* end(void) const {
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
				if (x->keyValue.first == val.first)
					return (ft::make_pair(x, false));
				if  (_compare(val, x->keyValue))
					x = x->left;
				else
					x = x->right;}
			node<value_type>* newNode = _alloc.allocate(1);
			_alloc.construct(newNode, ft::node<value_type>(val));
			
			newNode->parent = y;
			if (y == _nil){
				_root = newNode;
				_root->parent = _nil; //different from algor
				_nil->left = _root;} 
			else if  (_compare(val, y->keyValue))
				y->left = newNode;
			else
				y->right = newNode;
			newNode->left = newNode->right = _nil;
			newNode->color = RED;
			insertFixup(newNode);
			++_size;
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
				_nil->left = _root;} 			
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
				_nil->left = _root;} 
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
				_nil->left = _root;} 
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
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

			if (z == _nil){
				std::cerr << "Tree end() cannot be erased" << std::endl;
				throw ; }
			if (z->left == _nil){
				x = z->right; 
				transplant(z, z->right); }
			else if (z->right == _nil) {
				x = z->left; 
				transplant(z, z->left);}
			else {
				y = min(z->right);
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
			--_size;
			if (_size == 0)
				_root = _nil;
			
		}

		node<value_type>* treeSearch(const key_type& k) const
		{
			node<value_type>* x = _root;
			ft::pair<key_type, mapped_type> kPair = ft::make_pair(k, 0);

			while (x != _nil && k != x->keyValue.first) {	
				if (_compare(kPair, x->keyValue) == true )
					x = x->left;			
				else 
					x = x->right; }
			return (x);

		}

		size_t size(void) const { return _size; }

		node<value_type>* lower_bound (const key_type & k) const
		{
			node<value_type>* rootp = _root;
			node<value_type>* result = _nil;
			ft::pair<key_type, mapped_type> kPair = ft::make_pair(k, 0);
			
			while (rootp != _nil)
			{
			    if (!_compare(rootp->keyValue, kPair)) {
			        result = rootp;
			        rootp = rootp->left; }
			    else
			        rootp = rootp->right;
			}
		    return (result);
		}

		node<value_type>* upper_bound (const key_type & k) const
		{
			node<value_type>* rootp = _root;
			node<value_type>* result = _nil;
			ft::pair<key_type, mapped_type> kPair = ft::make_pair(k, 0);
			
			while (rootp != _nil)
			{
			    if (_compare(kPair, rootp->keyValue)) {
			        result = rootp;
			        rootp = rootp->left; }
			    else
			        rootp = rootp->right;
			}
		    return (result);
		}

		ft::pair<iterator, iterator> equal_range_unique(const key_type& k) 
		{
			typedef ft::pair<iterator, iterator> _Pp;

			ft::pair<key_type, mapped_type> kPair = ft::make_pair(k, 0);
			node<value_type>* result = _nil;
			node<value_type>* rootp = _root;

			while (rootp != _nil)
			{
				if (_compare(kPair, rootp->keyValue)){
					result =rootp;
					rootp = rootp->left;}
				else if (_compare(rootp->keyValue, kPair))
					rootp = rootp->right;
				else
					return _Pp(iterator(rootp), iterator(rootp->right != _nil ? min(rootp->right) : result));
			}

			return _Pp(iterator(result), iterator(result));
		}

		void printBT(const std::string& prefix, const node<value_type>* nodeV, bool isLeft) const
		{
				std::cout << prefix;

				std::cout << (isLeft ? "├──" : "└──" );
				
				if (nodeV == _nil){
					std::cout <<"\033[0;36m"<< "nil" << "\033[0m"<<std::endl;
					return ;
				}
				// print the value of the node
				if (nodeV->color == 0)
					std::cout <<"\033[0;36m"<< nodeV->keyValue.first<<"\033[0m"<<std::endl;
				else
					std::cout <<"\033[0;31m"<< nodeV->keyValue.first << "\033[0m"<<std::endl;
				printBT( prefix + (isLeft ? "│   " : "    "), nodeV->left, true);
				printBT( prefix + (isLeft ? "│   " : "    "), nodeV->right, false);		
		}

		void printTree(){
			printBT("", _root, false);
		}


		node<value_type>* min(node<value_type>* x) const {
			while (x->left->isNil != true)
				x = x->left;
			return (x);
		}
		
		friend bool	operator==(const tree& x, const tree& y){
			if (x.size() != y.size())
				return false;
			return (ft::equal(iterator(x.begin()), iterator(x.end()), iterator(y.begin())));
		};
		
	};
	 
}

#endif