main.elf : main.o Queue.o
	$(CC) -o $@ $^

main.c : Queue.h
	touch $@

Queue.c : Queue.h
	touch $@

.PHONY : clean

clean ::
	rm -f ./main.elf

clean ::
	rm -f ./*.o
