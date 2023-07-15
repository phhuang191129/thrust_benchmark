#include"compact.h"
#include<vector>
#include<gtest/gtest.h>

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
