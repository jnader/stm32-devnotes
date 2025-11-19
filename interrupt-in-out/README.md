# Interrupt input / output example

- Input (touch sensor) is connected to PC4 and configured as EXTI mode with RISING edge trigger detection.
- Output (relay with low-level trigger) is connected to PC5.

The configuration and code generation was done using STM32CubeMX with `EWARM` framework.

A post code generation script (`to_pio.sh`) was used to make the project Platform IO compatible.
