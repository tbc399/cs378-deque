// --------------------------
// projects/c++/deque/Deque.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Deque_h
#define Deque_h

/* size of an individual block in number of elements */
#define BLOCK_SIZE 25

#include <algorithm> // copy, equal, lexicographical_compare, max, swap
#include <cassert>   // assert
#include <iterator>  // iterator, bidirectional_iterator_tag
#include <memory>    // allocator
#include <stdexcept> // out_of_range
#include <utility>   // !=, <=, >, >=

using namespace std;

using std::rel_ops::operator!=;
using std::rel_ops::operator<=;
using std::rel_ops::operator>;
using std::rel_ops::operator>=;

template <typename A, typename BI>
BI destroy (A& a, BI b, BI e) {
    while (b != e) {
        --e;
        a.destroy(&*e);}
    return b;}

template <typename A, typename II, typename BI>
BI uninitialized_copy (A& a, II b, II e, BI x) {
    BI p = x;
    try {
        while (b != e) {
            a.construct(&*x, *b);
            ++b;
            ++x;}}
    catch (...) {
        destroy(a, p, x);
        throw;}
    return x;}

template <typename A, typename BI, typename U>
BI uninitialized_fill (A& a, BI b, BI e, const U& v) {
    BI p = b;
    try {
        while (b != e) {
            a.construct(&*b, v);
            ++b;}}
    catch (...) {
        destroy(a, p, b);
        throw;}
    return e;}

template < typename T, typename A = std::allocator<T> >
class my_deque {
    
    public:

        typedef A                                        allocator_type;
        typedef typename allocator_type::value_type      value_type;

        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;

        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;

        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;

        typedef typename A::template rebind<pointer>::other B;

    public:

        /**
         * Check to see if two my_deque objects are the same
         * @param lhs a my_deque
         * @param rhs a my_deque
         * @return true if lhs is less than rhs
         */
        friend bool operator == (const my_deque& lhs, const my_deque& rhs) {
            if (lhs.size() != rhs.size())
                return false;
            return equal(lhs.begin(), lhs.end(), rhs.begin());
        }

        /**
         * Checks to see if a my_deque is lexicographically less than another
         * @param lhs a my_deque
         * @param rhs a my_deque
         * @return true if lhs is less than rhs
         */
        friend bool operator < (const my_deque& lhs, const my_deque& rhs) {
            return lexicographical_compare(lhs.begin(), lhs.end(),
                                           rhs.begin(), rhs.end());
        }

    private:
        
        /* allocator for value_type */
        allocator_type _a;
        
        /* allocator for pointer */
        B _b;

        /* pointer to the beginning of the data blocks */
        pointer* _d;
        
        /* pointer to the end of the data blocks*/
        pointer* _e;
        
        /* index offset of the first element from _d */
        size_type _o;
        
        /* number of elements (help keep track of the end) */
        size_type _s;
        

    private:
        
        /**
         * Check to see if the my_deque is in a valid state
         * @return true if my_deque is in valid state
         */
        bool valid () const {
            if (_s < 0)
                return false;
            if (_o < 0 || _o > capacity())
                return false;
            if (_o + _s > capacity())
                return false;
            if (_e < _d)
                return false;
            if ((!_d && _e) || (_d && !_e))
                return false;
            return true;
        }
        
        /**
         * Get the total allocated capacity for this my_deque
         * @return the total capacity
         */
        size_type capacity () const {
            return (_e - _d) * BLOCK_SIZE;
        }
        
        /**
         * Get the amount of allocated space to the "left"
         * of my_deque, i.e. before the first constructed element
         * @return the capacity before the first element
         */
        size_type left_free () {
            return _o;
        }
        
        /**
         * Get the amount of allocated space to the "right"
         * of my_deque, i.e. after the last constructed element
         * @return the capacity after the last element
         */
        size_type right_free () {
            return capacity() - (_o + _s);
        }
        
