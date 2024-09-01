#ifndef std
#include <iostream>
#endif
#define __RTT template<typename R> // Macro defining a template alias for types used in the Range class
#define NULL_Range Range<R>(R(),R())   // Macro defining a default null range value

__RTT
class Range
{
public:
    R Begin, End;  // Public member variables for the beginning and end of the range

    class Iterator
    {
    private:
        R *Begin, *End;  // Pointers to the start and end of the range
        R current;       // Current position of the iterator
        R step = 1;      // Step size for iteration (default is 1)

        /*
        @brief Ensures the iterator does not exceed the range limits.
        @param n The value to check.
        @return The value adjusted to be within the range limits.
        */
        R LimitCheck(R n) {
            if(n <= *Begin) return *Begin;
            if(n >= *End) return *End;
            return n;
        }

    public:
        /*
        @brief Various constructors for initializing the iterator.
        @param Begin The starting value of the range.
        @param End The ending value of the range.
        */
        Iterator(R Begin, R End) {
            R *B = (R*) malloc(sizeof(R)), *E = (R*) malloc(sizeof(R));
            *B = Begin; *E = End;
            this->Begin = B; this->End = E; current = Begin;
        }

        /*
        @brief Constructor for initializing the iterator using pointers.
        @param Begin Pointer to the starting value of the range.
        @param End Pointer to the ending value of the range.
        */
        Iterator(R* Begin, R* End) { this->Begin = Begin; this->End = End; this->current = *Begin; }

        /*
        @brief Constructor for initializing the iterator using a Range object.
        @param r A Range object.
        */
        Iterator(Range r) { Iterator(r.Begin, r.End); }

        /*
        @brief Constructor for initializing the iterator using a Range pointer.
        @param r A pointer to a Range object.
        */
        Iterator(Range* r) { Iterator(r->Begin, r->End); }

        /*
        @brief Constructor for initializing the iterator with a step size.
        @param Begin The starting value of the range.
        @param End The ending value of the range.
        @param step The step size for iteration.
        */
        Iterator(R Begin, R End, R step) { Iterator(Begin, End); this->step = step; }

        /*
        @brief Constructor for initializing the iterator using pointers with a step size.
        @param Begin Pointer to the starting value of the range.
        @param End Pointer to the ending value of the range.
        @param step The step size for iteration.
        */
        Iterator(R* Begin, R* End, R step) { Iterator(Begin, End); this->step = step; }

        /*
        @brief Constructor for initializing the iterator using a Range object with a step size.
        @param r A Range object.
        @param step The step size for iteration.
        */
        Iterator(Range r, R step) { Iterator(r.Begin, r.End); this->step = step; }

        /*
        @brief Constructor for initializing the iterator using a Range pointer with a step size.
        @param r A pointer to a Range object.
        @param step The step size for iteration.
        */
        Iterator(Range* r, R step) { Iterator(r->Begin, r->End); this->step = step; }

        /*
        @brief Destructor for the Iterator class.
        */
        ~Iterator() {}  

        /*
        @brief Overloaded operator to increment the iterator by step size.
        */
        void operator++() { current = LimitCheck(current + step); }  

        /*
        @brief Overloaded operator to increment the iterator by step size (unused parameter).
        @param a Unused parameter.
        */
        void operator++(R a) { current = LimitCheck(current + step); }  

        /*
        @brief Overloaded operator to move the iterator forward by n steps.
        @param n Number of steps to move forward.
        @return The updated iterator.
        */
        Range::Iterator operator+(R n) { current = LimitCheck(current + n * step); return *this; }

        /*
        @brief Overloaded operator to increment the iterator by n steps.
        @param n Number of steps to increment.
        @return The updated iterator.
        */
        Range::Iterator operator+=(R n) { return operator+(n); }  

        /*
        @brief Overloaded operator to decrement the iterator by step size.
        */
        void operator--() { current = LimitCheck(current - step); }

        /*
        @brief Overloaded operator to move the iterator backward by n steps.
        @param n Number of steps to move backward.
        @return The updated iterator.
        */
        Range::Iterator operator-(R n) { current = LimitCheck(current - n * step); return *this; }  

        /*
        @brief Overloaded operator to decrement the iterator by n steps.
        @param n Number of steps to decrement.
        @return The updated iterator.
        */
        Range::Iterator operator-=(R n) { return operator-(n); }  

