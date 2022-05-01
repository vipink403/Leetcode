//https://leetcode.com/problems/print-foobar-alternately/

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iterator> 
#include <filesystem>
#include <functional>   // std::not1
#include <algorithm>    // std::count_if
#include <thread>
#include <atomic>
#include <condition_variable>

using namespace std;

namespace PrintFooBarAlternately
{
	class FooBar {
	private:
		int n;
		std::condition_variable cv;
		std::mutex mut;
		bool fooPrinted;
	public:
		FooBar(int n) :fooPrinted(false) {
			this->n = n;
		}

		void printBar() { cout << "Bar"; }
		void printFoo() { cout << "Foo"; }

		void foo(/*function<void()> printFoo*/) {

			for (int i = 0; i < n; i++) {
				std::unique_lock<std::mutex> ul(mut);
				cv.wait(ul, [&] {return !fooPrinted; });

				// printFoo() outputs "foo". Do not change or remove this line.
				printFoo();
				fooPrinted = true;
				cv.notify_all();
			}
			cout << "foo ended\n";
		}

		void bar(/*function<void()> printBar*/) {

			for (int i = 0; i < n; i++) {
				std::unique_lock<std::mutex> ul(mut);

				cv.wait(ul, [&] {return fooPrinted; });

				// printBar() outputs "bar". Do not change or remove this line.
				printBar();
				fooPrinted = false;
				cv.notify_all();
			}
			cout << "bar ended\n";
		}
	};

	int main()
	{
		FooBar foobar(2);
		std::thread t1(&FooBar::foo, &foobar);
		std::thread t2(&FooBar::bar, &foobar);
		t1.join();
		t2.join();
		cout << "\nmain() ended\n";

		return 0;
	}
}