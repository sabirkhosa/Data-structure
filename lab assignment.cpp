#include<iostream>
using namespace std;

class list {
public:
    int *arr, *temp, *a;
    int x, y, size;

    list() {
        arr = temp = NULL;
    }

    // Function to find the most frequent element in a subarray
    void MostFrequentElementInSubArray(int left, int right, int freq) {
        cout << "Enter the size of the array: ";
        cin >> size;

        arr = new int[size];
        temp = arr;

        // Input elements into the array
        cout << "Enter array elements: ";
        for (int i = 0; i < size; i++) {
            cin >> *temp;
            temp++;
        }

        // Array to store unique elements meeting the frequency condition
        a = new int[right];
        for (int i = 0; i < right; i++) {
            a[i] = NULL;
        }

        int counter = 0;
        int index = 0;
        int flag = 0;

        // Iterate through the array to find most frequent elements in the subarray
        for (int i = 0; i <= right; i++) {
            for (int k = 0; k < right; k++) {
                if (a[k] == arr[i]) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1) {
                flag = 0;
                continue;
            }

            for (int j = 0; j <= right; j++) {
                if (arr[i] == arr[j]) {
                    counter++;
                }

                if (counter >= freq) {
                    a[index] = arr[i];
                    counter = 0;
                    index++;
                }
            }
        }

        // Output the most frequent elements in the subarray
        cout << "Output: ";
        for (int i = 0; i < right; i++) {
            if 
