C := gcc
OBJ_FL := -o
BLD_FL := -c
SRC := main.c
OBJ := fifo-stack.o
DEPS := fifo-stack.c fifo-stack.h

OUT := fifo-stack.exe

.PHONY: all clean

object: $(SRC)
	$(C) $(SRC) $(DEPS) $(STND) $(OBJ_FL) $(OUT)

executable: $(OBJ)
	$(C) $(OBJ) $(BLD_FL) $(OUT)

clean:
	rm $(OBJ)