/***************************************************************************
*
*  NeuralNetThreeLayer.hpp
*  
*
*
* This is a  Three Layer  Neural Network Class header 
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
 
#ifndef NEURALNETTHREELAYER_H_   /* Include guard */
#define NEURALNETTHREELAYER_H_ 

#include "Matrix.hpp"

using namespace std; 

class NeuralNetThreeLayer{
	
	public :	
	NeuralNetThreeLayer(MatrixFuction *activation,MatrixFuction *activationDiv,int inputDim,int hiddenDim,int outputDim,double learningRate);
	void trainStepSGD(Matrix &X, Matrix &D);
	void train(Matrix &X, Matrix &D);
    void userTest();
	private:
	MatrixFuction *activation;
	MatrixFuction *activationDiv;
	Matrix *WIH;//weight Input-Hidden
	Matrix *WHO;//weight Hidden-Output
	int inputDim  =0;
	int hiddenDim =0;
	int outputDim =0;
	double learningRate=0.5;
    void testForward(Matrix &X);
};

#endif // HELLO_H_
