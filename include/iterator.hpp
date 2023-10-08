#pragma once

#include <bits/iterator_concepts.h>
#include <functional>
#include <utility>

namespace iter {

template <typename InputIteratorBase> struct derived_input_iterator {
  using value_type = typename InputIteratorBase::value_type;
  using difference_type = typename InputIteratorBase::difference_type;

  explicit derived_input_iterator(InputIteratorBase iter_)
      : base(std::move(iter_)) {}

  derived_input_iterator &operator++() {
    base.increment();
    return *this;
  }

  derived_input_iterator &operator++(int) { return ++(*this); }

  value_type operator*() const { return base.deref(); }

  bool operator==(derived_input_iterator const &given_iter) const {
    return base == given_iter.base;
  }

  InputIteratorBase base;
};

template <typename Iter> struct sentinal_iterator {};
} // namespace iter
