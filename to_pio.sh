#!/bin/sh

echo "Cleaning..."

cd interrupt-in-out

mv Inc include
mv Src src
rm -rf EWARM
rm -rf Drivers
rm .mxproject
rm *.ioc

echo "Creating pio project..."

pio project init -b black_f407ve --ide vscode -O 'framework=stm32cube' -O 'upload_flags=-d 0483:df11' -O 'upload_protocol=dfu'

echo "Done"