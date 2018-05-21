/***************************************************************************
*
* MatrixUnitTest.cpp
*
* This is a  unit test file to test Matrix Class
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
 



#include <limits>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include "Matrix.hpp"
#include "MatrixUnitTest.hpp"
 
class myMatrixFuctionUnitTest: public MatrixFuction{
	public:
	double f(double num){
		return num*10;
	}
    virtual ~myMatrixFuctionUnitTest(){
    }
};

// TEST Target : 
// bool operator == (const Matrix& a, const Matrix& b); 
void MatrixUnitTest::testMatrixEqual(){
	Matrix *testA =new Matrix(5,5,1);
	Matrix *testB =new Matrix(5,5,1);
	Matrix *testC =new Matrix(5,5,1);
	testC->set(3,3,1.01);
	assert((*testA==*testB));
	assert(!(*testA==*testC));
	delete testA;
	delete testB;
	delete testC;
	testA=nullptr;
	testB=nullptr;
	testC=nullptr;
}

// TEST Target : 
// Matrix(int, int);
void MatrixUnitTest::testMatrixC1(){
	Matrix *testA =new Matrix(2,2);
	assert(almost_equal(testA->get(0,0),0.0));
	assert(almost_equal(testA->get(0,1),0.0));
	assert(almost_equal(testA->get(1,0),0.0));
	assert(almost_equal(testA->get(1,1),0.0));
	assert(testA->rowSize()==2);
	assert(testA->colSize()==2);
	delete testA;
	testA=nullptr;
}

// TEST Target : 
// Matrix(int rowsN, int colsN,double value);
void MatrixUnitTest::testMatrixC2(){
	Matrix *testA =new Matrix(2,3,0.1);
	assert(almost_equal(testA->get(0,0),0.1));
	assert(almost_equal(testA->get(0,1),0.1));
	assert(almost_equal(testA->get(0,2),0.1));
	assert(almost_equal(testA->get(1,0),0.1));
	assert(almost_equal(testA->get(1,1),0.1));
	assert(almost_equal(testA->get(1,2),0.1));
	assert(testA->rowSize()==2);
	assert(testA->colSize()==3);
	delete testA;
	testA=nullptr;
}

// TEST Target : 
// Matrix(const Matrix& m);
void MatrixUnitTest::testMatrixC3(){
	Matrix *testA =new Matrix(2,3,1);
	Matrix *testB =new Matrix(*testA);
	assert((*testA==*testB));
	assert(!(testA==testB));
	delete testA;
	delete testB;
	testA=nullptr;
	testB=nullptr;
}

// TEST Target : 
// Matrix(int,int, const MatrixType &p);
void MatrixUnitTest::testMatrixC4(){
	
	// TEST Target :
	// MatrixType::ZeroM
	Matrix *testA =new Matrix(2,3,MatrixType::ZeroM);
	Matrix *testB =new Matrix(2,3,0);
	assert((*testA==*testB));
	delete testA;
	delete testB;
	
	// TEST Target :
	// MatrixType::OneM
	testA =new Matrix(2,3,MatrixType::OneM);
	testB =new Matrix(2,3,1);
	assert((*testA==*testB));
	delete testA;
	delete testB;
	
	// TEST Target :
	// MatrixType::IdentityM
	testA =new Matrix(2,2,MatrixType::IdentityM);
	testB =new Matrix(2,2,0);
	testB->set(0,0,1);
	testB->set(1,1,1);
	assert((*testA==*testB));
	delete testA;
	delete testB;
	
	// TEST Target :
	// MatrixType::StandardNormal01M
	testA =new Matrix(2,2,MatrixType::StandardNormal01M);
	assert((testA->get(0,0)>0)&&(testA->get(0,0)<1));
	assert((testA->get(0,0)>0)&&(testA->get(0,1)<1));
	assert((testA->get(0,0)>0)&&(testA->get(1,0)<1));
	assert((testA->get(0,0)>0)&&(testA->get(1,1)<1));
	delete testA;
	
	testA=nullptr;
	testB=nullptr;
}

// TEST Target : 
// Matrix(int rowsN, int colsN,double value);
void MatrixUnitTest::testMatrixC5(){
    // Windows devc++ user path :MatrixUnitTest.txt
    // MacOS  Xcode user path: use full path like
    // /Users/minghanyang/Desktop/LiteNN/LiteNN/MatrixUnitTest.txt
	Matrix *testA =new Matrix("./MatrixUnitTest.txt");
	assert(almost_equal(testA->get(0,0),4.0));
	assert(almost_equal(testA->get(0,1),0.8));
	assert(almost_equal(testA->get(1,0),4.1));
	assert(almost_equal(testA->get(1,1),0.7));
	assert(almost_equal(testA->get(2,0),4.4));
	assert(almost_equal(testA->get(2,1),1.1));
	assert(almost_equal(testA->get(3,0),3.9));
	assert(almost_equal(testA->get(3,1),1.2));
	assert(almost_equal(testA->get(4,0),4.0));
	assert(almost_equal(testA->get(4,1),1.0));
	assert(testA->rowSize()==5);
	assert(testA->colSize()==2);
	delete testA;
	testA=nullptr;
}

// TEST Target : 
// void fill(double );
void MatrixUnitTest::testMatrixFill(){
	Matrix *testA =new Matrix(3,3,0);
	Matrix *testB =new Matrix(3,3,1);
	testA->fill(1);
	assert((*testA==*testB));
	delete testA;
	delete testB;
	testA=nullptr;
	testB=nullptr;
}

// TEST Target : 
// Matrix operator*(const Matrix& a,double num);
void MatrixUnitTest::testMatrixScalarR(){
	Matrix *testAa =new Matrix(3,3,2.4);
	Matrix *testA =new Matrix(3,3,2.4);
	Matrix *testB =new Matrix(3,3,19.2);
	Matrix  testC =(*testA)*2*4;
	assert((testC==*testB));
	assert((*testA==*testAa));
	delete testA;
	delete testB;
	testA=nullptr;
	testB=nullptr;
}

// TEST Target : 
// Matrix & operator*=( double const & p) ;
void MatrixUnitTest::testMatrixScalarAssignVal(){
	Matrix *testA =new Matrix(3,3,2.4);
	Matrix *testB =new Matrix(3,3,19.2);
	(*testA)*=8.0;
	assert((*testA==*testB));
	delete testA;
	delete testB;
	testA=nullptr;
	testB=nullptr;
}

// TEST Target : 
// Matrix & operator*=( Matrix const & p) ;
void MatrixUnitTest::testMatrixScalarAssignMat(){
	Matrix *testA =new Matrix(3,3,2.0);
	Matrix *testC =new Matrix(3,3,0.5);
	Matrix *testB =new Matrix(3,3,1.0);
	(*testA)*=(*testC);
	assert((*testA==*testB));
	delete testA;
	delete testB;
	testA=nullptr;
	testB=nullptr;
}

// TEST Target : 
// Matrix operator*(double num,  const Matrix& a);
void MatrixUnitTest::testMatrixScalarL(){
	Matrix *testAa =new Matrix(3,3,2.4);
	Matrix *testA =new Matrix(3,3,2.4);
	Matrix *testB =new Matrix(3,3,19.2);
	Matrix  testC =2.0*4.0*(*testA);
	assert((testC==*testB));
	assert((*testA==*testAa));
	delete testA;
	delete testAa;
	delete testB;
	testA=nullptr;
	testB=nullptr;
	testAa=nullptr;
}

// TEST Target : 
// Matrix operator*(const Matrix& a, const Matrix& b); 
void MatrixUnitTest::testMatrixMultiplication(){
	
	/*	
		Matrix Multiplication (Inner  Product)
		---------------------------------------	
			M2*3	*	M3*2	=	M2*2
		---------------------------------------
			1 3 5		1	4		22	49
					*   2	5	=	
			2 4 6		3	6		28	64
	
	*/
	
	Matrix *test =new Matrix(2,3);
	test->set(0,0,1); test->set(0,1,3); test->set(0,2,5);
	test->set(1,0,2); test->set(1,1,4); test->set(1,2,6);
	
	Matrix *test2 =new Matrix(3,2);
	test2->set(0,0,1); test2->set(0,1,4);
	test2->set(1,0,2); test2->set(1,1,5);
	test2->set(2,0,3); test2->set(2,1,6);
	Matrix test3=(*test)*(*test2);
	
	Matrix *test4 =new Matrix(2,2);
	test4->set(0,0,22); test4->set(0,1,49);
	test4->set(1,0,28); test4->set(1,1,64);
	
	assert((test3==*test4));
	
	delete test;
	delete test2;
	delete test4;
	test=nullptr;
	test2=nullptr;
	test4=nullptr;
}


