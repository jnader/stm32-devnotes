# stm32-devnotes
Platform IO projects, testing with my old STM32F4 board

## Creating a sub-project
- To create a new project, create a folder and cd into it. Then a command that looks like this:
```
pio project init -b black_f407ve --ide vscode -O 'framework=stm32cube' -O 'upload_flags=-d 0483:df11' -O 'upload_protocol=dfu' --sample-code
```

In my case, the board is a `black_f407ve` and I chose to use `stm32cube` as framework.
For the `upload_flags`, I got the vid and pid of the board in `DFU` mode using `lsusb`.

- Build and upload to board:
```
pio run --target upload -v
```
