#include <pch.h>

#include "Emu/Utility/System/Loader/Elf64Reader.h"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    std::cerr << "Usage: loader binary-file-path" << std::endl;
    return 1;
  }

  Onikiri::EmulatorUtility::Elf64Reader reader;
  reader.Open(argv[1]);

  std::cout << "class " << reader.GetClass() << std::endl
            << "date encoding " << reader.GetDataEncoding() << std::endl
            << "version " << reader.GetVersion() << std::endl
            << "machine " << reader.GetMachine() << std::endl
            << "big endian " << reader.IsBigEndian() << std::endl;

  std::cout << std::hex
            << "e_entry 0x" << reader.GetEntryPoint() << std::endl
            << "e_phoff 0x" << reader.GetProgramHeaderOffset() << std::endl
            << "e_phnum 0x" << reader.GetProgramHeaderCount() << std::endl
            << "e_shoff 0x" << reader.GetSectionHeaderOffset() << std::endl
            << "e_shnum 0x" << reader.GetSectionHeaderCount() << std::endl
            << std::dec;

  std::cout << "sizeof(elf64_phdr) " << sizeof(Onikiri::EmulatorUtility::ELF64::ELF64_PROGRAM) << std::endl
            << "sizeof(elf64_shdr) " << sizeof(Onikiri::EmulatorUtility::ELF64::ELF64_SECTION) << std::endl;

  for (int i = 0; i < reader.GetProgramHeaderCount(); ++i) {
    const auto &header = reader.GetProgramHeader(i);
    if (header.p_type == Onikiri::EmulatorUtility::ELF::PT_LOAD) {
      std::cout << "phdr " << i << std::endl
                << std::hex
                << "  p_type 0x" << header.p_type << std::endl
                << "  p_flags 0x" << header.p_flags << std::endl
                << "  p_offset 0x" << header.p_offset << std::endl
                << "  p_vaddr 0x" << header.p_vaddr << std::endl
                << "  p_paddr 0x" << header.p_paddr << std::endl
                << "  p_filesz 0x" << header.p_filesz << std::endl
                << "  p_memsz 0x" << header.p_memsz << std::endl
                << "  p_align 0x" << header.p_align << std::endl
                << std::dec;
    }
  }

  for (int i = 0; i < reader.GetSectionHeaderCount(); ++i) {
    const auto &header = reader.GetSectionHeader(i);
    if (header.sh_type == 0) {
      // Skip null section
    } else {
      std::cout << "shdr " << i << std::endl
                << "  name " << reader.GetSectionName(i) << std::endl
                << std::hex
                << "  sh_name 0x" << header.sh_name << std::endl
                << "  sh_type 0x" << header.sh_type << std::endl
                << "  sh_flags 0x" << header.sh_flags << std::endl
                << "  sh_addr 0x" << header.sh_addr << std::endl
                << "  sh_offset 0x" << header.sh_offset << std::endl
                << "  sh_size 0x" << header.sh_size << std::endl
                << "  sh_link 0x" << header.sh_link << std::endl
                << "  sh_info 0x" << header.sh_info << std::endl
                << "  sh_addralign 0x" << header.sh_addralign << std::endl
                << "  sh_entsize 0x" << header.sh_entsize << std::endl
                << std::dec;
    }
  }

  return 0;
}
