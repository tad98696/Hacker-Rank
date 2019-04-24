DIRNAME := $(shell basename $(realpath .))

.PHONY: all
all: $(DIRNAME).exe

%.exe: %.c
	$(CC) -o $@ $<

.PHONY: clean
clean:
	echo $(DIRNAME)
	@rm -fv *.exe
