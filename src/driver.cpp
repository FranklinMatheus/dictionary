#include <iostream>
#include "dictionary.hpp"

struct MyKeyComparator {
	bool operator()(const int &lhs, const int &rhs) const
	{
		return lhs < rhs;
	}
};

int main()
{
	std::cout << "===============================================\n";
	std::cout << ">>>> TESTING THE DAL\n";
	std::cout << "-----------------------------------------------\n";
	{
		std::cout << ">>> Testing insert: \n";
		DAL< int, std::string, MyKeyComparator > dic;
		
		dic.insert(12, "apple");
		dic.insert(13, "pear");
		std::cout << dic;
		std::cout << "\n\n";
	}

	{
		std::cout << ">>> Testing search: \n";
		DAL< int, std::string, MyKeyComparator > dic;
		std::string name;
		
		dic.insert(12, "apple");
		dic.insert(13, "pear");

		dic.search(12, name);
		std::cout << "Name: " << name << "\n";
		dic.search(13, name);
		std::cout << "Name: " << name << "\n";
		std::cout << "\n";
	}

	{
		std::cout << ">>> Testing remove: \n";
		DAL< int, std::string, MyKeyComparator > dic;
		std::string name;

		dic.insert(12, "apple");
		dic.insert(13, "pear");

		dic.remove( 12, name );
		std::cout << "Removed name: " << name << "\n";
		std::cout << dic << "\n";
		std::cout << "\n";
	}

	{
		std::cout << ">>> Testing min: \n";
		DAL< int, std::string, MyKeyComparator > dic;
		std::string name;
		
		dic.insert(12, "apple");
		dic.insert(23, "pear");
		dic.insert(11, "orange");
		dic.insert(42, "banana");

		auto min = dic.min();
		std::cout << "Min key: " << min << "\n";
		std::cout << "\n";
	}

	{
		std::cout << ">>> Testing max: \n";
		DAL< int, std::string, MyKeyComparator > dic;
		std::string name;
		
		dic.insert(22, "apple");
		dic.insert(62, "pear");
		dic.insert(61, "orange");
		dic.insert(12, "banana");

		auto min = dic.max();
		std::cout << "Max key: " << min << "\n";
		std::cout << "\n";
	}

	{
		std::cout << ">>> Testing sucessor: \n";
		DAL< int, std::string, MyKeyComparator > dic;
		std::string name;
		
		dic.insert(21, "apple");
		dic.insert(33, "pear");
		dic.insert(5, "orange");
		dic.insert(11, "banana");

		auto suc(0);
		dic.sucessor( 21, suc );
		std::cout << "Sucessor of key 21 is: " << suc << "\n";
		std::cout << "\n";
	}

	{
		std::cout << ">>> Testing predecessor: \n";
		DAL< int, std::string, MyKeyComparator > dic;
		std::string name;
		
		dic.insert(21, "apple");
		dic.insert(33, "pear");
		dic.insert(5, "orange");
		dic.insert(11, "banana");

		auto pred(0);
		dic.predecessor( 11, pred );
		std::cout << "Predecessor of key 11 is: " << pred << "\n";
		std::cout << "\n";
	}

	std::cout << "===============================================\n";
	std::cout << "TESTING THE DSAL\n";
	std::cout << "-----------------------------------------------\n";

	{
		std::cout << ">>> Testing insert: \n";
		DSAL< int, std::string, MyKeyComparator > dic;
		
		dic.insert(12, "apple");
		dic.insert(13, "pear");
		std::cout << dic;
		std::cout << "\n\n";
	}

	{
		std::cout << ">>> Testing search: \n";
		DSAL< int, std::string, MyKeyComparator > dic;
		std::string name;
		
		dic.insert(12, "apple");
		dic.insert(13, "pear");

		dic.search(12, name);
		std::cout << "Name: " << name << "\n";
		dic.search(13, name);
		std::cout << "Name: " << name << "\n";
		std::cout << "\n";
	}

	{
		std::cout << ">>> Testing remove: \n";
		DSAL< int, std::string, MyKeyComparator > dic;
		std::string name;

		dic.insert(12, "apple");
		dic.insert(13, "pear");

		dic.remove( 12, name );
		std::cout << "Removed name: " << name << "\n";
		std::cout << dic << "\n";
		std::cout << "\n";
	}

	{
		std::cout << ">>> Testing min: \n";
		DSAL< int, std::string, MyKeyComparator > dic;
		std::string name;
		
		dic.insert(12, "apple");
		dic.insert(23, "pear");
		dic.insert(11, "orange");
		dic.insert(42, "banana");

		auto min = dic.min();
		std::cout << "Min key: " << min << "\n";
		std::cout << "\n";
	}

	{
		std::cout << ">>> Testing max: \n";
		DSAL< int, std::string, MyKeyComparator > dic;
		std::string name;
		
		dic.insert(22, "apple");
		dic.insert(62, "pear");
		dic.insert(61, "orange");
		dic.insert(12, "banana");

		auto min = dic.max();
		std::cout << "Max key: " << min << "\n";
		std::cout << "\n";
	}

	{
		std::cout << ">>> Testing sucessor: \n";
		DSAL< int, std::string, MyKeyComparator > dic;
		std::string name;
		
		dic.insert(21, "apple");
		dic.insert(33, "pear");
		dic.insert(5, "orange");
		dic.insert(11, "banana");

		auto suc(0);
		dic.sucessor( 21, suc );
		std::cout << "Sucessor of key 21 is: " << suc << "\n";
		std::cout << "\n";
	}

	{
		std::cout << ">>> Testing predecessor: \n";
		DSAL< int, std::string, MyKeyComparator > dic;
		std::string name;
		
		dic.insert(21, "apple");
		dic.insert(33, "pear");
		dic.insert(5, "orange");
		dic.insert(11, "banana");

		auto pred(0);
		dic.predecessor( 21, pred );
		std::cout << "Predecessor of key 21 is: " << pred << "\n";
		std::cout << "\n";
	}

	return EXIT_SUCCESS;
}
