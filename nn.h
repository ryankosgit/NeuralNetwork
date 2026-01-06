#include <vector>
using namespace std;

#ifndef NN_H
#define NN_H


class Module {
    public:
        Module();
        vector<double> forward(const vector<double>& input) const;
    protected:
        vector<double> weights;
};

class LinearLayer : public Module{
    public:
        LinearLayer(int in_size, int out_size);
        vector<double> forward(const vector<double>& input) const;
        void display() const;
        void size() const;
        void setFlatWeights(const vector<double>& newWeights);

    protected:
        int input_size;
        int output_size;
        vector<double> bias;
};

class ReLUActivation : public Module{
    public:
        ReLUActivation(double p_s = 1.0, double n_s = 0.0);
        vector<double> forward(const vector<double>& inputs) const;
        void display() const;
        void setWeights(const vector<double>& newWeights);
};

class Block {
    public:
        Block(int in_size, int out_size);
        vector<double> forward(const vector<double>& input) const;
        void display() const;
        void size() const;
        void setWeights(const vector<double>& flatWeights);
        void setActivationWeights(const vector<double>& actWeights);
    protected:
        LinearLayer linear;
        ReLUActivation relu;
};

class NeuralNetwork {
    public:
        NeuralNetwork(int num_blocks, int in_size, int hidden_size, int out_size);
        vector<double> forward(const vector<double>& input) const;
        void printModel() const;
        void printBlockSizes() const;
        void setBlockWeights(int block_index, const vector<double>& flatWeights);
        void setBlockActivationWeights(int block_index, const vector<double>& actWeights);
    protected:
        vector<Block> blocks;
};

#include "nn.cpp"	
#endif