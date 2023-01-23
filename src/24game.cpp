#include "24game.hpp"

void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

void selectionSort(std::vector<double>& numVec) {
    int idxMin;
    double min;

    for (int i = 0; i < 4; i++) {
        idxMin = i;
        min = numVec[i];
        for (int j = i + 1; j < 4; j++) {
            if (min > numVec[j]) {
                min = numVec[j];
                idxMin = j;
            }
        }
        swap(numVec[i], numVec[idxMin]);
    }
}

void reverseSubVec(std::vector<double>& numVec, int idxFirst, int idxLast) {
    while (idxFirst < idxLast) {
        swap(numVec[idxFirst], numVec[idxLast]);
        idxFirst++;
        idxLast--;
    }
}

bool nextPermutation(std::vector<double>& numVec) {
    int idxSwap;
    bool lastPermutation = true;
    for (int i = 3; i > 0; i--) {
        if (numVec[i] > numVec[i - 1]) {
            idxSwap = i - 1;
            lastPermutation = false;
            break;
        }
    }

    if (lastPermutation) {
        return false;
    }

    bool found = false;
    int min, idxMin;
    for (int i = 3; i > idxSwap; i--) {
        if (!found && numVec[idxSwap] < numVec[i]) {
            found = true;
            min = numVec[i];
            idxMin = i;
        } else if (found) {
            if (min > numVec[i]) {
                min = numVec[i];
                idxMin = i;
            }
        }
    }

    swap(numVec[idxMin], numVec[idxSwap]);
    reverseSubVec(numVec, idxSwap + 1, 3);
    return true;
}

