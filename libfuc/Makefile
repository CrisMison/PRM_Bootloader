
DIR_LIBFUC			:=	libfuc
DIR_LIBFUC_SUBDIRS	:=

LIBFUC_ASM		:=		$(wildcard $(DIR_LIBFUC)/*.s)
LIBFUC_SRC		:=		$(wildcard $(DIR_LIBFUC)/*.c)
LIBFUC_INC		:=		-I$(DIR_LIBFUC)
LIBFUC_OBJ		:=		$(patsubst %.c,$(DIR_OUT_OBJ)/%.o,$(LIBFUC_SRC))

OUTPUT_ASM			+=		$(LIBFUC_ASM)
OUTPUT_SRC			+=		$(LIBFUC_SRC)
OUTPUT_INC			+=		$(LIBFUC_INC)
OUTPUT_OBJ			+=		$(LIBFUC_OBJ)

DES_LIB_LIBFUC		:=		$(DIR_OUT_LIB)/lib$(DIR_LIBFUC).a
DES_LIB				+=		$(DES_LIB_LIBFUC)
DES_LIB_NAME		+=		$(DIR_LIBFUC)


$(DIR_OUT_OBJ)/$(DIR_LIBFUC)/%.o:$(DIR_LIBFUC)/%.c
	@ echo '  [CC]  ' $<
	@ mkdir -p $(DIR_OUT_OBJ)/$(DIR_LIBFUC)
	@ $(CC) -c $< $(OUTPUT_INC) $(OUTPUT_DEF) $(CFLAGS) -o $@

$(DES_LIB_LIBFUC):$(LIBFUC_OBJ)
	@ echo '  [AR]  ' $@
	@ mkdir -p $(DIR_OUT_LIB)
	@ $(AR) r $(DES_LIB_LIBFUC) $(LIBFUC_OBJ) > $(NULL)