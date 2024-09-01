# Range Module

The `Range` module provides a C++ class template for handling ranges of values with various utility functions. This module is designed to facilitate range-based operations such as iteration, intersection, union, difference, and comparison. The `Range` class also includes an `Iterator` class to allow easy traversal over the range.

## Features

- **Range Creation**: Define a range with a beginning and end value.
- **Iteration**: Use a range in a range-based `for` loop with custom step sizes.
- **Intersection and Union**: Find the intersection and union of two ranges.
- **Difference**: Compute the difference between two ranges.
- **Comparison**: Compare two ranges based on their lengths or equality.
- **Manipulation**: Change or move the beginning and end points of a range.
- **Output**: Overloaded `<<` operator for easy output of ranges.

## Usage

### Including the Module

To use the `Range` module in your project, include the header file where you define the class, or directly include the code in your project.

## Usage Examples

### 1. Basic Range Creation and Iteration

You can create a range and iterate over it using a range-based `for` loop:

```cpp
#include <iostream>
// Include the Range module here

int main() {
    // Create a range from 1 to 5
    Range<int> range(1, 5);

    // Iterate over the range and print each value
    for (int i : range) {
        std::cout << i << " ";  // Output: 1 2 3 4 5
    }

    return 0;
}
```

### 2. Intersection of Two Ranges

Find the intersection of two ranges:

```cpp
#include <iostream>
// Include the Range module here

int main() {
    Range<int> rangeA(1, 5);
    Range<int> rangeB(3, 7);

    // Get the intersection of rangeA and rangeB
    Range<int> intersection = rangeA.Intersection(rangeB);

    std::cout << "Intersection: " << intersection << std::endl;  // Output: Range(3, 5)

    return 0;
}
```

### 3. Union of Two Ranges

Find the union of two overlapping ranges:

```cpp
#include <iostream>
// Include the Range module here

int main() {
    Range<int> rangeA(1, 5);
    Range<int> rangeB(3, 7);

    // Get the union of rangeA and rangeB
    Range<int> rangeUnion = rangeA.Union(rangeB);

    std::cout << "Union: " << rangeUnion << std::endl;  // Output: Range(1, 7)

    return 0;
}
```

### 4. Difference Between Two Ranges

Compute the difference between two ranges:

```cpp
#include <iostream>
// Include the Range module here

int main() {
    Range<int> rangeA(1, 5);
    Range<int> rangeB(3, 7);

    // Get the difference of rangeA and rangeB
    Range<int> difference = rangeA.Difference(rangeB);

    std::cout << "Difference: " << difference << std::endl;  // Output: Range(1, 3)

    return 0;
}
```

### 5. Range Comparisons

Compare two ranges using comparison operators:

```cpp
#include <iostream>
// Include the Range module here

int main() {
    Range<int> rangeA(1, 5);
    Range<int> rangeB(3, 7);
    Range<int> rangeC(1, 5);

    std::cout << "rangeA == rangeB: " << (rangeA == rangeB) << std::endl;  // Output: 0 (false)
    std::cout << "rangeA == rangeC: " << (rangeA == rangeC) << std::endl;  // Output: 1 (true)
    std::cout << "rangeA != rangeB: " << (rangeA != rangeB) << std::endl;  // Output: 1 (true)
    std::cout << "rangeA > rangeB: " << (rangeA > rangeB) << std::endl;    // Output: 0 (false)
    std::cout << "rangeA < rangeB: " << (rangeA < rangeB) << std::endl;    // Output: 1 (true)

    return 0;
}
```

### 6. Modifying Ranges

Change the beginning and end of a range:

```cpp
#include <iostream>
// Include the Range module here

int main() {
    Range<int> range(1, 5);

    std::cout << "Original Range: " << range << std::endl;  // Output: Range(1, 5)

    // Change the beginning of the range
    range.ChangeBegin(2);
    std::cout << "After Changing Begin: " << range << std::endl;  // Output: Range(2, 5)

    // Change the end of the range
    range.ChangeEnd(8);
    std::cout << "After Changing End: " << range << std::endl;    // Output: Range(2, 8)

    return 0;
}
```

### 7. Moving Range Boundaries

Move the beginning or end of a range by a specific amount:

```cpp
#include <iostream>
// Include the Range module here

int main() {
    Range<int> range(1, 5);

    std::cout << "Original Range: " << range << std::endl;  // Output: Range(1, 5)

    // Move the beginning of the range by +2
    range.MoveBegin(2);
    std::cout << "After Moving Begin: " << range << std::endl;  // Output: Range(3, 5)

    // Move the end of the range by +3
    range.MoveEnd(3);
    std::cout << "After Moving End: " << range << std::endl;    // Output: Range(3, 8)

    return 0;
}
```

### 8. Custom Iteration with Step Size

Iterate over a range with a custom step size:

```cpp
#include <iostream>
// Include the Range module here

int main() {
    Range<int> range(1, 10);

    // Iterate with a step size of 2
    for (auto it = range.BeginIter(2); !it.isEnd(); ++it) {
        std::cout << *it << " ";  // Output: 1 3 5 7 9
    }

    std::cout << std::endl;

    // Iterate with a step size of 3
    for (auto it = range.BeginIter(3); !it.isEnd(); ++it) {
        std::cout << *it << " ";  // Output: 1 4 7 10
    }

    return 0;
}
```

