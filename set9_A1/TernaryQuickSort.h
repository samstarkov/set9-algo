#ifndef TERNARYQUICKSORT_H
#define TERNARYQUICKSORT_H

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

// Обычная реализация

std::vector<std::string> TernaryQuickSort(std::vector<std::string>& str, size_t l) {
  if (str.size() <= 1) {
    return str;
  }

  std::vector<std::string> r;
  std::vector<std::string> rx;
  for (auto& s : str) {
    if (s.size() != l) {
      r.push_back(s);
    }
    else {
      rx.push_back(s);
    }
  }

  std::string pivot = r[r.size() / 2];

  std::vector<std::string> rl;
  std::vector<std::string> re;
  std::vector<std::string> rb;

  for (auto& s : r) {
    if (s[l] < pivot[l]) {
      rl.push_back(s);
      continue;
    }
    if (s[l] > pivot[l]) {
      rb.push_back(s);
      continue;
    }
    re.push_back(s);
  }

  rl = TernaryQuickSort(rl, l);
  re = TernaryQuickSort(re, l + 1);
  rb = TernaryQuickSort(rb, l);

  str = rx;
  str.insert(str.end(), rl.begin(), rl.end());
  str.insert(str.end(), re.begin(), re.end());
  str.insert(str.end(), rb.begin(), rb.end());
  return str;
}


// Реализация с подсчётом посимвольных сравнений

std::vector<std::string> TernaryQuickSort(std::vector<std::string>& str, size_t l, long long& cmp) {
  if (str.size() <= 1) {
    return str;
  }

  std::vector<std::string> r;
  std::vector<std::string> rx;
  for (auto& s : str) {
    if (s.size() != l) {
      r.push_back(s);
    }
    else {
      rx.push_back(s);
    }
  }

  std::string pivot = r[r.size() / 2];

  std::vector<std::string> rl;
  std::vector<std::string> re;
  std::vector<std::string> rb;

  for (auto& s : r) {
    ++cmp;
    if (s[l] < pivot[l]) {
      rl.push_back(s);
      continue;
    }
    ++cmp;
    if (s[l] > pivot[l]) {
      rb.push_back(s);
      continue;
    }
    re.push_back(s);
  }

  rl = TernaryQuickSort(rl, l, cmp);
  re = TernaryQuickSort(re, l + 1, cmp);
  rb = TernaryQuickSort(rb, l, cmp);

  str = rx;
  str.insert(str.end(), rl.begin(), rl.end());
  str.insert(str.end(), re.begin(), re.end());
  str.insert(str.end(), rb.begin(), rb.end());
  return str;
}


#endif
