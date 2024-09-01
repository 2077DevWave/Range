#include <iostream>
#include <string>
#include "Range.cpp" // Assuming your class is defined in a header file named Range.hpp

void TestPassed(int num, std::string title){
    std::cout << "\n" << "[Test " << num << "](" << title << ")" << ": " << "✅ Passed" << '\n';
}

int main() {
    ///////////////////////// Test 1: Basic Range Usage ////////////////////////////////
    Range<int> range1(1, 5);
    std::cout << "Range1: " << range1 << std::endl;
    TestPassed(1, "Basic Range Usage");
    ///////////////////////////////////////////////////////////////////////////////////

    ///////////////////////// Test 2: Iterating through a Range /////////////////////////
    std::cout << "Iterating through Range1: ";
    for (auto it = range1.BeginIter(); it != range1.EndIter(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    TestPassed(2, "Iterating through a Range");
    ///////////////////////////////////////////////////////////////////////////////////

    ///////////////////////// Test 3: Using Custom Step with Iterators //////////////////
    Range<int> range2(0, 10);
    std::cout << "Iterating through Range2 with step 2: ";
    for (auto it = range2.BeginIter(2); it != range2.EndIter(2); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    TestPassed(3, "Using Custom Step with Iterators");
    ///////////////////////////////////////////////////////////////////////////////////

    ///////////////////////// Test 4: Range Intersection ///////////////////////////////
    Range<int> range3(4, 8);
    Range<int> intersection = range1.Intersection(range3);
    std::cout << "Intersection of Range1 and Range3: " << intersection << std::endl;
    TestPassed(4, "Range Intersection");
    ///////////////////////////////////////////////////////////////////////////////////

    ///////////////////////// Test 5: Range Union //////////////////////////////////////
    Range<int> unionRange = range1.Union(range3);
    std::cout << "Union of Range1 and Range3: " << unionRange << std::endl;
    TestPassed(5, "Range Union");
    ///////////////////////////////////////////////////////////////////////////////////

    ///////////////////////// Test 6: Range Difference //////////////////////////////////
    Range<int> difference = range1 - range3;
    std::cout << "Difference between Range1 and Range3: " << difference << std::endl;
    TestPassed(6, "Range Difference");
    ///////////////////////////////////////////////////////////////////////////////////

    ///////////////////////// Test 7: Using Relational Operators ////////////////////////
    std::cout << "Is Range1 equal to Range3? " << (range1 == range3) << std::endl;
    std::cout << "Is Range1 not equal to Range3? " << (range1 != range3) << std::endl;
    std::cout << "Is Range1 greater than Range3? " << (range1 > range3) << std::endl;
    std::cout << "Is Range1 less than or equal to Range3? " << (range1 <= range3) << std::endl;
    TestPassed(7, "Using Relational Operators");
    ///////////////////////////////////////////////////////////////////////////////////

    ///////////////////////// Test 8: Modifying Ranges /////////////////////////////////
    Range<int> range4(5, 15);
    std::cout << "Initial Range4: " << range4 << std::endl;
    range4.ChangeBegin(6);
    range4.ChangeEnd(14);
    std::cout << "Modified Range4: " << range4 << std::endl;
    TestPassed(8, "Modifying Ranges");
    ///////////////////////////////////////////////////////////////////////////////////

    ///////////////////////// Test 9: Using Compound Assignment Operators ///////////////
    Range<int> range5(3, 7);
    range5 += range1;
    std::cout << "Range5 after union with Range1: " << range5 << std::endl;

    range5 -= range3;
    std::cout << "Range5 after difference with Range3: " << range5 << std::endl;
    TestPassed(9, "Using Compound Assignment Operators");
    ///////////////////////////////////////////////////////////////////////////////////

    ///////////////////////// Test 10: Test Iterator Operations ////////////////////////
    Range<int>::Iterator it = range1.BeginIter();
    std::cout << "Current iterator value: " << *it << std::endl;
    ++it;
    std::cout << "Iterator after increment: " << *it << std::endl;

    it += 2;
    std::cout << "Iterator after adding 2: " << *it << std::endl;

    --it;
    std::cout << "Iterator after decrement: " << *it << std::endl;

    it -= 1;
    std::cout << "Iterator after subtracting 1: " << *it << std::endl;
    TestPassed(10, "Test Iterator Operations");
    ///////////////////////////////////////////////////////////////////////////////////

    return 0;
}
