/***************************************************************************
*
* TrainDataFactory.cpp
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
  
#include "Matrix.hpp"
#include "TrainDataFactory.hpp"
using namespace std; 

vector <trainSample> TrainDataFactory :: genANDTrainList()const{
	
	vector<trainSample> trainList;
	
	Matrix *X00=new Matrix (3,1,1);
	X00->set(0,0,0);X00->set(1,0,0);
	
	Matrix *X11=new Matrix (3,1,1);
	X11->set(0,0,1);X11->set(1,0,1);
	
	Matrix *X01=new Matrix (3,1,1);
	X01->set(0,0,0);X01->set(1,0,1);
	
	Matrix *X10=new Matrix (3,1,1);
	X10->set(0,0,1);X10->set(1,0,0);
	
	Matrix *D0=new Matrix (1,1,0);
	Matrix *D1=new Matrix (1,1,1);
	
	trainSample *t1=new trainSample() ;
	t1->X=X00;
	t1->Y=D0;
	
	trainSample *t2=new trainSample() ;
	t2->X=X01;
	t2->Y=D0;
	
	trainSample *t3=new trainSample() ;
	t3->X=X10;
	t3->Y=D0;
	
	trainSample *t4=new trainSample() ;
	t4->X=X11;
	t4->Y=D1;
	
	trainList.push_back(*t1);
	trainList.push_back(*t2);
	trainList.push_back(*t3);
	trainList.push_back(*t4);
	
	return trainList;
}

vector <trainSample> TrainDataFactory :: genORTrainList()const{
	
	vector<trainSample> trainList;
	
	Matrix *X00=new Matrix (3,1,1);
	X00->set(0,0,0);X00->set(1,0,0);
	
	Matrix *X11=new Matrix (3,1,1);
	X11->set(0,0,1);X11->set(1,0,1);
	
	Matrix *X01=new Matrix (3,1,1);
	X01->set(0,0,0);X01->set(1,0,1);
	
	Matrix *X10=new Matrix (3,1,1);
	X10->set(0,0,1);X10->set(1,0,0);
	
	Matrix *D0=new Matrix (1,1,0);
	Matrix *D1=new Matrix (1,1,1);
	
	trainSample *t1=new trainSample() ;
	t1->X=X00;
	t1->Y=D0;
	
	trainSample *t2=new trainSample() ;
	t2->X=X01;
	t2->Y=D1;
	
	trainSample *t3=new trainSample() ;
	t3->X=X10;
	t3->Y=D1;
	
	trainSample *t4=new trainSample() ;
	t4->X=X11;
	t4->Y=D1;
	
	trainList.push_back(*t1);
	trainList.push_back(*t2);
	trainList.push_back(*t3);
	trainList.push_back(*t4);
	
	return trainList;
}

vector <trainSample> TrainDataFactory :: genXORTrainList()const{
	
	vector<trainSample> trainList;
	
	Matrix *X00=new Matrix (3,1,1);
	X00->set(0,0,0);X00->set(1,0,0);
	
	Matrix *X11=new Matrix (3,1,1);
	X11->set(0,0,1);X11->set(1,0,1);
	
	Matrix *X01=new Matrix (3,1,1);
	X01->set(0,0,0);X01->set(1,0,1);
	
	Matrix *X10=new Matrix (3,1,1);
	X10->set(0,0,1);X10->set(1,0,0);
	
	Matrix *D0=new Matrix (1,1,0);
	Matrix *D1=new Matrix (1,1,1);
	
	trainSample *t1=new trainSample() ;
	t1->X=X00;
	t1->Y=D0;
	
	trainSample *t2=new trainSample() ;
	t2->X=X01;
	t2->Y=D1;
	
	trainSample *t3=new trainSample() ;
	t3->X=X10;
	t3->Y=D1;
	
	trainSample *t4=new trainSample() ;
	t4->X=X11;
	t4->Y=D0;
	
	trainList.push_back(*t1);
	trainList.push_back(*t2);
	trainList.push_back(*t3);
	trainList.push_back(*t4);
	
	return trainList;
}