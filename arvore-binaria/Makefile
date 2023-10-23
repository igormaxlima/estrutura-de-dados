CC = gcc
LDFLAGS =
BLDDIR = .
INCDIR = $(BLDDIR)/inc
SRCDIR = $(BLDDIR)/src
OBJDIR = $(BLDDIR)/obj
CFLAGS = -c -w -I$(INCDIR)
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
EXE = main

.PHONY: all clean
.PHONY: compile_and_run

make: all run
all: clean $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJDIR)/*.o -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJDIR)/*.o $(EXE)

run:
	./$(EXE)

build:
	@echo "\033[1;34mBuilding...\033[0m"
	@mkdir -p $(INCDIR) $(SRCDIR)
	@echo "#include <stdio.h>" > $(SRCDIR)/main.c
	@echo "#include <stdlib.h>" >> $(SRCDIR)/main.c
	@echo "" >> $(SRCDIR)/main.c
	@echo "int main() {" >> $(SRCDIR)/main.c
	@echo "  return 0;" >> $(SRCDIR)/main.c
	@echo "}" >> $(SRCDIR)/main.c
	@echo ""
	@echo "\033[1;32mBuilded!\033[0m"
