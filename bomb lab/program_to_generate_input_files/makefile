CPPFLAGS = -std=c++11 -Wall -O2 -g -Wno-unused-result

main: main.o
	$(LINK.c) $^ $(OUTPUT_OPTION)

main.o: main.cpp
	 $(COMPILE.c) $< $(OUTPUT_OPTION)

%.o: %.c %.h
	$(COMPILE.c) $< $(OUTPUT_OPTION)

.PHONY: clean
clean:
	rm -rf *.o main
