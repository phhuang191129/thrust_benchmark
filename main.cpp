#include<stdio.h>
#include"compact.h"
#include<vector>
#include <thrust/host_vector.h>
#include <random>
#include <ctime>
using namespace std;



int main(){
	std::mt19937 rng(std::time(nullptr));  // Initialize random number generator with current time as seed

    // Calculate the number of elements for 1GB (1GB = 1024^3 bytes)
    const std::size_t numElements = 1024 * 1024 * 1024 / sizeof(int);

    // Create the distribution for random numbers (adjust parameters as needed)
    std::uniform_int_distribution<int> distribution(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

	thrust::host_vector<int> arr(numElements);
	std::generate_n(arr.begin(), numElements, [&]() {
        return distribution(rng);
    });
	compact_thrust(arr);
};
