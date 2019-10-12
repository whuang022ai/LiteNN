/***************************************************************************
 *
 * TrainDataFactory.hpp
 *
 * This is a  header of TrainDataFactory  Class
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

#ifndef TRAINDATAFACTORY_H_ /* Include guard */
#define TRAINDATAFACTORY_H_

#include "Matrix.hpp"

using namespace std;
class trainSample {
 public:
  trainSample() {}
  Matrix *X;
  Matrix *Y;
};

class TrainDataFactory {
 public:
  vector<trainSample> genANDTrainList() const;
  vector<trainSample> genORTrainList() const;
  vector<trainSample> genXORTrainList() const;
};

#endif  // TRAINDATAFACTORY_H_
