#include "Point.hpp"

static float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
   return std::abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

static bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{   
   /* Calculate area of triangle ABC */
   float A = area (x1, y1, x2, y2, x3, y3);
  
   /* Calculate area of triangle PBC */ 
   float A1 = area (x, y, x2, y2, x3, y3);
  
   /* Calculate area of triangle PAC */ 
   float A2 = area (x1, y1, x, y, x3, y3);
  
   /* Calculate area of triangle PAB */  
   float A3 = area (x1, y1, x2, y2, x, y);
    
   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    return (isInside(a.getX().getRawBits(), a.getY().getRawBits(), b.getX().getRawBits(), 
        b.getY().getRawBits(), c.getX().getRawBits(), c.getY().getRawBits(), 
            point.getX().getRawBits(), point.getY().getRawBits()));
}