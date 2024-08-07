#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct Thuoc {
    char maThuoc[6];
    char tenThuoc[21];
    char nhaSanXuat[21];
    char dangThuoc[11];
    double donGia;        
    char congDung[51];    
};
int compareByMaThuoc(const void* a, const void* b) {
    return strcmp(((struct Thuoc*)a)->maThuoc, ((struct Thuoc*)b)->maThuoc);
}

int binarySearch(struct Thuoc thuocList[], int size, const char* prefix) {
    int left = 0;
    int right = size - 1;
    int firstIndex = -1; // Để lưu chỉ số của thuốc đầu tiên tìm thấy

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Kiểm tra nếu mã thuốc ở giữa bắt đầu bằng prefix
        if (strncmp(thuocList[mid].maThuoc, prefix, strlen(prefix)) == 0) {
            firstIndex = mid; // Lưu chỉ số
            right = mid - 1;  // Tìm kiếm bên trái để tìm thuốc đầu tiên
        }
        else if (strcmp(thuocList[mid].maThuoc, prefix) < 0) {
            left = mid + 1; // Nếu mã thuốc nhỏ hơn prefix, bỏ qua nửa bên trái
        }
        else {
            right = mid - 1; // Nếu mã thuốc lớn hơn prefix, bỏ qua nửa bên phải
        }
    }

    return firstIndex; // Trả về chỉ số thuốc đầu tiên tìm thấy
}


int main() {
    struct Thuoc thuocList[100] = {
        {"T01A", "Paracetamol", "ABC Pharma", "viên", 15000, "Giảm đau, hạ sốt"},
        {"T02B", "Ibuprofen", "XYZ Pharma", "viên", 20000, "Giảm viêm, giảm đau"},
        {"T01C", "Aspirin", "DEF Pharma", "nước", 25000, "Giảm đau, chống viêm"},
        {"T03D", "Amoxicillin", "GHI Pharma", "viên", 30000, "Kháng sinh"},
        {"T01B", "Cefalexin", "JKL Pharma", "nước", 18000, "Kháng sinh"}
    };

    int numThuoc = 5; // Số lượng thuốc

    // 4.1: Xuất mảng 1 chiều chứa danh sách thuốc
    printf("Danh sách thuốc:\n");
    for (int i = 0; i < numThuoc; i++) {
        printf("%s - %s\n", thuocList[i].maThuoc, thuocList[i].tenThuoc);
    }

    // 4.2: Sắp xếp danh sách thuốc tăng dần theo mã thuốc
    qsort(thuocList, numThuoc, sizeof(struct Thuoc), compareByMaThuoc);

    printf("\nDanh sách thuốc sau khi sắp xếp:\n");
    for (int i = 0; i < numThuoc; i++) {
        printf("%s - %s\n", thuocList[i].maThuoc, thuocList[i].tenThuoc);
    }

    // 4.3: Tìm thuốc có mã số bắt đầu bằng "T01"
    char maTimKiem[5] = "T01A";
    int index = binarySearch(thuocList, numThuoc, maTimKiem);

    if (index != -1) {
        printf("\nThuốc tìm thấy:\n");
        printf("%s - %s\n", thuocList[index].maThuoc, thuocList[index].tenThuoc);
    }
    else {
        printf("\nKhông tìm thấy thuốc với mã bắt đầu bằng \"%s\".\n", maTimKiem);
    }

    return 0;
}