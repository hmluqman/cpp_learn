#include <iostream>
#include <unordered_set>

struct Point2D
{
    int u;
    int v;
};

inline bool operator == (Point2D const& lhs, Point2D const& rhs)
{
    return (lhs.u == rhs.u) && (lhs.v == rhs.v); 
}

int main()
{
Point2D point;
point.u = -9;
point.v = 5;

int a = 8;
int b = 4;

int c = a | b;

int64_t merge;
merge = (int64_t) a<<32 | b;

std::unordered_set<int64_t> setOfNum;
setOfNum.insert(merge);
std::cout << "Value of Concatination "<<merge<<std::endl;
return 0;
}

