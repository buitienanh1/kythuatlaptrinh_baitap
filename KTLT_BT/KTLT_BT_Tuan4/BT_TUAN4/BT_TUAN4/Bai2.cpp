#include <iostream>
using namespace std;

int ucln(int a, int b) {
    // Nếu b bằng 0, trả về a là UCLN
    if (b == 0)
        return a;
    // Nếu a > b, gọi hàm UCLN với b và a-b
    if (a > b)
        return ucln(b, a - b);
    // Ngược lại, gọi hàm UCLN với a và b-a
    return ucln(a, b - a);
}

int main() {
    int a, b;
    cout << "Nhap so nguyen duong a: ";
    cin >> a;
    cout << "Nhap so nguyen duong b: ";
    cin >> b;

    int result = ucln(a, b);
    cout << "uoc chung lon nhat cua " << a << " va " << b << " la: " << result << endl;

    return 0;
}
