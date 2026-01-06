#include "nn.h"
#include <iostream>
#include <iomanip>
using namespace std;

#ifndef NN_CPP
#define NN_CPP

Module::Module() : weights(1,1) {}

vector<double> Module::forward(const vector<double>& input) const{ //forward / multiplication function 
    vector<double> result(input.size(), 0);

    for(int i = 0; i < input.size(); i++)
        result[i] = input[i] * weights[i];

    return result;
}



LinearLayer::LinearLayer(int in_size, int out_size) : input_size(in_size), output_size(out_size) {
    bias.resize(out_size, 1.0);
    weights.resize(input_size * output_size, 1.0);
}

vector<double> LinearLayer::forward(const vector<double>& input) const{
    vector<double> result(output_size, 0);

    for(int i = 0; i < output_size; i++){
        result[i] = bias[i];

    for(int j = 0; j < input_size; j++)
        result[j] += weights[i * input_size + j] * input[j];

    }

    return result;
}

void LinearLayer::display() const{
    cout << "Linear Layer expected weight dimensions – " << "input: " << input_size << ", output: " << output_size << endl;

    cout << "Bias: ";
    for(auto & x: bias)
        cout << x << " ";

    cout << "\nFlat weight vector: ";

    for(auto & y : weights)
        cout << y << " ";

    cout << endl;

}

void LinearLayer::size() const{
    cout << fixed << setprecision(2);
    cout << "LinearLayer – Input size: " << input_size << ", " << "Output size: " << output_size;
}

void LinearLayer::setFlatWeights(const vector<double>& newWeights){ //set module::flatweights
    Module::weights.resize(newWeights.size());

    for(int i = 0; i < newWeights.size(); i++){
        Module::weights[i] = newWeights[i];
    }
}


ReLUActivation::ReLUActivation(double p_s, double n_s){
    Module::weights[0] = p_s;
    Module::weights[1] = n_s;
}

vector<double> ReLUActivation::forward(const vector<double>& inputs) const{
    int insize = inputs.size();

    vector<double> result(insize, 0);

    for(int i = 0 ; i < insize; i++){
        if(inputs[i] >= 0)
            result[i] = Module::weights[0] * inputs[i];
        else
            result[i] = Module::weights[1] * inputs[i];
    }

    return result;
}

void ReLUActivation::display() const{
    cout << fixed << setprecision(2);
    cout << "\nReLUActivation: slope = " << Module::weights[0] << ", negative slope = " << Module::weights[1];
}

void ReLUActivation::setWeights(const vector<double>& newWeights) {
    weights[0] = newWeights[0];
    weights[1] = newWeights[1];
}




Block::Block(int in_size, int out_size) : linear(in_size, out_size), relu() {}

vector<double> Block::forward(const vector<double>& input) const{
    vector<double> result;
    result = linear.forward(input);
    result = relu.forward(result);

    return result;
}

void Block::display() const{
    linear.display();
    relu.display();
    cout << "\n------------------------------";
};

void Block::size() const{
    linear.size();
    cout << endl;
};

void Block::setWeights(const vector<double>& flatWeights){
        linear.setFlatWeights(flatWeights);
};

void Block::setActivationWeights(const vector<double>& setActivationWeights){
    relu.setWeights(setActivationWeights);
};



NeuralNetwork::NeuralNetwork(int num_blocks, int in_size, int hidden_size, int out_size){
    if (num_blocks < 2){
        blocks.push_back(Block(in_size, out_size));
    }
    else{
        blocks.push_back(Block(in_size, hidden_size));
        for(int i = 0 ; i < num_blocks - 1; i++){
            blocks.push_back(Block(hidden_size, hidden_size));
        }
        blocks.push_back(Block(hidden_size, out_size));
    }
}

vector<double> NeuralNetwork::forward(const vector<double>& input) const{ // forward for all blocks
    vector<double> result = input;
    for(int i = 0; i < blocks.size(); i++){
        result = blocks[i].forward(result);
    }
    return result;
};

void NeuralNetwork::printModel() const{
    for(int i = 0; i < blocks.size(); i++){
        cout << "\nBlock " << i + 1 << ": " << endl;
        blocks[i].display();
    }
}


void NeuralNetwork::printBlockSizes() const{
    cout << "\n";
    cout << fixed << setprecision(2);
    for(int i = 0; i < blocks.size(); i++){
            cout << "Block " << i + 1 << " size: ";
            blocks[i].size();
            cout << endl;
    }
};

void NeuralNetwork::setBlockWeights(int block_index, const vector<double>& flatWeights){                  
    blocks[block_index].setWeights(flatWeights);
};


void NeuralNetwork::setBlockActivationWeights(int block_index, const vector<double>& actWeights){
    blocks[block_index].setActivationWeights(actWeights);
};

#endif