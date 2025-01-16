// HEADER FILES: contains declarations of functions, variables, constants
// Thet allow different parts of a program to communicate and share code efficiently
#include <stdio.h> // muse use this one for ANY program, ALWAYS the first line
#include <stdbool.h> // needed for BOOLEANS
#include <math.h> // you need to end compiling command with -lm
#include <stdint.h> // for bitwise variables
#include <string.h> // for using strings
#include <ctype.h> // includes tolower()
#include <stdlib.h> // required for malloc(), calloc(), and realloc()

// ************* C NOTES!!!!!! *************

// DATA TYPES
    // INT: at least 16 bits
        // SHORT INT: at least 16 bits
        // LONG INT: at least 32 bits
        // LONG LONG INT: should be at least 64 bits
        // UNSIGNED INT: used for bitwise
    // CHAR: a single character, can also store INTS in ASCII values
    // FLOAT: single precision floating point number (sign, mantissa, 24 bits)
    // DOUBLE: double precision floating point number (sign, mantissa, 53 bits)
    

// OPERATORS
    // +    add
    // -    subtract
    // *    multiply
    // /    division
    // %    modulus
    // &&   logical and
    // ||   logical or
    // !    logical not
    // &    bitwise and
    // |    bitwise or
    // ~    bitwise not/flip/ones complement
    // ^    bitwise xor
    // >>   bitwise right shift
    // <<   bitwise left shift


// FORMAT SPECIFIERS:
// %d        Signed decimal integer (int)                      
// %u        Unsigned decimal integer (unsigned int)              
// %p        Pointer address (void*) (memory address of pointer)                            
// %lu       Unsigned long integer (unsigned long)               
// %s        String (array of characters or string literal) (prints everything kntil it encounters '\0')    
// %f        Floating-point number (float)                        
// %c        Single character                                   
// %x        Hexadecimal (lowercase) unsigned integer            
// %X        Hexadecimal (uppercase) unsigned integer             
// %o        Octal (unsigned integer in base 8)                   
// %ld       Signed long integer                                  
// %lf       Double-precision floating-point number              
// %e        Scientific notation (lowercase) for floating-point   
// %E        Scientific notation (uppercase) for floating-point   
// %%        A literal percent sign ("%")                         


// FUNCTIONS:
// define functions at the top
// you must state:
    // 1) return type 
    // 2) types for formal parameters


int helloWorld() {
    // print statement
    // you MUST put \n after anything printed or it'll print on the same line as the last
    printf("Hello World!\n");	
    return 0;
}


// BITWISE
int bitwiseInfo() {

    unsigned int a = 10;    // 1010
    unsigned int b = 15;    // 1111

    // LOGIC GATES in code:

    // AND
    unsigned int result = a & b;
    // result = a and b
    // the result is 10, because the binary result is 1010 (1 if both bits are 1, otherwise 0)

    // OR
    unsigned int result2 = a | b;
    // result 2 = a or b
    // the result is 15, because the binary result is 1111 (1 if EITHER bit is 1, otherwise 0)

    // NOT
    unsigned int result3 = ~a;
    // result 3 = *not* a
    // this unsigned int is 4 bytes:
    // 00000000 00000000 00000000 00001010
    // so the NOT resut is:
    // 11111111 11111111 11111111 11110101 = 4,294,967,285

    // XOR
    unsigned int result4 = a ^ b;
    // result of XOR logic gaten

    // right shift
    // can be used for power of 2 division 
    uint32_t result5 = b >> 3;
    // shifs the bits of 15 to the right by 3 positions
    // bits shifted off the right are DISCARDED
    // new bits on left are filled with 0
    // result goes from 1111 to 00001

    // left shift
    // can be used for power of 2 muliplication 
    uint32_t result6 = b << 2;
    // shifts the bits of 15 to the left by 2 positions
    // zeroes are aded to the rightmost positions
    // result goes from 1111 to 111100

    // %d is needed when printing an integer in base-10 format (for ints)
    // %u is used for UNSIGNED integers in a base-10format
    printf("bitwise a & b = %d\n", result);
    printf("bitwise a | b = %d\n", result2);
    printf("bitwise NOT a = %u\n", result3);
    printf("bitwise a ^ b = %u\n", result4);
    printf("b >> 3 = %u\n", result5);
    printf("b >> 2 = %u\n", result6);

    return 0;
}


