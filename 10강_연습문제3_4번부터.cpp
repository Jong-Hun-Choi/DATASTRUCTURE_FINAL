#include <iostream>
#define MAX 200
using namespace std;

class HeapNode {
private:
	int key;
public:
	HeapNode(int k = 0) :key(k) {}
	void setKey(int k) { key = k; }
	int getKey() { return key; }
	void display() { cout << " " << key; }
};


class MinHeap {
private:
	HeapNode node[MAX];
	int size;

public:
	MinHeap() :size(0) {} //일단 size를 0으로 초기화 해주고 인덱스 0번째에 값을 안 넣겠다는 강력한 의지!
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX - 1; }
	HeapNode& getParent(int i) { return node[i / 2]; } //규칙1: 부모노드
	HeapNode& getLeft(int i) { return node[i * 2]; } //규칙2:  2배
	HeapNode& getRight(int i) { return node[i * 2 + 1]; } // 규칙3: 2배 +1

	void insert(int key) {
		if (isFull())return;
		int i = ++size; //전위증가를 해줘야해!
		while (i != 1 && key < getParent(i).getKey()) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key);

	}
	HeapNode remove() {
		if (isEmpty()) return NULL;
		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while (child <= size) {
			if (child < size && getLeft(parent).getKey() > getRight(parent).getKey()) {
				child++;
			}
			if (last.getKey() <= node[child].getKey()) break;
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return item;

	}
	HeapNode find() { return node[1]; }//최상단 값을 찾으면 되는데 최고 높은 인덱스는 0이 아니라 1이야

	void display() {
		for (int i = 1, level = 1; i <= size; i++) {
			if (i == level) {
				cout << endl;
				level *= 2;
			}
			node[i].display();//함수 오버라이딩!
		}
		cout << endl << "--------------------------";
	}
};


int main() {
	MinHeap heap;

	heap.insert(10);
	heap.insert(40);
	heap.insert(30);
	heap.insert(5);
	heap.insert(12);
	heap.insert(6);
	heap.insert(15);
	heap.insert(9);
	heap.insert(60);
	heap.display();

	//(6)번
	heap.remove();
	heap.display();


	cout << endl;
}