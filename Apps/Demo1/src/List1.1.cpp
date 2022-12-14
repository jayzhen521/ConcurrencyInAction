#include <iostream>
#include <thread>

//#define List1_1
#ifdef List1_1

void hello()
{
	std::cout << "Hello World\n";
}

int main()
{
	std::thread t(hello);
	t.join();//wait for hello() finished
	std::cout << "Run after hello called" << std::endl;
}

#endif