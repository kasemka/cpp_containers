// iterator.begin(): It returns the reference to the first element of the container.
// iterator.end(): It returns the reference to the last element of the container.
// iterator.prev(iterator_name, index): It returns the position of the new iterator that would point to the element before the specified index value in the parameter.
// iterator.next(iterator_name, index): It returns the position of the new iterator that would point to the element after the specified index value in the parameter.
// iterator.advance(index): It increments the iterator’s position to the specified index value.

// #include<iostream> 
// #include<iterator> 
// #include<list> 
// using namespace std; 
// int main() 
// { 
//     list<int> lst = {10, 50, 70, 45, 36}; 
     
//     list<int>::iterator itr; 
     
//     cout << "\nInput List:\n"; 
//     for (itr = lst.begin(); itr != lst.end(); itr++) 
//         cout << *itr << " "; 
         
//     list<int>::iterator it = lst.begin(); 
//     advance(it,1); 
       
//     cout << "\nThe position of iterator after advance():\n"; 
//     cout << *it << " "; 
         
     
//     return 0;    
// } 