        /*
        @brief Overloaded equality operator for iterators.
        @param t The iterator to compare with.
        @return True if iterators are equal, false otherwise.
        */
        bool operator==(Range::Iterator t) { return current == t.current; }  

        /*
        @brief Overloaded inequality operator for iterators.
        @param t The iterator to compare with.
        @return True if iterators are not equal, false otherwise.
        */
        bool operator!=(Range::Iterator t) { return current != t.current; }  

        /*
        @brief Overloaded dereference operator to get current iterator value.
        @return The current value of the iterator.
        */
        R operator*() { return current; }

        /*
        @brief Checks if iterator is at the end of the range.
        @return True if at the end, false otherwise.
        */
        bool isEnd() { return current == *End; }

        /*
        @brief Checks if iterator is at the beginning of the range.
        @return True if at the beginning, false otherwise.
        */
        bool isBegin() { return current == *Begin; }
    };

    /*
    @brief Constructor for the Range class.
    @param begin The starting value of the range.
    @param end The ending value of the range.
    */
    Range(R begin, R end);  

    /*
    @brief Destructor for the Range class.
    */
    ~Range() {};  

    /*
    @brief Returns the intersection of this range and t.
    @param t The range to intersect with.
    @return A new range representing the intersection.
    */
    Range Intersection(Range t);  

    /*
    @brief Returns the union of this range and t if they intersect.
    @param t The range to union with.
    @return A new range representing the union or NULL_Range if no intersection.
    */
    Range Union(Range t);  

    /*
    @brief Returns the difference between this range and t.
    @param t The range to find the difference with.
    @return A new range representing the difference.
    */
    Range Difference(Range t);  

    /*
    @brief Checks if two ranges are equal.
    @param t The range to compare with.
    @return True if ranges are equal, false otherwise.
    */
    bool equal(Range t);  

    /*
    @brief Checks if this range contains the range t.
    @param t The range to check.
    @return True if this range contains t, false otherwise.
    */
    bool IsContain(Range t);  

    /*
    @brief Overloaded equality operator for ranges.
    @param t The range to compare with.
    @return True if ranges are equal, false otherwise.
    */
    bool operator==(Range t);  

    /*
    @brief Overloaded inequality operator for ranges.
    @param t The range to compare with.
    @return True if ranges are not equal, false otherwise.
    */
    bool operator!=(Range t);  

    /*
    @brief Overloaded greater than or equal operator for comparing range lengths.
    @param t The range to compare with.
    @return True if this range is greater than or equal to t, false otherwise.
    */
    bool operator>=(Range t);  

    /*
    @brief Overloaded less than or equal operator for comparing range lengths.
    @param t The range to compare with.
    @return True if this range is less than or equal to t, false otherwise.
    */
    bool operator<=(Range t);  

    /*
    @brief Overloaded greater than operator for comparing range lengths.
    @param t The range to compare with.
    @return True if this range is greater than t, false otherwise.
    */
    bool operator>(Range t);  

    /*
    @brief Overloaded less than operator for comparing range lengths.
    @param t The range to compare with.
    @return True if this range is less than t, false otherwise.
    */
    bool operator<(Range t);  

    /*
    @brief Updates this range with the intersection of this and t.
    @param t The range to intersect with.
    */
    void operator&=(Range t);  

    /*
    @brief Updates this range with the union of this and t.
    @param t The range to union with.
    */
    void operator|=(Range t);  

    /*
    @brief Overloaded && operator to return the intersection of two ranges.
    @param t The range to intersect with.
    @return A new range representing the intersection.
    */
    Range operator&&(Range t);  

    /*
    @brief Overloaded || operator to return the union of two ranges.
    @param t The range to union with.
    @return A new range representing the union.
    */
    Range operator||(Range t);  

    /*
    @brief Changes the beginning of the range (must be less than or equal to End).
    @param begin The new beginning value.
    */
    void ChangeBegin(R begin);  

    /*
    @brief Moves the beginning of the range by a specified amount.
    @param begin The amount to move the beginning by.
    */
    void MoveBegin(R begin);  

    /*
    @brief Changes the end of the range (must be greater than or equal to Begin).
    @param end The new end value.
    */
    void ChangeEnd(R end);  

    /*
    @brief Moves the end of the range by a specified amount.
    @param end The amount to move the end by.
    */
    void MoveEnd(R end);  

