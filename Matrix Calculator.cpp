#include <iostream>

using namespace std;

class Matrix
{
private:
	int m_i_numRow;
	int m_i_numCol;
	double** m_ptr_Matrix;

public:
	Matrix(int rows, int cols)
	{
		
		m_i_numRow = rows;
		m_i_numCol = cols;

		m_ptr_Matrix = new double* [m_i_numRow];

		for (int i = 0; i < m_i_numRow; i++)
		{
			m_ptr_Matrix[i] = new double[m_i_numCol];
		}

	}

	void setRow(int row)
	{
		m_i_numRow = row;
	}

	void setRowUsr()
	{
		cout << "Enter number of rows: ";
		cin >> m_i_numRow;
	}

	void setCol(int col)
	{
		m_i_numCol = col;
	}

	void setColUsr()
	{
		cout << "Enter number of columns: ";
		cin >> m_i_numCol;
	}

	void setMatrix(int row, int col, double element)
	{
		if ((row < 0 || row > m_i_numRow - 1) && (col < 0 || col > m_i_numCol - 1) == 1)
			cout << "ERROR, MATRIX OUT OF RANGE.";
		else
			m_ptr_Matrix[row][col] = element;
	}

	double getMatrix(int row, int col)
	{
		return m_ptr_Matrix[row][col];
	}

	int getRow()
	{
		return m_i_numRow;
	}

	int getCol()
	{
		return m_i_numCol;
	}

	void transpose();

	Matrix operator + (Matrix A);
	void operator = (Matrix A);
	Matrix operator * (Matrix A);

};


int main()
{
	Matrix A(2, 2), B(2, 2), C(2, 2);


	A.setMatrix(0, 0, 1);
	A.setMatrix(0, 1, 2);
	A.setMatrix(1, 0, 3);
	A.setMatrix(1, 1, 4);

	cout << "Matrix A: " << endl;

	cout << "00: " << A.getMatrix(0, 0) << endl;
	cout << "01: " << A.getMatrix(0, 1) << endl;
	cout << "10: " << A.getMatrix(1, 0) << endl;
	cout << "11: " << A.getMatrix(1, 1) << endl;



	A.transpose();

	cout << endl << "Transpose of Matrix A: " << endl;

	cout << "00: " << A.getMatrix(0, 0) << endl;
	cout << "01: " << A.getMatrix(0, 1) << endl;
	cout << "10: " << A.getMatrix(1, 0) << endl;
	cout << "11: " << A.getMatrix(1, 1) << endl;

	C.setMatrix(0, 0, 0);
	C.setMatrix(0, 1, 0);
	C.setMatrix(1, 0, 0);
	C.setMatrix(1, 1, 0);

	cout << endl << "Matrix C: " << endl;

	cout << "00: " << C.getMatrix(0, 0) << endl;
	cout << "01: " << C.getMatrix(0, 1) << endl;
	cout << "10: " << C.getMatrix(1, 0) << endl;
	cout << "11: " << C.getMatrix(1, 1) << endl;

	C = A;

	cout << endl << "Operation C = A" << endl << endl;
	cout << "Matrix C: " << endl;

	cout << "00: " << C.getMatrix(0, 0) << endl;
	cout << "01: " << C.getMatrix(0, 1) << endl;
	cout << "10: " << C.getMatrix(1, 0) << endl;
	cout << "11: " << C.getMatrix(1, 1) << endl;

	B.setMatrix(0, 0, 5);
	B.setMatrix(0, 1, 6);
	B.setMatrix(1, 0, 7);
	B.setMatrix(1, 1, 8);

	cout << endl << "Matrix B: " << endl;

	cout << "00: " << B.getMatrix(0, 0) << endl;
	cout << "01: " << B.getMatrix(0, 1) << endl;
	cout << "10: " << B.getMatrix(1, 0) << endl;
	cout << "11: " << B.getMatrix(1, 1) << endl;

	C = A + B;

	cout << endl << "Operation C = A + B" << endl << endl;
	cout << "Matrix C: " << endl;

	cout << "00: " << C.getMatrix(0, 0) << endl;
	cout << "01: " << C.getMatrix(0, 1) << endl;
	cout << "10: " << C.getMatrix(1, 0) << endl;
	cout << "11: " << C.getMatrix(1, 1) << endl;

	C = A * B;

	cout << endl << "Operation C = A * B" << endl << endl;
	cout << "Matrix C: " << endl;

	cout << "00: " << C.getMatrix(0, 0) << endl;
	cout << "01: " << C.getMatrix(0, 1) << endl;
	cout << "10: " << C.getMatrix(1, 0) << endl;
	cout << "11: " << C.getMatrix(1, 1) << endl;


	return 0;
}

void Matrix::transpose()
{	
	int rows = m_i_numRow;
	int cols = m_i_numCol;

	double** temp;

	temp = new double* [rows];

	for (int i = 0; i < rows; i++)
		temp[i] = new double[cols];


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			temp[j][i] = m_ptr_Matrix[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			 m_ptr_Matrix[i][j] = temp[i][j];
		}
	}
}

Matrix Matrix:: operator + (Matrix A)
{
	int rows = m_i_numRow;
	int cols = m_i_numCol;
	Matrix Sum(rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Sum.m_ptr_Matrix[i][j] = m_ptr_Matrix[i][j] + A.m_ptr_Matrix[i][j];
		}
	}

	return Sum;

}

void Matrix:: operator = (Matrix A)
{
	m_i_numRow = A.m_i_numRow;
	m_i_numCol = A.m_i_numCol;
	m_ptr_Matrix = A.m_ptr_Matrix;
}

Matrix Matrix:: operator * (Matrix A)
{
	int rows = m_i_numRow;
	int cols = A.m_i_numCol;
	Matrix Product(rows, cols);

	if (m_i_numCol = A.m_i_numRow)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				Product.m_ptr_Matrix[i][j] = 0;

				for (int k = 0; k < cols; k++)
				{
					Product.m_ptr_Matrix[i][j] += m_ptr_Matrix[i][k] * A.m_ptr_Matrix[k][j];
				}
			}
		}

		return Product;
	}



}
