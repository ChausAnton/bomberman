#include "../inc/map.h"

int lvl1[20][25] = {
    {7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,8},
    {5,0,0,0,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,2,1,2,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,2,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,1,1,1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,1,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,2,2,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
    {9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,10},
};

void constrMap(){
    ground = LoadTexture("resource/ast/terrain/Ground.png", renderer);
    breakable_stone = LoadTexture("resource/ast/terrain/Breakable_Stone.png", renderer);
    stone = LoadTexture("resource/ast/terrain/Stone.png", renderer);
    // Stone Walls
    up_stone_wall = LoadTexture("resource/ast/terrain/UpStoneWall.png", renderer);
    down_stone_wall = LoadTexture("resource/ast/terrain/DownStoneWall.png", renderer);
    left_stone_wall = LoadTexture("resource/ast/terrain/LeftStoneWall.png", renderer);
    right_stone_wall = LoadTexture("resource/ast/terrain/RightStoneWall.png", renderer);
    // Stone Corners
    up_left_corner = LoadTexture("resource/ast/terrain/UpLeftCorner.png", renderer);
    up_right_corner = LoadTexture("resource/ast/terrain/UpRightCorner.png", renderer);
    down_left_corner = LoadTexture("resource/ast/terrain/DownLeftCorner.png", renderer);
    down_right_corner = LoadTexture("resource/ast/terrain/DownRightCorner.png", renderer);

    LoadMap(lvl1);
    map_src.x = map_src.y = 0;
    map_src.w = map_dst.w = 64;
    map_src.h = map_dst.h = 64;
    map_dst.x = map_dst.y = 0;
}

void LoadMap(int arr[20][25]){
    for(int row = 0; row < 20; ++row)
        for(int column = 0; column < 25; ++column)
            map[row][column] = arr[row][column];
}

void DrawMap(){
    constrMap();
    int terrain_type = 0;
    for(int row = 0; row < 20; ++row)
        for(int column = 0; column < 25; ++column){
            terrain_type = map[row][column];
            map_dst.x = column * 64;
            map_dst.y = row * 64;
            switch(terrain_type){
                case 0: drawMapCell(ground, map_src, map_dst); break;
                case 1: drawMapCell(breakable_stone, map_src, map_dst); break;
                case 2: drawMapCell(stone, map_src, map_dst); break;
                case 3: drawMapCell(up_stone_wall, map_src, map_dst); break;
                case 4: drawMapCell(down_stone_wall, map_src, map_dst); break;
                case 5: drawMapCell(left_stone_wall, map_src, map_dst); break;
                case 6: drawMapCell(right_stone_wall, map_src, map_dst); break;
                case 7: drawMapCell(up_left_corner, map_src, map_dst); break;
                case 8: drawMapCell(up_right_corner, map_src, map_dst); break;
                case 9: drawMapCell(down_left_corner, map_src, map_dst); break;
                case 10: drawMapCell(down_right_corner, map_src, map_dst); break;
            }
        }
}