#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0, choice;

    for (int menu = 0; menu < 1000; menu++) { // run menu many times
        cout << "\nMENU\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. REMOVE DUPLICATES\n7. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) { // CREATE
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++) cin >> arr[i];
        }
        else if (choice == 2) { // DISPLAY
            if (n == 0) cout << "Array is empty.\n";
            else {
                cout << "Array: ";
                for (int i = 0; i < n; i++) cout << arr[i] << " ";
                cout << "\n";
            }
        }
        else if (choice == 3) { // INSERT
            int pos, val;
            cout << "Enter position (0 to " << n << "): ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
            arr[pos] = val;
            n++;
        }
        else if (choice == 4) { // DELETE
            int pos;
            cout << "Enter position to delete (0 to " << n - 1 << "): ";
            cin >> pos;
            for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
            n--;
        }
        else if (choice == 5) { // LINEAR SEARCH
            int key, found = -1;
            cout << "Enter value to search: ";
            cin >> key;
            for (int i = 0; i < n; i++) {
                if (arr[i] == key) { found = i; break; }
            }
            if (found != -1) cout << "Found at index " << found << "\n";
            else cout << "Not found\n";
        }
        else if (choice == 6) { // REMOVE DUPLICATES
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (arr[i] == arr[j]) {
                        for (int k = j; k < n - 1; k++) arr[k] = arr[k + 1];
                        n--;
                        j--;
                    }
                }
            }
            cout << "Duplicates removed.\n";
        }
        else if (choice == 7) { // EXIT
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
