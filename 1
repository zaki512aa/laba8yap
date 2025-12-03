#include <iostream>
#include <ctime>
#include <climits>

using namespace std;
int get_from_interval(int a, int b);
void echo_matrix(int** matrix, int n);
int** fill_matrix(int n, int a, int b);
void clear_matrix(int** matrix, int n);
void draw_green(int** matrix, int n);
void draw_red(int** matrix, int n);
bool is_in_green(int i, int j, int n);
bool is_in_red(int i, int j, int n);
void find_max_negative_in_green(int** matrix, int n, int& max_neg_val, int& max_neg_i, int& max_neg_j);
void find_min_positive_in_red(int** matrix, int n, int& min_pos_val, int& min_pos_i, int& min_pos_j);
void swap_elements(int** matrix, int i1, int j1, int i2, int j2);
void process_matrix(int** matrix, int n);

int main() {
    srand(time(nullptr));

    int n, a, b;
    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter interval for values generation [a, b]: ";
    cin >> a >> b;

    int** matrix = fill_matrix(n, a, b);

    cout << "\nOriginal matrix:\n";
    echo_matrix(matrix, n);

    process_matrix(matrix, n);

    cout << "\nMatrix after swapping:\n";
    echo_matrix(matrix, n);

    clear_matrix(matrix, n);

    return 0;
}

// генерация случайного числа
int get_from_interval(int a, int b) {
    return rand() % (b - a + 1) + a;
}

// вывод матрицы
void echo_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
}

// заполнение матрицы случайными числами
int** fill_matrix(int n, int a, int b) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = get_from_interval(a, b);
        }
    }
    return matrix;
}

// очистка памяти
void clear_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// визуализация зелёной области
void draw_green(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_in_green(i, j, n)) {
                matrix[i][j] = 0;
            }
        }
    }
}

// визуализация красной области
void draw_red(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_in_red(i, j, n)) {
                matrix[i][j] = 0;
            }
        }
    }
}

// находится ли элемент в зелёной области
bool is_in_green(int i, int j, int n) {
    // Левый треугольник: j < i и j < n - i - 1
    return (j < i) && (j < n - i - 1);
}

// находится ли элемент в красной области
bool is_in_red(int i, int j, int n) {
    return (i < j) && (i < n - j - 1);
}

// поиск максимального отрицательного элемента green
void find_max_negative_in_green(int** matrix, int n, int& max_neg_val, int& max_neg_i, int& max_neg_j) {
    max_neg_val = INT_MIN;
    max_neg_i = -1;
    max_neg_j = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_in_green(i, j, n) && matrix[i][j] < 0) {
                if (matrix[i][j] > max_neg_val) {
                    max_neg_val = matrix[i][j];
                    max_neg_i = i;
                    max_neg_j = j;
                }
            }
        }
    }
}

// поиск минимального положительного red
void find_min_positive_in_red(int** matrix, int n, int& min_pos_val, int& min_pos_i, int& min_pos_j) {
    min_pos_val = INT_MAX;
    min_pos_i = -1;
    min_pos_j = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_in_red(i, j, n) && matrix[i][j] > 0) {
                if (matrix[i][j] < min_pos_val) {
                    min_pos_val = matrix[i][j];
                    min_pos_i = i;
                    min_pos_j = j;
                }
            }
        }
    }
}

// перестановка двух элементов
void swap_elements(int** matrix, int i1, int j1, int i2, int j2) {
    if (i1 == -1 || j1 == -1 || i2 == -1 || j2 == -1) {
        return;
    }
    int temp = matrix[i1][j1];
    matrix[i1][j1] = matrix[i2][j2];
    matrix[i2][j2] = temp;
}

// логика обработки матрицы
void process_matrix(int** matrix, int n) {
    int max_neg_val, max_neg_i, max_neg_j;
    int min_pos_val, min_pos_i, min_pos_j;

    find_max_negative_in_green(matrix, n, max_neg_val, max_neg_i, max_neg_j);
    find_min_positive_in_red(matrix, n, min_pos_val, min_pos_i, min_pos_j);

    if (max_neg_i != -1 && min_pos_i != -1) {
        cout << "\nFound:\n";
        cout << "Max negative in green: " << max_neg_val << " at (" << max_neg_i << ", " << max_neg_j << ")\n";
        cout << "Min positive in red: " << min_pos_val << " at (" << min_pos_i << ", " << min_pos_j << ")\n";
        swap_elements(matrix, max_neg_i, max_neg_j, min_pos_i, min_pos_j);
        cout << "Elements swapped.\n";
    } else {
        cout << "\nNo suitable elements found for swapping.\n";
    }
}
