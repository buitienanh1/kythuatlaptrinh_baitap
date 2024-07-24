#include <iostream>
#include <vector>

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Chia mảng thành hai nửa và lấy chỉ số của phần tử phân tách
        int pivotIndex = partition(arr, low, high);

        // Đệ quy sắp xếp hai nửa
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn

    for (int j = low; j < high; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++; // Tăng chỉ số của phần tử nhỏ hơn
            std::swap(arr[i], arr[j]); // Hoán đổi
        }
    }
    std::swap(arr[i + 1], arr[high]); // Hoán đổi pivot về vị trí đúng
    return i + 1; // Trả về chỉ số của pivot
}


