# "NOT C++" Language Rules

This document outlines the rules and syntax for a custom programming language that closely resembles C but with specific modifications and restrictions.

---

## General Syntax Rules
1. **Variable Declarations:**
   - Variables must be declared and initialized in separate statements.
   - Example:
     ```c
     int x;
     x = 1; // Correct

     int y = 1; // Not Allowed
     ```

2. **Booleans:**
   - The language does not have a boolean type.
   - Logical operations (`&&`, `||`, `!`) work with integers (0 for false, non-zero for true).

3. **Implicit Casting:**
   - Implicit type casting is supported.

---

## Supported Constructs

### 1. **Loops**
#### While Loops:
```c
while (condition) {
    // code block
}
```

#### For Loops:
```c
for (initialization; condition; increment) {
    // code block
}
```

#### Repeat-Until Loops:
```c
repeat {
    // code block
} until (condition);
```

- **Infinite Nesting:** Loops can be nested to any depth.

### 2. **Conditional Statements**
#### If-Else Statements:
```c
if (condition) {
    // code block
} else {
    // code block
}
```

#### If Statements:
```c
if (condition) {
    // code block
}
```

- **Infinite Nesting:** Supported.
- **`elsif`:** Not supported.

### 3. **Switch Statements**
```c
switch (variable) {
    case value1:
        // code block
        break;
    case value2:
        // code block
        break;
    default:
        // code block
        break;
}
```

- Nested `switch` statements are not supported.

---

## Functions

1. **Definition:**
   - Functions are defined similarly to C++.
   - Example:
     ```c
     int add(int a, int b) {
         return a + b;
     }
     ```

2. **Restrictions:**
   - Functions cannot be defined inside another function.
   - Nested function calls are not allowed.
     - To use the result of one function as an argument for another, assign the result to a temporary variable.
     - Example:
       ```c
       int a = foo();
       int b = bar(a); // Correct

       int c = bar(foo()); // Not Allowed
       ```

---

## Grammar Rules and Lexical Tokens

The following lexical tokens define the grammar and keywords of the language:

### Keywords:
- `for`, `while`, `repeat`, `until`
- `switch`, `case`, `default`, `break`
- `return`
- `if`, `else`
- `void`, `int`, `float`, `char`, `string`, `const`

### Tokens:
- **Data Types:**
  - `void`, `int`, `float`, `char`, `string`

- **Operators:**
  - Arithmetic: `+`, `-`, `*`, `/`, `%`, `^`
  - Relational: `==`, `!=`, `<`, `<=`, `>`, `>=`
  - Logical: `!`, `&&`, `||`
  - Assignment: `=`

- **Separators:**
  - `;`, `:`, `,`, `(`, `)`, `{`, `}`

### Comments:
- Single-line comments:
  ```c
  // This is a comment
    #This is also a comment
  ```


### Identifiers:
- Must begin with a letter or underscore (`_`).
- Can contain letters, numbers, and underscores.
- Example:
  ```c
  int myVariable;
  ```

### Literals:
- **Integer:** Any sequence of digits (`0-9`).
- **Float:** Digits with a decimal point (`0.0, 1.23`).
- **String:** Enclosed in double quotes (`"example"`).
- **Character:** Enclosed in single quotes (`'a'`).

---

## Example Code
```c
{
    int main() {
    int x;
    x = 10;

    if (x > 0) {
        while (x > 0) {
            x = x - 1;
        }
    }

    repeat {
        x = x + 1;
    } until (x == 10);

    return x;
    }
}
```
- The whole code should be wrapped in a scope 


