IDIR =../include
CXX=g++ -std=c++11 -o main
CFLAGS=-I$(IDIR) -g

ODIR=../src
LDIR =../files

LIBS=-lm

_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main
main: ${OBJ} 
	$(CXX) $(CXXFLAGS) ${OBJ} 

	#rm -rf $(OBJS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
