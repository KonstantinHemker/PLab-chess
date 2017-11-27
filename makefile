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
	#rm -f $(OBJ) $(EXE) $(OBJ:.o=.d)
	rm -i Bishop.d Bishop.o
	rm -i ChessBoard.d ChessBoard.o
	rm -i ChessMain.d ChessMain.o
	rm -i Figure.d Figure.o
	rm -i King.d King.o
	rm -i Knight.d Knight.o
	rm -i Pawn.d Pawn.o
	rm -i Queen.d Queen.o
	rm -i Rook.d Rook.o
