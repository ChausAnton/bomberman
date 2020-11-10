NAME = endgame
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
SDLFLAGS = -I resource/SDL/include -L resource/SDL/lib -l SDL2-2.0.0 -l SDL2_Image-2.0.0 -l SDL2_Mixer-2.0.0 -l SDL2_TTF-2.0.0

all: install
install:
	@clang $(CFLAGS) $(SDLFLAGS) src/*.c src/enemy/*.c -o $(NAME)
clean:
	@rm $(NAME)