### 9. Using Overloaded Operators for Ranges

Perform operations directly using overloaded operators:

```cpp
#include <iostream>
// Include the Range module here

int main() {
    Range<int> rangeA(1, 5);
    Range<int> rangeB(3, 7);

    // Use the overloaded '+' operator to compute the union
    Range<int> rangeUnion = rangeA + rangeB;
    std::cout << "Union using '+': " << rangeUnion << std::endl;  // Output: Range(1, 7)

    // Use the overloaded '&&' operator to compute the intersection
    Range<int> rangeIntersection = rangeA && rangeB;
    std::cout << "Intersection using '&&': " << rangeIntersection << std::endl;  // Output: Range(3, 5)

    // Use the overloaded '-' operator to compute the difference
    Range<int> rangeDifference = rangeA - rangeB;
    std::cout << "Difference using '-': " << rangeDifference << std::endl;  // Output: Range(1, 3)

    return 0;
}
```

### 10. Using Range Objects in Custom Logic

Combine the provided functions and operators to implement more complex logic:

```cpp
#include <iostream>
// Include the Range module here

int main() {
    Range<int> rangeA(1, 10);
    Range<int> rangeB(5, 15);

    // Check if ranges intersect
    if (rangeA && rangeB != NULL_Range) {
        std::cout << "Ranges intersect." << std::endl;

        // Compute and print the intersection
        Range<int> intersection = rangeA && rangeB;
        std::cout << "Intersection: " << intersection << std::endl;  // Output: Range(5, 10)
    } else {
        std::cout << "Ranges do not intersect." << std::endl;
    }

    // Compute and print the union of the ranges
    Range<int> unionRange = rangeA || rangeB;
    std::cout << "Union: " << unionRange << std::endl;  // Output: Range(1, 15)

    // Modify rangeA and print the results
    rangeA.MoveBegin(2);  // Move begin by 2
    rangeA.MoveEnd(-1);   // Move end by -1
    std::cout << "Modified RangeA: " << rangeA << std::endl;  // Output: Range(3, 9)

    return 0;
}
```

---

### Creating a Range

To create a range, instantiate the `Range` class with a specific type and specify the beginning and end values:

```cpp
Range<int> range(1, 10);  // Creates a range from 1 to 10
```

### Iterating Over a Range

You can iterate over a range using a range-based `for` loop:

```cpp
for (int i : range) {
    std::cout << i << " ";
}
```

### Performing Range Operations

The `Range` class supports various operations:

- **Intersection**: `rangeA.Intersection(rangeB);`
- **Union**: `rangeA.Union(rangeB);`
- **Difference**: `rangeA.Difference(rangeB);`
- **Comparison**: Use operators like `==`, `!=`, `>`, `<`, `>=`, `<=`.

### Custom Iteration

You can create custom iterators with specific step sizes:

```cpp
Range<int>::Iterator iter = range.BeginIter(2);  // Iterator with step size 2
```

## API Reference

### Range Class Template

#### Constructor

```cpp
Range(R begin, R end);
```

- **begin**: The starting value of the range.
- **end**: The ending value of the range.

#### Methods

- `Intersection(Range t)`: Returns the intersection of two ranges.
- `Union(Range t)`: Returns the union of two ranges.
- `Difference(Range t)`: Returns the difference between two ranges.
- `bool equal(Range t)`: Checks if two ranges are equal.
- `bool IsContain(Range t)`: Checks if one range contains another.
- `void ChangeBegin(R begin)`: Changes the beginning of the range.
- `void MoveBegin(R begin)`: Moves the beginning of the range.
- `void ChangeEnd(R end)`: Changes the end of the range.
- `void MoveEnd(R end)`: Moves the end of the range.
- `R length()`: Returns the length of the range.
- `Iterator BeginIter()`: Returns an iterator to the beginning of the range.
- `Iterator EndIter()`: Returns an iterator to the end of the range.
- `Iterator BeginIter(R step)`: Returns an iterator to the beginning of the range with a specific step size.
- `Iterator EndIter(R step)`: Returns an iterator to the end of the range with a specific step size.

### Iterator Class

#### Constructor

Multiple constructors are provided to initialize the iterator using values or pointers, with or without a step size.

#### Methods

- `void operator++()`: Increments the iterator by the step size.
- `void operator--()`: Decrements the iterator by the step size.
- `Range::Iterator operator+(R n)`: Moves the iterator forward by `n` steps.
- `Range::Iterator operator-(R n)`: Moves the iterator backward by `n` steps.
- `bool operator==(Range::Iterator t)`: Checks if two iterators are equal.
- `bool operator!=(Range::Iterator t)`: Checks if two iterators are not equal.
- `R operator*()`: Dereferences the iterator to get the current value.
- `bool isEnd()`: Checks if the iterator is at the end of the range.
- `bool isBegin()`: Checks if the iterator is at the beginning of the range.

## License

This module is provided under the GPL-V3.0 License. Feel free to use, modify, and distribute it as needed.

## Contributions

Contributions are welcome! Please feel free to open issues or submit pull requests.

## Author

[2077DevWave](https://github.com/2077DevWave)
