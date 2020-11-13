# tinyemu

## Vagrant

```shell
cd vagrant
vagrant up
```

## Update submodule

```shell
git submodule update --init --recursive --depth 1
```

## Build

```shell
sudo dnf install openssl-devel libcurl-devel SDL-devel
sudo dnf groupinstall -y 'Development tools'
cd tinyemu-2019-12-21
make
sudo make install
hash -r
```

## Run

```shell
make
```

```text
Press Control-a x to quit.

temu https://bellard.org/jslinux/fedora29-riscv-2.cfg

Welcome to Fedora 29 (riscv64)

[root@localhost ~]#
```

### Mount local filesystem

```shell
mount -t 9p /dev/hostfilesystem /mnt
```

The mounted host directory is `fs1` in `fedora/fedora29-riscv-2.cfg`. (`fedora/mnt`)

### Install glibc-static

Download the following files:

-   <http://fedora.riscv.rocks/koji/buildinfo?buildID=72819>
    -   glibc-static-2.28-6.fc29.riscv64.rpm
-   <http://fedora.riscv.rocks/koji/buildinfo?buildID=72851>
    -   libxcrypt-static-4.1.2-1.fc29.riscv64.rpm

Copy files to riscv machine via `fedora/mnt`, and then install them by `rpm -ihv /mnt/*.rpm`.

### Install gdb

Download the following files:

-   <http://fedora.riscv.rocks/koji/buildinfo?buildID=49086>
    -   gdb-8.1.50.20180629-27.0.riscv64.fc29.riscv64.rpm

Copy files to riscv machine via `fedora/mnt`, and then install them by `rpm -ihv /mnt/*.rpm`.

### Build static linked binary

```shell
gcc -O2 -static hello.c
strip -s a.out
```

### disassemble

```shell
objdump -d /mnt/hello.riscv > ~/disasm
```

```shell
gdb -batch -ex "disassemble/rs main" /mnt/hello.static.strip.riscv
```
