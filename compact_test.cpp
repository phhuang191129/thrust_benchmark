#include"compact.h"
#include<vector>
#include<gtest/gtest.h>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <iostream>

TEST(CompactTest, PostiveInteger) {
    auto arr=std::vector<int>{1,2,3,4,0,5,0,0};
	compact(arr);
	auto result=std::vector<int>{1,2,3,4,5};
    EXPECT_EQ(arr, result);
}

TEST(CompactTest, EmptyVector) {
    auto arr=std::vector<int>{};
	compact(arr);
	auto result=std::vector<int>{};
    EXPECT_EQ(arr, result);
}

TEST(CompactTest, Mixed) {
    auto arr=std::vector<int>{-1,-2,3,0,-4,0,5,0,0};
	compact(arr);
	auto result=std::vector<int>{-1,-2,3,-4,5};
    EXPECT_EQ(arr, result);
}
// thrust test
TEST(CompactThrustTest, PostiveInteger) {
    auto arr=thrust::host_vector<int>{1,2,3,4,0,5,0,0};
	compact_thrust(arr);
	// for(int i = 0; i < arr.size(); i++)
    //     std::cout << arr[i] << " ";
	// std::cout << std::endl;

	auto result=thrust::host_vector<int>{1,2,3,4,5};
    EXPECT_EQ(arr, result);
}

TEST(CompactThrustTest, EmptyVector) {
    auto arr=thrust::host_vector<int>{};
	compact_thrust(arr);
	auto result=thrust::host_vector<int>{};
    EXPECT_EQ(arr, result);
}

TEST(CompactThrustTest, Mixed) {
    auto arr=thrust::host_vector<int>{-1,-2,3,0,-4,0,5,0,0};
	compact_thrust(arr);
	auto result=thrust::host_vector<int>{-1,-2,3,-4,5};
    EXPECT_EQ(arr, result);
}
