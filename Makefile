BINARY=bin
CODEDIRS=. lib/Chess lib/Utils lib/Move lib/Bitboard lib/Position src
INCDIRS=$(addprefix -I, . ./lib/Chess ./lib/Utils .lib/Move ./lib/Bitboard ./lib/Position)

GXX=g++
OPT=-O0
DEPFLAGS=-MP -MD
CXXFLAGS=-Wall -Wextra -g $(INCDIRS) $(OPT)

CXXFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))
OBJECTS=$(patsubst %.cpp,%.o,$(CXXFILES))
DEPFILES=$(patsubst %.cpp,%.d,$(CXXFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(GXX) -o $@ $^

%.o: %.cpp
	$(GXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(BINARY)

-include $(DEPFILES)