#include<iostream>

typedef void (*fptr_t)(int*, int*, const int&);

void atLeastOnceOkay(int *arr, int* freq, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        if(freq[i] != 0)
            std::cout << arr[i] << std::endl;
    }
   

}

void notEvenOnce(int* arr, int* freq, const int& size)
{ 
    for (int i = 0; i < size; i++)
    {
        if(freq[i] == 1)
            std::cout << arr[i] << std::endl;
    }
}

void onlyUnique(int* arr, int* freq, const int& size, fptr_t fptr)
{
    for (int i = 0; i < size; i++)
    {
        int count = 1;
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
               freq[j] = 0; 
               count++;
            }
        }
        
        if (freq[i] != 0)
            freq[i] = count;
    }
    
    fptr(arr, freq, size);

}

void getArray(int *arr, const int& size)
{
    // Get input array user
    std::cout << "Enter the FIVE array elements seperated by space : " << std::endl;
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];
}

void printArray(int *arr, const int& size)
{
    std::cout << "Printed elements are : " << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void setDefaultsForFreqArray(int* freq, const int& size)
{
    for (int i = 0; i < size; i++)
        freq[i] = -1;
}

int main()
{
    const int size = 5;
    int arr[size], freq[size];
    
    getArray(arr, size);
    setDefaultsForFreqArray(freq, size);
    
    onlyUnique(arr, freq, size, notEvenOnce);
    
    

    
    return 0;
}
