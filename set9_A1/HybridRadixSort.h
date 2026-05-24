#ifndef MSDRADIXQUICKSORT_H
#define MSDRADIXQUICKSORT_H

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

const size_t hsize = 128;
const size_t sw = 74;

// Обычная реализация

std::vector<std::string> TernaryQuickSortR(std::vector<std::string>& str, size_t l) {
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

  rl = TernaryQuickSortR(rl, l);
  re = TernaryQuickSortR(re, l + 1);
  rb = TernaryQuickSortR(rb, l);

  str = rx;
  str.insert(str.end(), rl.begin(), rl.end());
  str.insert(str.end(), re.begin(), re.end());
  str.insert(str.end(), rb.begin(), rb.end());
  return str;
}

void HybridRadixSortTr(std::vector<std::string>& str, size_t l, size_t r, size_t p, std::vector<std::string>& aux) {
  if (sw + l > r) {
    std::vector<std::string> subst(str.begin() + l, str.begin() + r);
    auto _ = TernaryQuickSortR(subst, p);
    for (size_t i = l; i < r; ++i) {
      str[i] = subst[i - l];
    }
    return;
  }

  std::vector<int> cnt(hsize + 5, 0);

  for (size_t i = l; i < r; ++i) {
    char c = (p < str[i].size() ? str[i][p] : 0);
    ++cnt[c + 1];
  }

  for (size_t i = 0; i < hsize + 1; ++i) {
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

  for (size_t i = 0; i < hsize; ++i) {
    HybridRadixSortTr(str, l + cnt[i], l + cnt[i + 1], p + 1, aux);
  }
}

void HybridRadixSort(std::vector<std::string>& str, size_t l, size_t r, size_t p) {
  std::vector<std::string> aux(r);
  HybridRadixSortTr(str, 0, r, 0, aux);
}


// Реализация с подсчётом посимвольных сравнений

std::vector<std::string> TernaryQuickSortR(std::vector<std::string>& str, size_t l, long long& cmp) {
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

  rl = TernaryQuickSortR(rl, l, cmp);
  re = TernaryQuickSortR(re, l + 1, cmp);
  rb = TernaryQuickSortR(rb, l, cmp);

  str = rx;
  str.insert(str.end(), rl.begin(), rl.end());
  str.insert(str.end(), re.begin(), re.end());
  str.insert(str.end(), rb.begin(), rb.end());
  return str;
}

void HybridRadixSortTr(std::vector<std::string>& str, size_t l, size_t r, size_t p, std::vector<std::string>& aux, long long& cmp) {
  if (sw + l > r) {
    std::vector<std::string> subst(str.begin() + l, str.begin() + r);
    auto _ = TernaryQuickSortR(subst, p, cmp);
    for (size_t i = l; i < r; ++i) {
      str[i] = subst[i - l];
    }
    return;
  }

  std::vector<int> cnt(hsize + 5, 0);

  for (size_t i = l; i < r; ++i) {
    char c = (p < str[i].size() ? str[i][p] : 0);
    ++cnt[c + 1];
  }

  for (size_t i = 0; i < hsize + 1; ++i) {
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

  for (size_t i = 0; i < hsize; ++i) {
    HybridRadixSortTr(str, l + cnt[i], l + cnt[i + 1], p + 1, aux, cmp);
  }
}

void HybridRadixSort(std::vector<std::string>& str, size_t l, size_t r, size_t p, long long& cmp) {
  std::vector<std::string> aux(r);
  HybridRadixSortTr(str, 0, r, 0, aux, cmp);
}

#endif