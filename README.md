# translator

## Build

1. Clone this repository:

    ```shell
    git clone https://github.com/premo-inc/translator.git
    cd translator
    git submodule update --init --recursive --depth 1
    ```

2. Install required softwares:

    ```shell
    sudo apt install libboost-all-dev
    sudo apt install cmake
    ```

3. Build `loader`

    ```shell
    cd src/loader
    make
    ```

## Prerequisite

-   [Boost](https://www.boost.org/)
-   [CMake](https://cmake.org/)

## Usage 

```shell
cd src/loader
./build/loader ../../test-files/hello.riscv
```

Result:

```text
class 2
date encoding 1
version 1
machine 243
big endian 0
e_entry 0x103a0
e_phoff 0x40
e_phnum 0x8
e_shoff 0x1e28
e_shnum 0x1b
sizeof(elf64_phdr) 56
sizeof(elf64_shdr) 64
phdr 2
  p_type 0x1
  p_flags 0x5
  p_offset 0x0
  p_vaddr 0x10000
  p_paddr 0x10000
  p_filesz 0x578
  p_memsz 0x578
  p_align 0x1000
phdr 3
  p_type 0x1
  p_flags 0x6
  p_offset 0xe18
  p_vaddr 0x11e18
  p_paddr 0x11e18
  p_filesz 0x21c
  p_memsz 0x220
  p_align 0x1000
shdr 10
  name .plt
  sh_name 0x7f
  sh_type 0x1
  sh_flags 0x6
  sh_addr 0x10360
  sh_offset 0x360
  sh_size 0x40
  sh_link 0x0
  sh_info 0x0
  sh_addralign 0x10
  sh_entsize 0x10
0x10360: 00002397          auipc         t2,8192                         # 0x12360
0x10364: 41c30333          sub           t1,t1,t3
0x10368: ffffffffca03be03          ld    t3,-864(t2)
0x1036c: fffffffffd430313          addi  t1,t1,-44
0x10370: ffffffffca038293          addi  t0,t2,-864
0x10374: 00135313          srli          t1,t1,1
0x10378: 0082b283          ld            t0,8(t0)
0x1037c: 000e0067          jr            t3
0x10380: 00002e17          auipc         t3,8192                         # 0x12380
0x10384: ffffffffc90e3e03          ld    t3,-880(t3)
0x10388: 000e0367          jalr          t1,t3,0
0x1038c: 00000013          nop           
0x10390: 00002e17          auipc         t3,8192                         # 0x12390
0x10394: ffffffffc88e3e03          ld    t3,-888(t3)
0x10398: 000e0367          jalr          t1,t3,0
0x1039c: 00000013          nop           
shdr 11
  name .text
  sh_name 0x84
  sh_type 0x1
  sh_flags 0x6
  sh_addr 0x103a0
  sh_offset 0x3a0
  sh_size 0x12e
  sh_link 0x0
  sh_info 0x0
  sh_addralign 0x4
  sh_entsize 0x0
0x103a0: 02c000ef          jal           ra,44                           # 0x103cc
0x103a4: 87aa              mv            a5,a0
0x103a6: 00000517          auipc         a0,0                            # 0x103a6
0x103aa: 0a650513          addi          a0,a0,166
0x103ae: 6582              ld            a1,0(sp)
0x103b0: 0030              addi          a2,sp,8
0x103b2: ffffffffff017113          andi  sp,sp,-16
0x103b6: 00000697          auipc         a3,0                            # 0x103b6
0x103ba: 0be68693          addi          a3,a3,190
0x103be: 00000717          auipc         a4,0                            # 0x103be
0x103c2: 10e70713          addi          a4,a4,270
0x103c6: 880a              mv            a6,sp
0x103c8: fffffffffb9ff06f          j     -72                             # 0x10380
0x103cc: 00002197          auipc         gp,8192                         # 0x123cc
0x103d0: 45c18193          addi          gp,gp,1116
0x103d4: 8082              ret           
0x103d6: 6549              lui           a0,73728
0x103d8: 6749              lui           a4,73728
0x103da: 00050793          mv            a5,a0
0x103de: 00070713          mv            a4,a4
0x103e2: 00f70b63          beq           a4,a5,22                        # 0x103f8
0x103e6: 00000337          lui           t1,0
0x103ea: 00030313          mv            t1,t1
0x103ee: 00030563          beqz          t1,10                           # 0x103f8
0x103f2: 00050513          mv            a0,a0
0x103f6: 8302              jr            t1
0x103f8: 8082              ret           
0x103fa: 6549              lui           a0,73728
0x103fc: 00050793          mv            a5,a0
0x10400: 6749              lui           a4,73728
0x10402: 00070593          mv            a1,a4
0x10406: 8d9d              sub           a1,a1,a5
0x10408: 858d              srai          a1,a1,3
0x1040a: 03f5d793          srli          a5,a1,63
0x1040e: 95be              add           a1,a1,a5
0x10410: 8585              srai          a1,a1,1
0x10412: c991              beqz          a1,20                           # 0x10426
0x10414: 00000337          lui           t1,0
0x10418: 00030313          mv            t1,t1
0x1041c: 00030563          beqz          t1,10                           # 0x10426
0x10420: 00050513          mv            a0,a0
0x10424: 8302              jr            t1
0x10426: 8082              ret           
0x10428: 1141              addi          sp,sp,-16
0x1042a: e022              sd            s0,0(sp)
0x1042c: 6449              lui           s0,73728
0x1042e: 03444783          lbu           a5,52(s0)
0x10432: e406              sd            ra,8(sp)
0x10434: e791              bnez          a5,12                           # 0x10440
0x10436: fffffffffa1ff0ef          jal   ra,-96                          # 0x103d6
0x1043a: 4785              addi          a5,zero,1
0x1043c: 02f40a23          sb            a5,52(s0)
0x10440: 60a2              ld            ra,8(sp)
0x10442: 6402              ld            s0,0(sp)
0x10444: 0141              addi          sp,sp,16
0x10446: 8082              ret           
0x10448: fffffffffb3ff06f          j     -78                             # 0x103fa
0x1044c: 1101              addi          sp,sp,-32
0x1044e: ec06              sd            ra,24(sp)
0x10450: e822              sd            s0,16(sp)
0x10452: 1000              addi          s0,sp,32
0x10454: 87aa              mv            a5,a0
0x10456: fffffffffeb43023          sd    a1,-32(s0)
0x1045a: fffffffffef42623          sw    a5,-20(s0)
0x1045e: 67c1              lui           a5,65536
0x10460: 4d078513          addi          a0,a5,1232
0x10464: fffffffff2dff0ef          jal   ra,-212                         # 0x10390
0x10468: 4781              mv            a5,zero
0x1046a: 853e              mv            a0,a5
0x1046c: 60e2              ld            ra,24(sp)
0x1046e: 6442              ld            s0,16(sp)
0x10470: 6105              addi          sp,sp,32
0x10472: 8082              ret           
0x10474: 7139              addi          sp,sp,-64
0x10476: f822              sd            s0,48(sp)
0x10478: f04a              sd            s2,32(sp)
0x1047a: 00002417          auipc         s0,8192                         # 0x1247a
0x1047e: ffffffff9a640413          addi  s0,s0,-1626
0x10482: 00002917          auipc         s2,8192                         # 0x12482
0x10486: ffffffff9a690913          addi  s2,s2,-1626
0x1048a: 40890933          sub           s2,s2,s0
0x1048e: fc06              sd            ra,56(sp)
0x10490: f426              sd            s1,40(sp)
0x10492: ec4e              sd            s3,24(sp)
0x10494: e852              sd            s4,16(sp)
0x10496: e456              sd            s5,8(sp)
0x10498: 40395913          srai          s2,s2,3
0x1049c: 00090f63          beqz          s2,30                           # 0x104ba
0x104a0: 8ab2              mv            s5,a2
0x104a2: 8a2e              mv            s4,a1
0x104a4: 89aa              mv            s3,a0
0x104a6: 4481              mv            s1,zero
0x104a8: 601c              ld            a5,0(s0)
0x104aa: 8656              mv            a2,s5
0x104ac: 85d2              mv            a1,s4
0x104ae: 854e              mv            a0,s3
0x104b0: 0485              addi          s1,s1,1
0x104b2: 9782              jalr          ra,a5,0
0x104b4: 0421              addi          s0,s0,8
0x104b6: fffffffffe9919e3          bne   s2,s1,-14                       # 0x104a8
0x104ba: 70e2              ld            ra,56(sp)
0x104bc: 7442              ld            s0,48(sp)
0x104be: 74a2              ld            s1,40(sp)
0x104c0: 7902              ld            s2,32(sp)
0x104c2: 69e2              ld            s3,24(sp)
0x104c4: 6a42              ld            s4,16(sp)
0x104c6: 6aa2              ld            s5,8(sp)
0x104c8: 6121              addi          sp,sp,64
0x104ca: 8082              ret           
0x104cc: 8082              ret           
```