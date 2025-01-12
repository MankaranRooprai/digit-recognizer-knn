#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include "knn.h"
#include "utils.h"

using namespace std;

int main() {
    // Load training data (images and labels)
    string train_images_path = "data/train-images.idx3-ubyte";
    string train_labels_path = "data/train-labels.idx1-ubyte";
    string test_images_path = "data/t10k-images.idx3-ubyte";
    string test_labels_path = "data/t10k-labels.idx1-ubyte";

    vector<vector<double>> train_images = load_mnist_images(train_images_path);
    vector<int> train_labels = load_mnist_labels(train_labels_path);
    vector<vector<double>> test_images = load_mnist_images(test_images_path);
    vector<int> test_labels = load_mnist_labels(test_labels_path);

    // Create a KNN classifier
    KNN knn(3);  // k = 3

    // Train the KNN classifier
    knn.train(train_images, train_labels);

    // Test the classifier
    int correct = 0;
    for (size_t i = 0; i < test_images.size(); ++i) {
        int predicted_label = knn.predict(test_images[i]);
        if (predicted_label == test_labels[i]) {
            ++correct;
        }
    }

    cout << "Accuracy: " << (correct * 100.0) / test_images.size() << "%" << endl;

    return 0;
}
