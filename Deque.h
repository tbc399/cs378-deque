// --------------------------
// projects/c++/deque/Deque.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Deque_h
#define Deque_h

/* size of an individual block in number of elements */
#define BLOCK_SIZE 5

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
                                           rhs.begin(), lhs.end());
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
        
        bool valid () const {
            // <your code>
            return true;
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

                bool valid () const {
                    return _i <= _q.size();
                }

            public:

                /**
                 * Construct an iterator for a my_deque
                 * @param q a my_deque to iterate over
                 * @param i an index into the my_deque
                 */
                iterator (my_deque& q, size_type i) : _q(q) {
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

                /* a reference to an immutable my_deque */
                const my_deque& _q;
                
                /* represents an index into _q */
                size_type _i;

            private:

                bool valid () const {
                    return _i <= _q.size();
                }

            public:

                /**
                 * Construct a const_terator for a const my_deque
                 * @param q a const my_deque to iterate over
                 * @param i an index into the my_deque
                 */
                const_iterator (const my_deque& q, size_type i) : _q(q) {
                    _i = i;
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
                    return _q[_i];
                }

                /**
                 * Get the pointer to the underlying element of this const_iterator
                 * @return a pointer to an element of this my_deque
                 */
                pointer operator -> () const {
                    return &(_q[_i]);
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
            _o = _s = 0;
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
            
            /* even if s % BLOCK_SIZE == 0 give 'em an extra block just cuz */
            _d = _b.allocate((s / BLOCK_SIZE) + 1);
            _e = _d + (s / BLOCK_SIZE + 1);
            
            _o = 0;
            _s = s;
            
            resize(_s, v);
            
            assert(valid());
            
        }

        /**
         * Construct a copy of a my_deque
         * @param that the my_deque to copy
         */
        my_deque (const my_deque& that) {
            // <your code>
            if (!that.size()) {
                _d = _e = 0;
                _o = _s = 0;
                assert(valid());
                return;
            }
            
            /* even if s % BLOCK_SIZE == 0 give 'em an extra block just cuz */
            _d = _b.allocate((s / BLOCK_SIZE) + 1);
            _e = _d + (s / BLOCK_SIZE) + 1;
            
            _o = 0;
            _s = that.size();
            
            // TODO: copy over values
            
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
                ++d
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
            // <your code>
            if (this == &rhs)
                return *this;
            else if (rhs.size() == size())
                copy(rhs.begin(), rhs.end(), begin());
            else if (rhs.size() < size()) {
                copy(rhs.begin(), rhs.end(), begin());
                resize(rhs.size());
                _s = rhs.size();
            } else if (rhs.size() <= (_e - _d) * BLOCK_SIZE) {
                // TODO: handle case where rhs.size() > _e - (_d + _o)
                copy(rhs.begin(), rhs.begin() + size(), begin());
                _e = uninitialized_copy(_a, rhs.begin() + size(), rhs.end(), end());
                _s = rhs.size();
            } else {
                
                if (!empty())
                    clear();
                    
                /* reserve more memory */
                pointer* d = _d;
                while (d != _e) {
                    _a.deallocate(*d, BLOCK_SIZE);
                    ++d
                }
                _b.deallocate(_d, _e - _d);
                
                _d = _b.allocate((rhs.size() / BLOCK_SIZE) + 1);
                _e = d + (rhs.size() / BLOCK_SIZE) + 1;
                _o = 0;
                _s = rhs.size();
                
                uninitialized_copy(_a, rhs.begin(), rhs.end(), begin());
                    
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
            return iterator(*this, _s - 1);
        }

        /**
         * Get a const_iterator to the end of this constant my_deque
         * @return a const_iterator to the end
         */
        const_iterator end () const {
            return const_iterator(*this, _s - 1);
        }

        /**
         * <your documentation>
         */
        iterator erase (iterator it) {
            // <your code>
            assert(valid());
            return iterator();
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
         * <your documentation>
         */
        iterator insert (iterator it, const_reference v) {
            // <your code>
            assert(valid());
            return iterator();
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
         * <your documentation>
         */
        void push_back (const_reference v) {
            // <your code>
            //resize(size() + 1, v);
            assert(valid());
        }

        /**
         * <your documentation>
         */
        void push_front (const_reference v) {
            // <your code>
            assert(valid());}

        /**
         * <your documentation>
         */
        void resize (size_type s, const_reference v = value_type()) {
            // <your code>
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
            // <your code>
            // TODO: try and use move constructors
            if (this == &rhs)
                return;
            my_deque d(*this);
            *this = rhs;
            rhs = d;
            assert(valid());
        }
        
};

#endif // Deque_h
