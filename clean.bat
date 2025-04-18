:: clean.bat
@echo off

REM Remove todos os .o gerados e o binário
del /F /Q main.o Bitboard.o Chess.o Move.o Position.o utils.o
del /F /Q bin.exe bin

