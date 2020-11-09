#include "../../inc/enemy.h"

void init_slime(int x, int y) {
	if(slimes == NULL) {
		slimes = mx_create_slime(x, y);
	}
	else mx_push_back_slime(&slimes, x, y);

	slime_velocity = 2;
	slime_up = false;
	slime_down = false;
	slime_left = false;
	slime_right = false;

	srand(time(0));
}

int compare(int a1, int a2, int a3, int a4) {
	if (a1 > a2 && a1 > a3 && a1 > a4) {
		return 1;
	}
	else if (a2 > a1 && a2 > a3 && a2 > a4) {
		return 2;
	}
	else if (a3 > a2 && a3 > a1 && a3 > a4) {
		return 3;
	}
	else if (a4 > a2 && a4 > a3 && a4 > a3) {
		return 4;
	}
	else return 0;
}


void slimeUP(t_slime *cur_slime, int slime_velocity) {
	if(cur_slime->slime_R.y < 0) cur_slime->slime_R.y = 0;
	if(cur_slime->slime_R.y > 1280) cur_slime->slime_R.y = 1280;
	cur_slime->slime_R.y -= slime_velocity;
}

void slimeRIGHT(t_slime *cur_slime, int slime_velocity) {
	if(cur_slime->slime_R.x < 0) cur_slime->slime_R.x = 0;
	if(cur_slime->slime_R.x > 1600) cur_slime->slime_R.x = 1600;
	cur_slime->slime_R.x += slime_velocity;
}

void slimeLEFT(t_slime *cur_slime, int slime_velocity) {
	if(cur_slime->slime_R.x < 0) cur_slime->slime_R.x = 0;
	if(cur_slime->slime_R.x > 1600) cur_slime->slime_R.x = 1600;
	cur_slime->slime_R.x -= slime_velocity;
}

void slimeDOWN(t_slime *cur_slime, int slime_velocity) {
	if(cur_slime->slime_R.y < 0) cur_slime->slime_R.y = 0;
	if(cur_slime->slime_R.y > 1280) cur_slime->slime_R.y = 1280;
	cur_slime->slime_R.y += slime_velocity;
}

void slimeMove(int slime_velocity) {
	t_slime *cur_slime = slimes;
	for (int i = 0; cur_slime != NULL; i++) {
		slime_up = false;
		slime_down = false;
		slime_left = false;
		slime_right = false;
		
		int x_player = player_R.x;
		int y_player = player_R.y;

		if(map[(cur_slime->slime_R.y - 1) / 64][(cur_slime->slime_R.x) / 64] == 0 && map[(cur_slime->slime_R.y - 1) / 64][(cur_slime->slime_R.x + 63) / 64] == 0) {//move_up
			int temp = (cur_slime->slime_R.x - x_player);
			if (temp < 0 ) temp = temp * -1;
			if( temp < 63) {
				if (cur_slime->slime_R.y != (y_player + 40))
					slime_up = true;
			}
			else slime_up = true;
		}
		if(map[(cur_slime->slime_R.y) / 64][(cur_slime->slime_R.x + 63) / 64] == 0 && map[(cur_slime->slime_R.y + 63) / 64][(cur_slime->slime_R.x + 63) / 64] == 0) {//move_right
			slime_right = true;
		}
		if (map[(cur_slime->slime_R.y) / 64][(cur_slime->slime_R.x - 1) / 64] == 0 && map[(cur_slime->slime_R.y + 63) / 64][(cur_slime->slime_R.x - 1) / 64] == 0) {//move_left
			slime_left = true;
		}
		if(map[(cur_slime->slime_R.y + 63) / 64][(cur_slime->slime_R.x) / 64] == 0 && map[(cur_slime->slime_R.y + 63) / 64][(cur_slime->slime_R.x + 63) / 64] == 0) {//move_down
			slime_down = true;
		}
		
		if(cur_slime->gener == true) {
			cur_slime->random_slime = (rand() % 400 + 1);
		}


		if(200 <= cur_slime->random_slime && cur_slime->random_slime <= 300 && slime_left == true) {
			slimeLEFT(cur_slime, slime_velocity);
			cur_slime->gener = false;
		}


		if(300 <= cur_slime->random_slime && cur_slime->random_slime <= 400 && slime_down == true) {
			slimeDOWN(cur_slime, slime_velocity);
			cur_slime->gener = false;
		}

		if(100 <= cur_slime->random_slime && cur_slime->random_slime <= 200 && slime_right == true) {
			slimeRIGHT(cur_slime, slime_velocity);
			cur_slime->gener = false;
		}

		if(1 <= cur_slime->random_slime && cur_slime->random_slime <= 100 && slime_up == true) {
			slimeUP(cur_slime, slime_velocity);
			cur_slime->gener = false;
		}


		if ((1 <= cur_slime->random_slime && cur_slime->random_slime <= 100) && slime_up == false) cur_slime->gener = true;
		else if ((100 <= cur_slime->random_slime && cur_slime->random_slime <= 200) && slime_right == false) cur_slime->gener = true;
		else if ((200 <= cur_slime->random_slime && cur_slime->random_slime <= 300) && slime_left == false) cur_slime->gener = true;
		else if ((300 <= cur_slime->random_slime && cur_slime->random_slime <= 400) && slime_down == false) cur_slime->gener = true;
		

		cur_slime = cur_slime->next;
	}
}



