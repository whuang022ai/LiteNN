/***************************************************************************
*
*  NeuralNetThreeLayer.cpp
*  
*
*
* This is a NeuralNetThreeLayer Class implement
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
#include "NeuralNetThreeLayer.hpp"

using namespace std; 

NeuralNetThreeLayer::NeuralNetThreeLayer(MatrixFuction *activation,MatrixFuction *activationDiv,int inputDim,int hiddenDim,int outputDim,double learningRate){
	this->inputDim  =inputDim;
	this->hiddenDim =hiddenDim;
	this->outputDim =outputDim;
	this->activation=activation;
	this->activationDiv=activationDiv;
	this->learningRate=learningRate;
	WIH=new Matrix(hiddenDim,inputDim +1,MatrixType::StandardNormal01M);
	WHO=new Matrix(outputDim,hiddenDim+1,MatrixType::StandardNormal01M);
}
NeuralNetThreeLayer::~NeuralNetThreeLayer(){
    delete WIH;
    delete WHO;
    delete activation;
    delete activationDiv;
}
void NeuralNetThreeLayer::userTest(){
    while(true){
        cout << "Test Neural Net \n";
        Matrix input(inputDim+1, 1,1);
        for(int i=0;i<inputDim;i++){
            cout << "Input X"<<i<<":";
            double d=0;
            cin >> d;
            input.set(i, 0, d);
        }
        testForward(input);
        cout << "Enter 0 to end ,1 to keep testing.\n";
        int c=0;
        cin>>c;
        if(!c){
            break;
        }
    }
}
void NeuralNetThreeLayer::testForward(Matrix &X){
    Matrix SumH=*WIH*X; //get w*x+b
    SumH.setMatrixFuction(activation); //set activation fuction
    Matrix NetH=SumH.F();//get net hidden
    NetH.setMatrixFuction(activationDiv);//set activation fuction div
    NetH.argRow();//add the bias of Hidden to Output
    Matrix dNetH=NetH.F();//get the dNetH
    //Hidden- Output
    Matrix SumO=*WHO*NetH; //get w*x+b
    SumO.setMatrixFuction(activation); //set activation fuction
    Matrix NetO=SumO.F();//get net output
    cout << "Output:";
    NetO.print();
}
void NeuralNetThreeLayer::trainStepSGD(Matrix &X,Matrix &D){
	
	//Forward Path
	cout << "Input:";
	X.print();
	//Input - Hidden
	Matrix SumH=*WIH*X; //get w*x+b
	SumH.setMatrixFuction(activation); //set activation fuction
	Matrix NetH=SumH.F();//get net hidden
	NetH.setMatrixFuction(activationDiv);//set activation fuction div
	NetH.argRow();//add the bias of Hidden to Output
	Matrix dNetH=NetH.F();//get the dNetH
	//Hidden- Output
	
	Matrix SumO=*WHO*NetH; //get w*x+b
	SumO.setMatrixFuction(activation); //set activation fuction
	Matrix NetO=SumO.F();//get net output
	
	cout << "Output:";
	NetO.print();
	cout << "DesireOut:";
	D.print();
	NetO.setMatrixFuction(activationDiv);//set activation fuction div
	Matrix dNetO=NetO.F();//get the dNetO
	
	//BackWard Path
	Matrix E=D-NetO;//get error
	Matrix dO=-1*E>>dNetO;//get Output Layer gradient = -1 * Output active div (Hadamard Product) Error
	//
    Matrix dWHO=dO<<NetH.T();// get WeightHO gradient = Output Layer gradient (Table Product) Hidden Layer Trans
    Matrix dH=dNetH>>(WHO->T()*dO);//get Hidden Layer gradient = Hidden active div (Hadamard Product) { WeightHO trans dot Output Layer gradient}
    Matrix dWIH=dH<<X.T();//get WeightIH gradient = Hidden Layer gradient  (Table Product) Input Layer Trans
	
	*WHO-=learningRate*dWHO;//update weight with the opposite of the gradient vector
	*WIH-=learningRate*dWIH;//update weight with the opposite of the gradient vector
    
	E.print();
    
}

