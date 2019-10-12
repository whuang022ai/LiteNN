/***************************************************************************
 *
 * Matrix.cpp
 *
 * This is an  cpp file to implement a basic Matrix Class
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
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#define DOUBLE_SIZE 2  // control print matrix double digit size
using namespace std;
/// row=up-down dir size , cols=left-right dir size

class defaultMatrixFuction : public MatrixFuction {
 public:
  double f(double num) { return num; }
  virtual ~defaultMatrixFuction() {}
};

Matrix::Matrix(int rowsN, int colsN) {
  rows = new int(rowsN);
  cols = new int(colsN);
  mat.resize(rowsN);
  for (int i = 0; i < rowsN; i++) mat[i].resize(colsN);
  std::shared_ptr<MatrixFuction> f = std::make_shared<defaultMatrixFuction>();
  this->setMatrixFuction(f);
}

Matrix::Matrix(int rowsN, int colsN, double value) {
  rows = new int(rowsN);
  cols = new int(colsN);
  for (int i = 0; i < *rows; i++) {
    vector<double> vec(*cols, value);
    mat.push_back(vec);
  }
  std::shared_ptr<MatrixFuction> f = std::make_shared<defaultMatrixFuction>();
  this->setMatrixFuction(f);
}

Matrix::Matrix(const Matrix& m) {
  rows = new int(m.rowSize());
  cols = new int(m.colSize());
  mat.resize(m.rowSize());
  for (int i = 0; i < m.rowSize(); i++) mat[i].resize(m.colSize());

  for (int i = 0; i < m.rowSize(); i++) {
    for (int j = 0; j < m.colSize(); j++) {
      mat[i][j] = m.get(i, j);
    }
  }
  std::shared_ptr<MatrixFuction> f = std::make_shared<defaultMatrixFuction>();
  this->setMatrixFuction(f);
}

Matrix::Matrix(const string& dataPath) {
  ifstream in(dataPath);
  string record;
  while (getline(in, record)) {
    istringstream is(record);
    vector<double> row((istream_iterator<double>(is)),
                       istream_iterator<double>());
    mat.push_back(row);
  }
  rows = new int((int)mat.size());
  cols = new int((int)mat[0].size());
  std::shared_ptr<MatrixFuction> f = std::make_shared<defaultMatrixFuction>();
  this->setMatrixFuction(f);
}

Matrix::Matrix(int rowsN, int colsN, const MatrixType& p) {
  switch (p) {
    case MatrixType::OneM: {
      rows = new int(rowsN);
      cols = new int(colsN);
      for (int i = 0; i < rowsN; i++) {
        vector<double> vec(colsN, 1.0);
        mat.push_back(vec);
      }
      std::shared_ptr<MatrixFuction> f =
          std::make_shared<defaultMatrixFuction>();
      this->setMatrixFuction(f);
    } break;
    case MatrixType::ZeroM: {
      rows = new int(rowsN);
      cols = new int(colsN);
      for (int i = 0; i < rowsN; i++) {
        vector<double> vec(colsN, 0.0);
        mat.push_back(vec);
      }
      std::shared_ptr<MatrixFuction> f =
          std::make_shared<defaultMatrixFuction>();
      this->setMatrixFuction(f);
    } break;
    case MatrixType::IdentityM: {
      rows = new int(rowsN);
      cols = new int(colsN);
      if (isSquareMatrix()) {
        for (int i = 0; i < rowsN; i++) {
          vector<double> vec(colsN, 0.0);
          vec[i] = 1;
          mat.push_back(vec);
        }
        std::shared_ptr<MatrixFuction> f =
            std::make_shared<defaultMatrixFuction>();
        this->setMatrixFuction(f);
      } else {
        for (int i = 0; i < rowsN; i++) {
          vector<double> vec(colsN, 0.0);
          mat.push_back(vec);
        }
        std::shared_ptr<MatrixFuction> f =
            std::make_shared<defaultMatrixFuction>();
        this->setMatrixFuction(f);
        throw std::invalid_argument("Identity Matrix must be Square Matrix.");
      }
      std::shared_ptr<MatrixFuction> f =
          std::make_shared<defaultMatrixFuction>();
      this->setMatrixFuction(f);
    } break;
    case MatrixType::StandardNormal01M: {
      mt19937 gen = mt19937(static_cast<unsigned int>(time(NULL)));
      uniform_real_distribution<double> unif(0.0, 1.0);
      auto randfun = bind(unif, gen);
      rows = new int(rowsN);
      cols = new int(colsN);
      for (int i = 0; i < rowsN; i++) {
        vector<double> vec(colsN, randfun());
        mat.push_back(vec);
      }
      std::shared_ptr<MatrixFuction> f =
          std::make_shared<defaultMatrixFuction>();
      this->setMatrixFuction(f);
    } break;
    default: {
      std::shared_ptr<MatrixFuction> f =
          std::make_shared<defaultMatrixFuction>();
      this->setMatrixFuction(f);
      throw invalid_argument("Unimplemented Matrix type");
      break;
    }
  }
}

Matrix::~Matrix() {
  // delete rows;
  // delete cols;
  mat.clear();
  vector<vector<double> > tmp;
  mat.swap(tmp);

  rows = nullptr;
  cols = nullptr;
  // delete MF;
  MF = nullptr;
}

int Matrix::rowSize() const { return int(*rows); }

int Matrix::colSize() const { return int(*cols); }

void Matrix::print() {
  cout << "\n";
  vector<vector<double> >::iterator iterR = mat.begin();
  while (iterR != mat.end()) {
    vector<double>::iterator iter = (*iterR).begin();
    while (iter != (*iterR).end()) {
      cout << setiosflags(ios::fixed) << setprecision(DOUBLE_SIZE) << *iter
           << " ";
      iter++;
    }
    cout << "\n";
    iterR++;
  }
}

void Matrix::fill(double element) {
  for (int i = 0; i < *rows; i++) {
    for (int j = 0; j < *cols; j++) {
      mat[i][j] = element;
    }
  }
}

Matrix Matrix::T() {
  Matrix trans(*cols, *rows);
  for (int i = 0; i < *rows; i++) {
    for (int j = 0; j < *cols; j++) {
      trans.mat[j][i] = mat[i][j];
    }
  }
  return trans;
}

Matrix Matrix::F() {
  Matrix trans(*rows, *cols);
  for (int i = 0; i < *rows; i++) {
    for (int j = 0; j < *cols; j++) {
      trans.set(i, j, MF->f(mat[i][j]));
    }
  }
  return trans;
}

void Matrix::setMatrixFuction(std::shared_ptr<MatrixFuction> p) { MF = p; }

bool Matrix::isSquareMatrix() {
  if (*rows == *cols)
    return true;
  else
    return false;
}

bool Matrix::isSymmetricMatrix() {
  if (*rows == *cols) {
    bool tmp = true;
    for (int i = 0; i < *rows; i++) {
      for (int j = 0; j < *cols; j++) {
        if (mat[i][j] != mat[j][i]) tmp = false;
        ;
      }
    }
    return tmp;
  }
  return false;
}

double Matrix::get(int row, int col) const {
  if (row >= 0 && row < *rows) {
    if (col >= 0 && col < *cols) {
      return mat[row][col];
    } else {
      throw out_of_range("Col Size out of boundary.");
    }
  } else {
    throw out_of_range("Row Size out of boundary.");
  }
  return 0.0;
}

void Matrix::set(int row, int col, double val) {
  if (row >= 0 && row < *rows) {
    if (col >= 0 && col < *cols) {
      mat[row][col] = val;
      return;
    } else {
      throw out_of_range("Col Size out of boundary.");
      return;
    }
  } else {
    throw out_of_range("Row Size out of boundary.");
    return;
  }
}

Matrix& Matrix::operator+=(Matrix const& p) {
  for (int i = 0; i < *rows; i++) {
    for (int j = 0; j < *cols; j++) {
      mat[i][j] += p.get(i, j);
    }
  }
  return *this;
}

Matrix& Matrix::operator+=(double const& p) {
  for (int i = 0; i < *rows; i++) {
    for (int j = 0; j < *cols; j++) {
      mat[i][j] += p;
    }
  }
  return *this;
}

Matrix& Matrix::operator-=(Matrix const& p) {
  for (int i = 0; i < *rows; i++) {
    for (int j = 0; j < *cols; j++) {
      mat[i][j] -= p.get(i, j);
    }
  }
  return *this;
}

Matrix& Matrix::operator-=(double const& p) {
  for (int i = 0; i < *rows; i++) {
    for (int j = 0; j < *cols; j++) {
      mat[i][j] -= p;
    }
  }
  return *this;
}

Matrix& Matrix::operator*=(double const& p) {
  for (int i = 0; i < *rows; i++) {
    for (int j = 0; j < *cols; j++) {
      mat[i][j] *= p;
    }
  }
  return *this;
}

Matrix& Matrix::operator*=(Matrix const& p) {
  for (int i = 0; i < *rows; i++) {
    for (int j = 0; j < *cols; j++) {
      mat[i][j] *= p.get(i, j);
    }
  }
  return *this;
}

void Matrix::argRow() {
  vector<double> vec(1, 1);
  mat.push_back(vec);
  *rows += 1;
}

bool isMatrixSameSize(const Matrix& a, const Matrix& b) {
  if (a.rowSize() == b.rowSize() && a.colSize() == b.colSize()) {
    return true;
  } else {
    return false;
  }
}

Matrix operator+(const Matrix& a, const Matrix& b) {
  if (isMatrixSameSize(a, b)) {
    Matrix temp(a);
    return temp += b;
  } else {
    throw invalid_argument("The Two Matrix Size not equal . Can not do Sum.");
  }
}

Matrix operator+(double num, const Matrix& a) {
  Matrix sum(a.rowSize(), a.colSize());
  for (int i = 0; i < a.rowSize(); i++) {
    for (int j = 0; j < a.colSize(); j++) {
      sum.set(i, j, a.get(i, j) + num);
    }
  }
  return sum;
}

Matrix operator+(const Matrix& a, double num) { return operator+(num, a); }

Matrix operator-(const Matrix& a, const Matrix& b) {
  if (isMatrixSameSize(a, b)) {
    Matrix temp(a);
    return temp -= b;
  } else {
    throw invalid_argument("The Two Matrix Size not equal . Can not do Sub.");
  }
}

Matrix operator*(const Matrix& a, const Matrix& b) {
  // This implementation has performance issue , only for demo
  // more info at https://ppt.cc/fRd91x
  if (a.colSize() == b.rowSize()) {
    Matrix dot(a.rowSize(), b.colSize());
    for (int i = 0; i < a.rowSize(); i++) {
      for (int j = 0; j < b.colSize(); j++) {
        for (int k = 0; k < a.colSize(); k++) {
          dot.set(i, j, dot.get(i, j) + a.get(i, k) * b.get(k, j));
        }
      }
    }
    return dot;
  } else {
    throw invalid_argument(
        "The Two Matrix Size not match . Can not do Matrix multiplication.");
  }
}

Matrix operator*(double num, const Matrix& a) {
  Matrix dot(a.rowSize(), a.colSize());
  for (int i = 0; i < a.rowSize(); i++) {
    for (int j = 0; j < a.colSize(); j++) {
      dot.set(i, j, a.get(i, j) * num);
    }
  }
  return dot;
}

Matrix operator*(const Matrix& a, double num) { return operator*(num, a); }

Matrix operator-(double num, const Matrix& a) {
  Matrix sub(a.rowSize(), a.colSize());
  for (int i = 0; i < a.rowSize(); i++) {
    for (int j = 0; j < a.colSize(); j++) {
      sub.set(i, j, num - a.get(i, j));
    }
  }
  return sub;
}

Matrix operator-(const Matrix& a, double num) {
  Matrix sub(a.rowSize(), a.colSize());
  for (int i = 0; i < a.rowSize(); i++) {
    for (int j = 0; j < a.colSize(); j++) {
      sub.set(i, j, a.get(i, j) - num);
    }
  }
  return sub;
}

Matrix operator>>(const Matrix& a, const Matrix& b) {
  if (isMatrixSameSize(a, b)) {
    Matrix dot(a.rowSize(), b.colSize());
    for (int i = 0; i < a.rowSize(); i++) {
      for (int j = 0; j < b.colSize(); j++) {
        dot.set(i, j, a.get(i, j) * b.get(i, j));
      }
    }
    return dot;
  } else {
    throw invalid_argument(
        "The Two Matrix Size not equal . Can not do Hadamard Product.");
  }
}

Matrix operator<<(const Matrix& a, const Matrix& b) {  // never used
  if (a.colSize() == 1 && b.rowSize() == 1) {
    Matrix dot(a.rowSize(), b.colSize());
    for (int i = 0; i < a.rowSize(); i++) {
      for (int j = 0; j < b.colSize(); j++) {
        dot.set(i, j, a.get(i, 0) * b.get(0, j));
      }
    }
    return dot;
  } else {
    throw invalid_argument(
        "The Two Matrix Size not match . Can not do Table Product.");
  }
}

bool operator==(const Matrix& a, const Matrix& b) {
  if (isMatrixSameSize(a, b)) {
    bool equal = true;
    for (int i = 0; i < a.rowSize(); i++) {
      for (int j = 0; j < a.colSize(); j++) {
        if (almost_equal(a.get(i, j), b.get(i, j)) == false) {
          equal = false;
        }
      }
    }
    return equal;
  } else {
    throw invalid_argument(
        "The Two Matrix Size not equal . Can not do Check IF Equal.");
  }
}
