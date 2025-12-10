#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void createFile(const string& name, const vector<vector<int>>& data);
void createFile(const string& name, const vector<int>& data);
vector<vector<int>> readMatrix(const string& name, int& n, int& m);
vector<int> readVector(const string& name, int& size);
void printMatrix(const vector<vector<int>>& matrix);
vector<vector<int>> computeExpression(const vector<vector<int>>& A,
                                      const vector<vector<int>>& C,
                                      const vector<int>& B,
                                      const vector<int>& D);

int main() {
    srand(time(0));

    int n = 3, m = 4;

    // создаём случайные данные
    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> C(n, vector<int>(m));
    vector<int> B(m), D(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = rand() % 10;
            C[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < m; i++) {
        B[i] = rand() % 10;
        D[i] = rand() % 10;
    }

    // сохраняем в файлы
    createFile("A.txt", A);
    createFile("C.txt", C);
    createFile("B.txt", B);
    createFile("D.txt", D);

    // читаем из файлов
    int nA, mA, nC, mC, sizeB, sizeD;
    vector<vector<int>> matrixA = readMatrix("A.txt", nA, mA);
    vector<vector<int>> matrixC = readMatrix("C.txt", nC, mC);
    vector<int> vectorB = readVector("B.txt", sizeB);
    vector<int> vectorD = readVector("D.txt", sizeD);


    // вывод изначальных матриц
    cout << "Matrix A (" << nA << "x" << mA << "):" << endl;
    printMatrix(matrixA);

    cout << "\nMatrix C (" << nC << "x" << mC << "):" << endl;
    printMatrix(matrixC);

    cout << "\nVector B (size " << sizeB << "):" << endl;
    for (int val : vectorB) cout << val << " ";
    cout << endl;

    cout << "\nVector D (size " << sizeD << "):" << endl;
    for (int val : vectorD) cout << val << " ";
    cout << endl << endl;

    // вычисляем выражение
    vector<vector<int>> result = computeExpression(matrixA, matrixC, vectorB, vectorD);

    // выводим результат
    cout << "result A^T * C + 4 * B * D^T:" << endl;
    printMatrix(result);

    return 0;
}

// реализации функций
void createFile(const string& name, const vector<vector<int>>& data) {
    ofstream file(name);
    file << data.size() << " " << data[0].size() << endl;
    for (const auto& row : data) {
        for (int val : row) file << val << " ";
        file << endl;
    }
    file.close();
}

void createFile(const string& name, const vector<int>& data) {
    ofstream file(name);
    file << data.size() << endl;
    for (int val : data) file << val << endl;
    file.close();
}

vector<vector<int>> readMatrix(const string& name, int& n, int& m) {
    ifstream file(name);
    file >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            file >> matrix[i][j];
    file.close();
    return matrix;
}

vector<int> readVector(const string& name, int& size) {
    ifstream file(name);
    file >> size;
    vector<int> vec(size);
    for (int i = 0; i < size; i++)
        file >> vec[i];
    file.close();
    return vec;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) cout << val << "\t";
        cout << endl;
    }
}

vector<vector<int>> computeExpression(const vector<vector<int>>& A,
                                      const vector<vector<int>>& C,
                                      const vector<int>& B,
                                      const vector<int>& D) {
    int n = A.size();
    int m = A[0].size();

    vector<vector<int>> result(m, vector<int>(m, 0));

    // A^T * C
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[k][i] * C[k][j];
            }
        }
    }

    // + 4 * B * D^T
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] += 4 * B[i] * D[j];
        }
    }

    return result;
}
