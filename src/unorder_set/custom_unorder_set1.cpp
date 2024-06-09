#include <iostream>
#include <unordered_set>

struct Point2D
{
    int u;
    int v;
};

struct Hash 
{
   size_t operator() (const Point2D &point2d) const 
{
     std::string temp = std::to_string(point2d.u) + 
                   std::to_string(point2d.v);
     return (temp.length());
   }
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

std::unordered_set<Point2D, Hash> setOfPoints;

setOfPoints.insert(point);

point.u = 5;
point.v = -9;
setOfPoints.insert(point);

point.u = -9;
point.v = 5;
setOfPoints.insert(point);
for(auto iter = setOfPoints.begin(); iter != setOfPoints.end(); iter++)
{
	std::cout<<"Point.u = "<<(*iter).u<<" Point.v "<<(*iter).v<<std::endl;
}

return 0;
}

