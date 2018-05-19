/***************************************************************************
*
*  Perceptron.cpp
*  
*
*
* This is a  Perceptron Class implement
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
 
#include "Matrix.hpp"
#include "Perceptron.hpp"

using namespace std; 

Perceptron::Perceptron(MatrixFuction *activation,MatrixFuction *activationDiv,int inputDim,double learningRate){
	
	this->activation=activation;
	this->activationDiv=activationDiv;
	this->learningRate=learningRate;
	WIO=new Matrix(1,inputDim+1,MatrixType::StandardNormal01M);
}

void Perceptron::trainStepSGD(Matrix &X,Matrix &D){
	
	//Forward Path
    cout << "Input:";
    X.print();
	Matrix Sum=*WIO*X; //get w*x+b
	Sum.setMatrixFuction(activation); //set activation fuction
	Matrix NetO=Sum.F();//get net output
	NetO.setMatrixFuction(activationDiv);//set activation fuction div
    cout << "Output:";
    NetO.print();
    cout << "DesireOut:";
    D.print();
	//BackWard Path
	Matrix dNetO=NetO.F();//get the dNetO
	Matrix E=D-NetO;//get error
	Matrix dWIO=-1*E*dNetO<<X.T();//get weight gradient = Output Layer gradient (Table Product) Input Layer Trans
	*WIO-=learningRate*dWIO;//update weight with the opposite of the gradient vector
	E.print();
}

