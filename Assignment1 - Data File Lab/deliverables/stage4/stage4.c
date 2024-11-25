#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define the structure for data records using traditional C types
struct field {
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
    unsigned long beam;          // 64-bit unsigned integer
};

// Function to read a record from the new file format
int read_new_format_record(FILE *inputFile, struct field *record) {
    uint32_t plough_new;
    if (fread(&plough_new, sizeof(uint32_t), 1, inputFile) != 1) return 0;
    record->plough = (unsigned short)plough_new;

    double truck_new;
    if (fread(&truck_new, sizeof(double), 1, inputFile) != 1) return 0;
    record->truck = (float)truck_new;

    int32_t gate_new;
    if (fread(&gate_new, sizeof(int32_t), 1, inputFile) != 1) return 0;
    record->gate = gate_new;

    uint8_t pizzas_new;
    if (fread(&pizzas_new, sizeof(uint8_t), 1, inputFile) != 1) return 0;
    record->pizzas = pizzas_new;

    int32_t push_new;
    if (fread(&push_new, sizeof(int32_t), 1, inputFile) != 1) return 0;
    record->push = push_new;

    if (fread(record->pail, sizeof(char), 11, inputFile) != 11) return 0;

    if (fread(&record->aunt, sizeof(char), 1, inputFile) != 1) return 0;

    uint8_t payment_new;
    if (fread(&payment_new, sizeof(uint8_t), 1, inputFile) != 1) return 0;
    record->payment = payment_new;

    double wheel_new;
    if (fread(&wheel_new, sizeof(double), 1, inputFile) != 1) return 0;
    record->wheel = wheel_new;

    uint8_t roof_new;
    if (fread(&roof_new, sizeof(uint8_t), 1, inputFile) != 1) return 0;
    record->roof = roof_new;

    uint8_t veil_new;
    if (fread(&veil_new, sizeof(uint8_t), 1, inputFile) != 1) return 0;
    record->veil = veil_new;

    uint32_t fuel_new;
    if (fread(&fuel_new, sizeof(uint32_t), 1, inputFile) != 1) return 0;
    record->fuel = fuel_new;

    uint8_t growth_new;
    if (fread(&growth_new, sizeof(uint8_t), 1, inputFile) != 1) return 0;
    record->growth = growth_new;

    uint8_t list_new;
    if (fread(&list_new, sizeof(uint8_t), 1, inputFile) != 1) return 0;
    record->list = list_new;

    double play_new;
    if (fread(&play_new, sizeof(double), 1, inputFile) != 1) return 0;
    record->play = play_new;

    uint64_t beam_new;
    if (fread(&beam_new, sizeof(uint64_t), 1, inputFile) != 1) return 0;
    record->beam = beam_new;

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 2;
    }

    FILE *outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening file for writing: %s\n", argv[2]);
        fclose(inputFile);
        return 3;
    }

    struct field record;
    while (read_new_format_record(inputFile, &record)) {
        fwrite(&record.plough, sizeof(record.plough), 1, outputFile);
        fwrite(&record.truck, sizeof(record.truck), 1, outputFile);
        fwrite(&record.gate, sizeof(record.gate), 1, outputFile);
        fwrite(&record.pizzas, sizeof(record.pizzas), 1, outputFile);
        fwrite(&record.push, sizeof(record.push), 1, outputFile);
        fwrite(record.pail, sizeof(char), 11, outputFile);
        fwrite(&record.aunt, sizeof(record.aunt), 1, outputFile);
        fwrite(&record.payment, sizeof(record.payment), 1, outputFile);
        fwrite(&record.wheel, sizeof(record.wheel), 1, outputFile);
        fwrite(&record.roof, sizeof(record.roof), 1, outputFile);
        fwrite(&record.veil, sizeof(record.veil), 1, outputFile);
        fwrite(&record.fuel, sizeof(record.fuel), 1, outputFile);
        fwrite(&record.growth, sizeof(record.growth), 1, outputFile);
        fwrite(&record.list, sizeof(record.list), 1, outputFile);
        fwrite(&record.play, sizeof(record.play), 1, outputFile);
        fwrite(&record.beam, sizeof(record.beam), 1, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}