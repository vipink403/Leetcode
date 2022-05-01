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
using namespace std;

namespace stl
{
	void asssignment_func()
	{
		vector<int> v1{ 1, 2, 3, 4, 5, 6 };
		vector<int> v2;

		v2.assign(begin(v1) + (int)(v1.size() / 2), end(v1));
		for (auto p : v2)
			cout << p << " ";
		cout << endl;
	}

	void read_ints_from_file()
	{
		//std::ifstream file("C:\\Users\\vkehri166703\\OneDrive - Applied Materials\Documents\\New folder\\ints.dat");
		std::ifstream file("ints.dat");
		istream_iterator<string> iter(file);
		istream_iterator<string> eos;			// end of stream iterator

		list<string> data(iter, eos);
		for (auto item : data)
			cout << item << " ";
		cout << endl;
	}

	// Make functor class adaptable by inherting it this way
	// By doing so, we could use apply not1 function in the predicate
	// like "auto nonEvens = remove_if(ints.begin(), ints.end(), not1(IsOdd()));"
	struct IsOdd : std::unary_function < int, bool >
	{
		// it won't compile if operator() is not const function
		bool operator()(const int& val) const
		{
			return (val % 2 == 0);
		}
	};

	void functor_classes_which_are_adaptable()
	{
		vector<int> ints = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		auto nonOdds = remove_if(ints.begin(), ints.end(), IsOdd());
		ints.erase(nonOdds, ints.end());
		for (auto p : ints)
			cout << p << " ";
		cout << endl;

		ints = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		//auto nonEvens = remove_if(ints.begin(), ints.end(), not1(function<int>(IsOdd())));
		auto nonEvens = remove_if(ints.begin(), ints.end(), not1(IsOdd()));
		ints.erase(nonEvens, ints.end());
		for (auto p : ints)
			cout << p << " ";
		cout << endl;
	}

	class Widget
	{
		static int count;
		int i;
	public:
		Widget() { count++; i = count; cout << "Widgets Ctor called" << endl; }
		~Widget() { cout << "Widgets Dtor called" << endl; }
		void display() const { cout << i << endl; }
	};
	int Widget::count = 0;
};

void HelperFuncVersion1()
{
	char* str = new char[80];
	vector<stl::Widget*> widgets;
	for (size_t i = 0; i < 10; i++)
		widgets.push_back(new(str + (i * 8)) stl::Widget());

	for (auto widget : widgets)
	{
		(*widget).display();
	}

	// Memory leak... widgets
}

void HelperFuncVersion2()
{
	vector<stl::Widget*> widgets;
	for (size_t i = 0; i < 10; i++)
		widgets.push_back(new stl::Widget());

	for (auto widget : widgets)
	{
		(*widget).display();
	}

	// No memory leak?? No
	// Memory leak can occur if exception gets thrown before
	// deleting the memory present in widgets
	for (auto widget : widgets)
	{
		delete(widget);
	}
}

void HelperFuncVersion3()
{
	typedef shared_ptr<stl::Widget> SPW;

	vector<SPW> widgets;

	for (size_t i = 0; i < 10; i++)
		widgets.push_back(SPW(new stl::Widget()));

	for (auto widget : widgets)
	{
		(*widget).display();
	}

	// No memory leak now even if exception gets thrown
}

int main2()
{
	//HelperFuncVersion1();
	//HelperFuncVersion2();
	//HelperFuncVersion3();

	//typedef auto_ptr<stl::Widget> SPW;
	//vector<SPW> widgets;	//auto_ptr should not used to store in stl container

	//set<int> mp;
	//mp.insert(11);
	//mp.begin()->first = 2;
	return 0;
}