    /*
    @brief Overloaded assignment operator to set this range equal to t.
    @param t The range to assign to this range.
    */
    void operator=(Range t);  

    /*
    @brief Overloaded + operator to return the union of this range and t.
    @param t The range to union with.
    @return A new range representing the union.
    */
    Range operator+(Range t);  

    /*
    @brief Overloaded - operator to return the difference between this range and t.
    @param t The range to subtract from this range.
    @return A new range representing the difference.
    */
    Range operator-(Range t);  

    /*
    @brief Overloaded += operator to update this range with the union of this and t.
    @param t The range to union with.
    */
    void operator+=(Range t);  

    /*
    @brief Overloaded -= operator to update this range with the difference between this and t.
    @param t The range to subtract from this range.
    */
    void operator-=(Range t);  

    /*
    @brief Returns the length of the range.
    @return The length of the range.
    */
    R length();  

    /*
    @brief Returns an iterator starting at the beginning of the range.
    @return An iterator at the beginning of the range.
    */
    typename Range<R>::Iterator BeginIter();  

    /*
    @brief Returns an iterator starting at the end of the range.
    @return An iterator at the end of the range.
    */
    typename Range<R>::Iterator EndIter();  

    /*
    @brief Returns an iterator with a specific step size starting at the beginning of the range.
    @param step The step size for iteration.
    @return An iterator at the beginning of the range.
    */
    typename Range<R>::Iterator BeginIter(R step);  

    /*
    @brief Returns an iterator with a specific step size starting at the end of the range.
    @param step The step size for iteration.
    @return An iterator at the end of the range.
    */
    typename Range<R>::Iterator EndIter(R step);  

    /*
    @brief Returns an iterator pointing to the beginning of the range.
    @return An iterator at the beginning of the range.
    */
    typename Range<R>::Iterator begin();  

    /*
    @brief Returns an iterator pointing to the end of the range.
    @return An iterator at the end of the range.
    */
    typename Range<R>::Iterator end();  
};

__RTT
Range<R>::Range(R begin, R end)
{
    // Constructor initializes the range with specified begin and end values
    this->Begin = begin;
    this->End = end;
}

__RTT
Range<R> Range<R>::Intersection(Range t)
{
    // Returns the intersection of this range and t, or NULL_Range if no intersection
    if (t.End > this->Begin || t.Begin < this->End)
    {
        if (this->IsContain(t))  // t is inside this range
        {
            return t;
        }

        if (t.IsContain(*this))  // this range is inside t
        {
            return *this;
        }
        
        if (t.Begin <= this->End && t.Begin >= this->Begin)  // Right overlap
        {
            return Range<R>(t.Begin, this->End);
        }

        if (t.End >= this->Begin && t.End <= this->End)  // Left overlap
        {
            return Range<R>(this->Begin, t.End);
        }
    }
    return NULL_Range;  // No overlap
}

__RTT
Range<R> Range<R>::Union(Range t)
{
    // Returns the union of this range and t if they intersect, otherwise returns NULL_Range
    Range<R> temp = NULL_Range;
    if (Intersection(t) != temp) {
        if (this->Begin < t.Begin) temp.Begin = this->Begin;
        else temp.Begin = t.Begin;

        if (this->End > t.End) temp.End = this->End;
        else temp.End = t.End;
    }

    return temp;
}

__RTT bool Range<R>::equal(Range t)
{
    // Checks if two ranges are equal
    return (t.Begin == this->Begin && t.End == this->End);
}

__RTT bool Range<R>::IsContain(Range t)
{
    // Checks if this range contains the range t
    return (this->Begin <= t.Begin && this->End >= t.End);
}

__RTT bool Range<R>::operator==(Range t)
{
    // Overloaded equality operator for ranges
    return this->equal(t);
}

__RTT bool Range<R>::operator!=(Range t)
{
    // Overloaded inequality operator for ranges
    return !this->equal(t);
}

__RTT bool Range<R>::operator>=(Range t)
{
    // Overloaded greater than or equal operator for comparing range lengths
    return this->length() >= t.length();
}

__RTT bool Range<R>::operator<=(Range t)
{
    // Overloaded less than or equal operator for comparing range lengths
    return this->length() <= t.length();
}

__RTT bool Range<R>::operator>(Range t)
{
    // Overloaded greater than operator for comparing range lengths
    return this->length() > t.length();
}

