#makefile
EXE = main
CXX = @g++
CXXFLAGS = -I../headers -Wall -g -std=c++17 -O2 -lSDL2


$(EXE): $(OBJS) makefile
	@rm -f $(EXE)
	$(CXX) *.cpp $(CXXFLAGS)  -o $(EXE) 

clean:
		@rm -f $(EXE)
run: $(EXE)
	@rm -f $(EXE)
	@./$(EXE)