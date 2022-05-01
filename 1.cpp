#include <mutex>
#include <string>
#include <vector>
#include <thread>
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
void print(T& container)
{
	for (auto num : container)
	{
		cout << num << "\n";
	}
	cout << endl;
}

std::mutex g_display_mutex;

// Callable objects - thread entry point
void displayMsg(string & str)
{
	g_display_mutex.lock();
	cout << str << " With from Thread Id : " << this_thread::get_id() << endl;
	g_display_mutex.unlock();
}

void fun(int i)
{
	cout << "fun(int i) is called"<< endl;
}

void fun(int *i)
{
	cout << "fun(int *i) is called" << endl;
}

int main_thread()
{
	//fun(NULL);
	/*fun(nullptr);*/
	cout << "Msg from Main Thread with ID : " <<this_thread::get_id() << endl;
	string WorkerMsg{ "Hello from Worker Thread - " };
	std::thread t(displayMsg, WorkerMsg);
	//t.join();
	return 0;
}