// --------------------------------
// projects/c++/deque/TestDeque.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// http://www.cplusplus.com/reference/deque/deque/

// --------
// includes
// --------

#include <deque>     // deque
#include <stdexcept> // invalid_argument, out_of_range
#include <memory>
#include <algorithm>

#include "gtest/gtest.h"

#include "Deque.h"

// -----
// Using
// -----

using namespace std;

using testing::Test;
using testing::Types;

// -----
// Types
// -----

template <typename T>
struct Deque_Fixture : Test {
    typedef T                               deque_t;
    typedef typename deque_t::value_type value_t;};

typedef Types<deque<int>, my_deque<int>> deque_types;
//typedef Types<deque<int>> deque_types;

TYPED_TEST_CASE(Deque_Fixture, deque_types);

// -----
// Tests
// -----

TYPED_TEST(Deque_Fixture, test_1) {
    typedef typename TestFixture::deque_t deque_t;

    const deque_t d;
    ASSERT_TRUE(d.empty());
    ASSERT_EQ(d.size(),0);
}

// -------------------------------
// deque ==
// -------------------------------

TYPED_TEST(Deque_Fixture, equal_equal_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    const deque_t y(3,2);
    ASSERT_FALSE(d == y);
}

TYPED_TEST(Deque_Fixture, equal_equal_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    const deque_t y(3,1);
    ASSERT_TRUE(d == y);
}

TYPED_TEST(Deque_Fixture, equal_equal_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    const deque_t y(2,1);
    ASSERT_FALSE(d == y);
}

TYPED_TEST(Deque_Fixture, equal_equal_4) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(16,1);
    const deque_t y(19,2);
    ASSERT_FALSE(d == y);
}

// -------------------------------
// deque <
// -------------------------------

TYPED_TEST(Deque_Fixture, less_than_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    const deque_t y(3,1);
    ASSERT_FALSE(d < y);
}

TYPED_TEST(Deque_Fixture, less_than_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    const deque_t y{3,2};
    ASSERT_TRUE(d < y);
}

TYPED_TEST(Deque_Fixture, less_than_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(2,1);
    const deque_t y(3,1);
    ASSERT_TRUE(d < y);
}

// -------------------------------
// iterator ==
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_equal_equal_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_FALSE(b == e);
}

TYPED_TEST(Deque_Fixture, iterator_equal_equal_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d;
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(b == e);
}

TYPED_TEST(Deque_Fixture, iterator_equal_equal_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.begin();
    ASSERT_TRUE(b == e);
}

// -------------------------------
// iterator !=
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_not_equal_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(b != e);
}

TYPED_TEST(Deque_Fixture, iterator_not_equal_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d;
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_FALSE(b != e);
}

TYPED_TEST(Deque_Fixture, iterator_not_equal_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.begin();
    ASSERT_FALSE(b != e);
}

// ------------------------
// iterator +
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_plus_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(e == b + 3);
}

TYPED_TEST(Deque_Fixture, iterator_plus_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(e != b + 2);
}

TYPED_TEST(Deque_Fixture, iterator_plus_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(e == ((b + 1) + 1) + 1);
}

// -------------------------------
// iterator -
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_minus_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(b == e - 3);
}

TYPED_TEST(Deque_Fixture, iterator_minus_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(b + 1 == e - 2);
}

TYPED_TEST(Deque_Fixture, iterator_minus_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(b + 2 == e - 1);
}

// -------------------------------
// iterator * (dereference)
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_deref_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator it = d.begin();
    ASSERT_EQ(1, *it);
}

TYPED_TEST(Deque_Fixture, iterator_deref_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator it = d.end() - 1;
    *it = 2;
    ASSERT_EQ(2, *it);
}

TYPED_TEST(Deque_Fixture, iterator_deref_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator it = d.begin() + 1;
    *it = 2;
    ASSERT_EQ(2, *it);
}