// TEST Target : 
// Matrix operator-(double num, const Matrix& a);
void MatrixUnitTest::testMatrixSubL(){
	Matrix *testAa =new Matrix(3,3,2.4);
	Matrix *testA =new Matrix(3,3,2.4);
	Matrix *testB =new Matrix(3,3,2.6);
	Matrix  testC =5-(*testA);
	assert((testC==*testB));
	assert((*testA==*testAa));
	delete testAa;
	delete testA;
	delete testB;
	testA=nullptr;
	testB=nullptr;
	testAa=nullptr;
}

// TEST Target : 
// Matrix & operator-=( double const & p) ;
void MatrixUnitTest::testMatrixSubAssignVal(){
	Matrix *testA =new Matrix(3,3,2.4);
	Matrix *testB =new Matrix(3,3,1.3);
	(*testA)-=1.1;
	assert((*testA==*testB));
	delete testA;
	delete testB;
	testA=nullptr;
	testB=nullptr;
}

// TEST Target : 
// Matrix & operator-=( Matrix const & p) ;
void MatrixUnitTest::testMatrixSubAssignMat(){
	Matrix *testA =new Matrix(3,3,2.4);
	Matrix *testC =new Matrix(3,3,1.1);
	Matrix *testB =new Matrix(3,3,1.3);
	(*testA)-=(*testC);
	assert((*testA==*testB));
	delete testA;
	delete testC;
	delete testB;
	testA=nullptr;
	testB=nullptr;
	testC=nullptr;
}

