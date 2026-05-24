#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include "StringGenerator.h"
#include "StringSortTester.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "MergeSortLCP.h"
#include "TernaryQuickSort.h"
#include "MSDRadixSort.h"
#include "HybridRadixSort.h"

int main() {
  std::ofstream outTimeRandom("TimeRandom.txt");
  std::ofstream outTimeReversed("TimeReversed.txt");
  std::ofstream outTimeAlmostSorted("TimeAlmostSorted.txt");
  std::ofstream outCmpRandom("ComparisonsRandom.txt");
  std::ofstream outCmpReversed("ComparisonsReversed.txt");
  std::ofstream outCmpAlmostSorted("ComparisonsAlmostSorted.txt");

  StringGenerator stringGenerator;

  for (size_t size = 100; size <= 3000; size += 100) {
    std::vector<std::string> randomArray = stringGenerator.GetRandomArray(size);
    std::vector<std::string> reversedArray = stringGenerator.GetReversedArray(size);
    std::vector<std::string> almostSortedArray = stringGenerator.GetAlmostSortedArray(size);

    // MergeSort
    double mergeRandomTime = SortTester::MeasureTime(randomArray, [](std::vector<std::string>& a) {
      MergeSort(a, 0, a.size());
      });
    double mergeReversedTime = SortTester::MeasureTime(reversedArray, [](std::vector<std::string>& a) {
      MergeSort(a, 0, a.size());
      });
    double mergeAlmostSortedTime = SortTester::MeasureTime(almostSortedArray, [](std::vector<std::string>& a) {
      MergeSort(a, 0, a.size());
      });

    double mergeRandomCmp = SortTester::MeasureComparisons(randomArray, [](std::vector<std::string>& a, long long& c) {
      MergeSort(a, 0, a.size(), c);
      });
    double mergeReversedCmp = SortTester::MeasureComparisons(reversedArray, [](std::vector<std::string>& a, long long& c) {
      MergeSort(a, 0, a.size(), c);
      });
    double mergeAlmostSortedCmp = SortTester::MeasureComparisons(almostSortedArray, [](std::vector<std::string>& a, long long& c) {
      MergeSort(a, 0, a.size(), c);
      });

    // QuickSort
    double quickRandomTime = SortTester::MeasureTime(randomArray, [](std::vector<std::string>& a) {
      QuickSort(a, 0, a.size());
      });
    double quickReversedTime = SortTester::MeasureTime(reversedArray, [](std::vector<std::string>& a) {
      QuickSort(a, 0, a.size());
      });
    double quickAlmostSortedTime = SortTester::MeasureTime(almostSortedArray, [](std::vector<std::string>& a) {
      QuickSort(a, 0, a.size());
      });

    double quickRandomCmp = SortTester::MeasureComparisons(randomArray, [](std::vector<std::string>& a, long long& c) {
      QuickSort(a, 0, a.size(), c);
      });
    double quickReversedCmp = SortTester::MeasureComparisons(reversedArray, [](std::vector<std::string>& a, long long& c) {
      QuickSort(a, 0, a.size(), c);
      });
    double quickAlmostSortedCmp = SortTester::MeasureComparisons(almostSortedArray, [](std::vector<std::string>& a, long long& c) {
      QuickSort(a, 0, a.size(), c);
      });

    // MergeSortLCP
    double mergeLcpRandomTime = SortTester::MeasureTime(randomArray, [](std::vector<std::string>& a) {
      MergeSortLCP(a, 0, a.size());
      });
    double mergeLcpReversedTime = SortTester::MeasureTime(reversedArray, [](std::vector<std::string>& a) {
      MergeSortLCP(a, 0, a.size());
      });
    double mergeLcpAlmostSortedTime = SortTester::MeasureTime(almostSortedArray, [](std::vector<std::string>& a) {
      MergeSortLCP(a, 0, a.size());
      });

    double mergeLcpRandomCmp = SortTester::MeasureComparisons(randomArray, [](std::vector<std::string>& a, long long& c) {
      MergeSortLCP(a, 0, a.size(), c);
      });
    double mergeLcpReversedCmp = SortTester::MeasureComparisons(reversedArray, [](std::vector<std::string>& a, long long& c) {
      MergeSortLCP(a, 0, a.size(), c);
      });
    double mergeLcpAlmostSortedCmp = SortTester::MeasureComparisons(almostSortedArray, [](std::vector<std::string>& a, long long& c) {
      MergeSortLCP(a, 0, a.size(), c);
      });

    // TernaryQuickSort
    double ternaryRandomTime = SortTester::MeasureTime(randomArray, [](std::vector<std::string>& a) {
      auto _ = TernaryQuickSort(a, 0);
      });
    double ternaryReversedTime = SortTester::MeasureTime(reversedArray, [](std::vector<std::string>& a) {
      auto _ = TernaryQuickSort(a, 0);
      });
    double ternaryAlmostSortedTime = SortTester::MeasureTime(almostSortedArray, [](std::vector<std::string>& a) {
      auto _ = TernaryQuickSort(a, 0);
      });

    double ternaryRandomCmp = SortTester::MeasureComparisons(randomArray, [](std::vector<std::string>& a, long long& c) {
      auto _ = TernaryQuickSort(a, 0, c);
      });
    double ternaryReversedCmp = SortTester::MeasureComparisons(reversedArray, [](std::vector<std::string>& a, long long& c) {
      auto _ = TernaryQuickSort(a, 0, c);
      });
    double ternaryAlmostSortedCmp = SortTester::MeasureComparisons(almostSortedArray, [](std::vector<std::string>& a, long long& c) {
      auto _ = TernaryQuickSort(a, 0, c);
      });

    // MSDRadixSort
    double msdRandomTime = SortTester::MeasureTime(randomArray, [](std::vector<std::string>& a) {
      MSDRadixSort(a, 0, a.size(), 0);
      });
    double msdReversedTime = SortTester::MeasureTime(reversedArray, [](std::vector<std::string>& a) {
      MSDRadixSort(a, 0, a.size(), 0);
      });
    double msdAlmostSortedTime = SortTester::MeasureTime(almostSortedArray, [](std::vector<std::string>& a) {
      MSDRadixSort(a, 0, a.size(), 0);
      });

    double msdRandomCmp = SortTester::MeasureComparisons(randomArray, [](std::vector<std::string>& a, long long& c) {
      MSDRadixSort(a, 0, a.size(), 0, c);
      });
    double msdReversedCmp = SortTester::MeasureComparisons(reversedArray, [](std::vector<std::string>& a, long long& c) {
      MSDRadixSort(a, 0, a.size(), 0, c);
      });
    double msdAlmostSortedCmp = SortTester::MeasureComparisons(almostSortedArray, [](std::vector<std::string>& a, long long& c) {
      MSDRadixSort(a, 0, a.size(), 0, c);
      });

    // HybridRadixSort
    double hybridRandomTime = SortTester::MeasureTime(randomArray, [](std::vector<std::string>& a) {
      HybridRadixSort(a, 0, a.size(), 0);
      });
    double hybridReversedTime = SortTester::MeasureTime(reversedArray, [](std::vector<std::string>& a) {
      HybridRadixSort(a, 0, a.size(), 0);
      });
    double hybridAlmostSortedTime = SortTester::MeasureTime(almostSortedArray, [](std::vector<std::string>& a) {
      HybridRadixSort(a, 0, a.size(), 0);
      });

    double hybridRandomCmp = SortTester::MeasureComparisons(randomArray, [](std::vector<std::string>& a, long long& c) {
      HybridRadixSort(a, 0, a.size(), 0, c);
      });
    double hybridReversedCmp = SortTester::MeasureComparisons(reversedArray, [](std::vector<std::string>& a, long long& c) {
      HybridRadixSort(a, 0, a.size(), 0, c);
      });
    double hybridAlmostSortedCmp = SortTester::MeasureComparisons(almostSortedArray, [](std::vector<std::string>& a, long long& c) {
      HybridRadixSort(a, 0, a.size(), 0, c);
      });

    // Write time
    outTimeRandom << size
      << ' ' << mergeRandomTime
      << ' ' << quickRandomTime
      << ' ' << mergeLcpRandomTime
      << ' ' << ternaryRandomTime
      << ' ' << msdRandomTime
      << ' ' << hybridRandomTime << '\n';

    outTimeReversed << size
      << ' ' << mergeReversedTime
      << ' ' << quickReversedTime
      << ' ' << mergeLcpReversedTime
      << ' ' << ternaryReversedTime
      << ' ' << msdReversedTime
      << ' ' << hybridReversedTime << '\n';

    outTimeAlmostSorted << size
      << ' ' << mergeAlmostSortedTime
      << ' ' << quickAlmostSortedTime
      << ' ' << mergeLcpAlmostSortedTime
      << ' ' << ternaryAlmostSortedTime
      << ' ' << msdAlmostSortedTime
      << ' ' << hybridAlmostSortedTime << '\n';

    // Write comparisons
    outCmpRandom << size
      << ' ' << mergeRandomCmp
      << ' ' << quickRandomCmp
      << ' ' << mergeLcpRandomCmp
      << ' ' << ternaryRandomCmp
      << ' ' << msdRandomCmp
      << ' ' << hybridRandomCmp << '\n';

    outCmpReversed << size
      << ' ' << mergeReversedCmp
      << ' ' << quickReversedCmp
      << ' ' << mergeLcpReversedCmp
      << ' ' << ternaryReversedCmp
      << ' ' << msdReversedCmp
      << ' ' << hybridReversedCmp << '\n';

    outCmpAlmostSorted << size
      << ' ' << mergeAlmostSortedCmp
      << ' ' << quickAlmostSortedCmp
      << ' ' << mergeLcpAlmostSortedCmp
      << ' ' << ternaryAlmostSortedCmp
      << ' ' << msdAlmostSortedCmp
      << ' ' << hybridAlmostSortedCmp << '\n';

    if (size % 500 == 0) {
      std::cout << "Processed size: " << size << '\n';
    }
  }

  std::cout << "Done\n";
  return 0;
}