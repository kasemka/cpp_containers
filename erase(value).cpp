#include <iostream>
#include "vector.hpp"
#include <vector>
#include <string>

/*
template <typename T>
std::vector<int> erase_test_1(std::vector<T> vector) {
    std::vector<int> v;
    for (int i = 0; i < 9900 * _ratio; ++i)
        vector.push_back(i);
    g_start1 = timer();
    v.push_back(*(vector.erase(vector.begin() + 8 * _ratio)));
    g_end1 = timer();
    v.push_back(*(vector.begin() + 82 * _ratio));
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> erase_test_1(_vector<T> vector) {
    std::vector<int> v;
    for (int i = 0; i < 9900 * _ratio; ++i)
        vector.push_back(i);
    g_start2 = timer();
    v.push_back(*(vector.erase(vector.begin() + 8 * _ratio)));
    g_end2 = timer();
    v.push_back(*(vector.begin() + 82 * _ratio));
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}
*/

int main() {
    std::vector<int> v;
    for (int i = 0; i < 9900; ++i)
        v.push_back(i);

    v.push_back(*(v.erase(v.begin() + 8)));
    // std::cout << *(v.erase(v.begin() + 8)) << std::endl;

    v.push_back(*(v.begin() + 82 ));
    v.push_back(v.size());
    v.push_back(v.capacity());
     std::cout << v.size()<<"  " <<v.capacity()<<std::endl;
     for (int i =v.size(); i>v.size()-20; --i)
         std::cout << v[i] <<std::endl;
    return 0;

}