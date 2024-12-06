#ifndef CLASSIFIER_H
#define CLASSIFIER_H

// Define the maximum number of features
#define MAX_FEATURES 8  // Modify according to your system constraints

class Perceptron {
public:
    Perceptron(int num_features);

    // Forward function to calculate the prediction
    int forward(float x[MAX_FEATURES], int num_features);

    // Update function to adjust weights based on the error
    int update(float x[MAX_FEATURES], int true_y, int num_features);

    float weights[MAX_FEATURES];  // Weights array
    float bias;                   // Bias term
};

#endif // CLASSIFIER_H
