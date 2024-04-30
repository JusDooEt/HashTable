#include "HashTable.h"

bool HashTable::isEmpty() const
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

int HashTable::hashFunction(int key)
{
	return key & hashGroups; // Key: 905, returns 5
}

void  HashTable::insertItem(int key, string value)
{
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	bool keyExists = false;

	for (auto bItr = begin(cell); bItr != end(cell); bItr++)
	{
		if (bItr->first == key)
		{
			keyExists = true;
			bItr->second = value;

			cout << "\n\t< Key: " << bItr->first << " Exists. Value Replaced.> \n\n";
			break;
		}
	}

	if (!keyExists)
	{
		cell.emplace_back(key, value); // Adds the new key and value to the end of the cell
	}

	return;
}

void HashTable::removeItem(int key)
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

string HashTable::searchTable(int key)
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
		return "";
	}
}

void HashTable::printTable()
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