// POINTERS
int pointerInfo() {

    // a pointer REFERENCES a memory location
    // * = states something is a pointer
    // & = "address at"
    int faveNum = 10;   // normal variable
    int *faveNumPtr = &faveNum; // faveNumPrt POINTS TO the ADDRESS AT faveNum

    // %p will display pointer's address
    printf("My favorite number is %d and it is stored at %p\n", faveNum, faveNumPtr);

    // we can access the VALUE of a pointer by using * with %p
    printf("My favorite number is still %d\n", *faveNumPtr);

    return 0;
}

// ARRRAYS AND LOOPS
int arrayLoopInfo() {

    // arrays in c are CONTIGUOUS
    int someNums[] = {1, 2, 3, 4, 5, 6};
    int moreNums[10]; // creating an empty list with 10 elements

    // the identifier can be used as a pointer to the memory location of the first item
    printf("The memory address of the array is: %p\n", someNums);
    printf("The memory address of the first item is: %p\n", &someNums[0]); // need to use & to get address


    // you can use sizeof() to get how large an array is
    // %lu will print an unsigned long integer
    printf("The number of bytes in the array is %lu\n", sizeof(someNums));
    printf("That makes sense because 4 bytes * 6 items = %lu\n", sizeof(someNums));

    // we can also use sizeof() to get the length of an array
    printf("The length of the array is: %lu\n", sizeof(someNums) / sizeof(int));

    // WHILE LOOPS
    int counter = 0;
    // while loop is assigning values to the empty moreNums array
    while (counter < 10) {
        moreNums[counter] = counter;
        printf("Added %d as a value to myOtherFaves\n", counter);
        counter++; // iterator
    }

    // FOR LOOPS
    // layout: for (start; stop; iterator)
    // get upper limit of incrementer by dividing number of bytes of array by size of data type
    // identifier of someNums is not treated as a pointer
    size_t n = sizeof(someNums) / sizeof(int); // HOW TO GET 'LENGTH' (no length() function exists)
    for (int i = 0; i < n; i++) {
        printf("The %dth item in the array is %d\n", i, someNums[i]);
    }

    return 0;
}

// FUNCTIONS WITH ARRAYS
void addStuff(int myArray[], int myArrayLength) {

    // array decays to a pointer when passed through
    // sizeof() returns size of the pointer
    // you can still use the index to access values inside function

    for (int i = 0; i < myArrayLength; i++) {
        myArray[i] = i * 2;
    }
}
void viewStuff(int *myArray, int myArrayLength) {
// common to use * here since it will decay to a pointer

    for (int i = 0; i < myArrayLength; i++) {
        printf("The item at index %d id %d\n", i, myArray[i]);
    }
}


// STRINGS
// a string is an array of characters
// arrays terminate using \0  (null character)
int stringsInfo() {

    char aMessage[] = "Hi how are you?";
    // %s used to print string variables
    printf("%s\n", aMessage);
    
    // getting size of string WITH null character
    printf("Size: %lu\n", sizeof(aMessage) / sizeof(char));
    
    // strlen() gets us the length of the string!
    printf("Size again: %lu\n", strlen(aMessage));;

    // comparing strings
    char hello[] = "hello";
    char you1[] = "you";
    char you2[] = "you ";

    // strcmp returns -1, 0, or 1
    // 0  = EQUAL
    // -1 = first string is LESS THAN second string (ascii vals)
    // 1  = first string is GREATER THAN second string (ascii vals)
    
    // comparing hello and you1
    if (strcmp(hello, you1) == 0) {
        printf("They're equal -1\n");
    } else {
        printf("They're NOT equal - 1\n");
    }

    // comparing you1 and you2
    if (strcmp(you1, you2) == 0) {
        printf("They're equal -2\n");
    } else {
        printf("They're NOT equal -2\n");
    }

    // reassigning string values
    strcpy(hello, "you");

    return 0;
    }

