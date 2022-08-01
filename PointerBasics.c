#include <stdio.h>
#include <stdlib.h>

// passing pointers as function arguments
void increment(int *x)
{
    *x = *x + 1;
}

// arrays when passed as arguments are always called by reference
int sumofArray(int arr[], size_t size)
{
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

// arrays when passed as arguments are always called by reference thus allowing us to modify it's contents
void doubleArray(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = 2 * arr[i];
    }
}

void readline(const char *string) // taking the argument as a const prevents us from modifying the string
{
    printf("%s\n", string);
}

int function_x(int x, int y)
{
    return x + y;
}

/*  
qsort() function can be used to sort arrays in ascending order or descending or by any other order in case of array of structures, with function pointers and void pointers, it is possible to use qsort for any data type.function qsort is a function that that takes function 'compare' as an argument'compare' is a function that takes two arguments and returns an integer the integer is used to determine the order of the elements in the array the type of function pointer must be (int (*)(const void *, const void *))
*/
int compare(const void *x, const void *y)
{
    return *((int *)x) > *((int *)y);
}

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}



int main()
{

    // Basics
    {
        int a;
        int *p;

        a = 10; // assigning a value to a
        p = &a; // assigning the address of a to p

        printf("Value of a: %d\n", a);
        printf("Address of a: %d\n", &a); // address operator (&)

        printf("\n");

        printf("Value of ptr: %d\n", p);
        printf("Value pointed by ptr: %d\n", *p); // derefrencing the pointer

        printf("\n\n");
    }

    // Pointer Arithmetic
    {
        int a = 10;
        int *p = &a;

        printf("Size of int: %d\n", sizeof(int));
        printf("Value of ptr: %d\n", p);
        printf("Value of ++ptr: %d\n", ++p);

        printf("\n\n");
    }

    // Pointer Typecasting
    {
        int a = 1025; // 00000000 00000000 00000100 00000001 in binary
        int *p = &a;

        printf("Address of (int)a: %d\n", p);
        printf("Value pointed by ptr: %d\n", *p);

        printf("\n");

        // char pointer pointing to the address of int pointer
        char *char_p = (char *)p;

        printf("Address of (char)a: %d\n", p);

        printf("Value pointed by char ptr: %d\n", *char_p);       // ptr points to byte (00000001) = 1
        printf("Value pointed by char ++ptr: %d\n", *(++char_p)); // ++ptr points to byte (00000100) = 4

        printf("\n\n");
    }

    // Void pointer
    {
        /*
            void is a generic type of pointer
            can't be derefrenced/ incremented/ decremented
            any pointer type can be assigned to void ptr    

            example:
                int* a;
                char* b;
                void* p;
                (p = a) & (p = b) is allowed
        */
        void *p;
    }

    // Pointer to pointer
    {
        // creating a pointer chain
        int x = 10;

        int *p = &x;
        int **q = &p;
        int ***r = &q;

        printf("a: %d\n", ***r); // multiple derefrencing

        printf("\n\n");
    }

    // Function call by referance
    {
        int a = 10;

        increment(&a); // call by reference

        printf("a after incrementing: %d\n", a);
        printf("\n\n");
    }

    // Array pointers
    {
        int array_one[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        /* variable array_one is a array pointer, it can be treated as an int pointer
        except it cannot be incremented/ decremented */

        size_t sz = sizeof(array_one) / sizeof(array_one[0]);

        printf("Size of array: %d\n", sz);

        int sum = sumofArray(array_one, sz);

        printf("Sum of array: %d\n", sum);

        doubleArray(array_one, sz); // function can modify array contents

        // printing the new array
        printf("New array: [");
        for (size_t i = 0; i < sz; i++)
        {
            printf("%d, ", array_one[i]);
        }
        printf("\b\b]\n");

        int two_dimensionsal[2][3] = {{1, 2, 3}, {4, 5, 6}};

        int(*x)[3] = two_dimensionsal;
        int *y = *two_dimensionsal;

        printf("array[0][1]: %d\n", **x); // or *y

        // x + 3 = x + 3(sizeof(one dimensional sub array))

        /*
        let:
            int A[2][3];

        then:
            A[i][j] = *(A[i] + j) =  *(*(A + i) + j)


        similarly for a three dimensional array:
            A[i][j][k] = *(*(*(A + i) + j) + k)  =  *(A[i][j]) + k)


        thus while defining a function parameters:
            funcion(int a[]) = funcion(int *a) // passed 1d array
            funcion(int a[][2]]) = funcion(int (*a)[2]) // passed 2d array
            funcion(int a[][2][3]) = funcion(int (*a)[2][3]) // passed 3d array
        */

        printf("\n\n");
    }

    // Character arrays/ Strings
    {
        // minimum length of charecter array = length of string + 1
        char name[8] = {'a', 't', 'h', 'a', 'r', 'v', 'a', '\0'}; // null terminated

        // declaring using string literals
        char username[] = "nasamark";

        // string is a array of characters and can be treated as an array pointer

        printf("Name: %s ; Username: %s\n", name, username);

        char *temp = name;

        // printing using a loop
        while (*temp != '\0')
        {
            printf("%c", *(temp++));
        }
        printf("\n");

        char *idol = "Mark Robers"; // string is stored as a compile time constant and cannot be modified

        idol = "Elon Musk"; // this is allowed

        // idol[5] = 'H'; // this is not allowed

        readline(idol);

        printf("\n\n");
    }

    // Memory allocation & deallocation
    {
        int *a = (int *)malloc(sizeof(int)); // creating a integer on heap

        int *arr = (int *)malloc(sizeof(int) * 10); // creating a integer array on heap

        // creating a integer array on heap with all elements zero
        int *arr_zero = (int *)calloc(10, sizeof(int));

        free(arr); // deallocating the array

        /* in C++:
            int *arr = new int[10];
            delete[] arr;
        */

        // reallocates the memory block pointed by pointer to a new size
        int *arr_realloc = (int *)realloc(arr_zero, sizeof(int) * 20);

        // using realloc as malloc
        int *arr_malloc = (int *)realloc(NULL, sizeof(int) * 20);

        // using realloc as free
        arr_malloc = (int *)realloc(arr_malloc, 0);

        // NOTE:
        // if a pointer to a variable is returned from a function, it will be deallocated automatically when the variable goes out of scope (i.e. when the function returns), thus it must be allocated using malloc or calloc
    }

    // Function pointers
    {
        // synatax of function pointer
        // {return datatype} (*{variable name})({data type of arguments..});
        int (*fptr)(int, int); // function pointer to a function

        // assigning value to the function pointer
        fptr = &function_x;
        // the & is optional ie  fptr = function_x; is also valid

        // calling the function pointer
        int result = (*fptr)(10, 20);
        // the * is optional ie  result = fptr(10, 20); is also valid
        printf("Result: %d\n", result);
    }

    {
        // Basicall, function pointers are used to pass functions as arguments to other functions which are not defined in the same file

        // https: //www.geeksforgeeks.org/function-pointer-in-c/

        int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

        //passing function pointer 'compare' to a function
        qsort(a, 10, sizeof(int), compare);

        // printing the sorted array
        for (size_t i = 0; i < 10; i++)
        {
            printf("%d, ", a[i]);
        }

        // synatax for creating an array of function pointers
        int (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};

        unsigned int choice, x = 15, y = 10;

        printf("\n0 for add/ 1 for subtract/ 2 for multiply: ");
        scanf("%d", &choice);

        int result = (*fun_ptr_arr[choice])(x, y);

        printf("Result: %d\n", result);

        return 0;
    }

    return 0;
}