//======================================================
// Emma Steinmna
// January 30, 2017
// Arrays1.cpp
// This program illustrates basic c++ arrays with 
// various functions.
//======================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

int findMax(int [], int);
int findSum(int [], int);
void selectionSort (int [], int);

//======================================================
// main
//======================================================

int main(void)
{
    int n = 10;     // array size
    int nums[n];    // array declaration

    srand(time(NULL));
    for( int i = 0; i<n; i++)
        nums[i] = rand() % 100;

    for(int i = 0;i<n;i++)
        cout<<nums[i]<<" ";
    cout<<endl;

    cout << "Largest value is " << findMax(nums,n) << endl;
    cout << "Sum is " << findSum(nums, n) << endl;

    selectionSort(nums, n);
    for(int i = 0;i<n;i++)
        cout<<nums[i]<<" ";
    cout<<endl;

    return 0;
}

//======================================================
// findMax
// This function finds and returns the largest value
// in an array of integers.
// Parameters:
// - array of integers
// - size of array
// Return Value:
// - largest value in the array
//======================================================

int findMax(int array[], int size)
{
    int answer = array[0];
    for(int i = 1; i < size; i++)
        if (array[i] > answer)
            answer = array[i];

    return answer;
}

//======================================================
// findSum
// This function finds and returns the sum of values in
// an array of integers.
// Parameters:
// - array of integers
// - size of array
// Return Value:
// - sum of the array
//======================================================


int findSum(int array[], int size)
{
    int total = 0;    
    int sum = array[0];
    for(int i = 1; i < size; i++)
        total += array[i];

    return sum;
}

//======================================================
// selectionSort
// This function finds and returns the sum of values in
// an array of integers.
// Parameters:
// - array of integers
// - size of array
// Return Value:
// - sum of the array
//======================================================


void selectionSort(int array[], int size)
{
    int smallest = 0;
    for(int i = 0; i < size; i++)
        for(int m = 0; m < size; i++)
            if(array[m] < smallest)
                smallest = m;
        array[i] = array[smallest];

    return 0;         

}
