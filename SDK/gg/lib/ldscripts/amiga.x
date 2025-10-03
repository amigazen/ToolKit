OUTPUT_FORMAT("amiga")
OUTPUT_ARCH(m68k)
SEARCH_DIR(/gg/os-lib); SEARCH_DIR(/gg/lib); SEARCH_DIR(/gg/m68k-amigaos/lib);
SECTIONS
{
  . = 0x0;
  .text :
  {
    ___machtype = ABSOLUTE(0x0);
    __stext = .;
    *(.text)
    __etext = .;
    ___text_size = ABSOLUTE(__etext - __stext);
  }
  . = ALIGN(0x0);
  .data :
  {
    __sdata = .;
    CONSTRUCTORS
    *(.data)
    __edata = .;
    ___data_size = ABSOLUTE(__edata - __sdata);
  }
  . = ALIGN(0x0);
  .bss :
  {
     __bss_start = .;
    *(.bss)
    *(COMMON)
    __end = . ;
    ___bss_size = ABSOLUTE(__end - __bss_start);
  }
  .data_chip :
  {
    *(.data_chip)
  }
  .bss_chip :
  {
    *(.bss_chip)
  }
}
