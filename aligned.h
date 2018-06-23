#pragma once

// Aligned vector of things.
// This is only used by tests.

#include <cstdlib>

namespace intgemm {

template <class T> class AlignedVector {
  public:
    explicit AlignedVector(std::size_t size)
      : mem_(static_cast<T*>(aligned_alloc(64, size * sizeof(T)))) {}

    ~AlignedVector() { std::free(mem_); }

    T &operator[](std::size_t offset) { return mem_[offset]; }
    const T &operator[](std::size_t offset) const { return mem_[offset]; }

    T *get() { return mem_; }
    const T *get() const { return mem_; }

  private:
    T *mem_;
};

} // namespace intgemm