        /**
         * Allocate enough blocks of size BLOCK_SIZE in which to fit
         * a specified number of elements
         * @param n the number of elements required to store
         * @param b a reference to a value_type** to mark the beginning of the
         * blocks
         * @param e a reference to a value_type** to mark the end of the blocks
         */
        void half_alloc (size_type n, pointer*& b, pointer*& e) {
            
            if (n % BLOCK_SIZE){
                b = _b.allocate(n / BLOCK_SIZE + 1);
                e = b + (n / BLOCK_SIZE + 1);
            } else {
                b = _b.allocate(n / BLOCK_SIZE);
                e = b + (n / BLOCK_SIZE);
            }

        }
        
        /**
         * Allocate enough space for blocks of size BLOCK_SIZE in which to fit
         * a specified number of elements without actually allocating the
         * blocks
         * @param n the number of elements required to store
         * @param b a reference to a value_type** to mark the beginning of the
         * blocks
         * @param e a reference to a value_type** to mark the end of the blocks
         */
        void full_alloc (size_type n, pointer*& b, pointer*& e) {
            
            half_alloc(n, b, e);
            
            pointer* p = b;
            while (p != e) {
                (*p) = _a.allocate(BLOCK_SIZE);
                ++p;
            }
            
        }
        
        /**
         * Make more space for new data giving preference
         * to the "right" side of the my_deque
         * @param n the number of elements that will have to be
         * accomodated after the reallocation
         */
        void rrealloc (size_type n) {
        
            size_type new_blocks;
            if (n % BLOCK_SIZE)
                new_blocks = n / BLOCK_SIZE + 1;
            else
                new_blocks = n / BLOCK_SIZE;
                
            size_type s1 = new_blocks * BLOCK_SIZE;
            size_type s2 = (capacity() - _o) * 2;
            size_type new_cap = max(s1, s2);
            
            pointer* new_d;
            pointer* new_e;
            half_alloc(new_cap, new_d, new_e);
            
            pointer* p = copy(_d, _e, new_d);
            
            while (p != new_e) {
                *p = _a.allocate(BLOCK_SIZE);
                ++p;
            }
            
            _b.deallocate(_d, _e - _d);
            
            _d = new_d;
            _e = new_e;
            
            assert(valid());
            
        }
        
        /**
         * Make more space for new data giving preference
         * to the "left" side of the my_deque
         * @param n the number of elements that will have to be
         * accomodated after the reallocation
         */
        void lrealloc (size_type n) {
        
            size_type new_blocks;
            if (n % BLOCK_SIZE)
                new_blocks = n / BLOCK_SIZE + 1;
            else
                new_blocks = n / BLOCK_SIZE;
                
            size_type s1 = new_blocks * BLOCK_SIZE;
            size_type s2 = (_o + _s) * 2;
            size_type new_cap = max(s1, s2);
            
            pointer* new_d;
            pointer* new_e;
            half_alloc(new_cap, new_d, new_e);
            
            size_type num_blocks_added = (new_e - new_d) - (_e - _d);
            copy(_d, _e, new_d + num_blocks_added);
            
            pointer* b = new_d;
            pointer* e = new_d + num_blocks_added;
            while (b != e) {
                *b = _a.allocate(BLOCK_SIZE);
                ++b;
            }
            
            _b.deallocate(_d, _e - _d);
            
            _d = new_d;
            _e = new_e;
            
            _o += (num_blocks_added * BLOCK_SIZE);
            
            assert(valid());
            
        }

    public:

        class iterator {
            
            public:

                typedef          std::bidirectional_iterator_tag iterator_category;
                typedef typename my_deque::value_type            value_type;
                typedef typename my_deque::difference_type       difference_type;
                typedef typename my_deque::pointer               pointer;
                typedef typename my_deque::reference             reference;

            public:

                /**
                 * Check to see if two iterators are equivalent
                 * @param lhs a const iterator reference
                 * @param rhs a const iterator reference
                 * @return true if lhs is equivalent to rhs
                 */
                friend bool operator == (const iterator& lhs, const iterator& rhs) {
                    return lhs._i == rhs._i;
                }

