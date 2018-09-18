#include <stdio.h>
#include <iostream>
#include "radixSort.h"
using namespace std;

/**
 * Method:
 *    Input data from user.
 *
 * @param   N/A
 *
 * @return  nothing
 */
void radixSort::getdata (){
    
    cout<<"How many elements you require: ";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
}

/**
 * Method:
 *    Write array data on screen.
 *
 * @param   N/A
 *
 * @return  nothing
 */
void radixSort::showdata (){
    cout<<"\n--Display--\n";
    for(int i=0;i<size;i++){
        cout << i+1 << ". " << "" << arr[i] << "   " << endl;
    }
}


/**
 * Method:
 *    Get maximum value from array.
 *
 * @param   N/A
 *
 * @return  nothing
 */
int radixSort::getMax (){
    int max = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

/**
 * Method:
 *    Count sort of arr[].
 *
 * @param   N/A
 *
 * @return  nothing
 */
void radixSort::countSort (int exp, int base){
    
    // Count[i] array will be counting the number of array values having that 'i' digit at their (exp)th place.
    int output[size], i, count[10] = {0};
    
    int x = base;
    
    // Count the number of times each digit occurred at (exp)th place in every input.
    for (i = 0; i < size; i++)
        count[(arr[i] / exp) % x]++;
    
    // Calculating their cumulative count.
    for (i = 1; i < 10; i++)
        count[i] += count[i-1];
    
    // Inserting values according to the digit '(arr[i] / exp) % 10' fetched into count[(arr[i] / exp) % 10].
    for (i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % x] - 1] = arr[i];
        count[(arr[i] / exp) % x]--;
    }
    
    // Assigning the result to the arr pointer of main().
    for (i = 0; i < size; i++)
        arr[i] = output[i];
}

/**
 * Method:
 *    Sort arr[] of size n using Radix Sort.
 *
 * @param   base - base for sorting
 *
 * @return  nothing
 */
void radixSort::radixsort(int base)
{
    int exp, m;
    m = getMax();
    int x = base;
    // Calling countSort() for digit at (exp)th place in every input.
    for (exp = 1; m/exp > 0; exp *= x)
        countSort(exp, x);
}
