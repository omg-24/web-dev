#include <iostream>
using namespace std;

class MaxHeap {
private:
    int heap[100]; 
    int size;    

   
    void heapifyDown(int i, int n) {
        int largest = i;
        int left = 2 * i;      
        int right = 2 * i + 1; 

        if (left <= n && heap[left] > heap[largest])
            largest = left;
        if (right <= n && heap[right] > heap[largest]) 
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest, n);
        }
    }

   
    void heapifyUp(int i) {
        while (i > 1 && heap[i] > heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }
    }

public:
    MaxHeap() { size = 0; }


    void insert(int value) {
        heap[++size] = value;
        int index = size;
        while (index > 1) {
            int parent = index / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapSort() {
        int tempSize = size;
        while (tempSize > 1) {
            swap(heap[1], heap[tempSize]); 
            tempSize--;                   
            heapifyDown(1, tempSize);     
        }
    }

    void deleteNode(int index) {
        if (index > size || index < 1) {
            cout << "Index out of range!\n";
            return;
        }

        heap[index] = heap[size];
        size--;

        if (index > 1 && heap[index] > heap[index / 2]) {
            heapifyUp(index);
        } else {
            heapifyDown(index, size); 
        }
    }

    void printHeap() {
        for (int i = 1; i <= size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap heap;
    

    heap.insert(50);
    heap.insert(30);
    heap.insert(40);
    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    heap.insert(30);

    cout << "Heap after insertions: ";
    heap.printHeap();


    heap.deleteNode(7);

    cout << "Heap after deletion: ";
    heap.printHeap();


    heap.heapSort();
    cout << "Sorted array using Heap Sort: ";
    heap.printHeap();

    return 0;
}