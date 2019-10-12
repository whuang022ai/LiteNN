/***************************************************************************
 *
 *  Perceptron.hpp
 *
 *
 *
 * This is a  Perceptron Class header
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

#ifndef PERCEPTRON_H_ /* Include guard */
#define PERCEPTRON_H_

#include "Matrix.hpp"

using namespace std;

class Perceptron {
 public:
  Perceptron(std::shared_ptr<MatrixFuction> activation,
             std::shared_ptr<MatrixFuction> activationDiv, int inputDim,
             double learningRate);
  void trainStepSGD(Matrix &X, Matrix &D);
  void train(Matrix &X, Matrix &D);

 private:
  std::shared_ptr<MatrixFuction> activation;
  std::shared_ptr<MatrixFuction> activationDiv;
  Matrix *WIO;  // weight Input-Output
  double learningRate = 0.5;
};

#endif  // HELLO_H_
