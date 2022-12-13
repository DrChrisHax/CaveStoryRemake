#makefile
EXE = main
CXX = @g++
CXXFLAGS = -Wall -g -std=c++17 -O2 
HEADERS = -I../headers 
LINKERFLAGS = -lSDL2 -lSDL2_image


$(EXE): $(OBJS) makefile
	@rm -f $(EXE)
	$(CXX) *.cpp $(CXXFLAGS) $(HEADERS) $(LINKERFLAGS) -o $(EXE) 

clean:
		@rm -f $(EXE)
run: $(EXE)
	@./$(EXE)