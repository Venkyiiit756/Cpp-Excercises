#include<iostream>
#include <algorithm> 

/*
1 1 2 2 3 4 -> 1 2 3 4
1 1 1 2 2 3 4 -> 1 2 3 4
1 2 3 4 -> 1 2 3 4
*/

void getUniqueElementsFromSortedArray(int* arr, int* newArr, const int& size, int& newSize)
{
    int i = 0;
    int newIdx = 0;
    while (i < size)
    {
        //Updating the new array
        newArr[newIdx++] = arr[i];
        
        int count = i + 1;
        // Iterate till we skip the duplicated elements
        while (arr[i] == arr[count])
        {
            count++; 
        }
        // Move the original index to end of the skipped elements
        i = count;
    }
    
    //Update the new Size
    newSize = newIdx;
}

void printArray(int* arr, const int& size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{

    int arr[] = {1, 1, 1, 2, 2, 3, 4, 5, 5, 6};
    const int size = sizeof(arr)/sizeof(int);
    
    int newSize = 0;
    int newArr[size] = {0};
    
    getUniqueElementsFromSortedArray(arr, newArr, size, newSize);
    printArray(arr, size);
    printArray(newArr, newSize);
    
    

    return 0;
}
