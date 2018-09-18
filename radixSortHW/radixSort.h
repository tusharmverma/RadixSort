#ifndef radixSort_h
#define radixSort_h
#define MAX 10000
using namespace std;

class radixSort{
private:
    int arr[MAX];
public:
    int getMax();
    void countSort(int exp, int base);
    void radixsort(int base);
    void getdata();
    void showdata();
    int size;
};

#endif /* radixSort_h */