// TEST Target : 
// Matrix operator-(const Matrix& a ,double num);
void MatrixUnitTest::testMatrixSubR(){
	Matrix *testAa =new Matrix(3,3,2.4);
	Matrix *testA =new Matrix(3,3,2.4);
	Matrix *testB =new Matrix(3,3,-2.6);
	Matrix  testC =(*testA-5);
	assert((testC==*testB));
	assert((*testA==*testAa));
	delete testA;
	delete testB;
	testA=nullptr;
	testB=nullptr;
}

// TEST Target : 
// Matrix operator-(const Matrix& a, const Matrix& b);
void MatrixUnitTest::testMatrixSubMat(){
	Matrix *testAa =new Matrix(3,3,2.4);
	Matrix *testA =new Matrix(3,3,2.4);
	Matrix *testB =new Matrix(3,3,-2.6);
	Matrix *testD =new Matrix(3,3,5);
	Matrix  testC =(*testA)-(*testD);
	assert((testC==*testB));
	assert((*testA==*testAa));
	delete testAa;
	delete testA;
	delete testB;
	delete testD;
	testAa=nullptr;
	testA=nullptr;
	testB=nullptr;
	testD=nullptr;
}

// TEST Target : 
// Matrix operator+(double num, const Matrix& a);
void MatrixUnitTest::testMatrixSumL(){
	Matrix *testAa =new Matrix(3,3,2.4);
	Matrix *testA =new Matrix(3,3,2.4);
	Matrix *testB =new Matrix(3,3,7.4);
	Matrix  testC =5+(*testA);
	assert((testC==*testB));
	assert((*testA==*testAa));
	delete testAa;
	delete testA;
	delete testB;
	testA=nullptr;
	testB=nullptr;
	testAa=nullptr;
}

// TEST Target : 
// Matrix & operator+=( double const & p) ;
void MatrixUnitTest::testMatrixSumAssignVal(){
	Matrix *testA =new Matrix(3,3,2.4);
	Matrix *testB =new Matrix(3,3,3.5);
	(*testA)+=1.1;
	assert((*testA==*testB));
	delete testA;
	delete testB;
	testA=nullptr;
	testB=nullptr;
}

// TEST Target : 
// Matrix & operator+=( Matrix const & p) ;
void MatrixUnitTest::testMatrixSumAssignMat(){
	Matrix *testA =new Matrix(3,3,2.4);
	Matrix *testC =new Matrix(3,3,1.1);
	Matrix *testB =new Matrix(3,3,3.5);
	(*testA)+=(*testC);
	assert((*testA==*testB));
	delete testA;
	delete testC;
	delete testB;
	testA=nullptr;
	testB=nullptr;
	testC=nullptr;
}

// TEST Target : 
// Matrix operator+(const Matrix& a ,double num);
void MatrixUnitTest::testMatrixSumR(){
	Matrix *testAa =new Matrix(3,3,2.4);
	Matrix *testA =new Matrix(3,3,2.4);
	Matrix *testB =new Matrix(3,3,7.4);
	Matrix  testC =(*testA)+5;
	assert((testC==*testB));
	assert((*testA==*testAa));
	delete testA;
	delete testB;
	testA=nullptr;
	testB=nullptr;
}

