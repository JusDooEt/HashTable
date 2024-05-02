#include "HashTable.h"

int main()
{
	HashTable<string> HT;

	if (HT.isEmpty())
	{
		cout << "The Hash Table is empty\n";
	}
	else
	{
		cout << "Issue with is empty() \n";
	}

	cout << "\nInserting values in the hash table...\n";
	HT.insertItem(905, "Jim");
	HT.insertItem(10258, "Gary");
	HT.insertItem(1654, "Mary");
	HT.insertItem(65489, "Carl");
	HT.insertItem(5621, "Bob");
	HT.insertItem(8548, "Sally");
	HT.insertItem(5621, "Betty");
	HT.insertItem(6584, "Jeff");

	cout << "Printing HashTable...\n";
	HT.printTable();

	HT.removeItem(905);
	HT.removeItem(65489);
	HT.removeItem(5);

	cout << "Searching for key: 8548\n";
	string name = HT.searchTable(8548);
	if (name.size() > 0)
	{
		cout << name << " Was found!\n\n";
	}
	else
	{
		"Key: 8548 was not found\n\n";
	}

	if (!HT.isEmpty())
	{
		cout << "The Hash Table is not empty\n";
	}
	else
	{
		cout << "Issue with is empty() \n";
	}
}