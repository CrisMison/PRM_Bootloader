
DIR_CORE			:=	core
DIR_CORE_SUBDIRS	:=

CORE_ASM		:=		$(wildcard $(DIR_CORE)/*.s)
CORE_SRC		:=		$(wildcard $(DIR_CORE)/*.c)
CORE_INC		:=		-I$(DIR_CORE)
CORE_OBJ		:=		$(patsubst %.c,$(DIR_OUT_OBJ)/%.o,$(CORE_SRC))

OUTPUT_ASM			+=		$(CORE_ASM)
OUTPUT_SRC			+=		$(CORE_SRC)
OUTPUT_INC			+=		$(CORE_INC)
OUTPUT_OBJ			+=		$(CORE_OBJ)

DES_LIB_CORE		:=		$(DIR_OUT_LIB)/lib$(DIR_CORE).a
DES_LIB				+=		$(DES_LIB_CORE)
DES_LIB_NAME		+=		$(DIR_CORE)

$(DIR_OUT_OBJ)/$(DIR_CORE)/%.o:$(DIR_CORE)/%.c
	@ echo '  [CC]  ' $<
	@ mkdir -p $(DIR_OUT_OBJ)/$(DIR_CORE)
	@ $(CC) -c $< $(OUTPUT_INC) $(OUTPUT_DEF) $(CFLAGS) -o $@  $(BUILD_LIB)

$(DES_LIB_CORE):$(CORE_OBJ)
	@ echo '  [AR]  ' $@
	@ mkdir -p $(DIR_OUT_LIB)
	@ $(AR) r $(DES_LIB_CORE) $(CORE_OBJ) >> $(NULL)
	