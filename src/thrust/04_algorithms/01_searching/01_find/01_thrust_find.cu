#include <thrust/device_vector.h>
#include <thrust/execution_policy.h>
#include <thrust/find.h>
#include <thrust/iterator/counting_iterator.h>

#include <iostream>
#include <vector>
void GpuWork(const std::vector<int>& v) {
  thrust::device_vector<int> input(9);

  thrust::copy(v.begin(), v.end(), input.begin());

  auto printiter = [&](const thrust::device_vector<int>::iterator& iterator) {
    if (iterator != input.end()) {
      // Print the value pointed to by the iterator
      std::cout << "Value found: " << *iterator << std::endl;
    } else {
      std::cout << "Value not found" << std::endl;
    }
  };

  for (const int n : {3, 5, 9}) {
    (thrust::find(thrust::device, input.begin(), input.end(), n) ==
     std::end(input))
        ? std::cout << "input does not contain " << n << '\n'
        : std::cout << "input contains " << n << '\n';
  }
  thrust::device_vector<int>::iterator iter;

  iter = thrust::find(thrust::device, input.begin(), input.end(), 9);
  printiter(iter);
}

int main() {
  std::vector<int> v{9, 0, 4, 1, 8, 3, 8, 2, 9};

  GpuWork(v);
  return 0;
}