#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1, 1, 2, 4};

  for (const int n : {3, 5}) {
    (std::find_if(v.begin(), v.end(), [n](int x) -> bool { return x > n; }) ==
     std::end(v))
        ? std::cout << "v does not contain greater than " << n << '\n'
        : std::cout << "v contains greater than" << n << '\n';
  }

  return 0;
}