// -------------------------------
// iterator ->
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_arrow_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator it = d.begin();
    ASSERT_EQ(&d[0], (it.operator->()));
}

TYPED_TEST(Deque_Fixture, iterator_arrow_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator it = d.end();
    ASSERT_EQ(&d[2], ((it - 1).operator->()));
}

TYPED_TEST(Deque_Fixture, iterator_arrow_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator it = d.begin();
    ASSERT_EQ(&d[1], ((it + 1).operator->()));
}

// -------------------------------
// iterator ++
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_plus_plus_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    ASSERT_TRUE(++b != d.begin());
}

TYPED_TEST(Deque_Fixture, iterator_plus_plus_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    ASSERT_TRUE(++b == d.begin() + 1);
}

TYPED_TEST(Deque_Fixture, iterator_plus_plus_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(++++++b == e);
}

// -------------------------------
// iterator ++(int)
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_plus_plus_int_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    ASSERT_TRUE(b++ == d.begin());
}

TYPED_TEST(Deque_Fixture, iterator_plus_plus_int_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    //typename deque_t::iterator e = d.end();
    ASSERT_TRUE(b++ != d.begin() + 1);
    ASSERT_TRUE(b == d.begin() + 1);
}

TYPED_TEST(Deque_Fixture, iterator_plus_plus_int_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    b++;
    b++;
    b++;
    ASSERT_TRUE(b == e);
}

// -------------------------------
// iterator --
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_minus_minus_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(--e != d.end());
}

TYPED_TEST(Deque_Fixture, iterator_minus_minus_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(--e == d.end() - 1);
}

TYPED_TEST(Deque_Fixture, iterator_minus_minus_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(------e == b);
}

// -------------------------------
// iterator --(int)
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_minus_minus_int_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(e-- == d.end());
}

TYPED_TEST(Deque_Fixture, iterator_minus_minus_int_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    //typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(e-- != d.end() - 1);
    ASSERT_TRUE(e == d.end() - 1);
}

TYPED_TEST(Deque_Fixture, iterator_minus_minus_int_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    e--;
    e--;
    e--;
    ASSERT_TRUE(b == e);
}

// -------------------------------
// iterator +=
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_plus_equal_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    b += 3;
    ASSERT_TRUE(b == e);
}

TYPED_TEST(Deque_Fixture, iterator_plus_equal_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    //typename deque_t::iterator e = d.end();
    b += 1;
    ASSERT_TRUE(b != d.begin());
}

TYPED_TEST(Deque_Fixture, iterator_plus_equal_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    b += 1;
    b += 1;
    b += 1;
    ASSERT_TRUE(b == e);
}

// -------------------------------
// iterator -=
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_minus_equal_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    e -= 3;
    ASSERT_TRUE(e == b);
}

TYPED_TEST(Deque_Fixture, iterator_minus_equal_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    //typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    e -= 1;
    ASSERT_TRUE(e != d.end());
}

TYPED_TEST(Deque_Fixture, iterator_minus_equal_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    e -= 1;
    e -= 1;
    e -= 1;
    ASSERT_TRUE(e == b);
}

// -------------------------------
// const_iterator ==
// -------------------------------

TYPED_TEST(Deque_Fixture, const_iterator_equal_equal_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    ASSERT_FALSE(b == e);
}

TYPED_TEST(Deque_Fixture, const_iterator_equal_equal_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d;
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(b == e);
}

TYPED_TEST(Deque_Fixture, const_iterator_equal_equal_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.begin();
    ASSERT_TRUE(b == e);
}

// -------------------------------
// const_iterator !=
// -------------------------------

TYPED_TEST(Deque_Fixture, const_iterator_not_equal_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(b != e);
}

TYPED_TEST(Deque_Fixture, const_iterator_not_equal_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d;
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    ASSERT_FALSE(b != e);
}

TYPED_TEST(Deque_Fixture, const_iterator_not_equal_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.begin();
    ASSERT_FALSE(b != e);
}

