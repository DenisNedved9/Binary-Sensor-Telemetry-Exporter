#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int id;
    int info;
    int temperature;
    int pressure;
}sensor;


int main() {

    FILE *output_file = fopen("sensor_output.txt", "w");

    if (output_file == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    int files = 0;

    //create a malloc to store structs of sensor data
    sensor *sensors = malloc(sizeof(sensor) * 100); // allocate memory for 100 sensor structs

    //while loop to continuously read sensor data files until there is none left
    while (1) {
        char name[50];
        sprintf(name, "data_folder\\Sensor_data%d.bin", files);

        FILE *file = fopen(name, "rb");
        if (file == NULL) {
            printf("No more sensor data files to read.\n");
            break;
        }
        fread(&sensors[files].id, sizeof(int), 1, file);
        fread(&sensors[files].info, sizeof(int), 1, file);
        fread(&sensors[files].temperature, sizeof(int), 1, file);
        fread(&sensors[files].pressure, sizeof(int), 1, file);
        fclose(file);

        files++;
    }

    for (int i = 0; i < files; i++) {
        fprintf(output_file, "Sensor Data for Sensor %d:\n", (i + 1));
        fprintf(output_file, "Sensor ID: %d\n", sensors[i].id);
        fprintf(output_file, "Sensor Info: %s\n", (sensors[i].info == 0) ? "Inactive" : "Active");
        fprintf(output_file, "Sensor Temperature: %d°C\n", sensors[i].temperature);
        fprintf(output_file, "Sensor Pressure: %d Pa", sensors[i].pressure);
        if (i < files - 1) {
            fprintf(output_file, "\n\n");
        }
    }

    printf("Sensor data processing complete. Output written to sensor_output.txt\n");



    fclose(output_file);
    free(sensors);
    return 0;
}