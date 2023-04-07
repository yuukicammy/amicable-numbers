# Compilation-time calculation of Amicable Numbers

Amicable numbers are a pair of positive integers, such that the sum of the proper divisors of each number in the pair is equal to the other number in the pair.

This paired numbers have a very romantic relationship.

This code was used for wedding entertainment. 
The Amicable numbers were calculated to represent the strong relatinoship between the groom and bride. Also, since modern C++ allows for complex computation at compile time, we take advantage of this to find the fraternity number at compile time.

## Requirements
- C++17 or higher

## How to use
1. Set the maxmum number. The program will calculate the maximum Amicable numbers from a number less than or equal to this number.
```
int main(int argc, char *argv[]) {
  // Please set the maxmum number as you want!
  constexpr size_t kMax{15000};
```

2. Build the program.
```
$ cmake .
$ make
```

3. Compile the program to show the result.
```
$ ./amicable_numbers
$ Found amicable numbers!
$ The maxinum pair is (14595,12285).
```