// INPUT AND OUTPUT:
int input() {
	char name [25];
	int age;
	
	// prompt with a print statement
	printf("What's your name? ");
    // scanf is how we read input from user 
	scanf("%s", name);
	
	printf("What's your age? " );
	scanf("%d", &age); // "address at age"

    // outputting the results
	printf("Hi %s, your age is %d\n", name, age);

	// taking more than 1 input
	printf("What's your name AND age? ");
	scanf("%s, %d", name, &age);

	printf("Hi %s, your age is %d\n", name, age);

	return 0;
}

int fullLine() {

    char afullline[100]; // 100 character empy string basically

    // fgets() = file get string
    // used for reading lines of files
    // we can use it with stdin to prompt
    printf("Type a sentence: ");
    // fgets() automatically adds a new line character to the end
    fgets(afullline, 100, stdin);

    // to remove it:
    afullline[strlen(afullline) - 1] = '\0';
    printf("You said:%s", afullline);

    return 0;
}

int countVowels (char *sentence) {
    int count = 0;

    for (int i = 0; i < strlen(sentence); i++) {
        switch(tolower(sentence[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                count++;
            // no default case needed
        }
    }
    return count;
} 

char calculateGrade(float ngrade) {
        if (ngrade > 89) {
                return 'A';
        } else if (ngrade > 79) {
                return 'B';
        } else if (ngrade > 69) {
                return 'C';
        } else if (ngrade > 59) {
                return 'D';
        } else {
                return 'F';
        }
}

// BUBBLE SORT:
void bubbleSort (int *aList, size_t listSize) {
    for (int i = 0; i < listSize - 1; i++) {
        for (int j = 0; j < listSize -1 - i; j++) {
            if (aList[j + 1] < aList[j]) {
                // swapping elements:
                int temp = aList[j];
                aList[j] = aList[j + 1];
                aList[j + 1] = temp;
            }
        }
    }
}

// MEMORY ALLOCATION:
// three main types:
    // 1. malloc
    // 2. calloc
    // 3. realloc

int malloc(){

    int *value;

    // malloc lets us dynamically allocate memory on the heap
    value = malloc(4); // allows for 4 bytes to be stored at `value`
    value = malloc(sizeof(int) * 10); // allows 10 integers next to each other

    // set each value in the array
    for (int i=0; i < 10;  i++){
        value[i] = i * 2;
    }

    // print each value
    for (int i=0; i < 10; i++){
        printf("%d ", value[i]);
    }
    printf("\n");

    // the function free() frees up the space taken by a dynamically 
    // allocated reference
    free(value);

    // reallocate value with a new size
    value = malloc(sizeof(int) * 20);

    // note that malloc does not zero out the data that was there
    // note the operating system may cause it to zero out as a security feature

    for (int i = 0; i < 10; i++){
        printf("%d ", value[i]);
    }

    printf("\n");

    return 0;
}

int calloc() {

    // calloc gaurantees that the allocated memory will be zeroed out
    // two args: number of things, size of each thing
    int *value = calloc(10, sizeof(int));

    for (int i=0; i < 10; i++){
        printf("%d ", value[i]);
    }

    free(value);
    printf("\n");
    
    return 0;
}

int main(){

    helloWorld();

    bitwiseInfo();

    pointerInfo();

    arrayLoopInfo();

    // ARRAY NOTES
    int ages[5];
    // getting length of list
    size_t length = sizeof(ages) / sizeof(int);
    // passes length into function
    addStuff(ages, length);
    viewStuff(ages, length);

    // STRING NOTES
    stringsInfo();
    input();

    char sentence [100];
    int numVowels;

    printf("Give me a sentence to count the vowels: ");
    fgets(sentence, 100, stdin);

    // removing newline char if present
    // strcspn returns index of '\n'
    sentence[strcspn(sentence, "\n")] = '\0';

    numVowels = countVowels(sentence);
    printf("There were %d vowels.", numVowels);

    printf("\n");

    float ngrade;
	printf("What is your numerical grade? ");
	scanf("%f",&ngrade);
	char fgrade = calculateGrade(ngrade);
	printf("Your final grade is: %c\n", fgrade); 

    // MEMORY ALLOCATION
    malloc();
    calloc();

    return 0;
}
