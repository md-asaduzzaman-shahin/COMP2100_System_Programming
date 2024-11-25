#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct field {
    uint16_t plough;
    float truck;
    int32_t gate;
    uint8_t pizzas;
    uint32_t push;
    char pail[11];
    char aunt;
    uint8_t payment;
    double wheel;
    uint8_t roof;
    uint8_t veil;
    uint32_t fuel;
    uint8_t growth;
    uint8_t list;
    double play;
    uint64_t beam;
};

int read_new_format_record(FILE *inputFile, struct field *record) {
    uint32_t plough_new;
    if (fread(&plough_new, sizeof(uint32_t), 1, inputFile) != 1) return 0;
    record->plough = (uint16_t)plough_new;

    double truck_new;
    if (fread(&truck_new, sizeof(double), 1, inputFile) != 1) return 0;
    record->truck = (float)truck_new;

    if (fread(&record->gate, sizeof(int32_t), 1, inputFile) != 1) return 0;
    if (fread(&record->pizzas, sizeof(uint8_t), 1, inputFile) != 1) return 0;
    if (fread(&record->push, sizeof(uint32_t), 1, inputFile) != 1) return 0;
    if (fread(record->pail, sizeof(char), 11, inputFile) != 11) return 0;
    if (fread(&record->aunt, sizeof(char), 1, inputFile) != 1) return 0;
    if (fread(&record->payment, sizeof(uint8_t), 1, inputFile) != 1) return 0;
    if (fread(&record->wheel, sizeof(double), 1, inputFile) != 1) return 0;
    if (fread(&record->roof, sizeof(uint8_t), 1, inputFile) != 1) return 0;
    if (fread(&record->veil, sizeof(uint8_t), 1, inputFile) != 1) return 0;
    if (fread(&record->fuel, sizeof(uint32_t), 1, inputFile) != 1) return 0;
    if (fread(&record->growth, sizeof(uint8_t), 1, inputFile) != 1) return 0;
    if (fread(&record->list, sizeof(uint8_t), 1, inputFile) != 1) return 0;
    if (fread(&record->play, sizeof(double), 1, inputFile) != 1) return 0;
    if (fread(&record->beam, sizeof(uint64_t), 1, inputFile) != 1) return 0;
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (inputFile == NULL) {
        perror("Failed to open input file");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        perror("Failed to open output file");
        fclose(inputFile);
        return 1;
    }

    struct field record;
    while (read_new_format_record(inputFile, &record)) {
        fprintf(outputFile, "plough: %u, truck: %f, gate: %d, pizzas: %u, push: %x, pail: %s, aunt: %c, payment: %u, wheel: %f, roof: %u, veil: %u, fuel: %u, growth: %u, list: %u, play: %f, beam: %lu\n",
                record.plough, record.truck, record.gate, record.pizzas, record.push, record.pail, record.aunt, record.payment, record.wheel, record.roof, record.veil, record.fuel, record.growth, record.list, record.play, record.beam);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}