// -------------------------------
// const_iterator +
// -------------------------------

TYPED_TEST(Deque_Fixture, const_iterator_plus_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(e == b + 3);
}

TYPED_TEST(Deque_Fixture, const_iterator_plus_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(e != b + 2);
}

TYPED_TEST(Deque_Fixture, const_iterator_plus_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(e == ((b + 1) + 1) + 1);
}

// -------------------------------
// const_iterator -
// -------------------------------

TYPED_TEST(Deque_Fixture, const_iterator_minus_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(b == e - 3);
}

TYPED_TEST(Deque_Fixture, const_iterator_minus_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(b + 1 == e - 2);
}

TYPED_TEST(Deque_Fixture, const_iterator_minus_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(b + 2 == e - 1);
}

// -------------------------------
// const_iterator * (dereference)
// -------------------------------

TYPED_TEST(Deque_Fixture, const_iterator_deref_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator it = d.begin();
    ASSERT_EQ(1, *it);
}

TYPED_TEST(Deque_Fixture, const_iterator_deref_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator it = d.end() - 1;
    ASSERT_EQ(1, *it);
}

TYPED_TEST(Deque_Fixture, const_iterator_deref_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator it = d.begin() + 1;
    ASSERT_EQ(1, *it);
}

// -------------------------------
// const_iterator ->
// -------------------------------

TYPED_TEST(Deque_Fixture, const_iterator_arrow_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator it = d.begin();
    ASSERT_EQ(&d[0], (it.operator->()));
}

TYPED_TEST(Deque_Fixture, const_iterator_arrow_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator it = d.end();
    ASSERT_EQ(&d[2], ((it - 1).operator->()));
}

TYPED_TEST(Deque_Fixture, const_iterator_arrow_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator it = d.begin();
    ASSERT_EQ(&d[1], ((it + 1).operator->()));
}

// -------------------------------
// const_iterator ++
// -------------------------------

TYPED_TEST(Deque_Fixture, const_iterator_plus_plus_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    ASSERT_TRUE(++b != d.begin());
}

TYPED_TEST(Deque_Fixture, const_iterator_plus_plus_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    ASSERT_TRUE(++b == d.begin() + 1);
}

TYPED_TEST(Deque_Fixture, const_iterator_plus_plus_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(++++++b == e);
}

// -------------------------------
// const_iterator ++(int)
// -------------------------------

TYPED_TEST(Deque_Fixture, const_iterator_plus_plus_int_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    ASSERT_TRUE(b++ == d.begin());
}

TYPED_TEST(Deque_Fixture, const_iterator_plus_plus_int_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    //typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(b++ != d.begin() + 1);
    ASSERT_TRUE(b == d.begin() + 1);
}

TYPED_TEST(Deque_Fixture, const_iterator_plus_plus_int_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    b++;
    b++;
    b++;
    ASSERT_TRUE(b == e);
}

// -------------------------------
// const_iterator --
// -------------------------------

TYPED_TEST(Deque_Fixture, const_iterator_minus_minus_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(--e != d.end());
}

TYPED_TEST(Deque_Fixture, const_iterator_minus_minus_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(--e == d.end() - 1);
}

TYPED_TEST(Deque_Fixture, const_iterator_minus_minus_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(------e == b);
}

// -------------------------------
// const_iterator --(int)
// -------------------------------

TYPED_TEST(Deque_Fixture, const_iterator_minus_minus_int_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(e-- == d.end());
}

TYPED_TEST(Deque_Fixture, const_iterator_minus_minus_int_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    //typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    ASSERT_TRUE(e-- != d.end() - 1);
    ASSERT_TRUE(e == d.end() - 1);
}

TYPED_TEST(Deque_Fixture, const_iterator_minus_minus_int_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    e--;
    e--;
    e--;
    ASSERT_TRUE(b == e);
}

// -------------------------------
// const_iterator +=
// -------------------------------

