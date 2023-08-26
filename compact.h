#pragma once
#include<vector>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
using namespace std;
void compact(vector<int> &arr);
void compact_thrust(thrust::host_vector<int> &arr);
