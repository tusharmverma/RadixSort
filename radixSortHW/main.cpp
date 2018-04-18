#include <iostream>
#include "radixSort.h"
#include <chrono>
using namespace std;


int main()
{
    radixSort s;
    int base;
    cout <<"Enter the Base: ";
    cin>> base;
    s.getdata();
    s.radixsort(base);
    s.showdata();
    return 0;
}
