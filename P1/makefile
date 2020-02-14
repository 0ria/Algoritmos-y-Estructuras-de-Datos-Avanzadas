CXX=g++
CXXFLAGS=-g -std=c++11 -o main
#TEXTO=cp /home/oria/Desktop/Universidad/3º/1_Cuatri/CyA/achivosTexto/*.gra /home/oria/Desktop/Universidad/3º/1_Cuatri/CyA/P8
OBJS = main.o	

all: ${OBJS}
#	${TEXTO}
	$(CXX) $(CXXFLAGS) ${OBJS} 

	rm -rf $(OBJS)

clean:
	find . -type f ! \( -name "*.cpp" -or -name "*.h" -or -name "makefile" \) -delete
