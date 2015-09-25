all: piece.o pawn.o rook.o bishop.o queen.o king.o knight.o main.o evaluate.o graphics.o incheck.o endgame.o AI.o movement.o setup_and_position_values.o allpieces.h
	g++ piece.o pawn.o rook.o bishop.o queen.o king.o knight.o setup_and_position_values.o graphics.o evaluate.o endgame.o incheck.o main.o movement.o AI.o `fltk-config --ldflags --cxxflags --use-images` -lfltk -lX11 -lXext -lm -lpthread

piece.o: piece.h piece.cpp
	g++ -c piece.cpp

pawn.o: piece.cpp pawn.cpp pawn.h
	g++ -c pawn.cpp
	
rook.o: piece.cpp rook.cpp rook.h
	g++ -c rook.cpp
	
bishop.o: piece.cpp bishop.cpp bishop.h
	g++ -c bishop.cpp
	
queen.o: piece.cpp queen.cpp queen.h
	g++ -c queen.cpp
	
king.o: piece.cpp king.cpp king.h
	g++ -c king.cpp
	
knight.o: piece.cpp knight.cpp knight.h
	g++ -c knight.cpp

setup_and_position_values.o: setup_and_position_values.cpp board.h
	g++ -c setup_and_position_values.cpp
	
graphics.o: graphics.cpp board.h
	g++ -c graphics.cpp

evaluate.o: evaluate.cpp board.h
	g++ -c evaluate.cpp

incheck.o: incheck.cpp board.h
	g++ -c incheck.cpp

endgame.o: endgame.cpp board.h
	g++ -c endgame.cpp

movement.o: movement.cpp board.h
	g++ -c movement.cpp

AI.o: AI.cpp board.h 
	g++ -c AI.cpp
	
main.o: main.cpp
	g++ -c main.cpp 

