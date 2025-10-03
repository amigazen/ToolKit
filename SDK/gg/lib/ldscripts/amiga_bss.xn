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
    ___datadata_relocs = .;
    __etext = .;
    ___text_size = ABSOLUTE(__etext - __stext);
  }
  . = ALIGN(0x0);
  .data :
  {
    __sdata = .;
    CONSTRUCTORS
    *(.data)
    ___a4_init = 0x7ffe;
    ___data_size = ABSOLUTE(__edata - __sdata);
    ___bss_size = ABSOLUTE(0);
  }
  .bss :
  {
    *(.bss)
    *(COMMON)
    __edata  =  .;
    __bss_start  =  .;
    __end = ALIGN(4) ;
  }
}
