# test-files

## hello

```shell
gcc -O2 -o /mnt/hello.riscv /mnt/hello.c
objdump -x /mnt/hello.riscv > /mnt/hello.riscv.objdump
objdump -d /mnt/hello.riscv > /mnt/hello.riscv.disasm
```

## fizz-buzz

```shell
gcc -O2 -o /mnt/fizz-buzz.riscv /mnt/fizz-buzz.c
objdump -x /mnt/fizz-buzz.riscv > /mnt/fizz-buzz.riscv.objdump
objdump -d /mnt/fizz-buzz.riscv > /mnt/fizz-buzz.riscv.disasm
```
