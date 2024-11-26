#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // для accumulate
#include <windows.h>

using namespace std;

// Функція для знаходження індексу елемента
template <typename Iterator>
int indexOf(Iterator begin, Iterator end, Iterator target) {
    return distance(begin, target);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Вхідні дані
    vector<int> arr = { 3, -5, 7, -2, 8, 3, 7, -9, 4, -6 };

    cout << "Початковий масив: ";
    for (const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    // Обчислення суми додатніх елементів
    int positiveSum = accumulate(arr.begin(), arr.end(), 0, [](int sum, int val) {
        return val > 0 ? sum + val : sum;
        });
    cout << "Сума додатніх елементів: " << positiveSum << endl;

    // Знаходження максимального та мінімального за модулем елементів
    auto maxModIt = max_element(arr.begin(), arr.end(), [](int a, int b) {
        return abs(a) < abs(b);
        });
    auto minModIt = min_element(arr.begin(), arr.end(), [](int a, int b) {
        return abs(a) < abs(b);
        });

    cout << "Максимальний за модулем елемент: " << *maxModIt
        << " (індекс " << indexOf(arr.begin(), arr.end(), maxModIt) << ")" << endl;
    cout << "Мінімальний за модулем елемент: " << *minModIt
        << " (індекс " << indexOf(arr.begin(), arr.end(), minModIt) << ")" << endl;

    // Обчислення добутку елементів між maxModIt і minModIt
    int product = 1;
    if (maxModIt > minModIt) {
        product = accumulate(next(minModIt), maxModIt, 1, multiplies<int>());
    }
    else {
        product = accumulate(next(maxModIt), minModIt, 1, multiplies<int>());
    }
    cout << "Добуток елементів між максимальним і мінімальним за модулем: " << product << endl;

    // Сортування за спаданням
    sort(arr.begin(), arr.end(), greater<int>());
    cout << "Масив після сортування за спаданням: ";
    for (const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
