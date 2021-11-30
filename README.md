# Project Title

## Table of Contents

- [About](#about)
- [New concepts](#concepts)

## About <a name = "about"></a>

[Full subject here](https://github.com/sdnc/ft_printf/blob/master/en.subject.pdf "ft_printf PDF")


### 💾 *Prototype*

```c
	int ft_printf(const char *, ...);
```

### ⚙️ *Parameters*

- const char *: The string to be printed
- **...**: arbitrary number of arguments

### ◀️ *Return value*

Returns an integer that represents the number of characters in the printed string

- Must recode the *libc's* *printf* function and it will be compared to real one
- It must not do the buffer management like the real *printf*
- Must use the command **ar** to create the library (libtool is forbidden)
- Libft library is allowed

Must manage the following conversions: **cspdiuxX%**

**%c** prints a single character

**%s** prints a string of characters

**%p** the void * pointer argument is printed in hexadecimal

**%d** prints a decimal (base 10) number

**%i** prints an integer in base 10

**%u** prints an unsigned decimal (base 10) number

**%x** prints a number in hexadecimal (base 16) - lowercase

**%X** prints a number in hexadecimal (base 16) - uppercase

**%%** prints a percentage sign


## Concepts <a name = "concepts"></a>

### Variadic functions

**This project calls for using a new standard C library → *<stdarg.h>*** 

This library is used to allow functions to accept an indefinite number of arguments. It facilitates stepping through a list of function arguments of unknown number and type. 

**Stdarg has one type:**

- *va_list:* type for iterating arguments

**Stdarg Macros:**

- *va_start:* start iterating arguments with a va_list. va_start expects a va_list & the last required argument
- *va_arg*: retrieve an argument. Expects a va_list & data type as input. Type must be self-promoting (no chars, shorts or floats).
- *va_end*: free a va_list
- *va_copy*: copy contents of one va_list to another
<details>
<summary>Code Example</summary>

```c
#include <stdarg.h>
#include <stdio.h>
 
// this function will take the number of values to average
// followed by all of the numbers to average
double average ( int num, ... )
{
    va_list arguments;                     
    double sum = 0;
 
    // Initializing arguments to store all values after num. 
		// Va_starts expects a va_list & last required argument
    va_start ( arguments, num );           
    // Sum all the inputs; we still rely on the function
    // caller to tell us how * many there are
    for ( int x = 0; x < num; x++ )        
    {
        sum += va_arg ( arguments, double ); 
    } // va_arg expects va_list & data type
    va_end ( arguments );   // Cleans up the list
 
    return sum / num;                    
}
 
int main()
{
    // this computes the average of 13.2, 22.3 and 4.5 (3 indicates the number of values to average)
    printf( "%f\n", average ( 3, 12.2, 22.3, 4.5 ) );
    // here it computes the average of the 5 values 3.3, 2.2, 1.1, 5.5 and 3.3
    printf( "%f\n", average ( 5, 3.3, 2.2, 1.1, 5.5, 3.3 ) );
```

Example by [Allain](https://www.cprogramming.com/tutorial/c/lesson17.html) 

</details>
