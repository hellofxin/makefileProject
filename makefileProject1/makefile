DIR_INC := -I./main -I./user
DIR_SRC := ./main
DIR_SRC_USER := ./user
DIR_OBJ := ./obj
DIR_BIN := ./bin

SRC := $(wildcard ${DIR_SRC}/*.c)  
SRC += $(wildcard $(DIR_SRC_USER)/*.c)
OBJ := $(patsubst %.c,${DIR_OBJ}/%.o,$(notdir ${SRC})) 
DEP := $(OBJ:.o=.d)
 
TARGET = main

BIN_TARGET = ${DIR_BIN}/${TARGET}

CC = g++
CFLAGS = -g -Wall ${DIR_INC}

${BIN_TARGET}:${OBJ}
	$(CC) $(OBJ)  -o $@
 
${DIR_OBJ}/%.o:${DIR_SRC}/%.c
	$(CC) $(CFLAGS) -c  $< -o $@


${DIR_OBJ}/%.o:$(DIR_SRC_USER)/%.c
	$(CC) $(CFLAGS) -c  $< -o $@


${DIR_OBJ}/%.d:$(DIR_SRC)/%.c
	@set -e; rm -f $@; \
	rm -f $@.*; \
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\).o[ :]*,$(dir $@)\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

${DIR_OBJ}/%.d:$(DIR_SRC_USER)/%.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\).o[ :]*,$(dir $@)\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$	

-include $(DEP)

.PHONY:clean
clean:
	rm -f $(OBJ) $(DEP) $(BIN_TARGET)

test:
	@echo dir_inc = $(DIR_INC)
	@echo dir src = $(DIR_SRC)
	@echo dir_obj = $(DIR_OBJ)
	@echo src = $(SRC)
	@echo obj = $(OBJ)
	@echo dep = $(DEP)
