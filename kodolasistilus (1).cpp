#include <iostream>

// Structure representing a pair of integers.
// 'a' is used as the key for sorting, and 'b' is used in computations.
struct Pair {
    int a;
    int b;
};

// Sorts the array of Pair objects in ascending order by the 'a' field.
// This uses a simple bubble sort algorithm.
void SortByA(Pair* data, int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - 1; ++j) {
            if (data[j].a > data[j + 1].a) {
                std::swap(data[j].a, data[j + 1].a);
                std::swap(data[j].b, data[j + 1].b);
            }
        }
    }
}

// Prints a visual separator with equal signs.
// Used to clearly separate sections in the output.
void PrintSeparatorEqual() {
    std::cout << "===" << std::endl;
}

// Prints a visual separator with dashes.
// Used for additional separation in the output.
void PrintSeparatorDash() {
    std::cout << "---" << std::endl;
}

// Prints the header that indicates the start of output values.
void PrintOutputHeader() {
    std::cout << "Output:" << std::endl;
}

// Processes each Pair in the array and prints a computed value
// based on the parity (even/odd) of its 'a' and 'b' fields.
void ProcessAndPrintResults(const Pair* data, int size) {
    for (int i = 0; i < size; ++i) {
        int result = 0;
        int a = data[i].a;
        int b = data[i].b;

        // Compute result based on custom rules using parity of a and b.
        if (a % 2 == 0) {
            if (b % 2 == 0) {
                result = a * b;
            }
            else {
                result = a + b;
            }
        }
        else {
            if (b % 2 == 0) {
                result = a - b;
            }
            else {
                result = a;
            }
        }

        std::cout << result << std::endl;
    }
}

// Main function that coordinates the program:
// 1. Sorts the array based on 'a'
// 2. Prints visual markers and a header
// 3. Computes and prints results for each pair
void ProcessData(Pair* data, int length) {
    SortByA(data, length);
    PrintSeparatorEqual();
    PrintOutputHeader();
    PrintSeparatorDash();
    ProcessAndPrintResults(data, length);
}

// Entry point of the program.
// Initializes an array of Pair values and processes them.
int main() {
    Pair data[5] = {
      {5, 1},
      {2, 4},
      {3, 7},
      {1, 6},
      {4, 5}
    };

    ProcessData(data, 5);
    return 0;
}
