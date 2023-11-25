#include <thrust/mismatch.h>
#include <thrust/device_vector.h>
#include <thrust/execution_policy.h>
int main() {
    thrust::device_vector<int> vec1(4);
    thrust::device_vector<int> vec2(4);
    vec1[0] = 0;
    vec2[0] = 0;
    vec1[1] = 5;
    vec2[1] = 5;
    vec1[2] = 3;
    vec2[2] = 8;
    vec1[3] = 7;
    vec2[3] = 7;

//    typedef thrust::device_vector<int>::iterator Iterator;
//    thrust::pair <Iterator, Iterator> result;
    const auto result = thrust::mismatch(thrust::device, vec1.begin(), vec1.end(), vec2.begin());

    std::cout<<"Result v1 "<< *result.first<<std::endl;
    std::cout<<"Result v2 "<< *result.second<<std::endl;

}