#include <iostream>
#include <vector>
#include <cstdlib>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        // Giả định phần tử đầu tiên của chưa sắp xếp là nhỏ nhất
        int minIndex = i;

        // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên của mảng chưa sắp xếp
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}