CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
OBJDIR = obj
SRCDIR = .
SRC := $(shell find $(SRCDIR) -name "*.c")
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.c
	@mkdir -p '$(@D)'
	$(CC) -c -ggdb3 $(CFLAGS) $< -o $@

APP = hsh

all: $(APP)

$(APP): $(OBJ)
	$(CC) $^ -ggdb3 $(CFLAGS) -o $(APP)

%.o: %.c
	@$(CC) -c -ggdb3 $(CFLAGS) $< -o $@

clean:
	find . -name *.o -delete
	rm -f $(APP)

style:
	@betty $(shell find . -name "*.c")
	@betty $(shell find . -name "*.h")

build: clean
	@docker build --tag hsh:latest .

run: build
	@docker run --rm -it hsh:latest