#include <iostream>
#include <vector>
using namespace std;

// Function to maintain the max-heap property
void maxHeapify(vector<int>& heap, int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(heap[index], heap[largest]);
        maxHeapify(heap, size, largest);
    }
}

// Function to build a max-heap
void buildMaxHeap(vector<int>& heap) {
    int size = heap.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, size, i);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> heap(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }

    // Build a max-heap
    buildMaxHeap(heap);

    cout << "Max-Heap: ";
    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    return 0;
}
