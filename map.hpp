// Some of the commonly used functions offered by Maps:
// map.insert(): This function inserts the element with a particular/specific key to the existing map.
// map.begin(): It returns an iterator element that points to the first element of the map.
// map.end(): It returns an iterator element that points to the last element of the map.
// map.size(): It returns the number of key-value pairs in the map.
// map.empty(): It checks whether the map is empty or not.

// #include <iostream> 
// #include <iterator> 
// #include <map> 
 
// using namespace std; 
 
// int main() 
// { 
 
 
//     map<int, int> M; 
 
     
//     M.insert(pair<int, int>(1, 100)); 
//     M.insert(pair<int, int>(2, 70)); 
//     M.insert(pair<int, int>(3, 90)); 
//     M.insert(pair<int, int>(4, 20)); 
 
 
 
//     map<int, int>::iterator itr; 
//     cout << "\nInput Map:\n"; 
//     cout << "key:value\n"; 
//     for (itr = M.begin(); itr != M.end(); ++itr) { 
//         cout << itr->first 
//             << ':' << itr->second << '\n'; 
//     } 
//     cout << endl; 
 
 
 
//     cout << "\nMap after removal of elements: \n"; 
//         cout << "key:value\n"; 
//     M.erase(M.begin(), M.find(3)); 
//     for (itr = M.begin(); itr != M.end(); ++itr) { 
//         cout << itr->first 
//             << ':' << itr->second << '\n'; 
//     } 
 
     
//     return 0; 
// } 