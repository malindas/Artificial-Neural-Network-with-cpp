IDIR = ./includes/
SDIR = ./src/
ODIR = ./obj
BDIR = ./bin
OBJ=main.o Neuron.o NeuralNetwork.o Matrix.o Layer.o Matrix2Vec.o MultiplyMat.o


app:$(OBJ)
	g++ -std=c++14 -o app $(OBJ)
	@echo "Build Successful"

main.o:$(SDIR)main.cpp $(IDIR)Neuron.hpp $(IDIR)NeuralNetwork.hpp $(IDIR)Matrix.hpp $(IDIR)Layer.hpp $(IDIR)MultiplyMat.hpp
	g++ -std=c++14 -c $(SDIR)main.cpp 

Neuron.o:$(SDIR)Neuron.cpp $(IDIR)Neuron.hpp
	g++ -std=c++14 -c $(SDIR)Neuron.cpp

Matrix.o:$(SDIR)Matrix.cpp $(IDIR)Matrix.hpp
	g++ -std=c++14 -c $(SDIR)Matrix.cpp

Layer.o:$(SDIR)Layer.cpp $(IDIR)Layer.hpp $(IDIR)Matrix.hpp $(IDIR)Neuron.hpp
	g++ -std=c++14 -c $(SDIR)Layer.cpp

NeuralNetwork.o:$(SDIR)NeuralNetwork.cpp $(IDIR)NeuralNetwork.hpp $(IDIR)Matrix.hpp $(IDIR)Layer.hpp
	g++ -std=c++14 -c $(SDIR)NeuralNetwork.cpp

Matrix2Vec.o:$(SDIR)Matrix2Vec.cpp $(IDIR)Matrix2Vec.hpp
	g++ -std=c++14 -c $(SDIR)Matrix2Vec.cpp

MultiplyMat.o:$(SDIR)MultiplyMat.cpp $(IDIR)MultiplyMat.hpp
	g++ -std=c++14 -c $(SDIR)MultiplyMat.cpp

directories:
	mkdir $(ODIR)
	mkdir $(BDIR)
	

.PHONY : clean
clean :
	rm app $(OBJ)

