#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{9, 0, 4, 1, 8, 3, 8, 2, 9};

  for (const int n : {3, 5}) {
    (std::find(v.begin(), v.end(), n) == std::end(v))
        ? std::cout << "v does not contain " << n << '\n'
        : std::cout << "v contains " << n << '\n';
  }
  const std::vector<int>::iterator found_iterator =
      std::find(v.begin(), v.end(), 2);

  std::cout << " found_iterator " << *found_iterator << "\n";

  return 0;
}