SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++ 
CPPFLAGS = -Wall -g -std=c++14  -I./$(INC) 

all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebacronologia: $(SRC)/cronologia.cpp $(SRC)/fechahistorica.cpp $(SRC)/pruebacronologia.cpp
	$(CXX) $(CPPFLAGS) -o $@ $^



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