                /**
                 * Check to see if two iterators are not equivalent
                 * @param lhs a const iterator reference
                 * @param rhs a const iterator reference
                 * @return true if lhs is not equivalent to rhs
                 */
                friend bool operator != (const iterator& lhs, const iterator& rhs) {
                    return !(lhs == rhs);
                }

                /**
                 * Add a value to an iterator
                 * @param lhs an iterator
                 * @param rhs a number to add to lhs
                 * @return a new iterator
                 */
                friend iterator operator + (iterator lhs, difference_type rhs) {
                    return lhs += rhs;
                }

                /**
                 * Subtract a value from an iterator
                 * @param lhs an iterator
                 * @param rhs a number to subtract from lhs
                 * @return a new iterator
                 */
                friend iterator operator - (iterator lhs, difference_type rhs) {
                    return lhs -= rhs;
                }

            private:

                /* a reference to a mutable my_deque */
                my_deque& _q;
                
                /* represents an index into _q */
                size_type _i;

            private:
            
				/**
				 * Check to make sure an iterator is valid
				 * @return true if the iterator index _i is
				 * less than or equal to the my_deque size
				 */
                bool valid () const {
                    return _i <= _q.size();
                }

            public:

                /**
                 * Construct an iterator for a my_deque
                 * @param q a my_deque to iterate over
                 * @param n an index into the my_deque
                 */
                iterator (my_deque& q, size_type n) : _q(q) {
                    _i = n;
                    assert(valid());
                }

                // Default copy, destructor, and copy assignment.
                // iterator (const iterator&);
                // ~iterator ();
                // iterator& operator = (const iterator&);

                /**
                 * Dereference this iterator to get the underlying element
                 * @return a reference to an element of this my_deque
                 */
                reference operator * () const {
                    return _q[_i];
                }

                /**
                 * Get the pointer to the underlying element of this iterator
                 * @return a pointer to an element of this my_deque
                 */
                pointer operator -> () const {
                    return &(_q[_i]);
                }

                /**
                 * Pre increment this iterator
                 * @return this iterator
                 */
                iterator& operator ++ () {
                    ++_i;
                    assert(valid());
                    return *this;
                }

                /**
                 * Post increment this iterator
                 * @return this iterator
                 */
                iterator operator ++ (int) {
                    iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;
                }

                /**
                 * Pre decrement this iterator
                 * @return this iterator
                 */
                iterator& operator -- () {
                    --_i;
                    assert(valid());
                    return *this;
                }

                /**
                 * Post decrement this iterator
                 * @return this iterator
                 */
                iterator operator -- (int) {
                    iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;
                }

                /**
                 * Add a numerical value to this iterator
                 * @param d a numerical value
                 * @return this iterator
                 */
                iterator& operator += (difference_type d) {
                    _i += d;
                    assert(valid());
                    return *this;
                }

                /**
                 * Subtract a numerical value from this iterator
                 * @param d a numerical value
                 * @return this iterator
                 */
                iterator& operator -= (difference_type d) {
                    _i -= d;
                    assert(valid());
                    return *this;
                }
                
        };

    public:

        class const_iterator {
            
            public:

                typedef          std::bidirectional_iterator_tag iterator_category;
                typedef typename my_deque::value_type            value_type;
                typedef typename my_deque::difference_type       difference_type;
                typedef typename my_deque::const_pointer         pointer;
                typedef typename my_deque::const_reference       reference;

            public:

                /**
                 * Check to see if two iterators are equivalent
                 * @param lhs a const iterator reference
                 * @param rhs a const iterator reference
                 * @return true if lhs is equivalent to rhs
                 */
                friend bool operator == (const const_iterator& lhs, const const_iterator& rhs) {
                    return lhs._i == rhs._i;
                }

