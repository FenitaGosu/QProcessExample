#include <iostream>
#include <string>

int main()
{
	std::cout << "Client started" << std::endl;

	std::string str;

	std::getline(std::cin, str);

	std::cout << "[Client] Message received: " << str << std::endl;

	return 0;
}
