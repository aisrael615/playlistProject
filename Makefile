CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

COMMON_OBJS = song.o node.o playlist.o playback.o utils.o sort.o hash.o

MAIN_OBJS = $(COMMON_OBJS) main.o
INTERACTIVE_OBJS = $(COMMON_OBJS) interactive_helpers.o interactive_main.o

MAIN_TARGET = app_playlist
INTERACTIVE_TARGET = interactive_playlist

all: $(MAIN_TARGET) $(INTERACTIVE_TARGET)

# ----- main (non-interactive) version -----
$(MAIN_TARGET): $(MAIN_OBJS)
	$(CC) $(CFLAGS) -o $(MAIN_TARGET) $(MAIN_OBJS)

# ----- interactive version -----
$(INTERACTIVE_TARGET): $(INTERACTIVE_OBJS)
	$(CC) $(CFLAGS) -o $(INTERACTIVE_TARGET) $(INTERACTIVE_OBJS)

# ----- compile rule -----
%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(MAIN_TARGET) $(INTERACTIVE_TARGET)
