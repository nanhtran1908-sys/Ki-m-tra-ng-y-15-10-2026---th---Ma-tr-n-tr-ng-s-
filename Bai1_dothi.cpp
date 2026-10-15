#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX = 100;

bool docMaTran(const char* tenFile, int a[][MAX], int &n) {
    ifstream f(tenFile);
    if (!f.is_open()) {
        cout << "Khong mo duoc file " << tenFile << endl;
        return false;
    }
    f >> n;
    if (n <= 0 || n > MAX) {
        cout << "So dinh khong hop le!" << endl;
        return false;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!(f >> a[i][j])) {
                cout << "File thieu du lieu!" << endl;
                return false;
            }
    f.close();
    return true;
}

void inMaTran(int a[][MAX], int n) {
    cout << "Ma tran trong so (" << n << " dinh):" << endl;
    cout << setw(4) << " ";
    for (int j = 0; j < n; j++)
        cout << setw(4) << char('A' + j);
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(4) << char('A' + i);
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

int main() {
    int a[MAX][MAX], n;
    if (docMaTran("matran.txt", a, n))
        inMaTran(a, n);
    return 0;
}

