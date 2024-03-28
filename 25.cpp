#include <iostream>
#include <sstream>
using namespace std;

// Функція для введення матриці
void inputMatrix(int **matrix, int M, int N, char *argv[]) {
    int k = 3; // Індекс в масиві аргументів, з якого починаються елементи матриці
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            stringstream(argv[k++]) >> matrix[i][j];
        }
    }
}

// Функція для виведення матриці
void printMatrix(int **matrix, int M, int N) {
    cout << "Matrix:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

// Функція для знаходження рядка з найбільшою сумою елементів
int findMaxSumRow(int **matrix, int M, int N) {
    int maxSum = 0;
    int maxRow = 0;
    for (int i = 0; i < M; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += matrix[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }
    return maxRow;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <number of rows> <number of columns> <matrix elements separated by spaces>" << endl;
        return 1;
    }

    int M, N;
    stringstream(argv[1]) >> N;
    stringstream(argv[2]) >> M;

    if (argc != 3 + M * N) {
        cout << "Invalid number of arguments." << endl;
        return 1;
    }

    int **matrix;

    // Виділення пам'яті для матриці
    matrix = new int*[N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[M];
    }

    // Введення матриці
    inputMatrix(matrix, N, M, argv);

    cout << "Size matrix: N = " << N << ", M = " << M << endl;

    // Виведення матриці
    printMatrix(matrix, N, M);

    // Пошук рядка з найбільшою сумою елементів
    int maxRow = findMaxSumRow(matrix, N, M);

    // Виведення результату
    cout << "Number of the row with the largest sum of elements: " << maxRow + 1 << endl;
    int maxSum = 0;
    for (int j = 0; j < M; ++j) {
        maxSum += matrix[maxRow][j];
    }
    cout << "Maximum sum: " << maxSum << endl;

    // Звільнення пам'яті
    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
