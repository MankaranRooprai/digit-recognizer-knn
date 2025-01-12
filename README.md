![image](https://github.com/user-attachments/assets/c92c3e9b-6940-43e6-a4bb-29a107da5c82)# K-Nearest Neighbors (KNN) Classifier for MNIST

This project implements a simple **K-Nearest Neighbors (KNN)** classifier to classify digits from the **MNIST dataset**. The MNIST dataset consists of handwritten digits (0-9) and is commonly used for training machine learning algorithms. This project demonstrates how to load the MNIST data, implement KNN, and evaluate its performance.

Results from this project:
![image](https://github.com/user-attachments/assets/69796083-cdee-456f-b3df-5f5957ca8097)

## Features:
- Loads MNIST dataset (images and labels).
- Implements a basic KNN classifier.
- Provides accuracy on test data.
- Written in **C++**.

## Prerequisites

To build and run this project, you need the following:

- A C++ compiler (e.g., `g++`).
- The **MNIST dataset** files (train images, train labels, test images, test labels).
- C++11 or later support.

### MNIST Dataset Files
Download the MNIST dataset from the [official source](http://yann.lecun.com/exdb/mnist/), and save the following files in a `data/` directory inside your project folder:

- `train-images.idx3-ubyte`
- `train-labels.idx1-ubyte`
- `t10k-images.idx3-ubyte`
- `t10k-labels.idx1-ubyte`

## Project Structure

```bash
/project-directory
    /data
        train-images.idx3-ubyte
        train-labels.idx1-ubyte
        t10k-images.idx3-ubyte
        t10k-labels.idx1-ubyte
    main.cpp
    knn.h
    knn.cpp
    utils.h
    utils.cpp
    README.md
```

### File Descriptions:
- **main.cpp**: The main entry point of the program. Loads the dataset, trains the model, and tests it.
- **knn.h**: Header file defining the KNN class.
- **knn.cpp**: Implementation of the KNN class, including training and prediction.
- **utils.h**: Header file with utility functions for loading the MNIST dataset.
- **utils.cpp**: Implementation of utility functions to load MNIST images and labels.

### Building and Running the Project

#### Step 1: Install a C++ compiler
Make sure you have `g++` installed. If you're using a system like **Windows**, you can install **MinGW** or **MSYS2**. On **Linux**, you can use:

```bash
sudo apt-get update
sudo apt-get install g++
```

#### Step 2: Compile the Program
Once you have the dataset files in the correct folder and your compiler set up, navigate to your project directory and run the following command:

```bash
g++ -o knn_mnist main.cpp knn.cpp utils.cpp -std=c++11
```

#### Step 3: Run the Program
After successful compilation, run the program with:

```bash
./knn_mnist
```

The program will output the classification accuracy on the test set:

```bash
Accuracy: X%
```

### Explanation of the Code

- **KNN Algorithm**: The K-Nearest Neighbors algorithm works by calculating the Euclidean distance between the test image and all training images, selecting the `k` nearest neighbors, and assigning the class that is most common among those neighbors.
  
- **Euclidean Distance**: For each test image, the program calculates the Euclidean distance from each training image and sorts them to find the nearest neighbors.
  
- **Accuracy Calculation**: After the model is trained, it tests the classifier on a separate test dataset and calculates the accuracy based on the correct predictions.

### Notes:
- The current KNN implementation is simple and may not be the fastest for large datasets like MNIST. Optimizations such as dimensionality reduction (PCA), parallelization, or using approximate nearest neighbor techniques could speed up the process.
- The program uses raw MNIST files. You may need to ensure the dataset files are in the correct format and path.
