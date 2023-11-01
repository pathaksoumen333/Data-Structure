// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
const int tables=100;
class Hash
{
    public:
    pair<int,string> table[tables];
    int hashf(int key)
    {
        return key%tables;
    }
    void insert(int key,const string& value)
    {
        int index=hashf(key);
        table[index]=make_pair(key,value);
    }
     string search(int key) {
        int index = hashf(key);

        // Linear probing for collision resolution
        while (table[index].first != key) {
            if (table[index].first == -1) {
                return "Not found";
            }
            index = (index + 1) % tables;
        }

        return table[index].second;
    }
    
};
int main() {
    Hash hashTable;

    int choice;

    while (true) {
        cout << "1. Insert data" << endl;
        cout << "2. Search data" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int key;
            string value;
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin.ignore(); // Consume newline character
            getline(cin, value);
            hashTable.insert(key, value);
        } else if (choice == 2) {
            int searchKey;
            cout << "Enter a key to search: ";
            cin >> searchKey;

            string result = hashTable.search(searchKey);
            if (result == "Not found") {
                cout << "Data not found." << endl;
            } else {
                cout << "Data found: " << result << endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
