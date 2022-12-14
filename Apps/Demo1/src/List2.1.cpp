#include <iostream>
#include <thread>
#include <cassert>

//#define List2_1
#ifdef List2_1

//class background_task
//{
//public:
//	void opeator() const
//	{
//		do_sth();
//		do_sth_else();
//	}
//
//private:
//	void do_sth() const{
//		std::cout << "do sth" << std::endl;
//	}
//
//	void do_sth_else() const{
//		std::cout << "do sth else" << std::endl;
//	}
//
//};
//
//class A
//{
//
//};
//
//int main()
//{
//	//std::thread my_thread(background_task());
//	//my_thread.join();
//
//	std::cout << "AA" << std::endl;
//
//	A a;
//	my_func2(&a);
//}
//
//void my_func2(A a) {
//	std::cout << "----" << std::endl;
//}

void do_sth(){
	std::cout << "do sth" << std::endl;
}

struct func
{
	int& i;
	func(int& i_) :i(i_) {}

	void operator()()
	{
		int origin_i = i;
		for (unsigned j = 0; j < 100000; ++j)
		{
			_sleep(100);
			std::cout << i << std::endl;
			assert(i == origin_i);//3.最初有效的i的值origin_i和现在引用的已释放的变量i做比较，出现问题
			
		}
	}
};

void oops()
{
	int some_local_state = 1;
	func my_func(some_local_state);
	std::thread my_thread(my_func);
	my_thread.detach();//1.已经脱离，但my_func依然引用some_local_state,并在内部将第一次引用的值赋为1

	assert(!my_thread.joinable());

	_sleep(1000);
	//2.跳出oops之后，some_local_state其实已经被收回，但my_fucn依然在引用，这时候值是未定义的
}

int main()
{
	oops();

	_sleep(10000);
}

#endif