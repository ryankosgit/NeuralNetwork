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

# Classes

This project contains:
- A base ```Module``` class
- Two derived classes: ```LinearLayer``` and ```ReLUActivation```
- A composite ```Block``` class that groups a ```LinearLayer``` instance with a ```ReLUActivation``` instance
- A final ```NeuralNetwork``` class that contains multiple ```Block``` objects



