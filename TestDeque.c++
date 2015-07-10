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
/*
typedef Types<
               deque<int>,
            my_deque<int>>
        deque_types;
*/
typedef Types<deque<int>> deque_types;

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
// my_deque ==
// -------------------------------

TYPED_TEST(Deque_Fixture, equal_equal_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d{1,2,3};
    const deque_t y{4,5,6};
    ASSERT_FALSE(x == y);
}

TYPED_TEST(Deque_Fixture, equal_equal_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d{1,2,3};
    const deque_t y{1,2,3};
    ASSERT_TRUE(x == y);
}

TYPED_TEST(Deque_Fixture, equal_equal_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d{1,2,3};
    const deque_t y{1,2};
    ASSERT_FALSE(x == y);
}

// -------------------------------
// my_deque <
// -------------------------------

TYPED_TEST(Deque_Fixture, less_than_1) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d{1,2,3};
    const deque_t y{1,2,3};
    ASSERT_FALSE(x < y);
}

TYPED_TEST(Deque_Fixture, less_than_2) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d{1,2,3};
    const deque_t y{2,3,4};
    ASSERT_TRUE(x < y);
}

TYPED_TEST(Deque_Fixture, less_than_3) {
    typedef typename TestFixture::deque_t deque_t;
    const deque_t d{1,2};
    const deque_t y{1,2,3};
    ASSERT_TRUE(x < y);
}

// -------------------------------
// iterator ==
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_equal_equal_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d{1,2,3};
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
    deque_t d{1,2,3};
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.begin();
    ASSERT_TRUE(b == e);
}

// -------------------------------
// iterator !=
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_not_equal_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d{1,2,3};
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
    deque_t d{1,2,3};
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.begin();
    ASSERT_FALSE(b != e);
}

// ------------------------
// iterator +
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_plus_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d{1,2,3};
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(e == b + 3);
}

TYPED_TEST(Deque_Fixture, iterator_plus_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d{1,2,3};
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(e != b + 2);
}

TYPED_TEST(Deque_Fixture, iterator_plus_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d{1,2,3};
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(e == ((b + 1) + 1) + 1);
}

// -------------------------------
// iterator -
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_minus_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d{1,2,3};
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(b == e - 3);
}

TYPED_TEST(Deque_Fixture, iterator_minus_2) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d{1,2,3};
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(b + 1 == e - 2);
}

TYPED_TEST(Deque_Fixture, iterator_minus_3) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d{1,2,3};
    typename deque_t::iterator b = d.begin();
    typename deque_t::iterator e = d.end();
    ASSERT_TRUE(b + 2 == e - 1);
}
/*
// -------------------------------
// iterator constructor
// -------------------------------

TYPED_TEST(Deque_Fixture, iterator_constructor_1) {
    typedef typename TestFixture::deque_t deque_t;
    deque_t d{1,2,3};
    typename deque_t::iterator b
}

TYPED_TEST(Deque_Fixture, iterator_constructor_2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, iterator_constructor_3) {
    typedef typename TestFixture::deque_t deque_t;
    
}
*/
// -------------------------------
// iterator * (dereference)
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}
/*
// -------------------------------
// iterator ->
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// iterator ++
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// iterator ++(int)
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// iterator --
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// iterator --(int)
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// iterator +=
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// iterator -=
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// const_iterator ==
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// const_iterator !=
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// const_iterator +
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// const_iterator -
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// const_iterator constructor
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// const_iterator * (dereference)
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// const_iterator ->
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// const_iterator ++
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// const_iterator ++(int)
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// const_iterator --
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// const_iterator --(int)
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// const_iterator +=
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// const_iterator -=
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque default constructor
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque constructor with size
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque copy constructor
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque destructor
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque assignment op
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque index op
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque const index op
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque at
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque const at
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque back
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque const back
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque begin
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque const begin
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque clear
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque empty
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque end
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque const end
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque erase
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque front
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque const front
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque insert
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque pop_back
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque pop_front
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque push_back
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque push_front
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque resize
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque size
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}

// -------------------------------
// my_deque swap
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_t deque_t;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_t deque_t;
    
}
*/