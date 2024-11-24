nasm -f win64 accelerationASM.asm
gcc -c accelerationC.c -o accelerationC.obj -m64
gcc accelerationASM.obj accelerationC.obj -o run.exe -m64

run.exe

pause