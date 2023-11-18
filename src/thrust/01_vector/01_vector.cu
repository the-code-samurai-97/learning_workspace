#include <thrust/device_vector.h>
#include <thrust/host_vector.h>

int main() {
  thrust::host_vector<int> host_array(5);

  host_array[0] = 1;
  host_array[1] = 2;
  host_array[2] = 3;
  host_array[3] = 4;
  host_array[4] = 5;
  int i{0};
  for (const auto& num : host_array) {
    std::cout << "host_array[" << i << "] = " << num << '\n';
    ++i;
  }
  i = 0;
  thrust::device_vector<int> device_array = host_array;
  for (const auto& num : device_array) {
    std::cout << "device_array[" << i << "] = " << num << '\n';
    ++i;
  }

  return 0;
}