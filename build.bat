:: build.bat
@echo off
setlocal

REM — Variáveis expandidas do Makefile —
set "BINARY=bin"
set "GXX=g++"
set "CXXFLAGS=-Wall -Wextra -g -I. -Ilib\Chess -Ilib\Utils -Ilib\Move -Ilib\Bitboard -Ilib\Position -O0"

REM Compila cada unidade (.cpp → .o)
"%GXX%" %CXXFLAGS% -c src\main.cpp       -o main.o
"%GXX%" %CXXFLAGS% -c lib\Utils\utils.cpp       -o utils.o
"%GXX%" %CXXFLAGS% -c lib\Move\Move.cpp         -o Move.o
"%GXX%" %CXXFLAGS% -c lib\Position\Position.cpp -o Position.o
"%GXX%" %CXXFLAGS% -c lib\Bitboard\Bitboard.cpp -o Bitboard.o
"%GXX%" %CXXFLAGS% -c lib\Chess\Chess.cpp       -o Chess.o

REM Linka todas as .o no executável “bin”
"%GXX%" -o %BINARY% main.o utils.o Bitboard.o Chess.o Move.o Position.o

endlocal