TYPED_TEST(Deque_Fixture, const_iterator_plus_equal_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    b += 3;
    ASSERT_TRUE(b == e);
}

TYPED_TEST(Deque_Fixture, const_iterator_plus_equal_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    //typename deque_t::const_iterator e = d.end();
    b += 1;
    ASSERT_TRUE(b != d.begin());
}

TYPED_TEST(Deque_Fixture, const_iterator_plus_equal_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    b += 1;
    b += 1;
    b += 1;
    ASSERT_TRUE(b == e);
}

// -------------------------------
// const_iterator -=
// -------------------------------

TYPED_TEST(Deque_Fixture, const_iterator_minus_equal_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    e -= 3;
    ASSERT_TRUE(e == b);
}

TYPED_TEST(Deque_Fixture, const_iterator_minus_equal_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    //typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    e -= 1;
    ASSERT_TRUE(e != d.end());
}

TYPED_TEST(Deque_Fixture, const_iterator_minus_equal_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(3,1);
    typename deque_t::const_iterator b = d.begin();
    typename deque_t::const_iterator e = d.end();
    e -= 1;
    e -= 1;
    e -= 1;
    ASSERT_TRUE(e == b);
}

// -------------------------------
// deque default constructor
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_constructor_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d;
    ASSERT_EQ(0, d.size());
}

TYPED_TEST(Deque_Fixture, deque_constructor_2) {
    typedef typename TestFixture::deque_t deque_t;
    typedef typename TestFixture::value_t value_t;
    allocator<value_t> a;
    deque_t d(a);
    ASSERT_EQ(0, d.size());
}

// -------------------------------
// deque constructor with size
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_constructor_size_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10);
    ASSERT_EQ(10, d.size());
}

TYPED_TEST(Deque_Fixture, deque_constructor_size_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10, 1);
    ASSERT_EQ(10, d.size());
    ASSERT_TRUE(all_of(d.begin(), d.end(), [](int i)->bool{return i == 1;}));
}

TYPED_TEST(Deque_Fixture, deque_constructor_size_3) {
    typedef typename TestFixture::deque_t deque_t;
    typedef typename TestFixture::value_t value_t;
    allocator<value_t> a;
    deque_t d(10, 1, a);
    ASSERT_EQ(10, d.size());
    ASSERT_TRUE(all_of(d.begin(), d.end(), [](int i)->bool{return i == 1;}));
}

// -------------------------------
// deque copy constructor
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_copy_constructor_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10);
    deque_t dd(d);
    ASSERT_EQ(10, dd.size());
}

TYPED_TEST(Deque_Fixture, deque_copy_constructor_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10, 1);
    deque_t dd(d);
    ASSERT_EQ(10, dd.size());
    ASSERT_TRUE(all_of(dd.begin(), dd.end(), [](int i)->bool{return i == 1;}));
}

TYPED_TEST(Deque_Fixture, deque_copy_constructor_3) {
    typedef typename TestFixture::deque_t deque_t;
    typedef typename TestFixture::value_t value_t;
    allocator<value_t> a;
    deque_t d(10, 1, a);
    deque_t dd(d);
    ASSERT_EQ(10, dd.size());
    ASSERT_TRUE(all_of(dd.begin(), dd.end(), [](int i)->bool{return i == 1;}));
}

// -------------------------------
// deque assignment op
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_copy_assignment_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10);
    deque_t dd;
    dd = d;
    ASSERT_EQ(10, dd.size());
}

TYPED_TEST(Deque_Fixture, deque_copy_assignment_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10, 1);
    deque_t dd;
    dd = d;
    ASSERT_EQ(10, dd.size());
    ASSERT_TRUE(all_of(dd.begin(), dd.end(), [](int i)->bool{return i == 1;}));
}

