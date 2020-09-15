// Ref: https://www.geeksforgeeks.org/c-program-hashing-chaining/
#include<iostream>
#include<list>
using namespace std;

class Hash
{
public:
	Hash(int V){
		this->BUCKET = V;
		table = new list<int>[BUCKET];
	}
	
	void insertItem(int key){
		int index = hashFunction(key);
		table[index].emplace_back(key);
	}
	
	void deleteItem(int key){
		int index = hashFunction(key);
		
		list<int>::iterator itr;
		for(itr=table[index].begin(); itr!=table[index].end(); itr++){
			if(*itr == key)		break;
		}
		
		if(itr != table[index].end())
			table[index].erase(itr);
	}
	
	int hashFunction(int key){
		return key % BUCKET;
	}
	
	void displayHash(){
		for(int i=0; i<BUCKET; i++){
			cout << i;
			for(const auto& key: table[i])
				cout << " --> " << key;
			cout << endl;
		}
	}
	
private:
	int BUCKET;
	list<int> *table;
};

int main()
{
	int a[] = {15, 11, 27, 8, 12};
	int n = sizeof(a) / sizeof(a[0]);
	
	Hash h(7);
	
	for(int i=0; i<n; i++){
		h.insertItem(a[i]);
	}
	
	h.displayHash();
	h.deleteItem(15);
	cout << endl;
	h.displayHash();
	
	return 0;
}
