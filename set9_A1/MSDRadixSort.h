#ifndef MSDRADIXSORT_H
#define MSDRADIXSORT_H

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

const size_t rsize = 128;

// Обычная реализация

void MSDRadixSortTr(std::vector<std::string>& str, size_t l, size_t r, size_t p, std::vector<std::string>& aux) {
  if (l + 1 >= r) {
    return;
  }

  std::vector <int> cnt(rsize + 5, 0);

  for (size_t i = l; i < r; ++i) {
    char c = (p < str[i].size() ? str[i][p] : 0);
    ++cnt[c + 1];
  }

  for (size_t i = 0; i < rsize + 1; ++i) {
    cnt[i + 1] += cnt[i];
  }

  for (size_t i = l; i < r; ++i) {
    char c = (p < str[i].size() ? str[i][p] : 0);
    aux[cnt[c]] = str[i];
    ++cnt[c];
  }

  for (size_t i = l; i < r; ++i) {
    str[i] = aux[i - l];
  }

  for (size_t i = 0; i < rsize; ++i) {
    MSDRadixSortTr(str, l + cnt[i], l + cnt[i + 1], p + 1, aux);
  }
}

void MSDRadixSort(std::vector<std::string>& str, size_t l, size_t r, size_t p) {
  std::vector<std::string> aux(r);
  MSDRadixSortTr(str, 0, r, 0, aux);
}


// Реализация с подсчётом посимвольных сравнений

void MSDRadixSortTr(std::vector<std::string>& str, size_t l, size_t r, size_t p, std::vector<std::string>& aux, long long& cmp) {
  if (l + 1 >= r) {
    return;
  }

  std::vector<int> cnt(rsize + 5, 0);

  for (size_t i = l; i < r; ++i) {
    char c = (p < str[i].size() ? str[i][p] : 0);
    ++cnt[c + 1];
  }

  for (size_t i = 0; i < rsize + 1; ++i) {
    cnt[i + 1] += cnt[i];
  }

  for (size_t i = l; i < r; ++i) {
    char c = (p < str[i].size() ? str[i][p] : 0);
    aux[cnt[c]] = str[i];
    ++cnt[c];
  }

  for (size_t i = l; i < r; ++i) {
    str[i] = aux[i - l];
  }

  for (size_t i = 0; i < rsize; ++i) {
    MSDRadixSortTr(str, l + cnt[i], l + cnt[i + 1], p + 1, aux, cmp);
  }
}

void MSDRadixSort(std::vector<std::string>& str, size_t l, size_t r, size_t p, long long& cmp) {
  std::vector<std::string> aux(r);
  MSDRadixSortTr(str, 0, r, 0, aux, cmp);
}

#endif