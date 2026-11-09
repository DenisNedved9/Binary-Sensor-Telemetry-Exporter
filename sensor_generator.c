#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int main() {
    
    //vytvoření složky pro uložení souborů
    if (CreateDirectory("data_folder", NULL) || ERROR_ALREADY_EXISTS == GetLastError()) {
        printf("Directory created or already exists.\n");
    } else {
        printf("Error creating directory.\n");
        return 1;
    }
    srand(time(NULL));
    // Generování a zapsání hodnot do souboru 'sensor_data.bin'

    int size = 5; // Počet hodnot senzoru, které chceme vygenerovat

    for (int i = 0; i < size; i++) {

        char name[50];
        sprintf(name, "data_folder\\Sensor_data%d.bin", i);

        FILE *file = fopen(name, "wb");
        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }
    

        int sensor_id = rand() % 2056; // Generování náhodného ID senzoru mezi 0 a 2055
        fwrite(&sensor_id, sizeof(int), 1, file);
        int sensor_info = rand() % 2; // Generování náhodného stavu senzoru (0 nebo 1)
        fwrite(&sensor_info, sizeof(int), 1, file);
        int sensor_temperature = rand() % 256; // Generování náhodné teploty senzoru (0 až 255)
        fwrite(&sensor_temperature, sizeof(int), 1, file);
        int sensor_pressure = rand() % 8224; // Generování náhodného tlaku senzoru (0 až 8223)
        fwrite(&sensor_pressure, sizeof(int), 1, file);
        fclose(file);
    }
    

    return 0;
}