/*void slimeMovePro(int slime_velocity) {
	for (int i = 0; i < number_of_slimes; i++) {
		if(map[(slime_R[i].y - 1) / 64][(slime_R[i].x) / 64] == 0 && map[(slime_R[i].y - 1) / 64][(slime_R[i].x + 63) / 64] == 0 && slime_up == true) {//move_up
			slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
		    if(slime_R[i].y < 0) slime_R[i].y = 0;
		    if(slime_R[i].y > 1280) slime_R[i].y = 1280;
		    slime_R[i].y -= slime_velocity;
			slime_down = false;
		}
		else if(map[(slime_R[i].y) / 64][(slime_R[i].x + 63) / 64] == 0 && map[(slime_R[i].y + 63) / 64][(slime_R[i].x + 63) / 64] == 0 && slime_right == true) {//move_right
			slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
		    if(slime_R[i].x < 0) slime_R[i].x = 0;
		    if(slime_R[i].x > 1600) slime_R[i].x = 1600;
		    slime_R[i].x += slime_velocity;
			slime_left = false;
		}
		else if (map[(slime_R[i].y) / 64][(slime_R[i].x - 1) / 64] == 0 && map[(slime_R[i].y + 63) / 64][(slime_R[i].x - 1) / 64] == 0 && slime_left == true) {//move_left
			slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
		    if(slime_R[i].x < 0) slime_R[i].x = 0;
		    if(slime_R[i].x > 1600) slime_R[i].x = 1600;
		    slime_R[i].x -= slime_velocity;
			slime_right = false;
		}
		else if(map[(slime_R[i].y + 63) / 64][(slime_R[i].x) / 64] == 0 && map[(slime_R[i].y + 63) / 64][(slime_R[i].x + 63) / 64] == 0 && slime_down == true) {//move_down
			slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
		    if(slime_R[i].y < 0) slime_R[i].y = 0;
		    if(slime_R[i].y > 1280) slime_R[i].y = 1280;
		    slime_R[i].y += slime_velocity;
			slime_up = false;
		}
		else {
			slimeTex[i] = LoadTexture("resource/ast/enemies/Slime.png", renderer);
			slime_up = true;
			slime_down = true;
			slime_left = true;
			slime_right = true;
		}
	}
}*/

void SDL_RENDERS_SLIMES() {
	t_slime *cur_slime = slimes;

    for (int i = 0; cur_slime != NULL; i++) {
        SDL_RenderCopy(renderer, cur_slime->slimeTex, NULL, &(cur_slime->slime_R));
		cur_slime = cur_slime->next; 
	}
}
