#include <iostream>
#include <vector>

using namespace std;

void duplicateMaxRow(vector<vector<int>>& matrix) {
    int maxRowIndex = 0;
    int maxElement = matrix[0][0];

    // Знаходимо індекс рядка з максимальним елементом
    for (int i = 0; i < matrix.size(); ++i) {
        int maxInRow = matrix[i][0];
        for (int j = 1; j < matrix[i].size(); ++j) {
            if (matrix[i][j] > maxInRow) {
                maxInRow = matrix[i][j];
            }
        }
        if (maxInRow > maxElement) {
            maxElement = maxInRow;
            maxRowIndex = i;
        }
    }

    // Дублюємо знайдений рядок
    matrix.insert(matrix.begin() + maxRowIndex + 1, matrix[maxRowIndex]);
}

void inputMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cin >> matrix[i][j];
        }
    }
}

void outputMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int M, N;
    cout << "Enter the number of rows (N): ";
    cin >> N;
    cout << "Enter the number of columns (M): ";
    cin >> M;

    vector<vector<int>> matrix(N, vector<int>(M));

    // Заповнюємо матрицю
    cout << "Enter the elements of the matrix:" << endl;
    inputMatrix(matrix);

    // Дублюємо рядок з максимальним елементом
    duplicateMaxRow(matrix);

    // Виводимо модифіковану матрицю
    cout << "Modified matrix:" << endl;
    outputMatrix(matrix);

    return 0;
}
