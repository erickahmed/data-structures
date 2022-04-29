C := gcc
OBJ_FL := -o
BLD_FL := -c
SRC := main.c
OBJ := doublyLinkedList.o
DEPS := doubly-linked-list.c doubly-linked-list.h

OUT := doublyLinkedList.exe

.PHONY: all clean

object: $(SRC)
	$(C) $(SRC) $(DEPS) $(STND) $(OBJ_FL) $(OUT)

executable: $(OBJ)
	$(C) $(OBJ) $(BLD_FL) $(OUT)

clean:
	rm $(OBJ)