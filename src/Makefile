CC = g++
CFLAGS = -Wall 
PROG = basicshapes

SRCS = l4.cpp text3d.cpp
LIBS = -lglut -lGL -lGLU -w

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)
