#include <stdio.h>
#include <stdbool.h> // for boolean data type


// 1 bit = 0 or 1 (binary), Bits are typically stored in memory cells,
                        //which can be implemented using various technologies,
                        //including transistors in modern computer systems.
// 1 nibble = 4 bits
// 1 byte = 8 bits
// 1 byte = 1 character = 1 ASCII character = 1 signed char = 1 unsigned char = 1 boolean
// -128 to +127(decimal) = 10000000 to 01111111(binary) = 0 to 177(octal) = 0x80 to 0x7F(hexadecimal)
// 0 to 255(decimal) = 00000000 to 11111111(binary) = 0 to 377(octal) =  0x00 to 0xFF(hexadecimal)



int main () {
    
// Declaring the variables
    bool aBool = true; // 1 byte (true or false) Although it logically represents 1 single bit,
                       // it is typically stored in a byte (8 bits) for alignment and efficiency reasons.
    
    
    char aChar = 'A'; // 1 byte single charecter (-128 to +127) signed
    char anotherChar = 65; // 1 byte (-128 to +127) signed
    unsigned char anUnsignedChar = 'A'; // 1 byte (0 to 255) unsigned
    unsigned char anotherUnsignedChar = 65; // 1 byte (0 to 255) unsigned
    // it would print "�" if the value is out of the range of the char data type
    
    
    char arrayOfChars[] = "Hello"; // (5+1) = 6 bytes including null terminator (0 to 281474976710655)
                                   // if we use arrayOfChars[5] = "Hello"; it will not include null terminator


    int anInt = 10; // 4 bytes (0 to 4294967295) signed and decimal by default
                    // but it can be represented in hexadecimal(0x0A), octal(012) or binary(0b1010)
    unsigned int anUnsignedInt = 20; // 4 bytes (0 to 4294967295) unsigned

    short int aShort = 5; // 2 bytes (−32,768 to +32,767) signed
    unsigned short int anUnsignedShort = 10; // 2 bytes (0 to 65535) unsigned

    float aFloat = 3.141592; // 4 bytes (0 to 4294967295) signed
    double aDouble = 3.141592653589793; // 8 bytes (2.3E-308 to 1.7E+308) signed


    long int aLong = -1000; // 4 bytes (-2147483648 to +2147483647) signed
    long long int aLongLong = -1000; // 8 bytes (-9223372036854775808 to +9223372036854775807) signed
    unsigned long long int anUnsignedLongLong = 1000; // 8 bytes (0 to 18446744073709551615) unsigned


    // other than the above data types, there are other data types such as long double, long long double, long double long, etc.
    // but they are not commonly used in C programming.

// IGNORE THE BELOW COMMENTS FOR NOW
    // There is a library of data types such as stdint.h
    // which includes fixed-width, fast, exact, least, etc. integer types such as int8_t, uint16_t, int_fast8_t, int_least8_t, intmax_t, intptr_t, etc.
    // These data types are used to store the exact size of the memory which helps in portability of the code.
    // - Fixed-width types (e.g., int8_t, uint16_t) ensure the integer has a specific size across different platforms.
    // - Fast types (e.g., int_fast8_t) are the fastest minimum-width integer types available on the platform.
    // - Least types (e.g., int_least8_t) are the smallest types that can hold the specified number of bits.
    // - intmax_t and uintmax_t are the largest signed and unsigned integer types provided by the implementation.
    // - intptr_t and uintptr_t are integer types capable of holding a pointer.

    // There is another library of data types such as stddef.h
    // which includes size_t data type which is used to store the size of the memory.
    // size_t is an unsigned integer type that is used to represent the size of objects in bytes and is returned by the sizeof operator.
    // It is platform-dependent and ensures that it can represent the maximum size of any object that can be created on the system.


    // There are also some data types that are used to store the memory address of a variable.
    // such as pointers, arrays, structures, unions, etc.
    // - Pointers: Variables that store the memory address of another variable. They are used for dynamic memory allocation, arrays, and function arguments.
    // - Arrays: Collections of elements of the same type stored in contiguous memory locations. The name of the array acts as a pointer to the first element.
    // - Structures: User-defined data types that group different types of variables under a single name. They are used to represent a record.
    // - Unions: Similar to structures, but all members share the same memory location. They are used to save memory when storing variables that are mutually exclusive.


// Printing the values of the variables
    printf("The boolean is %d\n", aBool); // boolean can be called using %d (0 = false or 1 = true)
    printf("The boolean in boolean string is %s\n", aBool ? "true" : "false"); // boolean can be printed as true or false

    
    printf("The character is %c\n", aChar); // char can be called using %c
    // %c is used to print a character.
    // %d is used to print the ASCII value of a char.
    // %u is used to print the ASCII value of an unsigned char
    // if the variable assigned with a different format, it will be converted to the specified calling format
    printf("The another character is %c\n", anotherChar); // char can be called using %c and %d
    printf("The unsigned character is in charecter %c\n", anUnsignedChar); // unsigned char can be called using %u
    printf("The another unsigned character is in unsigned decimal %u\n", anotherUnsignedChar); // unsigned char can be called using %c and %u
    // there is no difference in the output for signed and unsigned char when printing characters because ASCII values are positive.
    // however, the memory representation is different for signed and unsigned char.


    printf("The string is %s\n", arrayOfChars); // string can be called using %s and for each character indexing %c


    printf("The integer is %d\n", anInt); // int can be called using below formats and it will be converted to the specified calling format
                                          // Decimal (%d): 10
                                          // Decimal (%i): 10 --> for scanf, it can read decimal, octal, hexadecimal
                                          // Unsigned (%u): 10
                                          // Long decimal (%ld): 10
                                          // Binary (%b): 1010
                                          // Octal (%o): 12
                                          // Hexadecimal (%x): a
                                          // Hexadecimal (%X): A
    printf("The unsigned integer is %u\n", anUnsignedInt); // unsigned int can be called using %u


    printf("The short integer is %hd\n", aShort); // short int can be called using %hd
    printf("The unsigned short integer is %hu\n", anUnsignedShort); // unsigned short int can be called using %hu


    printf("The float is %f\n", aFloat); // float can be called using %f
    printf("The double is %lf\n", aDouble); // double can be called using %lf


    printf("The long integer -10000000 is in binary %ld\n", aLong); // long int can be called using %ld
    printf("The long long integer is %lld\n", aLongLong); // long long int can be called using %lld
    printf("The unsigned long long integer is %llu\n", anUnsignedLongLong); // unsigned long long int can be called using %llu
    
    return 0;
}