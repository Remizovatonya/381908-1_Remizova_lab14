#include <iostream>
#include "TSortMap.h"
using namespace std;
int main()
{
    TSortMap<string, int> a;
    a.Add("hello", 444);
    a.Add("world", 555);
    a.Add("rainy", 34);
    a.Add("day", 71);
    std::cout << a << std::endl;
    return 0;
}