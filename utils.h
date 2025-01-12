#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

std::vector<std::vector<double>> load_mnist_images(const std::string& filename);
std::vector<int> load_mnist_labels(const std::string& filename);

#endif
