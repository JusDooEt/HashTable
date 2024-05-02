# HashTable

## About
This program is meant to be used as a template for future projects that require a hash table. A hash table is a very efficient data structure for insertion and retrieval of data and is widely used for various applications. Hash tables use the key either being inserted or searched to organize the data structure. The key will be passed through a hash function. In this case the function will return key % hashGroups, and the returned answer will determine the placement of the key and its data within the Hash Table. This program uses an array of lists in order to hold the data. The returned hash value will determine which list to be either searched, inserted, or deleted from. After using the hash function to retrieve the correct list in the array, the list will be sequentially searched until the value is found or the end of the list is reached.

## Output
```
The Hash Table is empty

Inserting values in the hash table...

        < Key: 5621 Exists. Value: Bob Replaced with Betty.>

Printing HashTable...
Key: 65489 Value: Carl
Key: 5621 Value: Betty
Key: 8548 Value: Sally
Key: 10258 Value: Gary
Key: 1654 Value: Mary
Key: 905 Value: Jim
Key: 6584 Value: Jeff

        < Key: 6584 Exists.Item Removed. >


        < Key: 5621 Exists.Item Removed. >


        < Item not Found! >

Searching for key: 8548
Sally Was found!

The Hash Table is not empty
```
## Class HashTable
private:

	static const int hashGroups = 10;
	list<pair<int, string>> table[hashGroups]; 

public:

	bool   isEmpty() const;
	int    hashFunction(int key);
	void   insertItem(int key, string value);
	void   removeItem(int key);
	string searchTable(int key);
	void   printTable();


## Methods
- bool isEmpty()
  - This function will sequentially loop through the array 'table' and add the size of the lists to a sum variable.
  - If the sum equals 0 then the function will return true, else then the table is not empty and the function returns false.
- int hashFunction(int key)
  - This function receives a key and returns a hash value determined by the equation used in the function.
  - This program used the equation key % hashGroups. Ex. (Key = 104, hashGroups = 10, hash value = 4)
- void insertItem(int key, string value)
  - This function will receive a key and calculate the hash value with the hashFunction(int key).
  - The hash value is used to select a list to sequentially search for a duplicate.
  - If a duplicate key is found then the previous string value is replaced with the one passed to the function.
  - If there is no duplicate key then both the key and string value will be added to the end of the list.
- void removeItem(int key)
  - Uses the same methods to search the list as inserItem(int key, string value)
  - If a matching key is found in the list then it is removed from the list.
  - If not found the function will output a message to the console.
- string searchTable(int key)
  - Uses the same methods to search the list as inserItem(int key, string value).
  - If a matching key is found the string value is returned.
  - If a key is not found the function will return an empty string.
 
    


## Credit
[https://www.youtube.com/@CodingJesus](https://www.youtube.com/@CodingJesus)
- [video](https://www.youtube.com/watch?v=2_3fR-k-LzI)

