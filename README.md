# sdr

A minimal utility to verify communication with a USB-connected RTL-SDR dongle.

## Setup

Install build dependencies (Ubuntu):

```bash
sudo apt-get update
sudo apt-get install -y librtlsdr-dev build-essential
```

## Build

Compile the program using the provided Makefile:

```bash
make
```

## Usage

Ensure the RTL-SDR is plugged into the system, then run:

```bash
./check_rtl 100000000
```

The frequency argument is specified in Hz and defaults to 100000000 (100 MHz).
If successful, the program will open the device and tune it to the specified
frequency.