// TEST Target : 
// Matrix operator+(const Matrix& a, const Matrix& b);
void MatrixUnitTest::testMatrixSumMat(){
	Matrix *testAa =new Matrix(3,3,2.4);
	Matrix *testA =new Matrix(3,3,2.4);
	Matrix *testB =new Matrix(3,3,7.4);
	Matrix *testD =new Matrix(3,3,5);
	Matrix  testC =(*testA)+(*testD);
	assert((testC==*testB));
	assert((*testA==*testAa));
	delete testAa;
	delete testA;
	delete testB;
	delete testD;
	testAa=nullptr;
	testA=nullptr;
	testB=nullptr;
	testD=nullptr;
}

// TEST Target : 
// Matrix T ();
void MatrixUnitTest::testMatrixT(){
	Matrix *testAa =new Matrix(3,2,2.4);
	Matrix *testA =new Matrix(3,2,2.4);
	Matrix *testB =new Matrix(2,3,2.4);
	Matrix  testC =(*testA).T();
	assert((testC==*testB));
	assert((*testA==*testAa));
	delete testAa;
	delete testA;
	delete testB;
	testAa=nullptr;
	testA=nullptr;
	testB=nullptr;
}

// TEST Target : 
// Matrix F ();
void MatrixUnitTest::testMatrixF(){
	Matrix *testAa =new Matrix(3,2,2.4);
	Matrix *testA =new Matrix(3,2,2.4);
	Matrix *testB =new Matrix(3,2,24);
	MatrixFuction *f=new myMatrixFuctionUnitTest();
	(*testA).setMatrixFuction(f);
	Matrix  testC =(*testA).F();
	assert((testC==*testB));
	assert((*testA==*testAa));
	delete testAa;
	delete testA;
	delete testB;
	testAa=nullptr;
	testA=nullptr;
	testB=nullptr;
	f=nullptr;
	
}

// TEST Target : 
// Matrix operator >> (const Matrix& a, const Matrix& b);
void MatrixUnitTest::testMatrixHadamardProduct(){
			
	/*	
				Matrix Hadamard Product
		---------------------------------------	
			M2*3	*	M2*3	=	 M2*3
		---------------------------------------
			
			1 3 5		1 4 3		1 12 15
					*   		=	
			2 4 6		2 6 5		4 24 30
			

	*/

	Matrix *test =new Matrix(2,3);
	test->set(0,0,1); test->set(0,1,3); test->set(0,2,5);
	test->set(1,0,2); test->set(1,1,4); test->set(1,2,6);

	Matrix *test2 =new Matrix(2,3);
	test2->set(0,0,1); test2->set(0,1,4); test2->set(0,2,3);
	test2->set(1,0,2); test2->set(1,1,6); test2->set(1,2,5);

	Matrix test3=(*test)>>(*test2);

	Matrix *test4 =new Matrix(2,3);
	test4->set(0,0,1); test4->set(0,1,12); test4->set(0,2,15);
	test4->set(1,0,4); test4->set(1,1,24); test4->set(1,2,30);

	assert((test3==*test4));

	delete test;
	delete test2;
	delete test4;
	test=nullptr;
	test2=nullptr;
	test4=nullptr;
}

// TEST Target : 
// Matrix operator << (const Matrix& a, const Matrix& b);
void MatrixUnitTest::testMatrixTableProduct(){
			
	/*	
				Matrix Table Product
		---------------------------------------	
				   M1*3
		---------------------------------------
			    4   5   6
			   
			3  12  15  18
				
			2  8   10  12
			
		  M2*1 
	*/
	Matrix *test =new Matrix(2,1);
	test->set(0,0,3); 
	test->set(1,0,2);
	Matrix *test2 =new Matrix(1,3);
	test2->set(0,0,4); test2->set(0,1,5); test2->set(0,2,6);
	Matrix test3=(*test)<<(*test2);
	Matrix *test4 =new Matrix(2,3);
	test4->set(0,0,12); test4->set(0,1,15); test4->set(0,2,18);
	test4->set(1,0,8); test4->set(1,1,10); test4->set(1,2,12);
	assert((test3==*test4));
	delete test;
	delete test2;
	delete test4;
	test=nullptr;
	test2=nullptr;
	test4=nullptr;
}

// TEST Target : 
// bool Matrix::isSymmetricMatrix()
void MatrixUnitTest::testMatrixIsSymmetricMatrix(){
	Matrix *test =new Matrix(3,3,MatrixType::IdentityM);
	assert((test)->isSymmetricMatrix());
	delete test;
	test=nullptr;
}
