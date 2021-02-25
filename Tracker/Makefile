CC = gcc
OFILES = main.o sim.o params.o random.o output.o fxn.o ftarget.o ftracker.o gnu.o
HFILES = types.h global.h extern.h

sim:	$(OFILES) $(HFILES)
	$(CC) $(OFILES) -o sim

xx:	test.o random.o random.h
	$(CC) random.o test.o -o xx

test.o:	test.c
	$(CC) -c test.c

main.o:	main.c $(HFILES)
	$(CC) -c main.c

sim.o:		sim.c sim.h $(HFILES)
	$(CC) -c sim.c

params.o:	params.c params.h $(HFILES)
	$(CC) -c params.c

random.o:	random.c random.h $(HFILES)
	$(CC) -c random.c

output.o:	output.c output.h $(HFILES)
	$(CC) -c output.c

fxn.o:	fxn.c fxn.h $(HFILES)
	$(CC) -c fxn.c

ftarget.o:	ftarget.c ftarget.h $(HFILES)
	$(CC) -c ftarget.c

ftracker.o:	ftracker.c ftracker.h $(HFILES)
	$(CC) -c ftracker.c

gnu.o:	gnu.c gnu.h $(HFILES)
	$(CC) -c gnu.c
