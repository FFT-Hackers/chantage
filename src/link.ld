ENTRY(_start)
SECTIONS
{
    . = 0x0;

    .text : SUBALIGN(0x4) {
        * ( .text.start )
        * ( .text )
        * ( .text.* )
    }

    .rodata.sceModuleInfo : SUBALIGN(0x4) {
        * ( .rodata.sceModuleInfo )
    }

    .data : SUBALIGN(0x04) {
        * ( .data )
        * ( .data.* )
        * ( .rodata )
        * ( .rodata.* )
        * ( COMMON )
        * ( .bss )
    }

    .rel.text : SUBALIGN(0x4) {
        * ( .rel.text )
    }

    /DISCARD/ : {
        * ( .comment )
        * ( .pdr )
        * ( .MIPS.abiflags )
        * ( .reginfo )
        * ( .gnu.attributes )
        * ( .gcc_compiled_long32 )
        * ( .mdebug.eabi32 )
    }
}
