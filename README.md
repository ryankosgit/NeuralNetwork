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
```LinearLayer``` is one of the derived classes from ```Module```. Its default constructor sets the input and output sizes of the layer, and initalizes bias. It also has a forward function that performs weights multiplication and adds the bias. The function that sets the flat weights set them to whatever the input is. The display and size functions print the expected dimensions, bias, and flat weight vector. 

## ReLU Activation
```ReLUActivation``` is the second derived class from ```Module```.

## 

## 

