Binary Sensor Telemetry Exporter

A lightweight C-based application that parses raw binary telemetry files into structured, human-readable text logs using dynamic memory allocation and binary file I/O.

Problem & Purpose

In embedded systems, automotive microcontrollers, and IoT diagnostics, sensor data is frequently written to disk in raw binary format (.bin) to save bandwidth, storage, and processing overhead. Reading these files directly is impossible for humans without a specialized parsing tool.

This project addresses this need by providing:

Binary Data Simulation: Generating simulated multi-sensor binary files stored in dedicated system directories.

Dynamic Memory Management: Determining file sizes dynamically and allocating appropriate heap memory (malloc) to store sensor data structures.

Telemetry Parsing & Export: Converting raw integers and status flags into clean, structured human-readable text logs (sensor_output.txt).

File Overview:
sensor_generator.c — Simulates sensor diagnostics by generating raw binary files (Sensor_dataN.bin) into a local directory.

sensor_processor.c — Reads binary payload files into allocated RAM structures, parses values, and outputs formatted diagnostic reports.
