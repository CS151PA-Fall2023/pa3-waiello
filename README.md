# PA3: Create Rational Class (100 points)

## Learner Objectives
At the conclusion of this programming assignment, participants should be able to:
* Create a class that performs rational arithmetic operations
* Create constructors and convert constructors
* Overload type conversion operator
* Overload +, -, *, / operators
* Overload << operator


## Overview and Requirements
For this programming assignment, we are going to write a class Rational that works with rational numbers. The main function is given. You must create rational.h and rational.cpp files that define and implement Rational class. You will need to implement a default constructor and convert constructors that accept two integers, and that accept strings like "3/4". In addition, you will need to implement a type conversion operator that gets invoked when you assign Rational datatype to double. To perform arithmetic operations, you must overlord +, -, *, and / operators. Finally, in order to display Rational numbers on the screen, you should overload the stream insertion operator (<<). It must be overloaded as a stand-alone function.

## Example of output

```
num0 = 1/1
num1 = 12/16
num2 = 12/16
num2 as a decimal = 0.75
num3 = 12/16
Reduced num3 = 3/4
num4 = 3/-4
Reduced num4 = -3/4
num5 = -0.75
num6 = 3/4
num1 = 3/7

Let's do some math...

3/7 + 12/16 = 33/28
3/7 - 12/16 = -9/28
3/7 * 12/16 = 9/28
(3/7) / (12/16) = 4/7
3/4 + 3/7*12/16 = 15/14
```

## Submitting Assignments
1. Ensure that you `push` your local copy of this PA's repo to GitHub. Verify that the code in GitHub is the same code you have on your local computer.
2. You may continue to update and push your code into this repo as long as it is before the deadline.
3. It is VERY IMPORTANT that besides pushing the code to GitHub that you still submit the GitHub URL of this programming assignment in Canvas. This allows the instructor to be notified of your final submission and that you are ready for grading.

> **_NOTE: By submitting your code to be graded, you are stating that your submission does not violate the Academic Integrity Policy outlined in the syllabus._**
