#!/bin/bash
wget -P /tmp https://github.com/sidneyriffic/holbertonschool-low_level_programming/raw/master/0x17-dynamic_libraries/pullshak.so
export LD_PRELOAD=/tmp/pullshak.so
