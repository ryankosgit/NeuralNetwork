#include "nn.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {

    NeuralNetwork nn(4, 3, 4, 2);

    vector<double> flatWeights = {
        0.5, 0.6, 0.7,   // Weights for first output neuron
        0.8, 0.9, 1.0,   // Weights for second output neuron
        1.1, 1.2, 1.3,   // Weights for third output neuron
        1.4, 1.5, 1.6    // Weights for fourth output neuron
    };
    nn.setBlockWeights(0, flatWeights);

 vector<double> activationWeights = { 2.0, 0.1 };
    nn.setBlockActivationWeights(0, activationWeights);


    vector<double> input = { 1.0, 0.5, -1.0 };


    vector<double> output = nn.forward(input);
    

    cout << "Network output:" << endl;
    for (double o : output) {
        cout << o << " ";
    }
    cout << "\n\n";


    nn.printModel();
    nn.printBlockSizes();

    return 0;
}