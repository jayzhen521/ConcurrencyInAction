#include <iostream>
#include <thread>

#ifdef List2_4_1_part1
void f(int i, std::string const& s)
{
	for (int idx = 0; idx < i; idx++) {
		std::cout << s << std::endl;
		_sleep(100);
	}
}

void oops(int some_param)
{
	char buffer[1024];
	sprintf(buffer, "%i", some_param);

	std::thread t(f, 3, buffer);//buffer指针已经引用，并通过std::string constc&创建了一个新的变量，所以用_sleep看不出问题
	_sleep(50);
	
	sprintf(buffer, "kkkk");
	_sleep(1000);
	
	if (t.joinable()) {
		t.join();
	}
}

int main()
{
	oops(4);

	char* buf = new char[1024];
	memset(buf, 0, 1024);
	sprintf(buf, "kkkk");
	std::string const& x = buf;
	
	delete[] buf;
	buf = 0;

	std::cout << buf << std::endl;
	std::cout << x << std::endl;
	std::cout << &x << std::endl;
}
#endif

void update_data_for_widget(int& posx)
{
	posx += 1;
}

void oops_again()
{
	int aPos = 1024;

	//std::thread t(update_data_for_widget, aPos);不能通过这样的方式修改aPos的值，这里编译也通不过
	std::thread t(update_data_for_widget, std::ref(aPos));//正确的做法

	t.join();

	std::cout << "aPos now is " << aPos << std::endl;

}

int main()
{
	oops_again();
}