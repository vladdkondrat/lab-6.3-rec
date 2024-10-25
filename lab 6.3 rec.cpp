#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Рекурсивна функція для створення масиву
void Create(int* arr, int size, int Low, int High, int index = 0) {
    if (index == size) return;
    arr[index] = Low + rand() % (High - Low + 1);
    Create(arr, size, Low, High, index + 1);
}

// Рекурсивна функція для виведення масиву
void Print(const int* arr, int size, int index = 0) {
    if (index == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << arr[index];
    Print(arr, size, index + 1);
}

// Рекурсивна функція для визначення, чи елементи масиву впорядковані за не зростанням
bool isSortedNonIncreasing(const int* arr, int size, int index = 1) {
    if (index == size) return true;
    if (arr[index] > arr[index - 1]) return false;
    return isSortedNonIncreasing(arr, size, index + 1);
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    const int size = 10;
    int arr[size];

    Create(arr, size, -10, 10);
    cout << "Original array: ";
    Print(arr, size);

    if (isSortedNonIncreasing(arr, size)) {
        cout << "The elements of the array are sorted in non-increasing order." << endl;
    }
    else {
        cout << "The elements of the array are not sorted in non-increasing order." << endl;
    }

    return 0;
}
