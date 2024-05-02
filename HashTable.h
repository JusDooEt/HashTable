#pragma once
#include <iostream>
#include <list>
#include <cstring>
using namespace std;

template<class T> class HashTable
{
private:
	static const int hashGroups = 10;
	list<pair<int, T>> table[hashGroups]; // List 1. Index 0, List 2, index 1....

public:
	bool isEmpty() const
	{
		int sum = 0;
		for (int i = 0; i < hashGroups; i++)
		{
			sum += table[i].size();
		}

		if (!sum)
		{
			return true;
		}
		return false;
	}

	int hashFunction(int key)
	{
		return key & hashGroups; // Key: 905, returns 5
	}

	void insertItem(int key, T value)
	{
		int hashValue = hashFunction(key);
		auto& cell = table[hashValue];
		bool keyExists = false;

		for (auto bItr = begin(cell); bItr != end(cell); bItr++)
		{
			if (bItr->first == key)
			{
				keyExists = true;

				cout << "\n\t< Key: " << bItr->first << " Exists. Value: " << bItr->second << " Replaced with " << value << ".> \n\n";

				bItr->second = value;
				break;
			}
		}

		if (!keyExists)
		{
			cell.emplace_back(key, value); // Adds the new key and value to the end of the cell
		}

		return;
	}

	void removeItem(int key)
	{
		int hashValue = hashFunction(key);
		auto& cell = table[hashValue];
		bool keyExists = false;

		for (auto bItr = begin(cell); bItr != end(cell); bItr++)
		{
			if (bItr->first == key)
			{
				keyExists = true;
				bItr = cell.erase(bItr);
				cout << "\n\t< Key: " << bItr->first << " Exists.Item Removed. > \n\n";
				break;
			}
		}

		if (!keyExists)
		{
			cout << "\n\t< Item not Found! >\n\n";
		}
	}

	T searchTable(int key)
	{
		int hashValue = hashFunction(key);
		auto& cell = table[hashValue];
		bool keyExists = false;

		for (auto bItr = begin(cell); bItr != end(cell); bItr++)
		{
			if (bItr->first == key)
			{
				keyExists = true;
				return bItr->second;
			}
		}

		if (!keyExists)
		{
			cout << "\n\t< Item not Found! >\n\n";
			return T();
		}
	}


	void printTable()
	{
		for (int i = 0; i < hashGroups; i++)
		{
			if (table[i].size() == 0)
				continue;


			for (auto bItr = table[i].begin(); bItr != table[i].end(); bItr++)
			{
				cout << "Key: " << bItr->first << " Value: " << bItr->second << endl;
			}
		}
		return;
	}
};

	


