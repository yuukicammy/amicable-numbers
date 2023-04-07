#include "amicable_numbers.hpp"
#include <iostream>
#include <optional>
#include <tuple>
#include <utility>

constexpr size_t sum_div(size_t target) { // c++14
  size_t sum{1};
  for (size_t i = 2; i * i <= target; i++) {
    if (target % i == 0) {
      sum += i;
      if (i * i == target) {
        break;
      }
      sum += target / i;
    }
  }
  return sum;
}

constexpr bool has_amicable_numbers(size_t target) { // c++14
  size_t candidate{sum_div(target)};
  return candidate != target && sum_div(candidate) == target ? true : false;
}

constexpr std::optional<std::tuple<size_t, size_t>> // c++17
find_max_amicable_numbers(size_t n) {
  if (n == 2) {
    return std::nullopt;
  }
  size_t candidate{sum_div(n)};
  if (has_amicable_numbers(n)) {
    return std::make_tuple(n, candidate);
  }
  return find_max_amicable_numbers(n - 1);
}

int main(int argc, char *argv[]) {
  // Please set the maxmum number as you want!
  constexpr size_t kMax{15000};
  constexpr auto res{find_max_amicable_numbers(kMax)};

  // Error occurs if any amicable numbers are not found at compile time.
  static_assert(
      std::is_same_v<decltype(res)::value_type, std::tuple<size_t, size_t>>);

  // For result check at runtime.
  if (res.has_value()) {
    std::cout << "Found amicable numbers!" << std::endl;
    std::cout << "The maxinum pair is (" << std::get<0>(res.value()) << ","
              << std::get<1>(res.value()) << ")." << std::endl;
  } else {
    std::cout << "Not found amicable numbers." << std::endl;
  }
  return 0;
}
