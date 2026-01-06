# Neural Network in C++

This is a multi-layer, neural network framework I built using C++. It contains customizeable features for users to build and design their neural network's layers, weights, and more.

# PROJECT STRUCTURE
```
NeuralNetwork
├── README.md   # README
├── driver.cpp  # Driver file
├── makefile    # Makefile
├── nn.cpp      # Definitions
├── nn.h        # Header
```

# Class Summaries

This project contains:
- A base ```Module``` class
- Two derived classes: ```LinearLayer``` and ```ReLUActivation```
- A composite ```Block``` class that groups a ```LinearLayer``` with a ```ReLUActivation```
- A final ```NeuralNetwork``` class that contains multiple ```Block``` objects

## Module
```Module``` is a class that serves as the base for both ```LinearLayer``` and ```ReLUActivation```. It contains a vector that contains the weights, a forward function with an input parameter that performs element multiplication to the input vector with weights, and a default constructor that sets the weights automatically to {1.0}.

## Linear Layer
```LinearLayer``` is one of the derived classes from ```Module```. Its default constructor sets the input and output sizes of the layer, and initalizes bias. It also has a forward function that performs weights multiplication and adds the bias. 

## ReLU Activation
```ReLUActivation``` is the second derived class from ```Module```. It's default constructor sets Module's weights to 1 and 0 so that the first element is the slope for x ≥ 0 and the second is the slope for x < 0. Its forward function applies the ReLU function to every element in the input vector.

## Block
```Block``` is a composite class containing a forward function that computes a linear transformation and applies the ReLU function. Its constructor creates a block with the dimensions for the linear layer. It also has individual functions to set the linear layer's flat weight vectors or the activation weights for the ReLU component. 

## Neural Network
```NeuralNetwork``` is the grandmaster class that represents the complete network from multiple ```Block``` objects. It allows users to specify the number of blocks, as well as specific numbers of the input, hidden, and output layers.

