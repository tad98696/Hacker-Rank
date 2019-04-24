.PHONY: all
all: PlayingWithCharacters

PlayingWithCharacters.exe:
	$(GCC) -o PlayingWithCharacters.exe PlayingWithCharacters.c

.PHONY: clean
clean:
	@rm -fv *.exe
