
SCRIPT_CONFIG	:=	tools/script/config.sh
SCRIPT_CHAIN	:=	tools/script/toolchain.sh

PROJECT				:=	Proejct RM Bootloader
PLATFORM			:=	STM32F103ZET6
ARCH				:=	ARM Cortex-M3
VERSION				:=	0.01
VERSION_CODE		:=	NEST
VERSION_UPDATE		:=	20171221
MAKEFILE_VER		:=	0.01
MAKEFILE_UPDATE		:=	20171221
PLATFORM_TOOLCHAIN 	:=  $(shell $(SCRIPT_CHAIN))
NULL				:=	/dev/null


CC			:=	$(PLATFORM_TOOLCHAIN)gcc
AR			:=	$(PLATFORM_TOOLCHAIN)ar
LD			:=	$(PLATFORM_TOOLCHAIN)ld
AS			:=	$(PLATFORM_TOOLCHAIN)gcc
OBJCOPY		:=	$(PLATFORM_TOOLCHAIN)objcopy
OBJDUMP		:=	$(PLATFORM_TOOLCHAIN)objdump
MAKE		:=	make
CMAKE		:=	cmake
NULL		:=	/dev/null

DIR_OUT		:=	out
DIR_OUT_OBJ	:=	out/object
DIR_OUT_LIB	:=	out/lib
DIR_OUT_BIN	:=	out/bin
DIR_OUT_ASM	:=	out/bin
DIR_OUT_ELF	:=	out/bin
DIR_OUT_MAP	:=	out/bin
DIR_MCONF	:=	tools/menuconfig

DES_ASM	:=	$(DIR_OUT_BIN)/rm_bootloader.asm
DES_BIN	:=	$(DIR_OUT_BIN)/rm_bootloader.bin
DES_ELF	:=	$(DIR_OUT_ELF)/rm_bootloader.elf
DES_MAP :=	$(DIR_OUT_MAP)/rm_bootloader.map
DES_MONCIF:=$(DIR_MCONF)/mconf

ROOT_KCONFIG:= build/Kconfig

DIR_ROOT:=\
	core\
	libfuc\
	platform\
	shell
CFLAGS:=\
	-Lout/lib\
	-mcpu=cortex-m3	\
	-mthumb\
	-Wall\
	-Wextra\
	-Werror\
	-specs=nano.specs\
	-specs=nosys.specs\
	$(patsubst %,-T%,$(LINK_LD))

OUTPUT_DEF:=	\
	-DUSE_FULL_ASSERT\
	-DSTM32F10X_HD\
	-DUSE_STDPERIPH_DRIVER\
	-DHSE_VALUE=8000000\
	-DRM_CONSOLE_LINUX