#include <optional>
#include <string>

template <size_t I, size_t SUM, size_t N> struct sum_divisors {
  enum {
    value = N % I == 0 ? I * I == N
                             ? SUM + I
                             : sum_divisors<I - 1, SUM + I + (N / I), N>::value
                       : sum_divisors<I - 1, SUM, N>::value
  };
};

template <size_t SUM, size_t N> struct sum_divisors<1, SUM, N> {
  enum { value = SUM + 1 };
};

template <size_t N, size_t M, size_t Last> struct sqrt_impl {
  enum {
    value = M != Last && sqrt_impl<N, (M + N / M) / 2, M>::value != M
                ? sqrt_impl<N, (M + N / M) / 2, M>::value
                : M
  };
};

template <size_t N> struct sqrt_ {
  enum { value = sqrt_impl<N, N / 2, 0>::value };
};

template <size_t N> struct test_ {
  enum { value = test_<N - 1>::value + 1 };
};
template <> struct test_<1> {
  enum { value = 1 };
};