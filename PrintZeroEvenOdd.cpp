//https://leetcode.com/problems/print-zero-even-odd/

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

class Bank
{
	std::condition_variable cond;
	std::mutex m;
	int balance;
public:
	Bank() : balance(0) {}
	~Bank(){}
	void addMoney(int);
	void withdrawMoney(int);
};

void Bank::addMoney(int amount)
{
	cout << "\naddMoney is called";
	std::lock_guard<mutex> lg(m);	// no need to wait to acquire the lock
	balance += amount;
	cout << "\nAmount is added. Current balance = " << balance;
	cond.notify_one(); // notify the other threads waiting for "cond" conditional_variable signal
}

void Bank::withdrawMoney(int amount)
{
	cout << "\nwithdrawMoney is called";

	// Using Unique_lock because we need to wait for an event to occur (to acquire the lock) (balance != 0) 
	// so that the amount can be withdrawn
	std::unique_lock<mutex> uniqueLock(m);

	cond.wait(uniqueLock, [&]{ return (!balance) ? false : true; });
	if (balance >= amount)
	{
		balance -= amount;
		cout << "\nAmount is withdrawn. Current balance = " << balance;
	}
	else
		cout << "\nInsufficient balance" << endl;
}

namespace namespace_ZeroEvenOdd 
{
	class ZeroEvenOdd {
	private:
		int n;
		std::mutex mut;
		std::condition_variable cv;
		enum { ZERO, ODD, EVEN } nextPrintType;
		//std::atomic<int> counter;

	public:
		ZeroEvenOdd(int n)
		{
			this->n = n;
		}

		void printNumber(int x)
		{
			cout << x;
		}

		//void zero(function<void(int)> printNumber) {
		//	std::unique_lock<mutex> ul(mut);
		//	printNumber(0);
		//	nextPrintType = ODD;
		//	cv.notify_all();
		//	cv.wait(ul, [&] { return nextPrintType == ZERO ? true : false; });
		//}
		//void odd(function<void(int)> printNumber) {
		//	std::unique_lock<mutex> ul(mut);
		//	cv.wait(ul, [&] { return nextPrintType == ODD ? true : false; });
		//	if (counter % 2 != 0)
		//		printNumber(counter);
		//	if (n < counter) counter++;
		//	nextPrintType = ZERO;
		//	cv.notify_one();
		//}
		//void even(function<void(int)> printNumber) {
		//	std::unique_lock<mutex> ul(mut);
		//	cv.wait(ul, [&] { return nextPrintType == EVEN ? true : false; });
		//	if (counter % 2 == 0)
		//		printNumber(counter);
		//	if (n < counter) counter++;
		//	nextPrintType = ZERO;
		//	cv.notify_one();
		//}

		void zero()
		{
			for (size_t i = 0; i < n;) // 0 1 2 3 4 5 6 7 8 9
			{
				std::unique_lock<mutex> ul(mut);
				printNumber(0);
				i++;
				if (i % 2 == 0)
					nextPrintType = EVEN;
				else
					nextPrintType = ODD;
				cv.notify_all();
				cv.wait(ul, [&] { return nextPrintType == ZERO; });
			}
			//cout << "zero() ended\n";
		}

		void odd()
		{
			for (size_t i = 1; i <= n; i += 2) // 1 3 5 7 9
			{
				std::unique_lock<mutex> ul(mut);
				cv.wait(ul, [&] { return nextPrintType == ODD; });
				printNumber(i);
				nextPrintType = ZERO;
				cv.notify_all();
			}
			//cout << "odd() ended\n";
		}

		void even()
		{
			for (size_t i = 2; i <= n; i += 2) // 2 4 6 8
			{
				std::unique_lock<mutex> ul(mut);
				cv.wait(ul, [&] { return nextPrintType == EVEN; });
				printNumber(i);
				nextPrintType = ZERO;
				cv.notify_all();
			}
			//cout << "even() ended\n";
		}
	};

	int main()
	{
		//Bank bank;
		//std::thread t1(&Bank::addMoney, &bank, 1000);
		//std::thread t2(&Bank::withdrawMoney, &bank, 500);
		//t1.join();
		//t2.join();
		//cout << endl;

		ZeroEvenOdd ZeroEvenOddObj(5);
		std::thread t1(&ZeroEvenOdd::zero, &ZeroEvenOddObj);
		std::thread t2(&ZeroEvenOdd::odd, &ZeroEvenOddObj);
		std::thread t3(&ZeroEvenOdd::even, &ZeroEvenOddObj);
		t1.join();
		t2.join();
		t3.join();
		cout << "main() ended\n";

		return 0;
	}
}