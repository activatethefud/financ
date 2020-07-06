objects = main.o llist.o utility.o file_ops.o errors.o callbacks.o report.o

financ : $(objects)
	gcc -lm -Wall -Wstrict-prototypes -Wmissing-prototypes -Wshadow -Wconversion -o financ $(objects)

main.o : main.h
llist.o : llist.h
utility.o : utility.h
file_ops.o : file_ops.h
errors.o : errors.h
callbacks.o : callbacks.h

.PHONY : clean
clean : 
	rm financ $(objects)


.PHONY : debug
debug : $(objects)
	gcc -g -lm -Wall -Wstrict-prototypes -Wmissing-prototypes -Wshadow -Wconversion -o financ $(objects)
