#include<iostream>

void strcpy1(char* dest , const char* source)
{
	int i = 0;
	while(source[i] != '\0')
	{
		dest[i] = source[i];
        i++;
	}
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
