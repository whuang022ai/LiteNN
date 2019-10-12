#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include "Matrix.hpp"
#include "MatrixUnitTest.hpp"
#include "NeuralNetThreeLayer.hpp"
#include "Perceptron.hpp"
#include "TrainDataFactory.hpp"

using namespace std;

class sigmoid : public MatrixFuction {
 public:
  double f(double num) { return 1 / (1 + exp(-num)); }
  virtual ~sigmoid() {}
};

class sigmoidDiv : public MatrixFuction {
 public:
  double f(double num) { return num * (1 - num); }
  virtual ~sigmoidDiv() {}
};

void Perceptron_AND_SGD() {
  // generate traing data of AND
  TrainDataFactory *f = new TrainDataFactory();
  vector<trainSample> trainList = f->genANDTrainList();
  // setting activation
  std::shared_ptr<MatrixFuction> activation = std::make_shared<sigmoid>();
  std::shared_ptr<MatrixFuction> activationDiv = std::make_shared<sigmoidDiv>();
  // new Perceptron
  Perceptron *neural = new Perceptron(activation, activationDiv, 2, 0.7);
  // learning loop
  for (int i = 0; i < 1000; i++) {
    std::random_shuffle(trainList.begin(), trainList.end());
    for (int j = 0; j < trainList.size(); j++) {
      neural->trainStepSGD(*trainList[j].X, *trainList[j].Y);
    }
  }
  //
}

void Perceptron_OR_SGD() {
  // generate traing data of OR
  TrainDataFactory *f = new TrainDataFactory();
  vector<trainSample> trainList = f->genORTrainList();
  // setting activation
  std::shared_ptr<MatrixFuction> activation = std::make_shared<sigmoid>();
  std::shared_ptr<MatrixFuction> activationDiv = std::make_shared<sigmoidDiv>();
  // new Perceptron
  Perceptron *neural = new Perceptron(activation, activationDiv, 2, 0.7);
  // learning loop
  for (int i = 0; i < 1000; i++) {
    std::random_shuffle(trainList.begin(), trainList.end());
    for (int j = 0; j < trainList.size(); j++) {
      neural->trainStepSGD(*trainList[j].X, *trainList[j].Y);
    }
  }
  //
}

void Perceptron_XOR_SGD() {
  // generate traing data of OR
  TrainDataFactory *f = new TrainDataFactory();
  vector<trainSample> trainList = f->genXORTrainList();
  // setting activation
  std::shared_ptr<MatrixFuction> activation = std::make_shared<sigmoid>();
  std::shared_ptr<MatrixFuction> activationDiv = std::make_shared<sigmoidDiv>();
  // new Perceptron
  Perceptron *neural = new Perceptron(activation, activationDiv, 2, 0.7);
  // learning loop
  for (int i = 0; i < 1000; i++) {
    std::random_shuffle(trainList.begin(), trainList.end());
    for (int j = 0; j < trainList.size(); j++) {
      neural->trainStepSGD(*trainList[j].X, *trainList[j].Y);
    }
  }
  //
}

void NeuralNetThreeLayer_XOR_SGD() {
  // generate traing data of OR
  TrainDataFactory *f = new TrainDataFactory();
  vector<trainSample> trainList = f->genXORTrainList();
  // setting activation
  // MatrixFuction *activation=new sigmoid();
  std::shared_ptr<MatrixFuction> activation = std::make_shared<sigmoid>();
  std::shared_ptr<MatrixFuction> activationDiv = std::make_shared<sigmoidDiv>();
  // new NeuralNetThreeLayer
  NeuralNetThreeLayer *neural =
      new NeuralNetThreeLayer(activation, activationDiv, 2, 2, 1, 0.3);
  // learning loop
  for (int i = 0; i < 5000; i++) {
    std::random_shuffle(trainList.begin(), trainList.end());
    for (int j = 0; j < trainList.size(); j++) {
      neural->trainStepSGD(*trainList[j].X, *trainList[j].Y);
    }
  }
  // user testing
  neural->userTest();
  delete neural;
  neural = nullptr;
  trainList.clear();
  trainList.shrink_to_fit();
  cin.get();
}

void unitTest() {
  cout << "Testing...\n";
  MatrixUnitTest mTest;
  mTest.testMatrixUnit();
  cout << "Passed Matrix Unit Test.\n";
}

int main(int argc, char *argv[]) {
  // unitTest();
  // Perceptron_OR_SGD();
  NeuralNetThreeLayer_XOR_SGD();
}
