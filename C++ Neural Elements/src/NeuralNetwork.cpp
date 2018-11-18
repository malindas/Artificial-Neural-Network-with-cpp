#include "../includes/NeuralNetwork.hpp"



void NeuralNetwork::backPropagation(){

	this->setErrors(); 

	// Holders for Adjusted Weights and gradients
	vector<Matrix *> newWeights;
	Matrix * gradients;		
 	
	// Get Derived values of the output layer as a Matrix  
	// [y1' y2' y3']
	int outputLayerIndex = this->layers.size() - 1;
	Matrix * derivedValuesYtoZ = this->layers.at(outputLayerIndex)->matrixifyDerivedVal();
	

	// Calculate the gradients form ouptput to last hidden layer	
	// [gy1 gy2 gy3] = [e1 e2 e3].*[y1' y2' y3']
	
	Matrix * gradientsYtoZ = new Matrix(1,this->layers.at(outputLayerIndex)->getNeurons().size(),false);
	for(int i = 0; i <this->errors.size(); i++){
		double d = derivedValuesYtoZ->getValue(0,i);
		double e = this->errors.at(i);
		double g = d * e;
		gradientsYtoZ->setValue(0,i,g);
	}
	
	// Calculating the Delta weights from output To Hidden Layer
	int lastHiddenLayerIndex = outputLayerIndex - 1;
	Layer *lastHiddenLayer = this->layers.at(lastHiddenLayerIndex);
	Matrix *weightsOutputToHidden = this->weightMatrices.at(lastHiddenLayerIndex);

	Matrix *deltaOutputToHidden = (new utils::MultiplyMat(gradientsYtoZ->transpose(),
					 lastHiddenLayer->matrixifyActivatedVal()
					))->execute()->transpose();
	
	// Adjusting the new Weights Matrix from output To Hidden layer
	Matrix *newWeightsOutputToHidden = new Matrix(
						deltaOutputToHidden->getNumRows(),
						deltaOutputToHidden->getNumCols(),
						false);
	// Adjusting the Weights
	for(int r = 0; r < deltaOutputToHidden->getNumRows(); r++){
		for(int c = 0; c < deltaOutputToHidden->getNumCols(); c++){
		double originalWeight = weightsOutputToHidden->getValue(r,c);
		double deltaWeight = deltaOutputToHidden->getValue(r,c);
		newWeightsOutputToHidden->setValue(r,c,originalWeight -
							(Neuron::learningRate*deltaWeight));		
		}
	} 
	
	// Concatanate to new Wight Matrix array
	newWeights.push_back(newWeightsOutputToHidden);
	
	// set Current gradients to gradients Matrix
	gradients = new Matrix(gradientsYtoZ->getNumRows(),gradientsYtoZ->getNumCols(),false);
	
	for(int r = 0; r < gradientsYtoZ->getNumRows(); r++){
		for(int c = 0; c < gradientsYtoZ->getNumCols(); c++){
			gradients->setValue(r,c,gradientsYtoZ->getValue(r,c));	
		}
	}

/*-----------Last Hidden Layer to the Input-------------*/

	// Navigate through hidden layers to the input
	for(int i = (outputLayerIndex - 1); i > 0 ; i--){
		Layer *l = this->layers.at(i);
		Matrix *derivedHidden = l->matrixifyDerivedVal();
		Matrix *activatedHidden = l->matrixifyActivatedVal();
		Matrix *derivedGrads = new Matrix(
					1,
					l->getNeurons().size(),
					false);
		
		Matrix *weightMatrix = this->weightMatrices.at(i);
		Matrix *originalWeight = this->weightMatrices.at(i-1);

		for(int r = 0; r < weightMatrix->getNumRows(); r++){
			double sum = 0.0;
			
			for(int c = 0; c < weightMatrix->getNumCols(); c++){
				double p =  gradients->getValue(0,c) * (weightMatrix->getValue(r,c));
				sum += p;
			}
			
			double g = sum * activatedHidden->getValue(0,r);
			derivedGrads->setValue(0,r,g);			
		}
		
		// If input layer--> take raw values as a matrix
		// else--> take Activated values as a matrix
		
		Matrix * leftNeurons = (i-1) == 0 ? this->layers.at(0)->matrixify() :
											this->layers.at(i-1)->matrixifyActivatedVal();
											
		Matrix * deltaWeights = (new utils::MultiplyMat(derivedGrads->transpose(),
											leftNeurons))->execute()->transpose();
											
		Matrix * newWeightsHidden = new Matrix(
						deltaWeights->getNumRows(),
						deltaWeights->getNumCols(),
						false);
	 	
	 	// Updating new Weights = W(old) + W(delta);
		for(int r = 0; r < newWeightsHidden->getNumRows(); r++){
			for(int c = 0; c  < newWeightsHidden->getNumCols(); c++){
				newWeightsHidden->setValue(r,
										   c,
										   originalWeight->getValue(r,c) -
										   deltaWeights->getValue(0,c)
										   );	
			}
		}
		
		// Update Gradient Matrix
		gradients = new Matrix(derivedGrads->getNumRows(), derivedGrads->getNumCols(), false);
		for(int r= 0; r < derivedGrads->getNumRows(); r++){
			for(int c = 0; c < derivedGrads->getNumCols(); c++){
			gradients->setValue(r,c,derivedGrads->getValue(r,c));
			}
		}

	 	newWeights.push_back(newWeightsHidden);
	}
	
	
	cout << "done with Back prop" << endl;
	reverse(newWeights.begin(),newWeights.end()); 
	this->weightMatrices = newWeights;
		
	
}
 
