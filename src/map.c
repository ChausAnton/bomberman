#include "../inc/map.h"

void constrMap(){
    map_src.x = map_src.y = 0;
    map_src.w = map_dst.w = 64;
    map_src.h = map_dst.h = 64;
    map_dst.x = map_dst.y = 0;
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
                case 11: drawMapCell(loaded_door, map_src, map_dst); break;
            }
        }
}