                /**
                 * Check to see if two const_iterators are not equivalent
                 * @param lhs a const const_iterator reference
                 * @param rhs a const const_iterator reference
                 * @return true if lhs is not equivalent to rhs
                 */
                friend bool operator != (const const_iterator& lhs, const const_iterator& rhs) {
                    return !(lhs == rhs);
                }

                /**
                 * Add a value to a const_iterator
                 * @param lhs a const_iterator
                 * @param rhs a number to add to lhs
                 * @return a new const_iterator
                 */
                friend const_iterator operator + (const_iterator lhs, difference_type rhs) {
                    return lhs += rhs;
                }

                /**
                 * Subtract a value from a const_iterator
                 * @param lhs an const_iterator
                 * @param rhs a number to subtract from lhs
                 * @return a new const_iterator
                 */
                friend const_iterator operator - (const_iterator lhs, difference_type rhs) {
                    return lhs -= rhs;
                }

            private:

                /* a pointer to an immutable my_deque */
                const my_deque* _q;
                
                /* represents an index into _q */
                size_type _i;

            private:
            
				/**
				 * Check to make sure an iterator is valid
				 * @return true if the iterator index _i is
				 * less than or equal to the my_deque size
				 */
                bool valid () const {
                    return _i <= _q->size();
                }

            public:

                /**
                 * Construct a const_terator for a const my_deque
                 * @param q a const my_deque to iterate over
                 * @param n an index into the my_deque
                 */
                const_iterator (const my_deque& q, size_type n) {
                    _q = &q;
                    _i = n;
                    assert(valid());
                }

                // Default copy, destructor, and copy assignment.
                // const_iterator (const const_iterator&);
                // ~const_iterator ();
                // const_iterator& operator = (const const_iterator&);

                /**
                 * Dereference this const_iterator to get the underlying element
                 * @return a reference to an element of this my_deque
                 */
                reference operator * () const {
                    return (*_q)[_i];
                }

                /**
                 * Get the pointer to the underlying element of this const_iterator
                 * @return a pointer to an element of this my_deque
                 */
                pointer operator -> () const {
                    return &((*_q)[_i]);
                }

                /**
                 * Pre increment this const_iterator
                 * @return this const_iterator
                 */
                const_iterator& operator ++ () {
                    ++_i;
                    assert(valid());
                    return *this;
                }

                /**
                 * Post increment this const_iterator
                 * @return this const_iterator
                 */
                const_iterator operator ++ (int) {
                    const_iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;
                }

                /**
                 * Pre decrement this const_iterator
                 * @return this const_iterator
                 */
                const_iterator& operator -- () {
                    --_i;
                    assert(valid());
                    return *this;
                }

                /**
                 * Post decrement this const_iterator
                 * @return this const_iterator
                 */
                const_iterator operator -- (int) {
                    const_iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;
                }

                /**
                 * Add a numerical value to this const_iterator
                 * @param d a numerical value
                 * @return this const_iterator
                 */
                const_iterator& operator += (difference_type d) {
                    _i += d;
                    assert(valid());
                    return *this;
                }

                /**
                 * Subtract a numerical value from this const_iterator
                 * @param d a numerical value
                 * @return this const_iterator
                 */
                const_iterator& operator -= (difference_type d) {
                    _i -= d;
                    assert(valid());
                    return *this;
                }
                
        };

    public:

        /**
         * Default constructor
         * @param a the allocator to use for memory management
         */
        explicit my_deque (const allocator_type& a = allocator_type()) : _a(a) {
            _d = _e = 0;
            _o = 0;
            _s = 0;
            assert(valid());
        }

        /**
         * Construct a my_deque with an initial size
         * @param s the size of the new my_deque
         * @param v the fill value to be used
         * @param a the allocator to use for memory management
         */
        explicit my_deque (size_type s, const_reference v = value_type(),
                           const allocator_type& a = allocator_type()) : _a(a) {
            
            if (!s) {
                _d = _e = 0;
                _o = _s = 0;
                assert(valid());
                return;
            }
            
            _o = 0;
            _s = s;
            
            full_alloc(s, _d, _e);
            uninitialized_fill(_a, begin(), end(), v);
            
            assert(valid());
            
        }

