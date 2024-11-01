#include <iostream>

using namespace std;
const int SIZE = 4; // Global variable for matrix size
class Matrix {
private:
	int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)
public:
	// 1. Read values from stdin into a matrix
	void readFromStdin() {
		int x;
		cout << "Data for the matrix: ";
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				cin >> x;
				data[i][j] = x;
			}
		}
	}

	// 2. Display a matrix
	void display() const {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				cout << data[i][j];
				cout << " ";
			}
			cout << '\n';
		}
	}

	// 3. Add two matrices (operator overloading for +)
	Matrix operator+(const Matrix& other) const {
	Matrix final;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			final.data[i][j] = data[i][j] + other.data[i][j];
			
			}
		}
	return final;
	}
	// 4. Multiply two matrices (operator overloading for *)
	Matrix operator*(const Matrix& other) const{
	Matrix final;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			final.data[i][j] = data[i][j] * other.data[i][j];
			}
		}
	return final;
	}
	
	// 5. Compute the sum of matrix diagonal elements
	int sumOfDiagonals() const {
		int x = 0;
		for (int i = 0; i < SIZE; i++) {
			x = (data[i][i] + data[i][SIZE - 1 - i] + x);
		}
		return x;
	}

	
	// 6. Swap matrix rows
	void swapRows(int row1, int row2) {
		Matrix temp;
		for (int j = 0; j < SIZE; j++) {
			temp.data[row1][j] = data[row1][j];
		}
		for (int j = 0; j < SIZE; j++) {
			data[row1][j] = data[row2][j];
		}
		for (int j = 0; j < SIZE; j++) {
			data[row2][j] = temp.data[row1][j];
		}
	}


};
int main() {
	Matrix mat1;
	cout << "Enter values for Matrix 1:" << endl;
	mat1.readFromStdin();
	cout << "\nMatrix 1:" << endl;
	mat1.display();
	
	Matrix mat2;
	cout << "\n";
	cout << "Enter values for Matrix 2:" << endl;
	mat2.readFromStdin();
	cout << "\nMatrix 2:" << endl;
	mat2.display();
	
	Matrix sum = mat1 + mat2;
	cout << "\n";
	cout << "Sum of matrices:" << endl;
	sum.display();
	
	Matrix product = mat1 * mat2;
	cout << "\n";
	cout << "Product of matrices:" << endl;
	product.display();
	
	cout << "\n";
	cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

	mat1.swapRows(0, 2);
	cout << "\nMatrix 1 after swapping rows:" << endl;
	mat1.display();
	
	return 0;
}
