/***************************************************************************
*
* Matrix.hpp
*
* This is an  header file to implement a basic Matrix Class
*
*
***************************************************************************
* Copyright 2018 whuang022.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
 **************************************************************************/


#ifndef MATRIX_H_   /* Include guard */
#define MATRIX_H_

#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <memory>

using namespace std;

double const epsilon=std::numeric_limits<double>::epsilon();
template< typename A, typename B >inline
bool almost_equal(A const & a, B const & b){
	auto const x = abs(a);
	auto const y = abs(b);
	if((abs(x-0)<epsilon)&&(abs(y-0)<epsilon)){
		return true;
	}else{
		return(std::abs(x-y)<epsilon*std::max(std::abs(x),std::abs(y)));
	}
}

enum class MatrixType{
	ZeroM,OneM,IdentityM,StandardNormal01M
};

class MatrixFuction{
	public:
	virtual double f(double)=0 ;//define the mapping f(x) , must be implement.
    virtual ~MatrixFuction(){};
};

class Matrix {

	public :
	Matrix(int, int); //init by size
	Matrix(int, int,double); //init by size&value
	Matrix(const Matrix& m); //intit by object
	Matrix(int,int, const MatrixType &p); //intit by special type matrix
	Matrix(const string &dataPath);//init by file
	~Matrix(); //deconstructor
	void print();//print elements
	void fill(double ); //full by element
	Matrix & operator*=( double const & p) ; //scalar product
	Matrix & operator*=( Matrix const & p) ; //scalar product

	Matrix & operator+=( Matrix const & p) ; //add
	Matrix & operator+=( double const & p) ; //add

	Matrix & operator-=( Matrix const & p) ; //sub
	Matrix & operator-=( double const & p) ; //sub

	void setMatrixFuction(std::shared_ptr<MatrixFuction>  p);
	Matrix T (); //trans matrix
	Matrix F (); //f(x) matrix
	int rowSize()  const; // get row size
	int colSize()  const; // get col size
	double get(int row,int col)const;
	void set(int row,int col,double val);
	bool isSquareMatrix(); //check if square matrix
	bool isSymmetricMatrix(); //check if symmetric matrix
	void argRow();
	private :
	//MatrixFuction MF;//dynamic matrix elements mapping function
    std::shared_ptr<MatrixFuction> MF;
	int *rows; //rows = up-down direction size
	int *cols; //cols = left-right direction size
	vector<vector<double> > mat; //matrix body

};

Matrix operator+(const Matrix& a, const Matrix& b); //add
Matrix operator+(double num, const Matrix& a);
Matrix operator+(const Matrix& a,double num);

Matrix operator*(const Matrix& a, const Matrix& b); //dot product
Matrix operator*(double num,  const Matrix& a);
Matrix operator*(const Matrix& a, double num);

Matrix operator-(const Matrix& a, const Matrix& b); //sub
Matrix operator-(double num, const Matrix& a);
Matrix operator-(const Matrix& a,double num);

Matrix operator >> (const Matrix& a, const Matrix& b); //hadamard product
Matrix operator << (const Matrix& a, const Matrix& b); //table product
bool operator == (const Matrix& a, const Matrix& b); //almost equal of matrix

#endif // HELLO_H_
