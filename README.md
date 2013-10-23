Zawasowane jezyki programowania
https://github.com/bwinslawski/ZJP
	
	
	1.Oliczanie ca³ki. n =100000000
		a)calkampi.c jest to wersja wykorzystuj¹ca MPI
			*time mpirun -np 4 calkampi 512				Czas to 1.260s 
			*time mpirun -np 4 calkampi 5120			Czas to 1.269s
			*time mpirun -np 4 calkampi 51200			Czas to 1.271s
			*time mpirun -np 4 calkampi 512000			Czas to 1.292s
			*time mpirun -np 4 calkampi 5120000			Czas to 1.559s
			*time mpirun -np 4 calkampi 51200000		Czas to 4.303s
			*time mpirun -np 4 calkampi 51200000		Czas to 31.682s

		b)calka.c jest to wersja nie wykorzystuj¹ca MPI
			*time ./calka 512   		Czas to 0.005s 
			*time ./calka 5120  		Czas to 0.006s 
			*time ./calka 51200  		Czas to 0.007s 
			*time ./calka 512000  		Czas to 0.014s 
			*time ./calka 5120000  		Czas to 0.918s 
			*time ./calka 51200000  	Czas to 9.017s 
			*time ./calka 512000000  	Czas to 1m30.665s

		
	*************************************************************************************************
	
	2. Algorytmu Monte Carlo, niter=1000000000;
		a)montecarlompi.c jest to wersja wykorzystuj¹ca MPI
			*time mpirun -np 4 calkampi 1				Czas to 1.264s
			*time mpirun -np 4 calkampi 10				Czas to 1.365s
			*time mpirun -np 4 calkampi 100				Czas to 1.267s
			*time mpirun -np 4 calkampi 1000			Czas to 1.268s
			*time mpirun -np 4 calkampi 10000			Czas to 1.270s
			*time mpirun -np 4 calkampi 100000			Czas to 1.279s
			*time mpirun -np 4 calkampi 1000000			Czas to 1.340s
			*time mpirun -np 4 calkampi 10000000		Czas to 1.882s
			*time mpirun -np 4 calkampi 100000000		Czas to 7.310s
			*time mpirun -np 4 calkampi 1000000000		Czas to 46.321s
			*time mpirun -np 4 calkampi 10000000000		Czas to 47.321s
										
										
		b)montecarlo.c jest to wersja nie wykorzystuj¹ca MPI
			*./montecarlo 1					Czas to 0.004
			*./montecarlo 10				Czas to 0.005s
			*./montecarlo 100				Czas to 0.005s
			*./montecarlo 1000				Czas to 0.005s
			*./montecarlo 10000				Czas to 0.006s
			*./montecarlo 100000			Czas to 0.008s
			*./montecarlo 1000000			Czas to 0.036s
			*./montecarlo 10000000			Czas to 0.360s
			*./montecarlo 100000000			Czas to 3.346s
			*./montecarlo 1000000000		Czas to 33.773s
			
	*************************************************************************************************
	
	3. Mno¿enia macierzy przez wektor.
		a)mnozmacmpi.c jest to wersja wykorzystuj¹ca MPI
			*time mpirun -np 4 mnozmacmpi 4		Czas to ok 1.264s
			*time mpirun -np 4 mnozmacmpi 40	Czas to ok 1.274s
			*time mpirun -np 4 mnozmacmpi 400	Czas to ok 1.275s
		b)mnozmac.c jest to wersja bez MPI
			*./mnozmac 4 	Czas ok 0.005s
			*./mnozmac 40 	Czas ok 0.009s
			*./mnozmac 400 	Czas ok 0.500s

		*Opis
			Podejrzewam ¿e wersja z MPI jest wolniejsza poniewa¿ sporo czasu marnujê siê na 
			dostawianie zer tak aby macierz mog³a siê podzieliæ na równe czêœci
			
