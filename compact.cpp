#include"compact.h"
#include<vector>
#include <algorithm>
#include <iostream>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/copy.h>
#include <thrust/execution_policy.h>


void compact(vector<int> &arr){
	auto it=std::copy_if (arr.begin(), arr.end(), arr.begin(), [](int i){return (i!=0);} );
	arr.resize(std::distance(arr.begin(),it));
}


struct not_zero
{
  __host__ __device__
  bool operator()(const int i)
  {
    return (i!=0);
  }
};

void compact_thrust(thrust::host_vector<int> &arr){

	thrust::device_vector<int> arr_device(arr.begin(), arr.end());
	auto it=thrust::copy_if (thrust::device,arr_device.begin(), arr_device.end(), arr_device.begin(), not_zero());
	// for(int i = 0; i < arr_device.size(); i++)
	//     std::cout << arr_device[i] << " ";
	// std::cout << std::endl;
	arr_device.resize(std::distance(arr_device.begin(),it));
	arr= arr_device;
}
