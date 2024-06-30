# Verificar si ARGS está definido
ifndef ARGS
$(error No se proporcionaron las flags requeridas. Ejecute con make ARGS="-src "archivo a usar" -dst "ruta a guardar el resultado"")
endif

all: compile_general execute_general clean

# Variables
INPUTFILE = prueba.txt
FILES = main.cpp
EXECUTABLE = executeme

# COMPILERS INSTANCES pthread
compile_general:
	g++ -o $(EXECUTABLE) $(FILES)

clean:
	@echo "\n"
	rm -f $(EXECUTABLE)

# EXECUTERS INSTANCES
execute_general:
	@echo "\n"
	./$(EXECUTABLE) $(ARGS)
	@echo "\n"