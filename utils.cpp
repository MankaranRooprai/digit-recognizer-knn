#include "utils.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstdint>  // Add this line to include the necessary header for uint32_t

using namespace std;

std::vector<std::vector<double>> load_mnist_images(const std::string& filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening image file: " << filename << endl;
        exit(1);
    }

    // Read header
    uint32_t magic_number;
    uint32_t num_images;
    uint32_t num_rows;
    uint32_t num_cols;
    file.read(reinterpret_cast<char*>(&magic_number), 4);
    file.read(reinterpret_cast<char*>(&num_images), 4);
    file.read(reinterpret_cast<char*>(&num_rows), 4);
    file.read(reinterpret_cast<char*>(&num_cols), 4);

    // Convert from big-endian to little-endian (if necessary)
    magic_number = __builtin_bswap32(magic_number);
    num_images = __builtin_bswap32(num_images);
    num_rows = __builtin_bswap32(num_rows);
    num_cols = __builtin_bswap32(num_cols);

    vector<vector<double>> images(num_images, vector<double>(num_rows * num_cols));

    // Read image data
    for (uint32_t i = 0; i < num_images; ++i) {
        for (uint32_t j = 0; j < num_rows * num_cols; ++j) {
            unsigned char pixel;
            file.read(reinterpret_cast<char*>(&pixel), 1);
            images[i][j] = static_cast<double>(pixel) / 255.0;  // Normalize to [0, 1]
        }
    }

    return images;
}

std::vector<int> load_mnist_labels(const std::string& filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening label file: " << filename << endl;
        exit(1);
    }

    // Read header
    uint32_t magic_number;
    uint32_t num_labels;
    file.read(reinterpret_cast<char*>(&magic_number), 4);
    file.read(reinterpret_cast<char*>(&num_labels), 4);

    magic_number = __builtin_bswap32(magic_number);
    num_labels = __builtin_bswap32(num_labels);

    vector<int> labels(num_labels);
    for (uint32_t i = 0; i < num_labels; ++i) {
        unsigned char label;
        file.read(reinterpret_cast<char*>(&label), 1);
        labels[i] = static_cast<int>(label);
    }

    return labels;
}
