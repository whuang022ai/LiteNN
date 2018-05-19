

cppType = c++11 #編譯之C++標準
compiler = g++  -static #編譯器
compilerOp = -O2 #編譯優化
outputFileName= LiteNN #執行檔名


	
release: Clean  MainTest  Exe
test: Clean  MainTest  ExeTest
MainTest: Main.o Matrix.o MatrixUnitTest.o Perceptron.o TrainDataFactory.o NeuralNetThreeLayer.o
	@$(compiler) -std=$(cppType) -o $(outputFileName) Main.o Matrix.o MatrixUnitTest.o Perceptron.o TrainDataFactory.o NeuralNetThreeLayer.o
Main.o: Main.cpp 
	@$(compiler) -std=$(cppType) $(compilerOp) -c Main.cpp 
Matrix.o: Matrix.cpp  Matrix.hpp
	@$(compiler) -std=$(cppType) $(compilerOp) -c Matrix.cpp
MatrixUnitTest.o: MatrixUnitTest.cpp MatrixUnitTest.hpp
	@$(compiler) -std=$(cppType) $(compilerOp) -c MatrixUnitTest.cpp
Perceptron.o: Perceptron.cpp Perceptron.hpp
	@$(compiler) -std=$(cppType) $(compilerOp) -c Perceptron.cpp
NeuralNetThreeLayer.o: NeuralNetThreeLayer.cpp NeuralNetThreeLayer.hpp
	@$(compiler) -std=$(cppType) $(compilerOp) -c NeuralNetThreeLayer.cpp
TrainDataFactory.o: TrainDataFactory.cpp TrainDataFactory.hpp
	@$(compiler) -std=$(cppType) $(compilerOp) -c TrainDataFactory.cpp
Exe:
	@$(outputFileName).exe
ExeTest:
	@$(outputFileName).exe test
Clean:
	@del *.o
	@del *.exe
