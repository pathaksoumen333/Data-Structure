#include <iostream>
using namespace std;

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int num;
    
    cout << "Enter a number for Fibonacci and factorial calculations: ";
    cin >> num;

    if (num < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    // Calculate and display the Fibonacci number
    cout << "Fibonacci(" << num << ") = " << fibonacci(num) << endl;

    // Calculate and display the factorial
    cout << "Factorial(" << num << ") = " << factorial(num) << endl;

    return 0;
}
