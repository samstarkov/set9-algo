#ifndef SORTTESTER_H
#define SORTTESTER_H

#include "StringGenerator.h"
#include <ctime>
#include <chrono>
#include <functional>

class SortTester {
public:
  static double MeasureTime(std::vector<std::string>& arr, std::function<void(std::vector<std::string>&)> sortFunc) {
    const int attempts = 5;
    long long allTime = 0;

    for (int t = 0; t < attempts; ++t) {
      std::vector<std::string> tmpArr = arr;

      auto start = std::chrono::high_resolution_clock::now();
      sortFunc(tmpArr);
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      long long microsec = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

      allTime += microsec;
    }

    return static_cast<double>(allTime) / attempts;
  }

  static double MeasureComparisons(std::vector<std::string>& arr, std::function<void(std::vector<std::string>&, long long&)> sortFunc) {
    const int attempts = 5;
    long long allComparisons = 0;

    for (int t = 0; t < attempts; ++t) {
      std::vector<std::string> tmpArr = arr;
      long long comparisons = 0;

      sortFunc(tmpArr, comparisons);

      allComparisons += comparisons;
    }

    return static_cast<double>(allComparisons) / attempts;
  }
};

#endif