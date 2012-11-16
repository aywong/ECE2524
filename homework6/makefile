#Annie Wong Makefile

CC = g++ -Wall -g

all: generator consumer dispatcher

generator: generator.o
    ${CC} -o generator generator.cpp
    
generator.o: generator.cpp
    ${CC} -c generator.cpp
    
consumer: consumer.o
    ${CC} -o consumer consumer.cpp
    
consumer.o: consumer.cpp
    ${CC} -c consumer.cpp
    
dispatcher: dispatcher.o
    ${CC} -o dispatcher dispatcher.cpp
    
dispatcer.o: dispatcher.cpp
    ${CC} -c dispatcher.cpp
  
clean:
    rm -f *.o *~ core
    rm -f generator
    rm -f consumer
    rm -f dispatcher
    
