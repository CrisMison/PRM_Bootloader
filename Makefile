
all:
	@ $(MAKE) toolscheck
	@ $(MAKE) targetbin

include build/build.mk
include $(shell find $(DIR_ROOT) -maxdepth 1 -name Makefile)

targetbin: $(DES_BIN) $(DES_ASM) $(DES_ELF)
	@ echo -e '\033[37;1mMake Image files finished.\033[0m'

menuconfig:
	@ cd $(DIR_MCONF) && ($(CMAKE) . > $(NULL)) && ($(MAKE) > $(NULL))
	@ $(DES_MONCIF) $(ROOT_KCONFIG)
	
cmenuconfig:
	@ cd $(DIR_MCONF) && $(MAKE) clean > $(NULL)

LINK_LIB	:=	$(patsubst %,-l%,$(DES_LIB))

$(DES_ASM):$(DES_ELF)
	@ echo '  [OBJDUMP]  ' $@
	@ $(OBJDUMP) -d $< > $@

$(DES_BIN):$(DES_ELF)
	@ echo '  [OBJCOPY]  ' $@
	@ $(OBJCOPY) -O binary -R .note -R .comment -S $< $@

$(DES_ELF):$(DES_LIB)
	@ mkdir -p $(DIR_OUT_ELF)
	@ echo '  [CC]  ' $@
	@ echo $(LINK_LD)
	@ $(CC) -T$(LINK_LD) -o $(DES_ELF) $(CFLAGS) $(OUTPUT_INC) $(OUTPUT_DEF) -static -Wl,-cref "-Wl,-Map=$(DES_MAP)" -Wl,--gc-sections -Wl,--start-group  $(patsubst %,-l%,$(DES_LIB_NAME)) -Wl,--end-group 

$(DES_LIB):$(OUTPUT_OBJ)

toolscheck:
	@ $(SCRIPT_CONFIG)
	@ $(CC) -v > $(NULL)
	@ $(CMAKE) --version > $(NULL)
	
clean:
	@ rm -rf out
	@ rm -rf 
	@echo -e '\033[37;1mClean output files finished.\033[0m'