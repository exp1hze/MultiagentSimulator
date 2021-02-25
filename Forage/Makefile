CC = gcc
OFILES = main.o sim.o params.o random.o output.o fxn.o environ.o agent.o map.o nest.o gnu.o
HFILES = types.h global.h extern.h

sim:	$(OFILES) $(HFILES)
	$(CC) $(OFILES) -o sim

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

environ.o:	environ.c environ.h $(HFILES)
	$(CC) -c environ.c

agent.o:	agent.c agent.h $(HFILES)
	$(CC) -c agent.c

map.o:	map.c map.h $(HFILES)
	$(CC) -c map.c

nest.o:	nest.c nest.h $(HFILES)
	$(CC) -c nest.c

gnu.o:	gnu.c gnu.h $(HFILES)
	$(CC) -c gnu.c
