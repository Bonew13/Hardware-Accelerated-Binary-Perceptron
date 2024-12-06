#include "classifier.h"

void perceptron_top(
    float x[MAX_FEATURES],
    int true_y,
    int num_features,
    int *prediction,
    float weights[MAX_FEATURES],
    float *bias
) {
    #pragma HLS INTERFACE ap_none port=x
    #pragma HLS INTERFACE ap_none port=true_y
    #pragma HLS INTERFACE ap_none port=num_features
    #pragma HLS INTERFACE ap_none port=prediction
    #pragma HLS INTERFACE ap_none port=weights
    #pragma HLS INTERFACE ap_none port=bias

    #pragma HLS ARRAY_PARTITION variable=x complete dim=1
    #pragma HLS ARRAY_PARTITION variable=weights complete dim=1

    Perceptron p(num_features);

    for (int i = 0; i < num_features; i++) {
        #pragma HLS PIPELINE
        p.weights[i] = weights[i];
    }
    p.bias = *bias;

    *prediction = p.forward(x, num_features);

    p.update(x, true_y, num_features);

    for (int i = 0; i < num_features; i++) {
        #pragma HLS PIPELINE
        weights[i] = p.weights[i];
    }
    *bias = p.bias;
}
