#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

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

int read_record(FILE *file, DataRecord *record) {
    if (fread(&record->plough, sizeof(record->plough), 1, file) != 1) return 0;
    if (fread(&record->truck, sizeof(record->truck), 1, file) != 1) return 0;
    if (fread(&record->gate, sizeof(record->gate), 1, file) != 1) return 0;
    if (fread(&record->pizzas, sizeof(record->pizzas), 1, file) != 1) return 0;
    if (fread(&record->push, sizeof(record->push), 1, file) != 1) return 0;
    if (fread(&record->pail, sizeof(record->pail), 1, file) != 1) return 0;
    if (fread(&record->aunt, sizeof(record->aunt), 1, file) != 1) return 0;
    if (fread(&record->payment, sizeof(record->payment), 1, file) != 1) return 0;
    if (fread(&record->wheel, sizeof(record->wheel), 1, file) != 1) return 0;
    if (fread(&record->roof, sizeof(record->roof), 1, file) != 1) return 0;
    if (fread(&record->veil, sizeof(record->veil), 1, file) != 1) return 0;
    if (fread(&record->fuel, sizeof(record->fuel), 1, file) != 1) return 0;
    if (fread(&record->growth, sizeof(record->growth), 1, file) != 1) return 0;
    if (fread(&record->list, sizeof(record->list), 1, file) != 1) return 0;
    if (fread(&record->play, sizeof(record->play), 1, file) != 1) return 0;
    if (fread(&record->beam, sizeof(record->beam), 1, file) != 1) return 0;
    return 1;
}

void print_record(DataRecord *record) {
    printf("%u, %.6f, %d, %u, %x, %s, %c, %u, %.6f, %u, %u, %u, %u, %u, %.6f, %lu\n",
           record->plough, record->truck, record->gate, record->pizzas,
           record->push, record->pail, record->aunt, record->payment,
           record->wheel, record->roof, record->veil, record->fuel,
           record->growth, record->list, record->play, record->beam);
}



int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <binary_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    printf("plough, truck, gate, pizzas, push, pail, aunt, payment, wheel, roof, veil, fuel, growth, list, play, beam\n");

    DataRecord record;
    while (read_record(file, &record)) {
        print_record(&record);
    }

    fclose(file);
    return 0;
}