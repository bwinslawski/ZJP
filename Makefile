all: runmac runmacm runcal runcalm runmonte runmontem
runmacm: macm
	mpirun -np 4 mnozmacmpi 400
runmac: mac
	./mnozmac 400
macm: mnozmacmpi.c
	mpicc mnozmacmpi.c -o mnozmacmpi
mac: mnozmac.c
	gcc mnozmac.c -o mnozmac
runcalm: calm
	mpirun -np 10 calkampi
runcal: cal
	./calka
calm: calkampi.c
	mpicc calkampi.c -o calkampi -lm
cal: calka.c
	gcc calka.c -o calka -lm
runmonte: monte
	./montecarlo
runmontem: montem
	mpirun -np 10 montecarlo
monte: montecarlo.c
	gcc montecarlo.c -o montecarlo
montem: montecarlompi.c
	mpicc montecarlompi.c -o montecarlompi
clear: 
	rm -f *.o mnozmacmpi mnozmac montecarlompi montecarlo calkampi calka
	ls