TYPED_TEST(Deque_Fixture, deque_copy_assignment_3) {
    typedef typename TestFixture::deque_t deque_t;
    typedef typename TestFixture::value_t value_t;
    allocator<value_t> a;
    deque_t d(10, 1, a);
    deque_t dd;
    dd = d;
    ASSERT_EQ(10, dd.size());
    ASSERT_TRUE(all_of(dd.begin(), dd.end(), [](int i)->bool{return i == 1;}));
}

// -------------------------------
// deque index op
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_index_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    typename deque_t::iterator it = d.begin() + 5;
    *it = 3;
    ASSERT_EQ(3, d[5]);
}

TYPED_TEST(Deque_Fixture, deque_index_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    typename deque_t::iterator it = d.begin();
    *it = 3;
    ASSERT_EQ(3, d[0]);
}

TYPED_TEST(Deque_Fixture, deque_index_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    d[9] = 3;
    ASSERT_EQ(3, d[9]);
}

// -------------------------------
// deque const index op
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_const_index_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    typename deque_t::iterator it = d.begin() + 5;
    *it = 3;
    const deque_t dd(d);
    ASSERT_EQ(3, dd[5]);
}

TYPED_TEST(Deque_Fixture, deque_const_index_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    typename deque_t::iterator it = d.begin();
    *it = 3;
    const deque_t dd(d);
    ASSERT_EQ(3, dd[0]);
}

TYPED_TEST(Deque_Fixture, deque_const_index_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    d[9] = 3;
    const deque_t dd(d);
    ASSERT_EQ(3, dd[9]);
}

// -------------------------------
// deque at
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_at_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    typename deque_t::iterator it = d.begin() + 5;
    *it = 3;
    ASSERT_EQ(3, d.at(5));
}

TYPED_TEST(Deque_Fixture, deque_at_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    typename deque_t::iterator it = d.begin();
    *it = 3;
    ASSERT_EQ(3, d.at(0));
}

TYPED_TEST(Deque_Fixture, deque_at_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    bool success = true;
    try {
        d.at(10);
        success = true;
    } catch (out_of_range& e) {
        success = false;
    }
    ASSERT_FALSE(success);
}

// -------------------------------
// deque const at
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_const_at_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    typename deque_t::iterator it = d.begin() + 5;
    *it = 3;
    const deque_t dd(d);
    ASSERT_EQ(3, dd.at(5));
}

TYPED_TEST(Deque_Fixture, deque_const_at_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    typename deque_t::iterator it = d.begin();
    *it = 3;
    const deque_t dd(d);
    ASSERT_EQ(3, dd.at(0));
}

TYPED_TEST(Deque_Fixture, deque_const_at_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d(10,1);
    bool success = true;
    try {
        d.at(10);
        success = true;
    } catch (out_of_range& e) {
        success = false;
    }
    ASSERT_FALSE(success);
}

// -------------------------------
// deque back
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_back_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    d[9] = 2;
    ASSERT_EQ(2, d.back());
}

TYPED_TEST(Deque_Fixture, deque_back_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(1,1);
    d[0] = 2;
    ASSERT_EQ(2, d.back());
}

TYPED_TEST(Deque_Fixture, deque_back_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(1000,1);
    typename deque_t::iterator e = d.end() - 1;
    *e = 2;
    ASSERT_EQ(2, d.back());
}

// -------------------------------
// deque const back
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_const_back_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    d[9] = 2;
    const deque_t dd(d);
    ASSERT_EQ(2, dd.back());
}

TYPED_TEST(Deque_Fixture, deque_const_back_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(1,1);
    d[0] = 2;
    const deque_t dd(d);
    ASSERT_EQ(2, dd.back());
}

TYPED_TEST(Deque_Fixture, deque_const_back_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(1000,1);
    typename deque_t::iterator e = d.end() - 1;
    *e = 2;
    const deque_t dd(d);
    ASSERT_EQ(2, dd.back());
}

// -------------------------------
// deque begin
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_begin_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    d[1] = 2;
    d[2] = 3;
    ASSERT_EQ(1, *(d.begin()));
}

