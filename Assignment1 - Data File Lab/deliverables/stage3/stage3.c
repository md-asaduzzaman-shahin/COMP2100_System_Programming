#include <stdio.h>
#include <stdlib.h>
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
    unsigned long beam;     // 64-bit unsigned integer
};

// Comparison function for sorting records
int compareField(const void *a, const void *b) {
    const struct field *recordA = *(const struct field **)a;
    const struct field *recordB = *(const struct field **)b;

    // Sorting according to the specified order
    if (recordA->wheel != recordB->wheel) {
        return (recordB->wheel > recordA->wheel) - (recordB->wheel < recordA->wheel); // Descending order
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
        return (recordB->growth > recordA->growth) - (recordB->growth < recordA->growth); // Descending order
    }
    if (recordA->plough != recordB->plough) {
        return (recordB->plough > recordA->plough) - (recordB->plough < recordA->plough); // Descending order
    }
    if (recordA->payment != recordB->payment) {
        return (recordB->payment > recordA->payment) - (recordB->payment < recordA->payment); // Descending order
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
        return (recordB->gate > recordA->gate) - (recordB->gate < recordA->gate); // Descending order
    }
    if (strcmp(recordA->pail, recordB->pail) != 0) {
        return strcmp(recordB->pail, recordA->pail); // Descending order (lexicographical comparison)
    }
    if (recordA->pizzas != recordB->pizzas) {
        return (recordB->pizzas > recordA->pizzas) - (recordB->pizzas < recordA->pizzas); // Descending order
    }
    if (recordA->push != recordB->push) {
        return (recordB->push > recordA->push) - (recordB->push < recordA->push); // Descending order
    }

    return 0; // Records are equal
}


int read_field(struct field *data, FILE *inputFile) {
    return fread(&data->plough, sizeof(unsigned short), 1, inputFile) == 1 &&
           fread(&data->truck, sizeof(float), 1, inputFile) == 1 &&
           fread(&data->gate, sizeof(int), 1, inputFile) == 1 &&
           fread(&data->pizzas, sizeof(unsigned char), 1, inputFile) == 1 &&
           fread(&data->push, sizeof(int), 1, inputFile) == 1 &&
           fread(data->pail, sizeof(char), 11, inputFile) == 11 &&
           fread(&data->aunt, sizeof(char), 1, inputFile) == 1 &&
           fread(&data->payment, sizeof(unsigned char), 1, inputFile) == 1 &&
           fread(&data->wheel, sizeof(double), 1, inputFile) == 1 &&
           fread(&data->roof, sizeof(unsigned char), 1, inputFile) == 1 &&
           fread(&data->veil, sizeof(unsigned char), 1, inputFile) == 1 &&
           fread(&data->fuel, sizeof(unsigned int), 1, inputFile) == 1 &&
           fread(&data->growth, sizeof(unsigned char), 1, inputFile) == 1 &&
           fread(&data->list, sizeof(unsigned char), 1, inputFile) == 1 &&
           fread(&data->play, sizeof(double), 1, inputFile) == 1 &&
           fread(&data->beam, sizeof(unsigned long long), 1, inputFile) == 1;
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

    // Initializing dynamic array to store pointers to records
    struct field **dataArray = NULL;
    size_t arraySize = 0;
    size_t arrayCapacity = 100;  // This is the initial capacity, can be adjusted

    dataArray = (struct field **)malloc(arrayCapacity * sizeof(struct field *));
    if (dataArray == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(inputFile);
        return 3;
    }

    // Reading records from input file and dynamically resize array
    struct field data;
    while (read_field(&data, inputFile)) {
        if (arraySize == arrayCapacity) {  // Resize the array if it is full
            arrayCapacity *= 2; // Double the capacity
            dataArray = (struct field **)realloc(dataArray, arrayCapacity * sizeof(struct field *));
            if (dataArray == NULL) {
                fprintf(stderr, "Memory allocation error\n");
                fclose(inputFile);
                free(dataArray);
                return 3;
            }
        }

        struct field *newData = (struct field *)malloc(sizeof(struct field));
        if (newData == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            fclose(inputFile);
            free(dataArray);
            return 3;
        }
        *newData = data;

        dataArray[arraySize++] = newData; // Add the new record to the increasing array
    }

    fclose(inputFile);

    qsort(dataArray, arraySize, sizeof(struct field *), compareField);

    // Opening the output file for writing
    FILE *outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening file for writing: %s\n", argv[2]);
        free(dataArray);
        return 4;
    }

    // Writing the sorted records to the output file
    for (size_t i = 0; i < arraySize; i++) {
        fwrite(&dataArray[i]->plough, sizeof(unsigned short), 1, outputFile);
        fwrite(&dataArray[i]->truck, sizeof(float), 1, outputFile);
        fwrite(&dataArray[i]->gate, sizeof(int), 1, outputFile);
        fwrite(&dataArray[i]->pizzas, sizeof(unsigned char), 1, outputFile);
        fwrite(&dataArray[i]->push, sizeof(int), 1, outputFile);
        fwrite(dataArray[i]->pail, sizeof(char), 11, outputFile);
        fwrite(&dataArray[i]->aunt, sizeof(char), 1, outputFile);
        fwrite(&dataArray[i]->payment, sizeof(unsigned char), 1, outputFile);
        fwrite(&dataArray[i]->wheel, sizeof(double), 1, outputFile);
        fwrite(&dataArray[i]->roof, sizeof(unsigned char), 1, outputFile);
        fwrite(&dataArray[i]->veil, sizeof(unsigned char), 1, outputFile);
        fwrite(&dataArray[i]->fuel, sizeof(unsigned int), 1, outputFile);
        fwrite(&dataArray[i]->growth, sizeof(unsigned char), 1, outputFile);
        fwrite(&dataArray[i]->list, sizeof(unsigned char), 1, outputFile);
        fwrite(&dataArray[i]->play, sizeof(double), 1, outputFile);
        fwrite(&dataArray[i]->beam, sizeof(unsigned long long), 1, outputFile);
        free(dataArray[i]);
    }

    free(dataArray);
    fclose(outputFile);
    return 0;
}