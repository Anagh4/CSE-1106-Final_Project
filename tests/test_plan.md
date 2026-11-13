# Test Cases

5 test cases with expected outputs, actual outputs, and pass/fail results.

## Case 1

### Test Input:

68, exit

### Expected Output:

**Temperature - System Status - Warning LED**

68°F - NORMAL - OFF

### Actual Output:

### PASS/FAIL Result:

## Case 2

### Test Input:

68, 76, exit

### Expected Output:

**Temperature - System Status - Warning LED**

68°F - NORMAL - OFF

76°F - NORMAL - OFF

### Actual Output:

### PASS/FAIL Result:

## Case 3

### Test Input:

68, 76, 79, exit

### Expected Output:

**Temperature - System Status - Warning LED**

68°F - NORMAL - OFF

76°F - NORMAL - OFF

79°F - WARNING - ON

### Actual Output:

### PASS/FAIL Result:

## Case 4

### Test Input:

68, 76, 79, Average, exit

### Expected Output:

**Temperature - System Status - Warning LED**

68°F - NORMAL - OFF

76°F - NORMAL - OFF

79°F - WARNING - ON

**Average Temperature:** 74.33°F

### Actual Output:

### PASS/FAIL Result:

## Case 5

### Test Input:

68, 76, 79, Change, 60, 80, exit

### Expected Output:

**Temperature - System Status - Warning LED**

68°F - NORMAL - OFF

76°F - NORMAL - OFF

79°F - WARNING - ON

**Range Changed To Minimum 60°F & Maximum 80°F**

**Temperature - System Status - Warning LED**

68°F - NORMAL - OFF

76°F - NORMAL - OFF

79°F - NORMAL - OFF

### Actual Output:

### PASS/FAIL Result:
