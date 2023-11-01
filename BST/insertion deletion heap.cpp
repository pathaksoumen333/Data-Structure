#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i which is
// an index of arr[] and n is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as the root
    int left = 2 * i + 1; // Left child = 2*i + 1
    int right = 2 * i + 2; // Right child = 2*i + 2

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to insert an element into the heap
void insertElement(int arr[], int& n, int element) {
    arr[n] = element;
    n++;
    int i = n - 1;

    while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete the root from the heap
void deleteRoot(int arr[], int& n) {
    if (n <= 0) {
        cout << "Heap is empty. Cannot delete." << endl;
        return;
    }

    // Get the last element
    int lastElement = arr[n - 1];

    // Replace the root with the last element
    arr[0] = lastElement;

    // Decrease the size of the heap by 1
    n = n - 1;

    // Heapify the root node
    heapify(arr, n, 0);
}

/* A utility function to print array of size n */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the initial number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the initial elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (true) {
        cout << "1. Insert an element" << endl;
        cout << "2. Delete the root" << endl;
        cout << "3. Display the heap" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int element;
            cout << "Enter element to insert: ";
            cin >> element;
            insertElement(arr, n, element);
        } else if (choice == 2) {
            deleteRoot(arr, n);
            cout << "Root element deleted." << endl;
        } else if (choice == 3) {
            cout << "Heap elements: ";
            printArray(arr, n);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
