#include <thrust/device_vector.h>
#include <thrust/host_vector.h>

#include <iostream>
#include <string>
void PrintEqual(size_t num_of_times) {
  std::cout << "\n\n";
  for (size_t i{0}; i <= num_of_times; ++i) {
    std::cout << "=";
  }
  std::cout << "\n\n";
}
template <typename T>
void PrintThrustVector(const std::string& message,
                       thrust::host_vector<T>& list) {
  PrintEqual(20);
  std::cout << message << '\n';
  int i{0};
  for (const auto& num : list) {
    std::cout << "list[" << i << "] = " << num << '\n';
    ++i;
  }
  PrintEqual(20);
}
template <typename T>
void PrintThrustVector(const std::string& message,
                       thrust::device_vector<T>& list) {
  PrintEqual(20);
  std::cout << message << '\n';
  int i{0};
  for (const auto& num : list) {
    std::cout << "list[" << i << "] = " << num << '\n';
    ++i;
  }
  PrintEqual(20);
}

int main() {
  thrust::host_vector<int> cpu_list(12, 2);  // size,fill value

  PrintThrustVector(" Initial Vecotor", cpu_list);

  thrust::fill(cpu_list.begin(), cpu_list.begin() + 8, 13);
  PrintThrustVector("Fill 0 to 7 13", cpu_list);

  thrust::device_vector<int> device_list(
      cpu_list.begin(), cpu_list.begin() + cpu_list.size() - 5);
  PrintThrustVector("device Vector", device_list);

  thrust::sequence(device_list.begin(), device_list.end(), 99, 2);
  PrintThrustVector("device Vector After sequence", device_list);

  thrust::copy(device_list.begin(), device_list.end(), cpu_list.begin());
  PrintThrustVector("cpu Vector after copying from the device", cpu_list);

  return 0;
}
