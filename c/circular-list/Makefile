C := gcc
OBJ_FL := -o
BLD_FL := -c
SRC := main.c
OBJ := circular-list.o
DEPS := circular-list.c circular-list.h

OUT := circular-list.exe

.PHONY: all clean

object: $(SRC)
	$(C) $(SRC) $(DEPS) $(STND) $(OBJ_FL) $(OUT)

executable: $(OBJ)
	$(C) $(OBJ) $(BLD_FL) $(OUT)

clean:
	rm $(OBJ)