#include <stdio.h>
#include <stdint.h>

// Define the structure with the specified fields
typedef struct {
    unsigned short plough;       // 16-bit unsigned integer
    float truck;                 // 32-bit floating point
    int gate;                    // 32-bit integer
    unsigned char pizzas;        // 8-bit boolean
    int push;                    // 32-bit integer
    char pail[11];               // Fixed-length string of up to 11 characters
    char aunt;                   // 8-bit character
    unsigned char payment;       // 8-bit boolean
    double wheel;                // 64-bit floating point
    unsigned char roof;          // 8-bit boolean
    unsigned char veil;          // 8-bit boolean
    unsigned int fuel;           // 32-bit boolean
    unsigned char growth;        // 8-bit unsigned integer
    unsigned char list;          // 8-bit unsigned integer
    double play;                 // 64-bit floating point
    unsigned long beam;     // 64-bit unsigned integer
} DataRecord;


// Static initialization of the data structure
static DataRecord record = {
    .plough = 0x17F,        // Hexadecimal conversion of decimal number 383
    .truck = 0.006872f,     // Floating point
    .gate = 0xD22,          // Hexadecimal conversion of decimal number 3362
    .pizzas = 0,            // Boolean
    .push = -140,           // Decimal equivalent of 0xffffff74
    .pail = "sponge",       // String
    .aunt = '4',            // Character
    .payment = 0,           // Boolean
    .wheel = -0.056740,     // Floating point
    .roof = 0,              // Boolean
    .veil = 0,              // Boolean
    .fuel = 1,              // Boolean
    .growth = 97,           // Decimal
    .list = 0301,           // Octal conversion of decimal number 193
    .play = 15.436558,      // Floating point
    .beam = 037             // Octal conversion of decimal number 31
};



int main() {
    printf("plough, truck, gate, pizzas, push, pail, aunt, payment, wheel, roof, veil, fuel, growth, list, play, beam\n");
    printf("%u, %f, %d, %d, %x, %s, %c, %d, %f, %d, %d, %d, %u, %u, %f, %lu\n",
           record.plough, record.truck, record.gate, record.pizzas, record.push, record.pail, record.aunt, record.payment, record.wheel, record.roof, record.veil, record.fuel, record.growth, record.list, record.play, record.beam);
    return 0;
}