void computeSolution(std::vector<double> input, int& count, std::string& solution) {
    if (input[0] + input[1] + input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] + input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] + input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] + input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] - input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] - input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] - input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] - input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] * input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] * input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] * input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] * input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] / input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] / input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] / input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] / input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] + input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] + input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] + input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] + input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] - input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] - input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] - input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] - input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] * input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] * input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] * input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] * input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] / input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] / input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] / input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - input[1] / input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] + input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] + input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] + input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] + input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] - input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] - input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] - input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] - input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] * input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] * input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] * input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] * input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] / input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] / input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] / input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * input[1] / input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] + input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] + input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] + input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] + input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] - input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] - input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] - input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] - input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] * input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] * input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] * input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] * input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] / input[2] + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] / input[2] - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] / input[2] * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / input[1] / input[2] / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) + input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) + input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) + input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) + input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) - input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) - input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) - input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) - input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) * input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) * input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) * input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) * input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) / input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) / input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) / input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1]) / input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) + input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) + input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) + input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) + input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) - input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) - input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) - input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) - input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) * input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) * input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) * input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) * input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) / input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) / input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) / input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1]) / input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) + input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) + input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) + input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) + input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) - input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) - input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) - input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) - input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) * input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) * input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) * input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) * input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) / input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) / input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) / input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1]) / input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) + input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) + input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) + input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) + input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " + " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) - input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) - input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) - input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) - input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " - " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) * input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) * input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) * input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) * input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " * " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) / input[2] + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) / input[2] - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) / input[2] * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1]) / input[2] / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " / " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] + input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] + input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] + input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] + input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] - input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] - input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] - input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] - input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] * input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] * input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] * input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] * input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] / input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] / input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] / input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] / input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] + input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] + input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] + input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] + input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] - input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] - input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] - input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] - input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] * input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] * input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] * input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] * input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] / input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] / input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] / input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] - (input[1] / input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] + input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] + input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] + input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] + input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] - input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] - input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] - input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] - input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] * input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] * input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] * input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] * input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] / input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] / input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] / input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] * (input[1] / input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] + input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] + input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] + input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] + input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] - input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] - input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] - input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] - input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] * input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] * input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] * input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] * input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] / input[2]) + input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] / input[2]) - input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] / input[2]) * input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] / (input[1] / input[2]) / input[3] == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + input[1] + (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] + (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] + (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] + (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] - (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] - (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] - (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] - (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] * (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] * (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] * (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] * (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] / (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] / (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] / (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + input[1] / (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] + (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] + (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] + (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] + (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] - (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] - (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] - (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] - (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] * (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] * (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] * (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] * (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] / (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] / (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] / (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - input[1] / (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] + (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] + (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] + (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] + (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] - (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] - (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] - (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] - (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] * (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] * (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] * (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] * (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] / (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] / (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] / (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * input[1] / (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] + (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] + (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] + (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] + (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] - (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] - (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] - (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] - (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] * (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] * (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] * (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] * (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] / (input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] / (input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] / (input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / input[1] / (input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1] + input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] + input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] + input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] + input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] - input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] - input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] - input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] - input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] * input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] * input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] * input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] * input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] / input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] / input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] / input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + input[1] / input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] + input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] + input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] + input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] + input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] - input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] - input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] - input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] - input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] * input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] * input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] * input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] * input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] / input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] / input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] / input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - input[1] / input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] + input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] + input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] + input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] + input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] - input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] - input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] - input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] - input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] * input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] * input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] * input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] * input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] / input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] / input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] / input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * input[1] / input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] + input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] + input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] + input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] + input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] - input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] - input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] - input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] - input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] * input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] * input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] * input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] * input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] / input[2]) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] / input[2]) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] / input[2]) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / input[1] / input[2]) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + (input[1] + input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] + input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] + input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] + input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] - input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] - input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] - input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] - input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] * input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] * input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] * input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] * input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] / input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] / input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] / input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] / input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] + input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] + input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] + input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] + input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] - input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] - input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] - input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] - input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] * input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] * input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] * input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] * input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] / input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] / input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] / input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - (input[1] / input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] + input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] + input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] + input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] + input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] - input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] - input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] - input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] - input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] * input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] * input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] * input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] * input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] / input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] / input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] / input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * (input[1] / input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] + input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] + input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] + input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] + input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] - input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] - input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] - input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] - input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] * input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] * input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] * input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] * input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] / input[2] + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] / input[2] - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] / input[2] * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / (input[1] / input[2] / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (((input[0] + input[1]) + input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) + input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) + input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) + input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) - input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) - input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) - input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) - input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) * input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) * input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) * input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) * input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) / input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) / input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) / input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] + input[1]) / input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) + input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) + input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) + input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) + input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) - input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) - input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) - input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) - input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) * input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) * input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) * input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) * input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) / input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) / input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) / input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] - input[1]) / input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) + input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) + input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) + input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) + input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) - input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) - input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) - input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) - input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) * input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) * input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) * input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) * input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) / input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) / input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) / input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] * input[1]) / input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) + input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) + input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) + input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) + input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) - input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) - input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) - input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) - input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) * input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) * input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) * input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) * input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) / input[2]) + input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) / input[2]) - input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) / input[2]) * input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if (((input[0] / input[1]) / input[2]) / input[3] == 24) {
        count++;
        solution += "((" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")"+ " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] + input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] + input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] + input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] + input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] - input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] - input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] - input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] - input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] * input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] * input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] * input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] * input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] / input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] / input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] / input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] + (input[1] / input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] + input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] + input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] + input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] + input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] - input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] - input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] - input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] - input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] * input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] * input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] * input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] * input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] / input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] / input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] / input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] - (input[1] / input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] + input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] + input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] + input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] + input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] - input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] - input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] - input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] - input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] * input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] * input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] * input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] * input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] / input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] / input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] / input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] * (input[1] / input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] + input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] + input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] + input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] + input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] - input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] - input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] - input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] - input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] * input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] * input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] * input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] * input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] / input[2])) + input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " + " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] / input[2])) - input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " - " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] / input[2])) * input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " * " + std::to_string((int) input[3]) + "\n";
    }
    if ((input[0] / (input[1] / input[2])) / input[3] == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + "))" + " / " + std::to_string((int) input[3]) + "\n";
    }
    if (input[0] + ((input[1] + input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] + input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] + input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] + input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] - input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] - input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] - input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] - input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] * input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] * input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] * input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] * input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] / input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] / input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] / input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + ((input[1] / input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] + input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] + input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] + input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] + input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] - input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] - input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] - input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] - input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] * input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] * input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] * input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] * input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] / input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] / input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] / input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] - ((input[1] / input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] + input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] + input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] + input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] + input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] - input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] - input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] - input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] - input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] * input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] * input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] * input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] * input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] / input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] / input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] / input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] * ((input[1] / input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] + input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] + input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] + input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] + input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " + " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] - input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] - input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] - input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] - input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " - " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] * input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] * input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] * input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] * input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " * " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] / input[2]) + input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] / input[2]) - input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] / input[2]) * input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] / ((input[1] / input[2]) / input[3]) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "((" + std::to_string((int) input[1]) + " / " + std::to_string((int) input[2]) + ")" + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if (input[0] + (input[1] + (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] + (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] + (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] + (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] - (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] - (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] - (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] - (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] * (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] * (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] * (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] * (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] / (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] / (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] / (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] + (input[1] / (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " + " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] + (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] + (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] + (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] + (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] - (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] - (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] - (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] - (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] * (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] * (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] * (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] * (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] / (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] / (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] / (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] - (input[1] / (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " - " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] + (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] + (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] + (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] + (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] - (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] - (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] - (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] - (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] * (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] * (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] * (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] * (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] / (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] / (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] / (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] * (input[1] / (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " * " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] + (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] + (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] + (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] + (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " + " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] - (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] - (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] - (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] - (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " - " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] * (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] * (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] * (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] * (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " * " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] / (input[2] + input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] / (input[2] - input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] / (input[2] * input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if (input[0] / (input[1] / (input[2] / input[3])) == 24) {
        count++;
        solution += std::to_string((int) input[0]) + " / " + "(" + std::to_string((int) input[1]) + " / " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + "))" + "\n";
    }
    if ((input[0] + input[1]) + (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) + (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) + (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) + (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) - (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) - (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) - (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) - (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) * (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) * (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) * (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) * (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) / (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) / (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) / (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] + input[1]) / (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " + " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) + (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) + (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) + (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) + (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) - (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) - (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) - (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) - (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) * (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) * (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) * (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) * (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) / (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) / (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) / (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] - input[1]) / (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " - " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) + (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) + (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) + (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) + (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) - (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) - (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) - (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) - (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) * (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) * (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) * (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) * (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) / (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) / (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) / (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] * input[1]) / (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " * " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) + (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) + (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) + (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) + (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " + " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) - (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) - (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) - (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) - (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " - " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) * (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) * (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) * (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) * (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " * " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) / (input[2] + input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " + " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) / (input[2] - input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " - " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) / (input[2] * input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " * " + std::to_string((int) input[3]) + ")" + "\n";
    }
    if ((input[0] / input[1]) / (input[2] / input[3]) == 24) {
        count++;
        solution += "(" + std::to_string((int) input[0]) + " / " + std::to_string((int) input[1]) + ")" + " / " + "(" + std::to_string((int) input[2]) + " / " + std::to_string((int) input[3]) + ")" + "\n";
    }
}