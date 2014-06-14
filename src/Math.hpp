#ifndef MATH_HPP
#define MATH_HPP

constexpr int gcd(int x, int y) 
{
  return (x % y) == 0 ? y :  gcd(y, x % y);
}

constexpr int lcm(int x, int y) 
{
  return x == y ? x : (x * y) / gcd(x, y);
}

#endif