__RTT bool Range<R>::operator<(Range t)
{
    // Overloaded less than operator for comparing range lengths
    return this->length() < t.length();
}

__RTT void Range<R>::operator&=(Range t)
{
    // Updates this range with the intersection of this and t
    Range<R> temp = Intersection(t);
    if (temp != NULL_Range)
    {
        this->Begin = temp.Begin;
        this->End = temp.End;
    }
}

__RTT void Range<R>::operator|=(Range t)
{
    // Updates this range with the union of this and t
    Range<R> temp = Union(t);
    if (temp != NULL_Range)
    {
        this->Begin = temp.Begin;
        this->End = temp.End;
    }
}

__RTT Range<R> Range<R>::operator&&(Range t)
{
    // Overloaded && operator to return the intersection of two ranges
    return Intersection(t);
}

__RTT Range<R> Range<R>::operator||(Range t)
{
    // Overloaded || operator to return the union of two ranges
    return Union(t);
}

__RTT void Range<R>::ChangeBegin(R begin)
{
    // Changes the beginning of the range (must be less than or equal to End)
    if (begin <= this->End) this->Begin = begin;
}

__RTT void Range<R>::MoveBegin(R begin)
{
    // Moves the beginning of the range by a specified amount
    ChangeBegin(this->Begin + begin);
}

__RTT void Range<R>::ChangeEnd(R end)
{
    // Changes the end of the range (must be greater than or equal to Begin)
    if (end >= this->Begin) this->End = end;
}

__RTT void Range<R>::MoveEnd(R end)
{
    // Moves the end of the range by a specified amount
    ChangeEnd(this->End + end);
}

__RTT void Range<R>::operator=(Range t)
{
    // Overloaded assignment operator to set this range equal to t
    this->Begin = t.Begin;
    this->End = t.End;
}

__RTT Range<R> Range<R>::operator+(Range t)
{
    // Overloaded + operator to return the union of this range and t
    Range<R> temp = Union(t);
    if (temp == NULL_Range)
    {
        return *this;
    }
    return temp;
}

__RTT Range<R> Range<R>::operator-(Range t)
{
    // Overloaded - operator to return the difference between this range and t
    R begin = this->Begin, end = this->End;
    if (t.End < end && t.End >= begin) end = t.End;
    if (t.Begin > begin && t.Begin <= end) begin = t.Begin;
    return Range<R>(begin, end);
}

__RTT void Range<R>::operator+=(Range t)
{
    // Overloaded += operator to update this range with the union of this and t
    *this = *this + t;
}

__RTT void Range<R>::operator-=(Range t)
{
    // Overloaded -= operator to update this range with the difference between this and t
    *this = *this - t;
}

__RTT R Range<R>::length()
{
    // Returns the length of the range
    return this->End - this->Begin;
}

__RTT typename Range<R>::Iterator Range<R>::BeginIter()
{
    // Returns an iterator starting at the beginning of the range
    return Range<R>::Iterator(this->Begin, this->End);
}

__RTT typename Range<R>::Iterator Range<R>::EndIter()
{
    // Returns an iterator starting at the end of the range
    Range<R>::Iterator temp = BeginIter();
    temp += (this->length() + 1); // Move iterator to the end
    return temp;
}

__RTT typename Range<R>::Iterator Range<R>::BeginIter(R step)
{
    // Returns an iterator with a specific step size starting at the beginning of the range
    return Range<R>::Iterator(this->Begin, this->End, step);
}

__RTT typename Range<R>::Iterator Range<R>::EndIter(R step)
{
    // Returns an iterator with a specific step size starting at the end of the range
    Range<R>::Iterator temp = BeginIter(step);
    temp += (R)(this->length() / step + 1);  // Move iterator to the end
    return temp;
}

__RTT typename Range<R>::Iterator Range<R>::begin()
{
    // Returns an iterator pointing to the beginning of the range
    return BeginIter();
}

__RTT typename Range<R>::Iterator Range<R>::end()
{
    // Returns an iterator pointing to the end of the range
    return EndIter();
}

/*
@brief Overloaded stream insertion operator for outputting the range.
@param os The output stream.
@param t The range to output.
@return The output stream.
*/
__RTT std::ostream& operator<<(std::ostream& os, const Range<R>& t) {
    os << "Range(" << t.Begin << ", " << t.End << ")";
    return os;
}