# Basic input / output example

- Input (touch sensor) is connected to PC4.
- Output (relay with low-level trigger) is connected to PC5.

Current implementation is not correct. While the input is HIGH (GPIO_PIN_SET) the relay will toggle continuously.

One way to solve this is by using interrupt triggered on RISING event on PC4.