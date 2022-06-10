#include <iostream>
#include "vector.hpp"
#include <vector>
#include <string>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define SHALLOW "\033[0m"

#define _ratio 1

class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};


using namespace ft;

int main() {
    vector<int> v;
    vector<int> tmp;
    vector<int> v2;
    tmp.assign(2600 * _ratio, 1);
    v2.assign(4200 * _ratio, 1);
    // g_start2 = timer();
    // pause();
    vector<int>::iterator pos = v2.end() - 1000 * _ratio;
    vector<int>::iterator first = tmp.begin();
    vector<int>::iterator last = tmp.end();
    // std::cout<<"tmp.size() = " <<tmp.size()<<std::endl;
    // std::cout<<"tmp.size() = " <<tmp.size()<<std::endl;
    // pause();
    v2.insert(pos, first, tmp.end());
    // pause();
    // g_end2 = timer();
    v.push_back(v2[3]);
    v.push_back(v2.size());
    v.push_back(v2.capacity());
    // pause ();

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    vector<A> vv;
    vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));

    std::cout<<"*********************************************"<<std::endl;
     vv.begin(), v1.begin(), v1.end();
    // vv.insert(vv.begin(), v1.begin(), v1.end());
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        std::cout <<"catched\n";
         std::cout<<RED << "Size of ft vv: " << int (vv.size()) <<", capacity " <<(vv.capacity()) << '\n';
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }
    std::cout<<YELLOW << "Size of ft v: " << int (v.size()) <<", capacity " <<(v.capacity()) << '\n';
     std::cout<<YELLOW << "Size of ft v2: " << int (v2.size()) <<", capacity " <<(v2.capacity()) << '\n';
    std::cout<<YELLOW << "Size of ft v1: " << int (v1.size()) <<", capacity " <<(v1.capacity()) << '\n';
    std::cout<<YELLOW << "Size of ft vv: " << int (vv.size()) <<", capacity " <<(vv.capacity()) << '\n';
    std::cout<<YELLOW << "Size of ft tmp: " << int (tmp.size()) <<", capacity " <<(tmp.capacity()) << '\n';


}