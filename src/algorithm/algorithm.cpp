#include <iostream>
#include<vector>
#include<algorithm>

#define COPY_IF 0
#define REMOVE_IF 0
#define FOREACH 1
bool predicate(int n) 
{
    std::cout<<n<<"value of n: \n";
   return (n %2 != 0);
}

bool IsOdd(int i) 
{ 
    return ((i % 2) == 1); 
} 

void myfunction (int i) {  // function:
  std::cout << ' ' << i;
}

struct myclass {           // function object type:
  void operator() (int i) {std::cout << ' ' << i;}
} myobject;
  
int main()
{
#if (COPY_IF)
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2(3);

    std::copy_if(v1.begin(), v1.end(), v2.begin(), predicate);

    std::cout << "Following are the Odd numbers from vector \n";

    for (auto it = v2.begin(); it != v2.end(); ++it)
        std::cout << *it << std::endl;


    //** http://www.cplusplus.com/reference/algorithm/copy_if/ **//

    std::vector<int> foo = {25,15,5,-5,-15};
    std::vector<int> bar (foo.size());

    // copy only positive numbers:
    auto it = std::copy_if (foo.begin(), foo.end(), bar.begin(), [](int i){return !(i<0);} );
    bar.resize(std::distance(bar.begin(),it));  // shrink container to new size

    std::cout << "bar contains:";
    for (int x: bar) std::cout << ' ' << x;
    std::cout << '\n';

#elif REMOVE_IF
    //** remove_if  https://www.geeksforgeeks.org/stdremove-stdremove_if-c/ **//

    std::vector<int> vec1{ 10, 20, 30, 30, 20, 10, 10, 20}; 
    std::vector<int> vec2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
      
    // Print original vector 
    std :: cout << "Original vector : "; 
    for(int i=0; i < vec1.size(); i++) 
        std :: cout << " " << vec1[i]; 
    std :: cout << "\n"; 
  
    // Iterator that store the position of last element 
    std::vector <int>::iterator pend; 
      
    // std ::remove function call 
    pend = std::remove (vec1.begin(), vec1.end() , 20); 
    
    // Print the vector 
    std::cout << "After remove : "; 
    for (std::vector<int>::iterator p=vec1.begin(); p != pend; ++p) 
        std::cout << ' ' << *p; 
    std::cout << '\n'; 
    vec1.resize(std::distance(vec1.begin(),pend));
    std::cout << "After remove size of vector : "<< vec1.size()<<"\n"; 
    std :: cout << "Original Changed vector : "; 
    for(int i=0; i < vec1.size(); i++) 
        std :: cout << " " << vec1[i]; 
    std :: cout << "\n"; 


    // Print original vector 
    std::cout << "\nOriginal vector : "; 
    for(int i=0; i < vec2.size(); i++) 
        std::cout << " " << vec2[i]; 
    std::cout << "\n"; 
  
    // std ::remove_if function call 
    pend = std::remove_if(vec2.begin(), vec2.end() , IsOdd); 
      
    // Print the vector 
    std :: cout << "After remove_if : "; 
    for ( std :: vector<int> :: iterator q=vec2.begin(); q != pend; ++q) 
        std :: cout << ' ' << *q; 
    std :: cout << '\n'; 
    
    std::cout << "After remove size of vector : "<< vec2.size()<<"\n"; 

    vec2.resize(std::distance(vec2.begin(),pend));
   std :: cout << "Original Changed vector : "; 
    for(int i=0; i < vec2.size(); i++) 
        std :: cout << " " << vec2[i]; 
    std :: cout << "\n"; 
#else
    std::vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);

    std::cout << "myvector contains:";
    for_each (myvector.begin(), myvector.end(), myfunction);
    std::cout << '\n';

    // or:
    std::cout << "myvector contains:";
    for_each (myvector.begin(), myvector.end(), myobject);
    std::cout << '\n';
#endif
    return 0;
}