del objeto3d.off
g++ -c main.cpp -o main.o
g++ -c sculptor.cpp -o sculptor.o
g++ -o programa main.o sculptor.o
.\programa.exe
del *.exe
del *.o