TYPED_TEST(Deque_Fixture, deque_begin_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    d[1] = 2;
    d[2] = 3;
    ASSERT_EQ(2, *(d.begin() + 1));
}

TYPED_TEST(Deque_Fixture, deque_begin_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    d[1] = 2;
    d[2] = 3;
    ASSERT_EQ(3, *(d.begin() + 2));
}

// -------------------------------
// deque const begin
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_const_begin_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    d[1] = 2;
    d[2] = 3;
    const deque_t dd(d);
    ASSERT_EQ(1, *(dd.begin()));
}

TYPED_TEST(Deque_Fixture, deque_const_begin_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    d[1] = 2;
    d[2] = 3;
    const deque_t dd(d);
    ASSERT_EQ(2, *(dd.begin() + 1));
}

TYPED_TEST(Deque_Fixture, deque_const_begin_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    d[1] = 2;
    d[2] = 3;
    const deque_t dd(d);
    ASSERT_EQ(3, *(dd.begin() + 2));
}

// -------------------------------
// deque clear
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_clear_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10, 1);
    ASSERT_EQ(10, d.size());
    d.clear();
    ASSERT_EQ(0, d.size());
}

TYPED_TEST(Deque_Fixture, deque_clear_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d;
    ASSERT_EQ(0, d.size());
    d.clear();
    ASSERT_EQ(0, d.size());
}

TYPED_TEST(Deque_Fixture, deque_clear_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10000);
    ASSERT_EQ(10000, d.size());
    d.clear();
    ASSERT_EQ(0, d.size());
}

// -------------------------------
// deque empty
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_empty_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d;
    ASSERT_TRUE(d.empty());
}

TYPED_TEST(Deque_Fixture, deque_empty_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(1);
    ASSERT_FALSE(d.empty());
}

TYPED_TEST(Deque_Fixture, deque_empty_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(1);
    ASSERT_FALSE(d.empty());
    d.clear();
    ASSERT_TRUE(d.empty());
}

// -------------------------------
// deque end
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_end_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    d[1] = 2;
    d[2] = 3;
    ASSERT_EQ(3, *(d.end() - 1));
}

TYPED_TEST(Deque_Fixture, deque_end_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    d[1] = 2;
    d[2] = 3;
    ASSERT_EQ(2, *(d.end() - 2));
}

TYPED_TEST(Deque_Fixture, deque_end_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    d[1] = 2;
    d[2] = 3;
    ASSERT_EQ(1, *(d.end() - 3));
}

// -------------------------------
// deque const end
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_const_end_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    d[1] = 2;
    d[2] = 3;
    const deque_t dd(d);
    ASSERT_EQ(3, *(dd.end() - 1));
}

TYPED_TEST(Deque_Fixture, deque_const_end_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    d[1] = 2;
    d[2] = 3;
    const deque_t dd(d);
    ASSERT_EQ(2, *(dd.end() - 2));
}

TYPED_TEST(Deque_Fixture, deque_const_end_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3,1);
    d[1] = 2;
    d[2] = 3;
    const deque_t dd(d);
    ASSERT_EQ(1, *(dd.end() - 3));
}

// -------------------------------
// deque erase
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_erase_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10);
    d[2] = 1;
    d.erase(d.begin() + 2);
    ASSERT_EQ(9, d.size());
    ASSERT_TRUE(all_of(d.begin(), d.end(), [](int i)->bool{return i == 0;}));
}

TYPED_TEST(Deque_Fixture, deque_erase_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10);
    d[2] = 1;
    d[4] = 1;
    d[8] = 1;
    d.erase(d.begin() + 2);
    d.erase(d.begin() + 3);
    d.erase(d.begin() + 6);
    ASSERT_EQ(7, d.size());
    ASSERT_TRUE(all_of(d.begin(), d.end(), [](int i)->bool{return i == 0;}));
}

