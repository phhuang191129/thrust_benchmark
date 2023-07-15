#include"compact.h"
#include<vector>
#include <algorithm>
#include <iostream>

void compact(vector<int> &arr){
	auto it=std::copy_if (arr.begin(), arr.end(), arr.begin(), [](int i){return (i!=0);} );
	arr.resize(std::distance(arr.begin(),it));
}
