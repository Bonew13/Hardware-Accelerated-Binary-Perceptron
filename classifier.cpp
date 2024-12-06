#include "classifier.h"

Perceptron::Perceptron(int num_features) {
    for (int i = 0; i < MAX_FEATURES; i++) {
        #pragma HLS UNROLL
        weights[i] = 0.0;
    }
    bias = 0.0;
}


int Perceptron::forward(float x[MAX_FEATURES], int num_features) {
    #pragma HLS INLINE
    float weighted_sum = bias;

    for (int i = 0; i < num_features; i++) {
        #pragma HLS LOOP_TRIPCOUNT min=1 max=8
        #pragma HLS PIPELINE
        weighted_sum += x[i] * weights[i];
    }

    return (weighted_sum > 0) ? 1 : 0;
}

int Perceptron::update(float x[MAX_FEATURES], int true_y, int num_features) {
    #pragma HLS INLINE
    int prediction = forward(x, num_features);
    int error = true_y - prediction;

    for (int i = 0; i < num_features; i++) {
        #pragma HLS LOOP_TRIPCOUNT min=1 max=8
        weights[i] += error * x[i];
    }
    bias += error;

    return error;
}
