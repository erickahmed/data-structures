C := gcc
OBJ_FL := -o
BLD_FL := -c
SRC := main.c
OBJ := lifo-stack.o
DEPS := lifo-stack.c lifo-stack.h

OUT := lifo-stack.exe

.PHONY: all clean

object: $(SRC)
	$(C) $(SRC) $(DEPS) $(STND) $(OBJ_FL) $(OUT)

executable: $(OBJ)
	$(C) $(OBJ) $(BLD_FL) $(OUT)

clean:
	rm $(OBJ)