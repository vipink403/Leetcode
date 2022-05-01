//https://leetcode.com/problems/building-h2o/

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

class H2O {
	std::condition_variable cv;
	std::mutex mut;
	bool isHydrogenNeeded, isOxygenNeeded;
	int counter;
public:
	H2O() : isHydrogenNeeded(false), isOxygenNeeded(true), counter(0) {}

	void oxygen(function<void()> releaseOxygen) {
		std::unique_lock<mutex> ul(mut);

		cv.wait(ul, [&] { return isOxygenNeeded == true; });

		// releaseOxygen() outputs "O". Do not change or remove this line.
		releaseOxygen();

		isOxygenNeeded = false;
		isHydrogenNeeded = true;

		cv.notify_all();
	}

	void hydrogen(function<void()> releaseHydrogen) {
		std::unique_lock<mutex> ul(mut);

		cv.wait(ul, [&] { return isHydrogenNeeded == true; });

		// releaseHydrogen() outputs "H". Do not change or remove this line.
		releaseHydrogen();

		++counter;
		if (counter % 2 == 0)
		{
			isHydrogenNeeded = false;
			isOxygenNeeded = true;
		}

		cv.notify_all();
	}
};

int main_h2o()
{
	H2O h2o;
	//std::thread t1(&H2O::hydrogen, &h2o);
	//std::thread t2(&H2O::oxygen, &h2o);
	//t1.join();
	//t2.join();
	cout << "\nmain() ended\n";

	return 0;
}
