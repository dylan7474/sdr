#include <stdio.h>
#include <stdlib.h>
#include <rtl-sdr.h>

int main(int argc, char **argv) {
    uint32_t freq = 100000000; // default 100 MHz
    if (argc > 1) {
        freq = (uint32_t)strtoul(argv[1], NULL, 10);
    }

    int device_count = rtlsdr_get_device_count();
    if (device_count < 1) {
        fprintf(stderr, "No RTL-SDR devices found.\n");
        return 1;
    }

    rtlsdr_dev_t *dev = NULL;
    int r = rtlsdr_open(&dev, 0);
    if (r != 0) {
        fprintf(stderr, "Failed to open RTL-SDR device: %d\n", r);
        return 1;
    }

    r = rtlsdr_set_center_freq(dev, freq);
    if (r != 0) {
        fprintf(stderr, "Failed to set center frequency: %d\n", r);
    } else {
        printf("Tuned to %u Hz\n", freq);
    }

    rtlsdr_close(dev);
    printf("Device closed.\n");

    return 0;
}

