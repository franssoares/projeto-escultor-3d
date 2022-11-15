g++ -c main.cpp -o main.o
g++ -c sculptor.cpp -o sculptor.o

g++ -c putvoxel.cpp -o putvoxel.o
g++ -c cutvoxel.cpp -o cutvoxel.o
g++ -c interpretador.cpp -o interpretador.o

g++ -c putbox.cpp -o putbox.o
g++ -c cutbox.cpp -o cutbox.o

g++ -c putsphere.cpp -o putsphere.o
g++ -c cutsphere.cpp -o cutsphere.o

g++ -c putellipsoid.cpp -o putellipsoid.o
g++ -c cutellipsoid.cpp -o cutellipsoid.o

g++ -o programa main.o sculptor.o putvoxel.o cutvoxel.o interpretador.o putbox.o cutbox.o putsphere.o cutsphere.o putellipsoid.o cutellipsoid.o 

.\programa.exe

del *.exe
del *.o