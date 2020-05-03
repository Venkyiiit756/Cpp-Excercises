#include<stdlib.h>
#include<iostream>
#include<stdio.h>

//Prototypes
uint8_t reverseBits(uint8_t byte);
void setBit(uint8_t &byte, const uint8_t& pos);
void clearBit(uint8_t &byte, const uint8_t& pos);

void setBit(uint8_t &byte, const uint8_t& pos)
{
    byte |= (1 << pos);
}

void clearBit(uint8_t &byte, const uint8_t& pos)
{
   byte &= ~(1 << pos);
}

uint8_t reverseBits(uint8_t byte)
{
    // Take store the ith bit in temp
    // Now modify the ith bit based on MSB -ith bit
    // if MSB-ith bit is 0, then clear the ith bit
    // if MSB-ith bit is 1, then set the ith bit
    // if temp = 0, then clear the MSB-ith bit
    // if temp = 1, then set the MSB-ith bit
    // Base condition: ith > MSB-ith bit, stop there.
    // ith bit = 0 -> length -1 and length - i to 0 
    // start = ith bit and end = length -1; 
    
    uint8_t length = 8;
    uint8_t start = 0;
    uint8_t end = length - 1;
    
    while(start <= end) 
    {
        // save the start of the byte in temp
        uint8_t temp = byte & (1 << start);
      
        // set or clear stuff at start based on the end value
        if( byte & (1 << end))
        {
           setBit(byte, start);
        }
        else
        {
            clearBit(byte, start);    
        }
        
        if(temp)
        {
            setBit(byte, end);    
        }
        else
        {
            clearBit(byte, end);
        }

        start++;
        end--;
    }
    
    return byte;
}


int main()
{
    uint8_t byte = 0;
    std::cout << (int)reverseBits(byte) << std::endl;
    return 0;
}
