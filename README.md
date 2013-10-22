Zawasowane jezyki programowania

	1. Mno�enia macierzy przez wektor.
		a)mnozmacmpi.c jest to wersja wykorzystuj�ca MPI
			time mpirun -np 4 mnozmacmpi 400
			Czas to ok 1,2 sec
		b)mnozmac.c jest to wersja bez MPI
			./mnozmac 400
			Czas ok 1 sec

		*Opis
			Podejrzewam �e wersja z MPI jest wolniejsza poniewa� sporo czasu marnuj� si� na 
			dostawianie zer tak aby macierz mog�a si� podzieli� na r�wne cz�ci
			
	*************************************************************************************************
	
	2.Oliczanie ca�ki. n =100000000
		a)calkampi.c jest to wersja wykorzystuj�ca MPI
			mpirun -np 4 calkampi
			Czas to 3.0 sec
		b)calka.c jest to wersja nie wykorzystuj�ca MPI
			./calka
			Czas to 7,7 sec

		
	*************************************************************************************************
	
	3. Algorytmu Monte Carlo, niter=1000000000;
		a)montecarlompi.c jest to wersja wykorzystuj�ca MPI
			mpirun -np 4 calkampi
			Czas to 6.6 sec
		b)montecarlo.c jest to wersja nie wykorzystuj�ca MPI
			./montecarlo
			Czas to 34.0 sec