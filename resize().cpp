#include <iostream>
#include "vector.hpp"
#include <vector>
#include <string>

/*
template <typename T>
std::vector<int> resize_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    g_start1 = timer();
    vector.resize(5000 * _ratio);
    vector.reserve(5000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(15300 * _ratio, T());
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    v.push_back(vector[65]);
    g_end1 = timer();
    return v;
}

template <typename T>
std::vector<int> resize_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    g_start2 = timer();
    vector.resize(5000 * _ratio);
    vector.reserve(5000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(15300 * _ratio, T());
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    v.push_back(vector[65]);
    g_end2 = timer();
    return v;
}
*/


int main() {
    std::vector<int> v;
    v.assign(9900, 1);
   
    v.resize(5000);
    v.reserve(5000);
     v.push_back(v.size());
    v.push_back(v.capacity());
    v.resize(7000);
    v.push_back(v.size());
    std::cout << v.size()<<"  " <<v.capacity()<<std::endl;
    v.push_back(v.capacity());
    std::cout << v.size()<<"  " <<v.capacity()<<std::endl;
    v.resize(15300);
    std::cout << v.size()<<"  " <<v.capacity()<<std::endl;
    v.push_back(v.size());
     std::cout << v.size()<<"  " <<v.capacity()<<std::endl;
    v.push_back(v.capacity());
     std::cout << v.size()<<"  " <<v.capacity()<<std::endl;
    v.push_back(v[65]);
    std::cout << v.size()<<"  " <<v.capacity()<<std::endl;
    return 0;
   
}