        /**
         * Construct a copy of a my_deque
         * @param that the my_deque to copy
         */
        my_deque (const my_deque& that) {
            
            _d = _e = 0;
            _o = 0;
            _s = that.size();
            
            if (!that.size()) {
                _s = 0;
                assert(valid());
                return;
            }
            
            full_alloc(_s, _d, _e);
            uninitialized_copy(_a, that.begin(), that.end(), begin());
            
            assert(valid());
            
        }

        /**
         * Destruct this my_deque
         */
        ~my_deque () {
            if (!empty())
                clear();
            pointer* d = _d;
            while (d != _e) {
                _a.deallocate(*d, BLOCK_SIZE);
                ++d;
            }
            _b.deallocate(_d, _e - _d);
            assert(valid());
        }

        /**
         * Assign the contents of a my_deque to this my_deque
         * @param rhs a my_deque to assign from
         * @return this my_deque
         */
        my_deque& operator = (const my_deque& rhs) {
            if (this == &rhs)
                return *this;
            else if (rhs.size() == _s)
                copy(rhs.begin(), rhs.end(), begin());
            else if (rhs.size() < _s) {
                copy(rhs.begin(), rhs.end(), begin());
                resize(rhs.size());
                _s = rhs.size();
            } else {
                rrealloc(rhs.size() - _s);
                copy(rhs.begin(), rhs.begin() + _s, begin());
                size_type old_s = _s;
                iterator start_it = end();
                _s = rhs.size();
                uninitialized_copy(_a, rhs.begin() + old_s, rhs.end(), start_it);
            }
            
            assert(valid());
            return *this;
        }

        /**
         * Index into this my_deque to retrieve an element at
         * a specific location
         * @param index a location within the my_deque
         * @return a reference to the element at the location index
         */
        reference operator [] (size_type index) {
            size_type row = (index + _o) / BLOCK_SIZE;
            size_type col = (index + _o) % BLOCK_SIZE;
            return (_d[row])[col];
        }

        /**
         * Index into this constant my_deque to retrieve an element at
         * a specific location
         * @param index a location within the my_deque
         * @return a constant reference to the element at the location index
         */
        const_reference operator [] (size_type index) const {
            return const_cast<my_deque*>(this)->operator[](index);
        }

        /**
         * Index into this my_deque to retrieve an element at
         * a specific location. Throws an out_of_range exception
         * if index is greater than or equal to this my_deque's
         * size
         * @param index a location within the my_deque
         * @return a reference to the element at the location index
         * @throws out_of_range if index is >= this my_deque's size
         */
        reference at (size_type index) {
            if (index >= size())
                throw std::out_of_range("my_deque");
            return (*this)[index];
        }

        /**
         * Index into this constant my_deque to retrieve an element at
         * a specific location. Throws an out_of_range exception
         * if index is greater than or equal to this my_deque's
         * size
         * @param index a location within the my_deque
         * @return a constant reference to the element at the location index
         * @throws out_of_range if index is >= this my_deque's size
         */
        const_reference at (size_type index) const {
            return const_cast<my_deque*>(this)->at(index);
        }

        /**
         * Get the element at the back of this my_deque
         * @return a reference to the last element
         */
        reference back () {
            assert(!empty());
            return *(end() - 1);
        }

        /**
         * Get the element at the back of this constant my_deque
         * @return a constant reference to the last element
         */
        const_reference back () const {
            return const_cast<my_deque*>(this)->back();
        }

        /**
         * Get an iterator to the beginning of this my_deque
         * @return an iterator to the beginning
         */
        iterator begin () {
            return iterator(*this, 0);
        }

        /**
         * Get a const_iterator to the beginning of this constant my_deque
         * @return a const_iterator to the beginning
         */
        const_iterator begin () const {
            return const_iterator(*this, 0);
        }

