#Makefile for chess executable program

OBJ = ChessMain.o ChessBoard.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o Figure.o

EXE = chess
CXX = g++ -std=c++11
CXXFLAGS = -Wall -g -MMD

$(EXE):$(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(OBJ:.o=.d)

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXE) $(OBJ:.o=.d)
