# zsh in repo

mkdir resource/SDL
mkdir resource/SDL/include
mkdir resource/SDL/lib
mkdir resource/JSON
mkdir resource/JSON/include
mkdir resource/JSON/lib

brew install sdl2
brew install sdl2_image
brew install sdl2_mixer
brew install sdl2_ttf
brew install json-c

cp -aRv /Users/$USER/.brew/Cellar/sdl2/2.0.12_1/include/* resource/SDL/include/
cp -aRv /Users/$USER/.brew/Cellar/sdl2/2.0.12_1/lib/* resource/SDL/lib/

cp -aRv /Users/$USER/.brew/Cellar/sdl2_image/2.0.5/include/* resource/SDL/include/
cp -aRv /Users/$USER/.brew/Cellar/sdl2_image/2.0.5/lib/* resource/SDL/lib/

cp -aRv /Users/$USER/.brew/Cellar/sdl2_mixer/2.0.4/include/* resource/SDL/include/
cp -aRv /Users/$USER/.brew/Cellar/sdl2_mixer/2.0.4/lib/* resource/SDL/lib/

cp -aRv /Users/$USER/.brew/Cellar/sdl2_ttf/2.0.15/include/* resource/SDL/include
cp -aRv /Users/$USER/.brew/Cellar/sdl2_ttf/2.0.15/lib/* resource/SDL/lib/

cp -aRv /Users/$USER/.brew/Cellar/json-c/0.15/include/* resource/JSON/include/
cp -aRv /Users/$USER/.brew/Cellar/json-c/0.15/lib/* resource/JSON/lib/
