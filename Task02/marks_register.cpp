#include <iostream>
#include <vector>

// Returns a reference to the highest mark in the array
int& findHighest(int arr[], int size) {
    int* maxPtr = &arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > *maxPtr) {
            maxPtr = &arr[i];
        }
    }
    return *maxPtr;
}

int main() {
    int marks[] = {85, 92, 78, 95, 88};
    int n = 5;

    std::cout << "Original marks: ";
    for(int i=0; i<n; ++i) std::cout << marks[i] << " ";
    std::cout << "\n";

    // Applying moderation directly using the function call on the left side of =
    findHighest(marks, n) += 2;

    std::cout << "After moderation (+2 to highest): ";
    for(int i=0; i<n; ++i) std::cout << marks[i] << " ";
    std::cout << "\n";

    return 0;
}