/*=====================================================
*
*	Does the Error Calculations
*
=======================================================*/

void NeuralNetwork::setErrors(){

	if(this->target.size() == 0){
	cerr << "No target for this neural network" << endl;
	assert(false);
	}

	if(this->target.size() != this->layers.at(this->layers.size()-1)->getNeurons().size()){
		cerr << "Target size is not same as output layer size: " << this->layers.at(this->layers.size()-1)->getNeurons().size() << endl;
		assert(false);
	}
	
	this->error = 0.0;
	int outputLayerIndex = this->layers.size() - 1;
	vector<Neuron *> outputNeurons = this->layers.at(outputLayerIndex)->getNeurons();

	errors = this->target;
	for(int i = 0; i < target.size(); i++){
		double tempErr = (outputNeurons.at(i)->getActivatedVal() - target.at(i));
		this->errors.at(i) = tempErr;
		this->error += tempErr * tempErr;
		
	}
	this->error *= 0.5;
	errorHistory.push_back(this->error);
}






/*=====================================================
*
*	Does the Feed Forword Calculation
*
=======================================================*/
void NeuralNetwork::feedForword(){
  for(int i = 0; i < (this->layers.size()-1);i++){
	
    Matrix *a = this->getNeuronMatrix(i);

    if(i != 0){
	
     	a = this->getActivatedNeuronMatrix(i);
    }
	
    Matrix *b = this->getWeightMatrix(i);
    Matrix *c = (new utils::MultiplyMat(a,b))->execute();
	
    vector<double> vals;
    for(int c_index = 0; c_index < c->getNumCols(); c_index++){
      vals.push_back(c->getValue(0,c_index));
      this->setNeuronValue(i+1,c_index,c->getValue(0,c_index));
      }
  }
this->printToConsole();
}


/*=====================================================
*
*	Print Network Outputs to the console
*
=======================================================*/
void NeuralNetwork::printToConsole(){
    for(int i =0; i < this->layers.size();  i++){
      cout << "LAYER: " << i << endl;
      if (i == 0 ){
        Matrix *m = this->layers.at(i)->matrixify();
        m->printToConsole();
      }
      else{
        Matrix *m = this->layers.at(i)->matrixifyActivatedVal();
        m->printToConsole();
      }
	cout << "_____________________________________" << endl;

	if (i < this->layers.size() - 1){
		cout << "Weight Matrix at index " << i << endl;
		this->getWeightMatrix(i)->printToConsole();		
	}
	cout << "=====================================" << endl;

    }

}

/*=====================================================  
*
*	Set Current Input to a Layer
*
=======================================================*/
void NeuralNetwork::setCurrentInput(vector<double> input){
  this->input = input;
  for(int i = 0; i < input.size(); i++){
  this->layers.at(0)->setVal(i,input.at(i));

  }
}


/*=====================================================
*
*		     constructor
*
=======================================================*/
NeuralNetwork::NeuralNetwork(vector<int> topology){
  this->topology = topology;
  this->topologySize = topology.size();
  for(int i = 0; i < topologySize; i++){
    Layer * l = new Layer(topology.at(i));
    this->layers.push_back(l);
  }

  for(int i = 0; i < (topologySize - 1); i++){
    Matrix *m = new Matrix(topology.at(i), topology.at(i+1), true);
    this->weightMatrices.push_back(m);
  }

}
