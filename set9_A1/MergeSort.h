#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

// Обычная реализация

void Merge(std::vector<std::string>& str, size_t l, size_t m, size_t r) {
  size_t n1 = m - l;
  size_t n2 = r - m;

  std::vector<std::string> tmpl(n1);
  std::vector<std::string> tmpr(n2);

  for (size_t i = 0; i < n1; ++i) {
    tmpl[i] = str[l + i];
  }
  for (size_t j = 0; j < n2; ++j) {
    tmpr[j] = str[m + j];
  }

  size_t i = 0;
  size_t j = 0;
  size_t k = l;

  while (i < n1 && j < n2) {
    size_t p = 0;
    while (p < tmpl[i].size() && p < tmpr[j].size()) {
      if (tmpl[i][p] != tmpr[j][p]) {
        break;
      }
      ++p;
    }

    bool leftIsLess = false;
    if (p == tmpl[i].size() && p == tmpr[j].size()) {
      leftIsLess = false;
    }
    else if (p == tmpl[i].size()) {
      leftIsLess = true;
    }
    else if (p == tmpr[j].size()) {
      leftIsLess = false;
    }
    else {
      leftIsLess = (tmpl[i][p] < tmpr[j][p]);
    }

    if (leftIsLess) {
      str[k] = tmpl[i];
      ++i;
    }
    else {
      str[k] = tmpr[j];
      ++j;
    }
    ++k;
  }

  for (size_t ind = i; ind < n1; ++ind) {
    str[k] = tmpl[ind];
    ++k;
  }
  for (size_t ind = j; ind < n2; ++ind) {
    str[k] = tmpr[ind];
    ++k;
  }
}

void MergeSort(std::vector<std::string>& str, size_t l, size_t r) {
  if (l + 1 < r) {
    size_t m = l + (r - l) / 2;
    MergeSort(str, l, m);
    MergeSort(str, m, r);
    Merge(str, l, m, r);
  }
}


// Реализация с подсчётом посимвольных сравнений

void Merge(std::vector<std::string>& str, size_t l, size_t m, size_t r, long long& cmp) {
  size_t n1 = m - l;
  size_t n2 = r - m;

  std::vector<std::string> tmpl(n1);
  std::vector<std::string> tmpr(n2);

  for (size_t i = 0; i < n1; ++i) {
    tmpl[i] = str[l + i];
  }
  for (size_t j = 0; j < n2; ++j) {
    tmpr[j] = str[m + j];
  }

  size_t i = 0;
  size_t j = 0;
  size_t k = l;

  while (i < n1 && j < n2) {
    size_t p = 0;
    while (p < tmpl[i].size() && p < tmpr[j].size()) {
      ++cmp;
      if (tmpl[i][p] != tmpr[j][p]) {
        break;
      }
      ++p;
    }

    bool leftIsLess = false;
    if (p == tmpl[i].size() && p == tmpr[j].size()) {
      leftIsLess = false;
    }
    else if (p == tmpl[i].size()) {
      leftIsLess = true;
    }
    else if (p == tmpr[j].size()) {
      leftIsLess = false;
    }
    else {
      ++cmp;
      leftIsLess = (tmpl[i][p] < tmpr[j][p]);
    }

    if (leftIsLess) {
      str[k] = tmpl[i];
      ++i;
    }
    else {
      str[k] = tmpr[j];
      ++j;
    }
    ++k;
  }

  for (size_t ind = i; ind < n1; ++ind) {
    str[k] = tmpl[ind];
    ++k;
  }
  for (size_t ind = j; ind < n2; ++ind) {
    str[k] = tmpr[ind];
    ++k;
  }
}

void MergeSort(std::vector<std::string>& str, size_t l, size_t r, long long& cmp) {
  if (l + 1 < r) {
    size_t m = l + (r - l) / 2;
    MergeSort(str, l, m, cmp);
    MergeSort(str, m, r, cmp);
    Merge(str, l, m, r, cmp);
  }
}


#endif