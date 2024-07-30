#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Hàm tạo ma trận vuông ngẫu nhiên cấp n
void taoMaTran(int n, vector<vector<int>>& a) {
    srand(time(0));
    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100; // Số ngẫu nhiên từ 0 đến 99
        }
    }
}

// Hàm xuất ma trận
void xuatMaTran(const vector<vector<int>>& a) {
    for (const auto& row : a) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Hàm xuất các phần tử trên đường chéo chính
void xuatDuongCheoChinh(const vector<vector<int>>& a) {
    cout << "Duong cheo chinh: ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i][i] << " ";
    }
    cout << endl;
}

// Hàm xuất các phần tử thuộc đường chéo song song với đường chéo chính
void xuatDuongCheoSongSong(const vector<vector<int>>& a) {
    cout << "Duong cheo song song: ";
    for (int i = 0; i < a.size() - 1; i++) {
        cout << a[i][i + 1] << " ";
    }
    cout << endl;
}

// Hàm tìm phần tử max thuộc tam giác trên
int timMaxTamGiacTren(const vector<vector<int>>& a) {
    int maxVal = a[0][0];
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            maxVal = max(maxVal, a[i][j]);
        }
    }
    return maxVal;
}

// Hàm sắp xếp ma trận theo kiểu zic-zắc
void sapXepZicZac(vector<vector<int>>& a) {
    vector<int> flat;
    for (const auto& row : a) {
        for (int val : row) {
            flat.push_back(val);
        }
    }
    sort(flat.begin(), flat.end());

    int index = 0;
    for (int i = 0; i < a.size(); i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < a.size(); j++) {
                a[i][j] = flat[index++];
            }
        }
        else {
            for (int j = a.size() - 1; j >= 0; j--) {
                a[i][j] = flat[index++];
            }
        }
    }
}

// Hàm sắp xếp đường chéo chính
void sapXepDuongCheoChinh(vector<vector<int>>& a) {
    vector<int> diagonal;
    for (int i = 0; i < a.size(); i++) {
        diagonal.push_back(a[i][i]);
    }
    sort(diagonal.begin(), diagonal.end());

    for (int i = 0; i < a.size(); i++) {
        a[i][i] = diagonal[i];
    }
}

int main() {
    int n;
    cout << "Nhap cap ma tran (n >= 5): ";
    cin >> n;

    if (n < 5) {
        cout << "Cap ma tran phai lon hon hoac bang 5!" << endl;
        return 1;
    }

    vector<vector<int>> a;
    taoMaTran(n, a);

    int choice;
    do {
        cout << "\nMenu chon chuc nang:\n";
        cout << "1. Xuat ma tran\n";
        cout << "2. Xuat duong cheo chinh\n";
        cout << "3. Xuat duong cheo song song\n";
        cout << "4. Tim phan tu max trong tam giac tren\n";
        cout << "5. Sap xep ma tran theo kieu zic-zac\n";
        cout << "6. Sap xep duong cheo chinh\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Ma tran:\n";
            xuatMaTran(a);
            break;
        case 2:
            xuatDuongCheoChinh(a);
            break;
        case 3:
            xuatDuongCheoSongSong(a);
            break;
        case 4:
            cout << "Phan tu max thuoc tam giac tren: " << timMaxTamGiacTren(a) << endl;
            break;
        case 5:
            sapXepZicZac(a);
            cout << "Ma tran sau khi sap xep zic-zac:\n";
            xuatMaTran(a);
            break;
        case 6:
            sapXepDuongCheoChinh(a);
            cout << "Ma tran sau khi sap xep duong cheo chinh:\n";
            xuatMaTran(a);
            break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
