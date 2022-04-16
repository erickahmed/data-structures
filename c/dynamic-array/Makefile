C := gcc
OBJ_FL := -o
BLD_FL := -c
SRC := main.c
OBJ := dynamicArray.o
DEPS := dynamic_array.c dynamic_array.h

OUT := dynamicArray.exe

.PHONY: all clean

object: $(SRC)
	$(C) $(SRC) $(DEPS) $(STND) $(OBJ_FL) $(OUT)

executable: $(OBJ)
	$(C) $(OBJ) $(BLD_FL) $(OUT)

clean:
	rm $(OBJ)