#ifndef STRINGGENERATOR_H
#define STRINGGENERATOR_H

#include <vector>
#include <string>
#include <random>
#include <algorithm>

std::random_device random_dev;
std::mt19937 generator(random_dev());

class StringGenerator {
private:
  const size_t maxSize = 3000;
  const size_t minLen = 10;
  const size_t maxLen = 200;
  const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#%:;^&*()-";

  std::vector<std::string> randArray;
  std::vector<std::string> reversedArray;
  std::vector<std::string> almostSortedArray;

  std::string GenerateString() {
    std::uniform_int_distribution<size_t> lenDistr(minLen, maxLen);
    std::uniform_int_distribution<size_t> charDistr(0, chars.size() - 1);
    size_t len = lenDistr(generator);
    std::string s(len, '\0');
    for (size_t i = 0; i < len; ++i) {
      s[i] = chars[charDistr(generator)];
    }
    return s;
  }

  void buildMainArrays() {
    for (size_t i = 0; i < maxSize; ++i) {
      std::string s = GenerateString();
      randArray.push_back(s);
      reversedArray.push_back(s);
      almostSortedArray.push_back(s);
    }
    std::sort(reversedArray.begin(), reversedArray.end(), std::greater<std::string>());
    std::sort(almostSortedArray.begin(), almostSortedArray.end());

    std::uniform_int_distribution<size_t> distr_ind(0, maxSize - 1);

    for (size_t i = 0; i < 50; ++i) {
      std::swap(almostSortedArray[distr_ind(generator)], almostSortedArray[distr_ind(generator)]);
    }
  }

public:
  StringGenerator() {
    buildMainArrays();
  }

  std::vector<std::string> GetRandomArray(size_t size) {
    return std::vector<std::string>(randArray.begin(), randArray.begin() + size);
  }

  std::vector<std::string> GetReversedArray(size_t size) {
    return std::vector<std::string>(reversedArray.begin(), reversedArray.begin() + size);
  }

  std::vector<std::string> GetAlmostSortedArray(size_t size) {
    return std::vector<std::string>(almostSortedArray.begin(), almostSortedArray.begin() + size);
  }
};

#endif