# Verificar si ARGS está definido
ifndef ARGS
$(error No se proporcionaron las flags requeridas. Ejecute con make ARGS="-src 'archivo a usar' -dst 'ruta a guardar el resultado'")
endif

# Variables
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
EXECUTABLE = executeme
CXX = g++
CXXFLAGS = -Wall -I$(INCLUDE_DIR) -fopenmp
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Target principal
all: compile_general execute_general clean

# Regla para compilar el ejecutable
compile_general: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar archivos .cpp a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos compilados
clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLE)

# Regla para ejecutar el programa
execute_general: $(EXECUTABLE)
	./$(EXECUTABLE) $(ARGS)

.PHONY: all compile_general clean execute_general