TYPED_TEST(Deque_Fixture, deque_erase_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3);
    d.erase(d.begin());
    d.erase(d.begin());
    d.erase(d.begin());
    ASSERT_EQ(0, d.size());
}

// -------------------------------
// deque front
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_front_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    d[0] = 2;
    ASSERT_EQ(2, d.front());
}

TYPED_TEST(Deque_Fixture, deque_front_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(1,1);
    d[0] = 2;
    ASSERT_EQ(2, d.front());
}

TYPED_TEST(Deque_Fixture, deque_front_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(1000,1);
    typename deque_t::iterator b = d.begin();
    *b = 2;
    ASSERT_EQ(2, d.front());
}

// -------------------------------
// deque const front
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_const_front_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(10,1);
    d[0] = 2;
    const deque_t dd(d);
    ASSERT_EQ(2, dd.front());
}

TYPED_TEST(Deque_Fixture, deque_const_front_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(1,1);
    d[0] = 2;
    const deque_t dd(d);
    ASSERT_EQ(2, dd.front());
}

TYPED_TEST(Deque_Fixture, deque_const_front_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(1000,1);
    typename deque_t::iterator b = d.begin();
    *b = 2;
    const deque_t dd(d);
    ASSERT_EQ(2, dd.front());
}

// -------------------------------
// deque insert
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_insert_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3);
    d.insert(d.begin(), 1);
    ASSERT_EQ(4, d.size());
    ASSERT_EQ(1, *(d.begin()));
}

TYPED_TEST(Deque_Fixture, deque_insert_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3);
    d.insert(d.end(), 1);
    ASSERT_EQ(4, d.size());
    ASSERT_EQ(1, *(d.end() - 1));
}

TYPED_TEST(Deque_Fixture, deque_insert_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3);
    d.insert(d.begin() + 1, 1);
    ASSERT_EQ(4, d.size());
    ASSERT_EQ(1, *(d.begin() + 1));
}

// -------------------------------
// deque pop_back
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_pop_back_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3);
    d.pop_back();
    ASSERT_EQ(2, d.size());
}

TYPED_TEST(Deque_Fixture, deque_pop_back_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(100);
    d.insert(d.end(), 1);    
    ASSERT_EQ(101, d.size());
    d.pop_back();
    ASSERT_EQ(100, d.size());
    ASSERT_TRUE(all_of(d.begin(), d.end(), [](int i)->bool{return i == 0;}));
}

TYPED_TEST(Deque_Fixture, deque_pop_back_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(100);
    d.insert(d.begin() + 50, 1);
    ASSERT_EQ(101, d.size());
    d.pop_back();
    ASSERT_EQ(100, d.size());
    ASSERT_FALSE(all_of(d.begin(), d.end(), [](int i)->bool{return i == 0;}));
}

// -------------------------------
// deque pop_front
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_pop_front_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(3);
    d.pop_front();
    ASSERT_EQ(2, d.size());
}

TYPED_TEST(Deque_Fixture, deque_pop_front_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(100);
    d.insert(d.begin(), 1);
    ASSERT_EQ(101, d.size());
    d.pop_front();
    ASSERT_EQ(100, d.size());
    ASSERT_TRUE(all_of(d.begin(), d.end(), [](int i)->bool{return i == 0;}));
}

TYPED_TEST(Deque_Fixture, deque_pop_front_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(100);
    d.insert(d.begin() + 50, 1);
    ASSERT_EQ(101, d.size());
    d.pop_front();
    ASSERT_EQ(100, d.size());
    ASSERT_FALSE(all_of(d.begin(), d.end(), [](int i)->bool{return i == 0;}));
}

// -------------------------------
// deque push_back
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_push_back_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d;
    d.push_back(1);
    ASSERT_EQ(1, d.size());
}

TYPED_TEST(Deque_Fixture, deque_push_back_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    ASSERT_EQ(3, d.size());
    ASSERT_EQ(1, d[0]);
    ASSERT_EQ(2, d[1]);
    ASSERT_EQ(3, d[2]);
}

