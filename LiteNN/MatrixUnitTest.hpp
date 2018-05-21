/***************************************************************************
*
* MatrixUnitTest.hpp
*
* This is a  unit test header to test Matrix Class
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
#ifndef MATRIXUNITTEST_H_   /* Include guard */
#define MATRIXUNITTEST_H_ 

#include <limits>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include "Matrix.hpp"
using namespace std; 

class myMatrixFuction: public MatrixFuction{
	public:
	 double f(double num){
		return num*10;
	}
    virtual ~myMatrixFuction(){
    }
};

class MatrixUnitTest {
	public :
	void testMatrixUnit(){
		// test Equal
		testMatrixEqual();
		// test constructor
		testMatrixC1();
		testMatrixC2();
		testMatrixC3();
		testMatrixC4();
		testMatrixC5();
		// test Fill
		testMatrixFill();
		//test Scalar 
		testMatrixScalarR();
		testMatrixScalarAssignVal();
		testMatrixScalarAssignMat();
		testMatrixScalarL();
		// test Multiplication
		testMatrixMultiplication();
		// test Sub
		testMatrixSubL();
		testMatrixSubAssignVal();
		testMatrixSubAssignMat();
		testMatrixSubR();
		testMatrixSubMat();
		// test Sum
		testMatrixSumL();
		testMatrixSumAssignVal();
		testMatrixSumAssignMat();
		testMatrixSumR();
		testMatrixSumMat();
		// test Trans
		testMatrixT();
		// test Mapping Fuction
		testMatrixF();
		// test Hadamard Product
		testMatrixHadamardProduct();
		// test Is SymmetricMatrix
		testMatrixIsSymmetricMatrix();
		// test Table Product
		testMatrixTableProduct();
	}
	private:
	// test Equal
	void testMatrixEqual();
	// test constructor
	void testMatrixC1();
	void testMatrixC2();
	void testMatrixC3();
	void testMatrixC4();
	void testMatrixC5();
	// test Fill
	void testMatrixFill();
	// test Scalar 
	void testMatrixScalarR();
	void testMatrixScalarAssignVal();
	void testMatrixScalarAssignMat();
	void testMatrixScalarL();
	// test Multiplication
	void testMatrixMultiplication();
	// test Sub
	void testMatrixSubL();
	void testMatrixSubAssignVal();
	void testMatrixSubAssignMat();
	void testMatrixSubR();
	void testMatrixSubMat();
	// test Sum
	void testMatrixSumL();
	void testMatrixSumAssignVal();
	void testMatrixSumAssignMat();
	void testMatrixSumR();
	void testMatrixSumMat();
	// test Trans
	void testMatrixT();
	// test Mapping Fuction
	void testMatrixF();
	// test Hadamard Product
	void testMatrixHadamardProduct();
	// test Is SymmetricMatrix
	void testMatrixIsSymmetricMatrix();
	// test Table Product
	void testMatrixTableProduct();
};

#endif // HELLO_H_
