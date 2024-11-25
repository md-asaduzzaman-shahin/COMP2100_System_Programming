#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

// Define the structure for data records
typedef struct {
    uint16_t plough;       // 16-bit unsigned integer
    float truck;           // 32-bit floating point
    int32_t gate;          // 32-bit integer
    uint8_t pizzas;        // 8-bit boolean
    int32_t push;          // 32-bit integer
    char pail[11];         // Fixed-length string of up to 11 characters
    char aunt;             // 8-bit character
    uint8_t payment;       // 8-bit boolean
    double wheel;          // 64-bit floating point
    uint8_t roof;          // 8-bit boolean
    uint8_t veil;          // 8-bit boolean
    uint32_t fuel;         // 32-bit boolean
    uint8_t growth;        // 8-bit unsigned integer
    uint8_t list;          // 8-bit unsigned integer
    double play;           // 64-bit floating point
    uint64_t beam;         // 64-bit unsigned integer
} DataRecord;

// Comparison function for sorting records
int compare_records(const void *a, const void *b) {
    const DataRecord *recordA = *(const DataRecord **)a;
    const DataRecord *recordB = *(const DataRecord **)b;

    // Sorting according to the specified order
    if (recordA->wheel != recordB->wheel) {
        return (recordA->wheel > recordB->wheel) - (recordA->wheel < recordB->wheel); // Ascending order
    }
    if (recordA->veil != recordB->veil) {
        return (recordA->veil > recordB->veil) - (recordA->veil < recordB->veil); // Ascending order
    }
    if (recordA->play != recordB->play) {
        return (recordA->play > recordB->play) - (recordA->play < recordB->play); // Ascending order
    }
    if (recordA->roof != recordB->roof) {
        return (recordA->roof > recordB->roof) - (recordA->roof < recordB->roof); // Ascending order
    }
    if (recordA->growth != recordB->growth) {
        return (recordA->growth > recordB->growth) - (recordA->growth < recordB->growth); // Ascending order
    }
    if (recordA->plough != recordB->plough) {
        return (recordA->plough > recordB->plough) - (recordA->plough < recordB->plough); // Ascending order
    }
    if (recordA->payment != recordB->payment) {
        return (recordA->payment > recordB->payment) - (recordA->payment < recordB->payment); // Ascending order
    }
    if (recordA->truck != recordB->truck) {
        return (recordA->truck > recordB->truck) - (recordA->truck < recordB->truck); // Ascending order
    }
    if (recordA->fuel != recordB->fuel) {
        return (recordA->fuel > recordB->fuel) - (recordA->fuel < recordB->fuel); // Ascending order
    }
    if (recordA->list != recordB->list) {
        return (recordA->list > recordB->list) - (recordA->list < recordB->list); // Ascending order
    }
    if (recordA->aunt != recordB->aunt) {
        return (recordA->aunt > recordB->aunt) - (recordA->aunt < recordB->aunt); // Ascending order
    }
    if (recordA->beam != recordB->beam) {
        return (recordA->beam > recordB->beam) - (recordA->beam < recordB->beam); // Ascending order
    }
    if (recordA->gate != recordB->gate) {
        return (recordA->gate > recordB->gate) - (recordA->gate < recordB->gate); // Ascending order
    }
    int pailComparison = strcmp(recordA->pail, recordB->pail);
    if (pailComparison != 0) {
        return pailComparison; // Ascending order
    }
    if (recordA->pizzas != recordB->pizzas) {
        return (recordA->pizzas > recordB->pizzas) - (recordA->pizzas < recordB->pizzas); // Ascending order
    }
    if (recordA->push != recordB->push) {
        return (recordA->push > recordB->push) - (recordA->push < recordB->push); // Ascending order
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_binary_file> <output_binary_file>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *inputFile = fopen(argv[1], "rb");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    // Determine the number of records
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);
    int numRecords = fileSize / sizeof(DataRecord);

    // Allocate memory for pointers to records
    DataRecord **records = malloc(numRecords * sizeof(DataRecord *));
    if (records == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(inputFile);
        return 1;
    }

    // Read all records from the file
    for (int i = 0; i < numRecords; i++) {
        records[i] = malloc(sizeof(DataRecord));
        if (records[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            fclose(inputFile);
            return 1;
        }
        fread(&records[i]->plough, sizeof(uint16_t), 1, inputFile);
        fread(&records[i]->truck, sizeof(float), 1, inputFile);
        fread(&records[i]->gate, sizeof(int32_t), 1, inputFile);
        fread(&records[i]->pizzas, sizeof(uint8_t), 1, inputFile);
        fread(&records[i]->push, sizeof(int32_t), 1, inputFile);
        fread(records[i]->pail, sizeof(char), 11, inputFile);
        fread(&records[i]->aunt, sizeof(char), 1, inputFile);
        fread(&records[i]->payment, sizeof(uint8_t), 1, inputFile);
        fread(&records[i]->wheel, sizeof(double), 1, inputFile);
        fread(&records[i]->roof, sizeof(uint8_t), 1, inputFile);
        fread(&records[i]->veil, sizeof(uint8_t), 1, inputFile);
        fread(&records[i]->fuel, sizeof(uint32_t), 1, inputFile);
        fread(&records[i]->growth, sizeof(uint8_t), 1, inputFile);
        fread(&records[i]->list, sizeof(uint8_t), 1, inputFile);
        fread(&records[i]->play, sizeof(double), 1, inputFile);
        fread(&records[i]->beam, sizeof(uint64_t), 1, inputFile);
    }
    fclose(inputFile);

    // Sort the records using qsort
    qsort(records, numRecords, sizeof(DataRecord *), compare_records);

    // Open the output file to write the sorted records
    FILE *outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[2]);
        return 1;
    }

    // Write the sorted records to the output file
    for (int i = 0; i < numRecords; i++) {
        fwrite(&records[i]->plough, sizeof(uint16_t), 1, outputFile);
        fwrite(&records[i]->truck, sizeof(float), 1, outputFile);
        fwrite(&records[i]->gate, sizeof(int32_t), 1, outputFile);
        fwrite(&records[i]->pizzas, sizeof(uint8_t), 1, outputFile);
        fwrite(&records[i]->push, sizeof(int32_t), 1, outputFile);
        fwrite(records[i]->pail, sizeof(char), 11, outputFile);
        fwrite(&records[i]->aunt, sizeof(char), 1, outputFile);
        fwrite(&records[i]->payment, sizeof(uint8_t), 1, outputFile);
        fwrite(&records[i]->wheel, sizeof(double), 1, outputFile);
        fwrite(&records[i]->roof, sizeof(uint8_t), 1, outputFile);
        fwrite(&records[i]->veil, sizeof(uint8_t), 1, outputFile);
        fwrite(&records[i]->fuel, sizeof(uint32_t), 1, outputFile);
                fwrite(&records[i]->growth, sizeof(uint8_t), 1, outputFile);
        fwrite(&records[i]->list, sizeof(uint8_t), 1, outputFile);
        fwrite(&records[i]->play, sizeof(double), 1, outputFile);
        fwrite(&records[i]->beam, sizeof(uint64_t), 1, outputFile);
        free(records[i]);  // Free each record after writing
    }

    // Free the array of pointers and close the output file
    free(records);
    fclose(outputFile);

    return 0;
}
