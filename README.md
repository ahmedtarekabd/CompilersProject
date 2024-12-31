# Not C++ Compiler

## Overview

This project is a compiler for a custom programming language called `Not C++`.Written in lex , yacc The language closely resembles C but with specific modifications and restrictions. The compiler translates the source code written in `Not C++` into intermediate quadruples, which can be further processed or executed.
The compiler is written using **Lex** and **Yacc** for defining lexical and grammar rules. The grammar is designed to have **zero shift/reduce and reduce/reduce conflicts**.
## Features

- **Variable and Constants Declarations**: Variables must be declared and initialized in separate statements.
  - Example:
    ```c
    int x;
    x = 1; // Correct

    int y = 1; // Not Allowed
    ```

- **Mathematical Operations**: Supports addition, subtraction, multiplication, division, modulus, and negation.
  - Example:
    ```c
    int a = 5;
    int b = 3;
    int sum = a + b;       // Addition
    int diff = a - b;      // Subtraction
    int prod = a * b;      // Multiplication
    int quot = a / b;      // Division
    int mod = a % b;       // Modulus
    int neg = -a;          // Negation
    ```

- **Relational Operators**: Supports `<`, `>`, `<=`, `>=`, `==`, `!=`.
  - Example:
    ```c
    int a = 5;
    int b = 3;
    if (a > b) {
        // Code
    }
    if (a == b) {
        // Code
    }
    ```

- **Logical Operations**: Supports `AND`, `OR`, `NOT`.
  - Example:
    ```c
    int a = 1; // true
    int b = 0; // false
    if (a && b) {
        // Code
    }
    if (a || b) {
        // Code
    }
    if (!b) {
        // Code
    }
    ```

- **Implicit Casting**: Supported.
  - Example:
    ```c
    int x = 5;
    float y = 3.2;
    float z = x + y; // Implicit casting of 'a' to float
    string s = 'heb';
    char c ='a';
    s = s + c;  // Implicit casting of 'a' to string

    ```

- **Loops**: Supports infinitely nested `while`, `for`, and `repeat-until` loops.
  - Example:
    ```c
    int i = 0;
    while (i < 10) {
        // Code
        i = i+1;
    }

    for (int j = 0; j < 10; j++) {
        // Code
    }

    int k = 0;
    repeat {
        // Code
        k = k+1;
    } until (k >= 10);
    ```

- **Conditional Statements**: Supports infinitely nested `if-else`, `if-else` and one level `switch` statements.
  - Example:
    ```c
    int a = 5;
    if (a > 3) {
        // Code
    } else {
        // Code
    }

    switch (a) {
        case 1:
            // Code
            break;
        case 5:
            // Code
            break;
        default:
            // Code
            break;
    }
    ```
- **Functions**: Supports function definitions and calls with restrictions.
  - Example:
    ```c
    int add(int x, int y) {
        return x + y;
    }

    int main() {
        int result = add(5, 3);
        return 0;
    }
    ```
## Sample Input 
---
```c
{
    int i;
    i=0;
    int x;
    int sum (){
        return 0;
    }
    void print(){
        return;
    }
    if(x == 0){
        for (i=0;i<0;i=i+1)
        {
            x = sum();
            x = print();
        }
    }
}
```
## Sample Output 
---
### quadruples
```
ASSIGN  i  0 :=t0
int proc sum 
return 0

void proc print 
return
EQ  x  0 :=t1
if t1 goto L0
goto L1 
L0:
ASSIGN  i  0 :=t2
L2:
LT  i  0 :=t3
if t3 false goto L3
ADD  i  1 :=t4
call sum :=t5
ASSIGN  x  t5 :=t6
call print
ASSIGN  i  t4 :=t8
goto L2
L3:
L1:

```
### Symbol Table
```
+-------+----------------+--------+-------------+---------+------------+
| Scope | Symbol         | Type   | Initialized | Value   | Is Func    |
+-------+----------------+--------+-------------+---------+------------+
| 0     | print          | void   | 0           | 0.00    | 1          |
| 0     | sum            | int    | 0           | 0.00    | 1          |
| 0     | x              | int    | 1           | 0.00    | 0          |
| 0     | 0              | int    | 0           | 0.00    | 1          |
| 0     | i              | int    | 1           | 0.00    | 0          |
| 3     | 1              | int    | 0           | 0.00    | 1          |

+-------+----------------+--------+-------------+---------+------------+

```
### Semantics 
- Semantic error: Variable used before initialization at line 11
- Semantic error: void value cannot be assigned to a variable at line 15
- Warning       : Unused variable: y in scope 0