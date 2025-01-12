#include "knn.h"
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

KNN::KNN(int k) : k_(k) {}

void KNN::train(const vector<vector<double>>& images, const vector<int>& labels) {
    train_images_ = images;
    train_labels_ = labels;
}

double KNN::euclidean_distance(const vector<double>& img1, const vector<double>& img2) {0
    double sum = 0;
    for (size_t i = 0; i < img1.size(); ++i) {
        sum += pow(img1[i] - img2[i], 2);
    }
    return sqrt(sum);
}

int KNN::predict(const vector<double>& image) {
    vector<pair<double, int>> distances;

    // Calculate the distance from the test image to each training image
    for (size_t i = 0; i < train_images_.size(); ++i) {
        double dist = euclidean_distance(image, train_images_[i]);
        distances.push_back(make_pair(dist, train_labels_[i]));
    }

    // Sort by distance (ascending)
    sort(distances.begin(), distances.end());

    // Count the most common label among the k-nearest neighbors
    vector<int> label_count(10, 0);  // There are 10 possible labels (0-9)
    for (int i = 0; i < k_; ++i) {
        ++label_count[distances[i].second];
    }

    // Find the label with the maximum count
    int max_count = 0;
    int predicted_label = -1;
    for (int i = 0; i < 10; ++i) {
        if (label_count[i] > max_count) {
            max_count = label_count[i];
            predicted_label = i;
        }
    }

    return predicted_label;
}
