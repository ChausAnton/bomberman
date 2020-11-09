# zsh in repo

mkdir resource/SDL
mkdir resource/SDL/include
mkdir resource/SDL/lib
mkdir resource/JSON
mkdir resource/JSON/include
mkdir resource/JSON/lib

sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev
sudo apt-get install libsdl2-mixer-dev
sudo apt-get install libsdl2-ttf-dev
sudo apt-get install ljson-c-dev

cp -aRv /usr/include/SDL2/* resource/SDL/include/
cp -aRv /usr/lib/x86_64-linux-gnu/* resource/SDL/lib/

cp -aRv /usr/include/json-c/* resource/JSON/include/
cp -aRv /usr/lib/x86_64-linux-gnu/* resource/JSON/lib/
