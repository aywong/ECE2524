#Annie Wong Makefile

CC = g++ -Wall -g
FLS = driver.o scanner.o parser.o

all: exprtest

exprtest:
    myprog: ${FLS}
        ${CC} -o myprog ${FLS}
        
    driver.o: driver.cpp driver.hpp scanner.hpp 
        ${CC} -c driver.cpp
        
    flex:
        flex -t scanner.ll > scanner.cpp
        
    scanner.o: scanner.cpp scanner.hpp scanner.tab.hpp
        ${CC}  -c scanner.hpp
        
    bison:
        bison parser.ypp
        
    parser.o: parser.tab.cpp parser.tab.hpp expression.hpp scanner.hpp driver.hpp
        ${CC}  -c parser.tab.cpp
    
clean:
    -rm -f *.o *~ cor

exclean:
    -rm -f myprog
