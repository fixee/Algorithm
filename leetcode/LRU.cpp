#include<iostream>

using namespace std;

struct Node{
	int key;
	int value;
	public : Node(int key, int value, int index):key(key), value(value){}
};


class LRUCache{
	public:
		LRUCache(int capacity){				
			length = capacity;
			pointer = 0;
			queue = new int[length];
			node = new Node[length];
		}

		int get(int key) {
			int index = find_key( key );
			if( index == -1 )
				return -1;
			return node[index].value;
		}

		void set(int key, int value) {
			int index = find_key( key );
			if( key != -1 )
			{
				node[index].value = value;
				return;
			}
		}

		void ~LRUCache()
		{
			delete[] node;
			delete[] queue;
		}

	private:
		int find_key( int key )
		{
			int cur_length =  pointer > length ? length : 0;
			int start = 0;
			while( start < cur_length )
			{
				if( key == node[start].key )
					return start;

				if( key < node[start].key )
					start = 2 * start + 1;
				else
					start = 2 * start + 2;
			}

			return -1;
		}


	private:
		int length, pointer;
		Node *node;
		int *queue;
};

class Node
{
	public: 
		Node(int value) : value(value)
		{
		}

		int get_value()
		{
			return value;
		}

	private:
		int value;
};

int main()
{
	Node n(3);
	cout << n.get_value() << endl;
	return 0;
}

