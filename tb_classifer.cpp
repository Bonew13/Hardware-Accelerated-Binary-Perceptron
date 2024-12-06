#include "classifier.h"
#include <iostream>
#include <iomanip>

int main() {
	const int NUM_FEATURES = 3;
	const int NUM_SAMPLES = 20;


	float inputs[NUM_SAMPLES][NUM_FEATURES] = {
	    {1, 2, 9},  //Class 0
	    {8, 9, 1},  //Class 1
	    {2, 1, 8},  //Class 0
	    {9, 8, 2},  //Class 1
	    {3, 2, 7},  //Class 0
	    {9, 7, 2},  //Class 1
	    {2, 3, 9},  //Class 0
	    {7, 8, 1},  //Class 1
	    {1, 4, 8},  //Class 0
	    {8, 7, 2},  //Class 1
	    {2, 3, 9},  //Class 0
	    {7, 8, 2},  //Class 1
	    {3, 2, 8},  //Class 0
	    {9, 8, 3},  //Class 1
	    {4, 3, 7},  //Class 0
	    {8, 9, 2},  //Class 1
	    {2, 2, 9},  //Class 0
	    {7, 8, 1},  //Class 1
	    {3, 3, 8},  //Class 0
	    {9, 7, 1}   //Class 1
	};

	int true_outputs[NUM_SAMPLES] = {
	    0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
	    0, 1, 0, 1, 0, 1, 0, 1, 0, 1
	};


    float weights[MAX_FEATURES] = {0.0};
    float bias = 0.0;
    int prediction;

    const int epochs = 5;
    for (int epoch = 0; epoch < epochs; epoch++) {
        std::cout << "Epoch " << epoch + 1 << ":\n";

        for (int i = 0; i < NUM_SAMPLES; i++) {
            perceptron_top(inputs[i], true_outputs[i], NUM_FEATURES, &prediction, weights, &bias);

            std::cout << "Input: ["
                      << std::setw(5) << inputs[i][0] << ", "
					  << std::setw(5) << inputs[i][1] << ", "
                      << std::setw(5) << inputs[i][2] << "] "
                      << "True: " << true_outputs[i]
                      << " Predicted: " << prediction
                      << " Bias: " << bias
                      << "\n";
        }

        std::cout << "-----------------------\n";
    }

    std::cout << "Final weights and bias:\n";
    std::cout << "Weights: [";
    for (int i = 0; i < NUM_FEATURES; i++) {
        std::cout << std::setw(5) << weights[i] << " ";
    }
    std::cout << "]\n";
    std::cout << "Bias: " << bias << "\n";

    return 0;
}

