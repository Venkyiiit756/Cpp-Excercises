// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>

void makeOnlyUniqueArray(int *arr, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
           if (arr[i] == arr[j]) ++count;
        }
        
        if (count <= 1)
        {
            std::cout << arr[i] << std::endl; 
        }
    }

}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 4, 5, 6, 6};
    const int size = sizeof(arr)/sizeof(int);
    
    
    makeOnlyUniqueArray(arr, size);
}
