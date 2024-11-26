#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // ��� accumulate
#include <windows.h>

using namespace std;

// ������� ��� ����������� ������� ��������
template <typename Iterator>
int indexOf(Iterator begin, Iterator end, Iterator target) {
    return distance(begin, target);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // ����� ���
    vector<int> arr = { 3, -5, 7, -2, 8, 3, 7, -9, 4, -6 };

    cout << "���������� �����: ";
    for (const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    // ���������� ���� ������� ��������
    int positiveSum = accumulate(arr.begin(), arr.end(), 0, [](int sum, int val) {
        return val > 0 ? sum + val : sum;
        });
    cout << "���� ������� ��������: " << positiveSum << endl;

    // ����������� ������������� �� ���������� �� ������� ��������
    auto maxModIt = max_element(arr.begin(), arr.end(), [](int a, int b) {
        return abs(a) < abs(b);
        });
    auto minModIt = min_element(arr.begin(), arr.end(), [](int a, int b) {
        return abs(a) < abs(b);
        });

    cout << "������������ �� ������� �������: " << *maxModIt
        << " (������ " << indexOf(arr.begin(), arr.end(), maxModIt) << ")" << endl;
    cout << "̳�������� �� ������� �������: " << *minModIt
        << " (������ " << indexOf(arr.begin(), arr.end(), minModIt) << ")" << endl;

    // ���������� ������� �������� �� maxModIt � minModIt
    int product = 1;
    if (maxModIt > minModIt) {
        product = accumulate(next(minModIt), maxModIt, 1, multiplies<int>());
    }
    else {
        product = accumulate(next(maxModIt), minModIt, 1, multiplies<int>());
    }
    cout << "������� �������� �� ������������ � ��������� �� �������: " << product << endl;

    // ���������� �� ���������
    sort(arr.begin(), arr.end(), greater<int>());
    cout << "����� ���� ���������� �� ���������: ";
    for (const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
