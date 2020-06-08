#include<iostream>

bool isDuplicate(const int& element, int* newArr, const int& sizeNewArr)
{
    for(int i = 0; i < sizeNewArr; i++)
    {
        if(newArr[i] == element)
            return true;
    }
    return false;
}

void makeUnique(int* arr, const int& size, int* newArr, int& sizeNewArr)
{
    for(int i = 0; i < size; i++)
    {
        if(!isDuplicate(arr[i], newArr, sizeNewArr))
        {
            newArr[sizeNewArr++] = arr[i];    
        }
    }
}

void printArr(int* newArr, const int& sizeNewArr)
{
   //print new array
    for(int i = 0; i < sizeNewArr; i++)
    {
       std::cout << newArr[i] << std::endl;  
    }
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 4, 5, 6, 6};
    const int size = sizeof(arr)/sizeof(int);
    
    int newArr[size];
    int sizeNewArr = 0;
    
    makeUnique(arr, size, newArr, sizeNewArr);
    printArr(newArr, sizeNewArr);
    return 0;
}
