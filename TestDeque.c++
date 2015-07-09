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
    typedef T                               deque_type;
    typedef typename deque_type::value_type value_type;};

typedef Types<
               deque<int>,
            my_deque<int>>
        deque_types;

TYPED_TEST_CASE(Deque_Fixture, deque_types);

// -----
// Tests
// -----

TYPED_TEST(Deque_Fixture, test_1) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x;
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(),0);
}

// -------------------------------
// my_deque ==
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque <
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// iterator ==
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// iterator !=
// -------------------------------

// -------
TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}
------------------------
// iterator +
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// iterator -
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// iterator constructor
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// iterator * (dereference)
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// iterator ->
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// iterator ++
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// iterator ++(int)
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// iterator --
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// iterator --(int)
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// iterator +=
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// iterator -=
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// const_iterator ==
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// const_iterator !=
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// const_iterator +
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// const_iterator -
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// const_iterator constructor
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// const_iterator * (dereference)
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// const_iterator ->
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// const_iterator ++
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// const_iterator ++(int)
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// const_iterator --
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// const_iterator --(int)
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// const_iterator +=
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// const_iterator -=
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque default constructor
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque constructor with size
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque copy constructor
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque destructor
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque assignment op
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque index op
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque const index op
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque at
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque const at
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque back
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque const back
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque begin
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque const begin
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque clear
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque empty
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque end
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque const end
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque erase
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque front
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque const front
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque insert
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque pop_back
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque pop_front
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque push_back
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque push_front
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque resize
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque size
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}

// -------------------------------
// my_deque swap
// -------------------------------

TYPED_TEST(Deque_Fixture, _1) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _2) {
    typedef typename TestFixture::deque_type deque_type;
    
}

TYPED_TEST(Deque_Fixture, _3) {
    typedef typename TestFixture::deque_type deque_type;
    
}
