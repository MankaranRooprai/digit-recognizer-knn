#ifndef KNN_H
#define KNN_H

#include <vector>

class KNN {
public:
    KNN(int k);  // Constructor that sets the value of k
    void train(const std::vector<std::vector<double>>& images, const std::vector<int>& labels);
    int predict(const std::vector<double>& image);

private:
    int k_;  // Number of nearest neighbors
    std::vector<std::vector<double>> train_images_;
    std::vector<int> train_labels_;

    double euclidean_distance(const std::vector<double>& img1, const std::vector<double>& img2);
};

#endif