        /**
         * Remove all elements from this my_deque
         */
        void clear () {
            resize(0);
            assert(valid());
        }

        /**
         * Check to see if this my_deque is empty
         * @return true if this my_deque is empty
         */
        bool empty () const {
            return !size();
        }

        /**
         * Get an iterator to the end of this my_deque
         * @return an iterator to the end
         */
        iterator end () {
            return iterator(*this, _s);
        }

        /**
         * Get a const_iterator to the end of this constant my_deque
         * @return a const_iterator to the end
         */
        const_iterator end () const {
            return const_iterator(*this, _s);
        }

        /**
         * Remove a single element from this my_deque
         * @param it an iterator pointing to the element to be removed
         * @return an itertaor pointing to the element that came immediately
         * after the element that was removed
         */
        iterator erase (iterator it) {
            iterator b(it);
            iterator e(--end());
            while (b != e) {
                *b = *(b + 1);
                ++b;
            }
            pop_back();
            assert(valid());
            return it;
        }

        /**
         * Get the element at the front of this my_deque
         * @return a reference to the first element in this my_deque
         */
        reference front () {
            assert(!empty());
            return *begin();
        }

        /**
         * Get the element at the front of this constant my_deque
         * @return a constant reference to the first element in this my_deque
         */
        const_reference front () const {
            return const_cast<my_deque*>(this)->front();
        }

        /**
         * Insert an element into this my_deque
         * @param it an iterator to the insertion location
         * @param v a const reference to be inserted
         * @return an iterator pointing to the newly inserted element
         */
        iterator insert (iterator it, const_reference v) {
            push_back(*--end());
            iterator b(it);
            iterator e(--end());
            while (e != b) {
                *e = *(e - 1);
                --e;
            }
            *e = v;
            assert(valid());
            return it;
        }

        /**
         * Remove the last element from this my_deque
         */
        void pop_back () {
            assert(!empty());
            _a.destroy(&(*--end()));
            --_s;
            assert(valid());
        }

        /**
         * Remove the first element from this my_deque
         */
        void pop_front () {
            assert(!empty());
            _a.destroy(&(*begin()));
            ++_o;
            --_s;
            assert(valid());
        }

        /**
         * Put a new element at the back of this my_deque
         * @param v a const reference to the new element
         */
        void push_back (const_reference v) {
            if (!right_free())
                rrealloc(1);
            _a.construct(&(*end()), v);
            ++_s;
            assert(valid());
        }

        /**
         * Put a new element at the front of this my_deque
         * @param v a const reference to the new element
         */
        void push_front (const_reference v) {
            if (!left_free())
                lrealloc(1);
            --_o;
            ++_s;
            _a.construct(&(*begin()), v);
            assert(valid());
     	}

        /**
         * Change the size of this my_deque
         * @param s the new desired size for my_deque
         * @param v the value to fill with if the new size if greater
         * than the current size
         */
        void resize (size_type s, const_reference v = value_type()) {
            if (_s == s)
                return;
            else if (s < _s) {
                destroy(_a, begin() + s, end());
                _s = s;
            } else if (s <= _s + right_free()) {
            	iterator start_it = end();
            	size_type old_s = _s;
            	_s = s;
                uninitialized_fill(_a, start_it, start_it + (s - old_s), v);
            } else {
            	iterator start_it = end();
            	size_type old_s = _s;
            	_s = s;
                rrealloc(s - old_s);
                uninitialized_fill(_a, start_it, start_it + (s - old_s), v);
            }
            assert(valid());
        }

        /**
         * Get the size in number of elements of this my_deque
         * @return the number of elements in this my_deque
         */
        size_type size () const {
            return _s;
        }

        /**
         * Swap out the contents of this my_deque with the contents
         * of another my_deque
         * @param rhs a my_deque to swap with
         */
        void swap (my_deque& rhs) {
            if (this == &rhs)
                return;
            my_deque d(*this);
            *this = rhs;
            rhs = d;
            assert(valid());
        }
        
};

#endif // Deque_h
