#include <thrust/device_malloc.h>
#include <thrust/device_ptr.h>
#include <thrust/device_reference.h>
#include <thrust/device_vector.h>
template <typename T>
void PrintThrustVector(const std::string& message,
                       thrust::device_vector<T>& list) {
  std::cout << message << '\n';
  int i{0};
  for (const auto& num : list) {
    std::cout << "list[" << i << "] = " << num << '\n';
    ++i;
  }
}
int main() {
  // From Raw Pointer to Device memory
  constexpr size_t N{10};
  int* raw_ptr;
  cudaMalloc(&raw_ptr,
             N * sizeof(int));  // allocating in device in an array of 10
  thrust::device_ptr<int> device_ptr(
      raw_ptr);  // giving the starting address of raw pointer to device

  thrust::sequence(device_ptr, device_ptr + N, 4, 5);
  // Print the address and value of each array element on the device

  std::cout << " device_ptr\n";
  for (int i = 0; i < N; ++i) {
    std::cout << "device_ptr Address " << device_ptr + i << " device_ptr value "
              << device_ptr[i] << '\n';
  }
  std::cout << " device reference\n";

  for (int i{0}; i < N; ++i) {
    thrust::device_reference<int> device_reference = device_ptr[i];

    // Print the address and value of the device_reference
    std::cout << "device_reference Address " << &device_reference
              << " device_reference value " << device_reference << '\n';
  }

  // from device thrust to raw pointer
  thrust::device_ptr<int> dev_ptr =
      thrust::device_malloc<int>(N);  // cudamalloc + deviceptr
  thrust::sequence(dev_ptr, dev_ptr + N, 3, 6);

  int* raw_ptr_1 = new int[N];

  // Copy data from the device to the host
  thrust::copy(dev_ptr, dev_ptr + N, raw_ptr_1);

  // Print the address and value of each array element on the host
  for (int i = 0; i < N; ++i) {
    std::cout << "address " << &raw_ptr_1[i] << " value " << raw_ptr_1[i]
              << '\n';
  }

  delete[] raw_ptr_1;
  cudaFree(raw_ptr);
  return 0;
}