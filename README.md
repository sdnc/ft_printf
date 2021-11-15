# Project Title

## Table of Contents

- [About](#about)
- [Concepts](#concepts)
- [Pseudo Code](#pseudo)

## About <a name = "about"></a>

Write about 1-2 paragraphs describing the purpose of your project.

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

## Pseudo Code <a name = "pseudo"></a>

Printf consist of a srcs folder including four seperate function fails to run the main function, a library, a Makefile, and the all the includes of the Libft library. 

The srcs folder function are:
- ft_printf.c
- ft_char.c
- ft_num.c
- ft_hex.c

A struct is defined in ft_print.h called s_hold, it includes a va_list *arg* and an int *count* (which will be the final return of the printf function). The list type is accessed with t_hold.

### ft_printf.c
This file contains the main function plus two subfunction, respectively, ft_printf(), init_args(), and ft_getflag().

```int  ft_printf(const char *str, ...)```
Three variables are defined in this function.
```c
    t_hold *arguments; //pointer to the struct
    int     count;    
    int     i;
```
arguments is initialized by calling *init_args()*. The other two integers are set to 0.
*va_start()* is called with *arguments* pointing to the va_list variable *arg* (in the struct t_hold) and the last required parameter of ft_printf().

A while loop is defined while *str* is not nulled. This part of the function reads and prints the caller's input. As long as the input is not a %, the current character is printed and the *count* in the struct is incremented. Then the index is incremented and next character is checked. If a % occurs, *ft_getflag()* is called with the character on the index after the said %. 

When *str* is nulled, the value of *count* is set to the value of the *count* variable in the t_hold struct. The va_list variable in the struct is terminated with va_end, and then the t_hold *arguments* list gets freed.
The function returns *count* (the number of characters ft_printf() has printed). 

```static t_hold init_args(void)```
One variable is declared: 
```c
t_hold *arguments;
```
This functions purpose is to malloc the t_hold *arguments* with the size of the struct t_hold. It also sets the *count* variable in t_hold to 0 and then returns *arguments*. 


```static void ft_getflag(const char c, t_hold *arguments)```
This function takes the flag after the % in *ft_printf()* as input (*c*) and calls the corresponding function to print the datatype. The 