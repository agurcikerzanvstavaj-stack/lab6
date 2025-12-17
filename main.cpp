#include <iostream>
#include <limits>
using namespace std;

const int N = 50;

/* ---------- ФУНКЦІЇ ВВЕДЕННЯ ---------- */

// Введення додатного цілого числа
int input_positive_int(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0 || value > N) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка! Введіть число від 1 до " << N << endl;
        } else {
            return value;
        }
    }
}

// Введення цілого числа
int input_int(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка! Введіть ціле число!" << endl;
        } else {
            return value;
        }
    }
}

// Введення масиву
void input_array(int arr[N], int &n) {
    n = input_positive_int("Введіть кількість елементів: ");
    for (int i = 0; i < n; i++) {
        arr[i] = input_int("Елемент " + to_string(i + 1) + ": ");
    }
}

/* ---------- ВИВЕДЕННЯ МАСИВУ ---------- */

void output_array(const int arr[N], int n) {
    cout << "Масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* ---------- ЗАВДАННЯ 1 ---------- */
/* Підрахунок кількості різних елементів */

int count_unique(const int arr[N], int n) {
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        bool isUnique = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) uniqueCount++;
    }
    return uniqueCount;
}

void task1() {
    int arr[N], n;
    input_array(arr, n);
    output_array(arr, n);

    int result = count_unique(arr, n);
    cout << "Кількість різних елементів: " << result << endl;
}

/* ---------- ЗАВДАННЯ 2 ---------- */
/* Видалення елементів, що зустрічаються рівно 2 рази */

void remove_elements_twice(int arr[N], int &n) {
    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) count++;
        }

        if (count == 2) {
            // видалення елемента
            for (int k = i; k < n - 1; k++) {
                arr[k] = arr[k + 1];
            }
            n--;
            i--; // перевіряємо поточну позицію ще раз
        }
    }
}

void task2() {
    int arr[N], n;
    input_array(arr, n);

    cout << "Початковий ";
    output_array(arr, n);

    remove_elements_twice(arr, n);

    cout << "Змінений ";
    output_array(arr, n);
    cout << "Новий розмір масиву: " << n << endl;
}

/* ---------- ГОЛОВНЕ МЕНЮ ---------- */

int main() {
    int choice;

    do {
        cout << "\n===== Лабораторна робота №6 =====\n";
        cout << "1 - Завдання 1 (кількість різних елементів)\n";
        cout << "2 - Завдання 2 (видалити елементи, що зустрічаються 2 рази)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 0:
                cout << "Завершення програми.\n";
                break;
            default:
                cout << "Невірний вибір!\n";
        }
    } while (choice != 0);

    return 0;
}
