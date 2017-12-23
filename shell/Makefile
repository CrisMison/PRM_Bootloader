
DIR_SHELL			:=	shell
DIR_SHELL_SUBDIRS	:=

SHELL_ASM		:=		$(wildcard $(DIR_SHELL)/*.s)
SHELL_SRC		:=		$(wildcard $(DIR_SHELL)/*.c)
SHELL_INC		:=		-I$(DIR_SHELL)
SHELL_OBJ		:=		$(patsubst %.c,$(DIR_OUT_OBJ)/%.o,$(SHELL_SRC))

OUTPUT_ASM			+=		$(SHELL_ASM)
OUTPUT_SRC			+=		$(SHELL_SRC)
OUTPUT_INC			+=		$(SHELL_INC)
OUTPUT_OBJ			+=		$(SHELL_OBJ)

DES_LIB_SHELL		:=		$(DIR_OUT_LIB)/lib$(DIR_SHELL).a
DES_LIB				+=		$(DES_LIB_SHELL)
DES_LIB_NAME		+=		$(DIR_SHELL)


$(DIR_OUT_OBJ)/$(DIR_SHELL)/%.o:$(DIR_SHELL)/%.c
	@ echo '  [CC]  ' $<
	@ mkdir -p $(DIR_OUT_OBJ)/$(DIR_SHELL)
	@ $(CC) -c $< $(OUTPUT_INC) $(OUTPUT_DEF) $(CFLAGS) -o $@

$(DES_LIB_SHELL):$(SHELL_OBJ)
	@ echo '  [AR]  ' $@
	@ mkdir -p $(DIR_OUT_LIB)
	@ $(AR) r $(DES_LIB_SHELL) $(SHELL_OBJ) > $(NULL)
	