#include<iostream>

void strcpy1(char* dest , const char* source)
{
    /*
    while(*source != '\0')
    {
        *dest = *source;
        source++;
        dest++;
    }
    *dest = '\0';
    */
    
    while((*dest++ = *source++) != 0);
    // At some point *dest would be zero and while(0) exits the loop
    // while((*dest++ = *source++));
}

int main()
{
	char const* source = "abcd";
    char* dest = nullptr;
    dest = new char[5];
	strcpy1(dest, source);
	std::cout << source << std::endl;
	std::cout << dest << std::endl;
}
