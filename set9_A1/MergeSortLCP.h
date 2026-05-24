#ifndef MERGESORTLCP_H
#define MERGESORTLCP_H

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

// Обычная реализация

std::pair<int, int> GetLCP(const std::string& a, const std::string& b, int k) {
  for (int i = k; i < std::min(a.size(), b.size()); ++i) {
    if (a[i] != b[i]) {
      if (a[i] < b[i]) return { 0, i };
      if (a[i] == b[i]) return { 1, i };
      if (a[i] > b[i]) return { 2, i };
    }
  }

  if (a.size() == b.size()) {
    return { 1, static_cast<int>(a.size()) };
  }
  return (a.size() < b.size())
    ? std::make_pair(0, static_cast<int>(a.size()))
    : std::make_pair(2, static_cast<int>(b.size()));
}

std::vector<std::pair<std::string, int>> Merge(
  std::vector<std::pair<std::string, int>>& left,
  std::vector<std::pair<std::string, int>>& right) {

  std::vector<std::pair<std::string, int>> res;
  res.reserve(left.size() + right.size());

  auto itl = left.begin();
  auto itr = right.begin();

  while (itl != left.end() && itr != right.end()) {
    if (itl->second > itr->second) {
      res.push_back(*itl);
      ++itl;
    }
    else if (itl->second < itr->second) {
      res.push_back(*itr);
      ++itr;
    }
    else {
      auto pr = GetLCP(itl->first, itr->first, itl->second);
      int order = pr.first;
      int lcp = pr.second;
      if (order == 0) {
        res.push_back(*itl);
        ++itl;
        itr->second = lcp;
      }
      else {
        res.push_back(*itr);
        ++itr;
        itl->second = lcp;
      }
    }
  }

  while (itl != left.end()) {
    res.push_back(*itl);
    ++itl;
  }

  while (itr != right.end()) {
    res.push_back(*itr);
    ++itr;
  }

  return res;
}

std::vector<std::pair<std::string, int>> MergeSortLCPs(
  std::vector<std::string>::iterator begin,
  std::vector<std::string>::iterator end) {

  if (std::next(begin) == end) {
    return { {*begin, 0} };
  }

  auto mid = begin + (end - begin) / 2;
  auto left = MergeSortLCPs(begin, mid);
  auto right = MergeSortLCPs(mid, end);

  return Merge(left, right);
}

void MergeSortLCP(std::vector<std::string>& str, size_t l, size_t r) {
  if (r - l <= 1) return;

  auto sp = MergeSortLCPs(str.begin() + l, str.begin() + r);
  for (size_t i = 0; i < sp.size(); ++i) {
    str[l + i] = sp[i].first;
  }
}



// Реализация с подсчётом посимвольных сравнений

std::pair<int, int> GetLCP(const std::string& a, const std::string& b, int k, long long& cmp) {
  for (int i = k; i < std::min(a.size(), b.size()); ++i) {
    ++cmp;
    if (a[i] != b[i]) {
      if (a[i] < b[i]) return { 0, i };
      if (a[i] == b[i]) return { 1, i };
      if (a[i] > b[i]) return { 2, i };
    }
  }

  if (a.size() == b.size()) {
    return { 1, static_cast<int>(a.size()) };
  }
  return (a.size() < b.size())
    ? std::make_pair(0, static_cast<int>(a.size()))
    : std::make_pair(2, static_cast<int>(b.size()));
}

std::vector<std::pair<std::string, int>> Merge(
  std::vector<std::pair<std::string, int>>& left,
  std::vector<std::pair<std::string, int>>& right,
  long long& cmp) {

  std::vector<std::pair<std::string, int>> res;
  res.reserve(left.size() + right.size());

  auto itl = left.begin();
  auto itr = right.begin();

  while (itl != left.end() && itr != right.end()) {
    if (itl->second > itr->second) {
      res.push_back(*itl);
      ++itl;
    }
    else if (itl->second < itr->second) {
      res.push_back(*itr);
      ++itr;
    }
    else {
      auto pr = GetLCP(itl->first, itr->first, itl->second, cmp);
      int order = pr.first;
      int lcp = pr.second;
      if (order == 0) {
        res.push_back(*itl);
        ++itl;
        itr->second = lcp;
      }
      else {
        res.push_back(*itr);
        ++itr;
        itl->second = lcp;
      }
    }
  }

  while (itl != left.end()) {
    res.push_back(*itl);
    ++itl;
  }

  while (itr != right.end()) {
    res.push_back(*itr);
    ++itr;
  }

  return res;
}

std::vector<std::pair<std::string, int>> MergeSortLCPs(
  std::vector<std::string>::iterator begin,
  std::vector<std::string>::iterator end,
  long long& cmp) {

  if (std::next(begin) == end) {
    return { {*begin, 0} };
  }

  auto mid = begin + (end - begin) / 2;
  auto left = MergeSortLCPs(begin, mid, cmp);
  auto right = MergeSortLCPs(mid, end, cmp);

  return Merge(left, right, cmp);
}

void MergeSortLCP(std::vector<std::string>& str, size_t l, size_t r, long long& cmp) {
  if (r - l <= 1) return;

  auto sp = MergeSortLCPs(str.begin() + l, str.begin() + r, cmp);
  for (size_t i = 0; i < sp.size(); ++i) {
    str[l + i] = sp[i].first;
  }
}


#endif