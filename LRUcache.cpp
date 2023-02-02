#include<bits/stdc++.h>
using namespace std;

class LRUCache 
{

private:

	int keyCount;
	int maxKeyCount;
	
	list<pair<int, int>> dll;   // doubly linked list (dll) of <key, value>
	map<int, list<pair<int, int>>::iterator> k2it;   // map key to dll iterator

public:

    LRUCache(int capacity) 
	{
        keyCount = 0;
		maxKeyCount = capacity;
    }
    
    int get(int key) 
	{
		if(k2it.count(key) == 0) return -1;
		
		// Move <key, value> to the front
		dll.splice(dll.begin(), dll, k2it[key]);
		return dll.front().second;
    }
    
    // keep recently updated <key, value> at the front and oldest one at the back
    void put(int key, int value) 
	{
		if(k2it.count(key) > 0)
		{
			// Move <key, value> to the front
			dll.splice(dll.begin(), dll, k2it[key]);
			dll.front().second = value;
		}	
		else if(keyCount + 1 <= maxKeyCount)
		{
			dll.emplace_front(key, value);
			k2it[key] = dll.begin();
			keyCount++;
		}
		else
		{
			k2it.erase(dll.back().first);
			dll.pop_back();
			dll.emplace_front(key, value);
			k2it[key] = dll.begin();
		}
    }
};