TYPED_TEST(Deque_Fixture, deque_push_back_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(100000);
    d.push_back(1);
    ASSERT_EQ(100001, d.size());
    ASSERT_EQ(1, *(d.end() - 1));
}

// -------------------------------
// deque push_front
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_push_front_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d;
    d.push_front(1);
    ASSERT_EQ(1, d.size());
}

TYPED_TEST(Deque_Fixture, deque_push_front_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    ASSERT_EQ(3, d.size());
    ASSERT_EQ(3, d[0]);
    ASSERT_EQ(2, d[1]);
    ASSERT_EQ(1, d[2]);
}

TYPED_TEST(Deque_Fixture, deque_push_front_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(100000);
    d.push_front(1);
    ASSERT_EQ(100001, d.size());
    ASSERT_EQ(1, *(d.begin()));
}

// -------------------------------
// deque resize
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_resize_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d;
    d.resize(10);
    ASSERT_EQ(10, d.size());
    ASSERT_TRUE(all_of(d.begin(), d.end(), [](int i)->bool{return i == 0;}));
}

TYPED_TEST(Deque_Fixture, deque_resize_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d;
    d.resize(10, 1);
    ASSERT_EQ(10, d.size());
    ASSERT_TRUE(all_of(d.begin(), d.end(), [](int i)->bool{return i == 1;}));
}

TYPED_TEST(Deque_Fixture, deque_resize_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(5);
    d.resize(10, 1);
    ASSERT_EQ(10, d.size());
    ASSERT_TRUE(all_of(d.begin(), d.begin() + 5, [](int i)->bool{return i == 0;}));
    ASSERT_TRUE(all_of(d.begin() + 5, d.end(), [](int i)->bool{return i == 1;}));
}

// -------------------------------
// deque size
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_size_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d;
    ASSERT_EQ(0, d.size());
}

TYPED_TEST(Deque_Fixture, deque_size_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(187284);
    ASSERT_EQ(187284, d.size());
}

TYPED_TEST(Deque_Fixture, deque_size_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(187284);
    d.insert(d.begin() + 5000, 1);
    ASSERT_EQ(187285, d.size());
}

// -------------------------------
// deque swap
// -------------------------------

TYPED_TEST(Deque_Fixture, deque_swap_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(5, 89);
    deque_t e(293, 7);
    d.swap(e);
    ASSERT_EQ(293, d.size());
    ASSERT_TRUE(all_of(d.begin(), d.end(), [](int i)->bool{return i == 7;}));
    ASSERT_EQ(5, e.size());
    ASSERT_TRUE(all_of(e.begin(), e.end(), [](int i)->bool{return i == 89;}));
}

TYPED_TEST(Deque_Fixture, deque_swap_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(5, 89);
    deque_t e(293, 7);
    e.swap(d);
    ASSERT_EQ(293, d.size());
    ASSERT_TRUE(all_of(d.begin(), d.end(), [](int i)->bool{return i == 7;}));
    ASSERT_EQ(5, e.size());
    ASSERT_TRUE(all_of(e.begin(), e.end(), [](int i)->bool{return i == 89;}));
}

TYPED_TEST(Deque_Fixture, deque_swap_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d(5, 89);
    deque_t e(293, 7);
    deque_t f(10023, 34);
    d.swap(e);
    e.swap(f);
    ASSERT_EQ(293, d.size());
    ASSERT_TRUE(all_of(d.begin(), d.end(), [](int i)->bool{return i == 7;}));
    ASSERT_EQ(10023, e.size());
    ASSERT_TRUE(all_of(e.begin(), e.end(), [](int i)->bool{return i == 34;}));
    ASSERT_EQ(5, f.size());
    ASSERT_TRUE(all_of(f.begin(), f.end(), [](int i)->bool{return i == 89;}));
}
