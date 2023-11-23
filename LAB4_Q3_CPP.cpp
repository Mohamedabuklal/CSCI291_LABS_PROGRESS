#include<iostream>
#include<iomanip>
#include <cstdlib> 
using namespace std;

void print_real(float number, int fieldspace, int precision);

template <typename T>
T update_scale(T &m1, T &m2, T m3 = 10);

int main(void) {
    float x, y;
    cout << "\n\nPlease input two real numbers: ";
    cin >> x >> y;

    print_real(x, 7, 3);
    print_real(y, 7, 3);

    update_scale(x, y);
    print_real(x, 7, 3);
    print_real(y, 7, 3);

    return 0;
}

void print_real(float number, int fieldspace, int precision) {
    cout << fixed << setw(fieldspace) << setprecision(precision) << number << endl;
}

template <typename T>
T update_scale(T &m1, T &m2, T m3) {
    
    m1 = (m1 + m2) * m3;
    m2 = (m1 - m2) * m3;
}
