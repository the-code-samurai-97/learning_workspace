#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    ///////////////////////////////////6 and 4
    std::vector<int> v1{1, 1, 2, 4,4,5,6,7,4};
    std::vector<int> v2{1, 1, 2, 4,4,5,4,7,4};

    const auto result = std::mismatch(v1.begin(), v1.end(),v2.begin());

    std::cout<<"Result v1 "<< *result.first<<std::endl;
    std::cout<<"Result v2 "<< *result.second<<std::endl;


    return 0;
}