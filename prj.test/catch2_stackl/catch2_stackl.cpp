#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <stackl/stackl.h>

#include <array>
#include <limits>
#include <strstream>
#include <utility>

TEST_CASE("StackL ctor", "[StackL]") {
  StackL s_src;
  CHECK(s_src.is_empty());
}

TEST_CASE("StackL copy ctor", "[StackL]") {
  StackL s_src;
  s_src.push(1.0f);
  s_src.push(2.0f);
  s_src.push(3.0f);

  StackL s_copy(s_src);
  CHECK(!s_copy.is_empty());
  while (!s_copy.is_empty() && !s_src.is_empty()) {
    CHECK(s_src.top() == s_copy.top());
    s_src.pop();
    if (!s_src.is_empty()) {
      CHECK(s_src.top() != s_copy.top());
    }
    s_copy.pop();
    if (!s_copy.is_empty() && !s_src.is_empty()) {
      CHECK(s_src.top() == s_copy.top());
    }
  }
}

TEST_CASE("StackL operator=", "[StackL]") {
  StackL s_src;
  s_src.push(1.0f);
  s_src.push(2.0f);
  s_src.push(3.0f);

  StackL s_copy;
  s_copy = s_src;
  CHECK(!s_copy.is_empty());
  while (!s_copy.is_empty() && !s_src.is_empty()) {
    CHECK(s_src.top() == s_copy.top());
    s_src.pop();
    if (!s_src.is_empty()) {
      CHECK(s_src.top() != s_copy.top());
    }
    s_copy.pop();
    if (!s_copy.is_empty() && !s_src.is_empty()) {
      CHECK(s_src.top() == s_copy.top());
    }
  }

  const int count = 5;
  const float v[count] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
  for (int i = 0; i < count; i += 1) {
    s_copy.push(v[i]);
  }
  s_copy = s_src;
  CHECK(s_copy.is_empty());
  while (!s_copy.is_empty() && !s_src.is_empty()) {
    CHECK(s_src.top() == s_copy.top());
    s_src.pop();
    if (!s_src.is_empty()) {
      CHECK(s_src.top() != s_copy.top());
    }
    s_copy.pop();
    if (!s_copy.is_empty() && !s_src.is_empty()) {
      CHECK(s_src.top() == s_copy.top());
    }
  }
}

TEST_CASE("StackL push", "[StackL]") {
  const int count = 3;
  float v[count] = {1.0f, 2.0f, 3.0f};
  StackL s;
  for (int i = 0; i < count; i += 1) {
    s.push(v[i]);
    CHECK(v[i] == s.top());
    const StackL& sc(s);
    CHECK(v[i] == sc.top());
    CHECK(!s.is_empty());
    CHECK(!sc.is_empty());
  }
  s.pop();
  CHECK(v[count - 2] == s.top());
  for (int i = 0; i <= count; i += 1) {
    s.pop();
  }
  CHECK(s.is_empty());
}

