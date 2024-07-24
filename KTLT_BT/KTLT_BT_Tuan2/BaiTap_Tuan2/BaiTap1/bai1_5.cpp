#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int x) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Kiểm tra xem x có phải là phần tử giữa không
        if (arr[mid] == x) {
            return mid; // Trả về vị trí của x
        }

        // Nếu x lớn hơn phần tử giữa, bỏ qua nửa bên trái
        if (arr[mid] < x) {
            left = mid + 1;
        }
        // Nếu x nhỏ hơn phần tử giữa, bỏ qua nửa bên phải
        else {
            right = mid - 1;
        }
    }

    return -1; // Không tìm thấy x
}