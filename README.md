# sdr

A minimal utility to verify communication with a USB-connected RTL-SDR dongle.

## Setup

Install build dependencies (Ubuntu):

```bash
sudo apt-get update
sudo apt-get install -y librtlsdr-dev build-essential pkg-config
```

## Build

First, run the configuration script to verify dependencies and generate build
settings:

```bash
./configure
```

This will create a `config.mk` file with the appropriate compiler and linker
flags. You can choose a different compiler by setting `CC` when invoking the
script, e.g. `CC=clang ./configure`.

Compile the program using the generated settings:

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
