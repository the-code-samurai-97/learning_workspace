#include <thrust/device_vector.h>
#include <thrust/execution_policy.h>
#include <thrust/find.h>

#include <iostream>
#include <vector>

struct greater_than_four {
  __host__ __device__ bool operator()(int x) { return x > 4; }
};

void GpuWork(const std::vector<int>& v) {
  thrust::device_vector<int> input(9);

  thrust::copy(v.begin(), v.end(), input.begin());

  for (const int n : {3, 5, 9}) {
    auto iter = thrust::find_if(thrust::device, input.begin(), input.end(),
                                greater_than_four());

    // Check if the element was found
    if (iter != input.end()) {
      std::cout << "input contains " << n << '\n';
    } else {
      std::cout << "input does not contain " << n << '\n';
    }
  }
  for (const int n : {3, 5, 9}) {
    auto iter =
        thrust::find_if(thrust::device, input.begin(), input.end(),
                        [n] __device__(int x) -> bool { return x > n; });

    // Check if the element was found
    if (iter != input.end()) {
      std::cout << "input contains " << n << '\n';
    } else {
      std::cout << "input does not contain " << n << '\n';
    }
  }
}

int main() {
  std::vector<int> v{9, 0, 4, 1, 8, 3, 8, 2, 9};

  GpuWork(v);
  return 0;
}