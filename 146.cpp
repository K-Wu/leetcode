// 146. LRU Cache 93ms 65%
// Design and implement a data structure for Least Recently Used(LRU) cache.It should support the following operations : get and put.

// get(key) - Get the value(will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present.When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//Follow up :
//Could you do both operations in O(1) time complexity ?
#include<iostream>
#include<vector>
using namespace std;
struct FreqNode;
struct HashNode {
	int key;
	int val;
	bool isDummy;
	HashNode* prev;
	HashNode* next;
	FreqNode* _freqnode;
};
struct FreqNode {
	int key;
	FreqNode* prev;
	FreqNode* next;
	HashNode* _hashnode;
};

class HashList {
public:
	vector<HashNode*> hash_vect;
	int length;
	HashList(int capacity) {
		hash_vect.resize(2 * capacity + 1);
		for (int i = 0; i < 2 * capacity + 1; i += 1) {//dummy
			hash_vect.at(i) = new HashNode();
			hash_vect.at(i)->isDummy = true;
			hash_vect.at(i)->_freqnode = NULL;
			hash_vect.at(i)->next = NULL;
			hash_vect.at(i)->prev = NULL;
		}
		length = 2 * capacity + 1;
	}
	HashNode* put(int key, int val) {
		int pos = key%length;
		HashNode* curr = __get(key);
		if (curr->key == key)
		{
			curr->val = val;//需要update Freq
			return curr;
		}
		else
		{
			curr->next = new HashNode();
			curr->next->key = key;
			curr->next->val = val;
			curr->next->prev = curr;
			curr->next->next = NULL;
			curr->_freqnode = NULL;
			curr->next->isDummy = false;
			return curr->next;
		}
	}
	HashNode* __get(int key) {//如果当前key等于所需key，返回curr，否则返回最后一个节点。
		int pos = key%length;
		HashNode* curr = hash_vect.at(pos);
		while (curr->next != NULL) {
			curr = curr->next;
			if (curr->key == key)
				return curr;
		}
		return curr;
	}
	HashNode* get(int key) {
		HashNode* curr = __get(key);
		if (curr->key == key)
			return curr;
		else
			return NULL;
	}
	void del(HashNode* hashnode) {
		hashnode->prev->next = hashnode->next;
		if (hashnode->next != NULL)
			hashnode->next->prev = hashnode->prev;
		delete hashnode;
	}
};



class FreqList {
public:
	int size;
	int capacity;
	FreqNode* dummyhead;
	FreqList(int capacity_) {
		capacity = capacity_;
		size = 0;
		dummyhead = new FreqNode();
	}
	HashNode* __putnew(FreqNode* freqnode) {//return True if replacement happened
		if (size == 0) {
			dummyhead->next = freqnode;
			dummyhead->prev = freqnode;
			freqnode->prev = dummyhead;
			freqnode->next = dummyhead;
			size += 1;
			return NULL;
		}
		else {
			FreqNode* first = dummyhead->next;
			dummyhead->next = freqnode;
			freqnode->prev = dummyhead;
			freqnode->next = first;
			first->prev = freqnode;
			if(size==capacity){
				FreqNode* last = dummyhead->prev;
				dummyhead->prev = last->prev;
				last->prev->next = dummyhead;
				HashNode* hashnode_to_del = last->_hashnode;
				delete last;
				return hashnode_to_del;
			}
			else {
				size += 1;
				return NULL;
			}
		}
	}
	void __puttoFront(FreqNode* freqnode) {
		if (dummyhead->next == freqnode)
			return;
		freqnode->prev->next = freqnode->next;
		freqnode->next->prev = freqnode->prev;
		freqnode->next=dummyhead->next;
		freqnode->next->prev = freqnode;
		freqnode->prev = dummyhead;
		dummyhead->next = freqnode;
	}
	HashNode* updateFreq(HashNode* hashnode) {// return node to delete if replacement happened
		if (hashnode->_freqnode == NULL) {
			hashnode->_freqnode = new FreqNode();
			hashnode->_freqnode->key = hashnode->key;
			hashnode->_freqnode->_hashnode = hashnode;
			return __putnew(hashnode->_freqnode);
		}
		else {
			__puttoFront(hashnode->_freqnode);
			return NULL;
		}
	}


};
class LRUCache {
public:
	FreqList* _freqlist;
	HashList* _hashlist;
	LRUCache(int capacity) {
		_freqlist= new FreqList(capacity);
		_hashlist=new HashList(capacity);
	}

	int get(int key) {
		HashNode* _hashnode = _hashlist->get(key);

		if (_hashnode == NULL||_hashnode->isDummy==true)
			return -1;
		_freqlist->__puttoFront(_hashnode->_freqnode);

		return _hashnode->val;
	}

	void put(int key, int value) {
		HashNode* _hashnode = _hashlist->put(key,value);
		HashNode* _hashnode_to_del = _freqlist->updateFreq(_hashnode);
		if(_hashnode_to_del!=NULL)
			_hashlist->del(_hashnode_to_del);//第一遍写成删除新插入的节点了

	}
};

int main() {
	LRUCache* cache = new LRUCache(2 /* capacity */);
	cache->put(1, 1);
	cache->put(2, 2);
	cout<<cache->get(1);       // returns 1
	cache->put(3, 3);    // evicts key 2
	cout<<cache->get(2);       // returns -1 (not found)
	cache->put(4, 4);    // evicts key 1
	cout<<cache->get(1);       // returns -1 (not found)
	cout<<cache->get(3);       // returns 3
	cout<<cache->get(4);       // returns 4
	return 0;
}