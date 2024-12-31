# Quadruples Documentation
## Example Transformations
This section illustrates how common programming constructs are translated into quadruples.

### 1. **While Loop**
#### Input Code:
```c
while (i < 6) {
    some code
}
```
#### Quadruples:
```
label1:
if i >= 6 goto label2
some code
goto label1
label2:
```

### 2. **Switch Case**
#### Input Code:
```c
switch (i) {
    case 1:
        some code
        break;
    case 2:
        some code
        break;
    default:
        some code
        break;
}
```
#### Quadruples:
```
if i == 1 goto label1
if i == 2 goto label2
goto label3
label1:
some code
goto label4
label2:
some code
goto label4
label3:
some code
label4:
```

### 3. **For Loop**
#### Input Code:
```c
for (initialization; condition; increment) {
    some code
}
```
#### Quadruples:
```
if i >= 6 goto label2
label1:
some code
if i < 6 goto label1
label2:
```

### 4. **Repeat Until Loop**
#### Input Code:
```c
repeat {
    some code
} until (i < 6);
```
#### Quadruples:
```
label1:
some code
if i < 6 goto label1
```

### 5. **If-Else Statement (Matched IF)**
#### Input Code:
```c
if (i >= 6) {
    some code1
} else {
    some code2
}
```
#### Quadruples:
```
if i >= 6 goto label1
some code2
goto label2
label1:
some code1
label2:
```

### 6. **Unmatched If Statement**
#### Input Code:
```c
if (i >= 6) {
    some code
}
```
#### Quadruples:
```
if i >= 6 goto label1
goto label2
label1:
some code
label2:
```

## Key Functions in the Code
### 1. **`addQuadruple`**
This function generates quadruples for mathematical, logical, or relational operators.
- Inputs: Operator, operand1, operand2
- Output: A new quadruple added to the list and a temporary variable for the result.

### 2. **`addQuadrupleLabel`**
Handles loops and adds labels with appropriate conditional jumps.
- Example for a while loop:
    ```c
    label1:
    if condition false goto exitLabel
    some code
goto label1
    exitLabel:
    ```

### 3. **`unmatchedIfQuadruple`**
Generates quadruples for unmatched `if` statements.
- Example:
    ```c
    if condition goto label1
goto label2
    label1:
some code
    label2:
    ```

### 4. **`matchedIfQuadruple`**
Handles matched `if-else` statements by adding the necessary jumps and labels.

### 5. **`switchcaseQuadruple`**
Generates quadruples for `switch-case` statements with conditional jumps and fall-through behavior.

### 6. **`addQuadrupleFunction`**
Generates quadruples for function definitions and returns.

### 7. **`addQuadrupleFunctionCall`**
Handles function calls by generating the necessary quadruples for parameters and the call itself.

## Output File
All quadruples are written to `output_files/quadruples.txt`. Each quadruple or command is written in the following format:
```
operator  operand1  operand2 := result
```
For example:
```
ADD  b  c := t1
```

### Example Output:
```
label1:
if i < 6 goto label2
some code
goto label1
label2:
```


