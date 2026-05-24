#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

// Обычная реализация

size_t Partition(std::vector<std::string>& str, size_t l, size_t r) {
  size_t mid = l + (r - l) / 2;
  std::string pivot = str[mid];
  std::swap(str[mid], str[r - 1]);

  size_t i = l;

  for (size_t j = l; j < r - 1; ++j) {
    size_t p = 0;
    while (p < str[j].size() && p < pivot.size()) {
      if (str[j][p] != pivot[p]) {
        break;
      }
      ++p;
    }

    bool less = false;
    if (p == str[j].size() && p == pivot.size()) {
      less = false;
    }
    else if (p == str[j].size()) {
      less = true;
    }
    else if (p == pivot.size()) {
      less = false;
    }
    else {
      less = (str[j][p] < pivot[p]);
    }

    if (less) {
      std::swap(str[i], str[j]);
      ++i;
    }
  }

  std::swap(str[i], str[r - 1]);
  return i;
}

void QuickSort(std::vector<std::string>& str, size_t l, size_t r) {
  if (l + 1 < r) {
    size_t p = Partition(str, l, r);
    QuickSort(str, l, p);
    QuickSort(str, p + 1, r);
  }
}


// Реализация с подсчётом посимвольных сравнений

size_t Partition(std::vector<std::string>& str, size_t l, size_t r, long long& cmp) {
  size_t mid = l + (r - l) / 2;
  std::string pivot = str[mid];
  std::swap(str[mid], str[r - 1]);

  size_t i = l;

  for (size_t j = l; j < r - 1; ++j) {
    size_t p = 0;
    while (p < str[j].size() && p < pivot.size()) {
      ++cmp;
      if (str[j][p] != pivot[p]) {
        break;
      }
      ++p;
    }

    bool less = false;
    if (p == str[j].size() && p == pivot.size()) {
      less = false;
    }
    else if (p == str[j].size()) {
      less = true;
    }
    else if (p == pivot.size()) {
      less = false;
    }
    else {
      ++cmp;
      less = (str[j][p] < pivot[p]);
    }

    if (less) {
      std::swap(str[i], str[j]);
      ++i;
    }
  }

  std::swap(str[i], str[r - 1]);
  return i;
}

void QuickSort(std::vector<std::string>& str, size_t l, size_t r, long long& cmp) {
  if (l + 1 < r) {
    size_t p = Partition(str, l, r, cmp);
    QuickSort(str, l, p, cmp);
    QuickSort(str, p + 1, r, cmp);
  }
}

#endif
