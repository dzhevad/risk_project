


#include <stdio.h>
#include <stdlib.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>


#define LENGHT 800  // tool
#define WIDTH 650  //  arz

void draw_map();

int main(void) {
	
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	al_install_mouse();
	al_install_keyboard();
	al_init_primitives_addon();
	
	
	
	
	
	ALLEGRO_DISPLAY *display = al_create_display(LENGHT , WIDTH);
	ALLEGRO_FONT *font = al_load_ttf_font("arial.ttf" , 24 , 0);
	ALLEGRO_FONT *exitfont = al_load_ttf_font("arial.ttf" , 10 , 0);
	ALLEGRO_FONT *tfont = al_load_ttf_font("arial.ttf" , 15 , 0);
	ALLEGRO_FONT *nobatfont = al_load_ttf_font("arial.ttf" , 10 , 0);
	ALLEGRO_BITMAP *cursor = al_load_bitmap("cursor.tga");
	ALLEGRO_MOUSE_STATE curstate;			// gereftan mogheiat mouse
	ALLEGRO_KEYBOARD_STATE keystate;		// gereftan keyboard 
	 
	
	
	al_hide_mouse_cursor(display);			// hide mouse 
	
	
	
	
	
	if(!al_init()){
		printf("Eror init!\n");
	}
	if(!display){
		printf("Eror Display!\n");
	}
	
	if(!font){
		printf("Eror font!\n");
	}
	
	if(!exitfont){
		printf("Eror font!\n");
	}
	if(!cursor){
		printf("Eror cursor!\n");
	}
	if(!al_install_keyboard()){
		printf("Eror keyboard!\n");
	}
	if(!nobatfont){
		printf("Eror font!\n");
	}
	if(!font){
		printf("Eror font!\n");
	}
	
	
	
	
	char t[2] = "4";
	
	
	
	
	
	
	
	
	
	
	
	
	// rgb = red + green + blue = (0-255) + (0 - 255) + (0 -255) 
	

	do {
		al_clear_to_color(al_map_rgb(255 , 255 ,255));
		
		draw_map();
		al_draw_rectangle(350 , 50 , 470 , 100 , al_map_rgb(0,0,0),2);
		al_draw_text(tfont ,al_map_rgb(0,0,0) , 355 , 70 , 0 , "nobat bazikon");
		al_draw_text(tfont ,al_map_rgb(0,0,0) , 450 , 70 , 0 , t);
		
		al_draw_rectangle(480 , 62 , 530 , 87 , al_map_rgb(0,0,0),2);
		al_draw_rectangle(533 , 62 , 583 , 87 , al_map_rgb(0,0,0),2);
		al_draw_rectangle(586 , 62 , 636 , 87 , al_map_rgb(0,0,0),2);
		al_draw_text(nobatfont ,al_map_rgb(0,0,0) , 483 , 70 , 0 , "Datryaft");
		al_draw_text(nobatfont ,al_map_rgb(0,0,0) , 536 , 70 , 0 , "nabard");
		al_draw_text(nobatfont ,al_map_rgb(0,0,0) , 589 , 70 , 0 , "jabejayi");
		
		al_get_mouse_state(&curstate);
		al_draw_bitmap(cursor , curstate.x , curstate.y , 0);
		
		
		al_draw_text(exitfont ,al_map_rgb(0,0,0) , 724 , 640 , 0 , "Press Esc to exit");
		
		

		
		al_get_keyboard_state(&keystate);
		
		al_rest(0.01);
		al_flip_display();
	}while(!al_key_down(&keystate,ALLEGRO_KEY_ESCAPE));
	
	
	
	return 0;
}


void draw_map(){
	// drawing darya 
	al_draw_filled_rectangle(200 , 250 , 300 , 300 , al_map_rgb(0,255,255));	
	al_draw_filled_rectangle(200 , 300 , 300 , 350 , al_map_rgb(0,255,255));	
	al_draw_filled_rectangle(300 , 300 , 400 , 350 , al_map_rgb(0,255,255));	
	al_draw_filled_rectangle(200 , 350 , 300 , 400 , al_map_rgb(0,255,255));	
	al_draw_filled_rectangle(100 , 450 , 200 , 500 , al_map_rgb(0,255,255));	
	al_draw_filled_rectangle(200 , 450 , 300 , 500 , al_map_rgb(0,255,255));
	al_draw_filled_rectangle(500 , 350 , 600 , 400,  al_map_rgb(0,255,255));	
	al_draw_filled_rectangle(600 , 350 , 700 , 400 , al_map_rgb(0,255,255));	
	al_draw_filled_rectangle(500 , 400 , 600 , 450,  al_map_rgb(0,255,255));	
	al_draw_filled_rectangle(600 , 400 , 700 , 450 , al_map_rgb(0,255,255));
	al_draw_filled_rectangle(500 , 450 , 600 , 500,  al_map_rgb(0,255,255));	
	al_draw_filled_rectangle(600 , 450 , 700 , 500 , al_map_rgb(0,255,255));
	al_draw_filled_rectangle(400 , 450 , 500 , 500,  al_map_rgb(0,255,255));
	
	
	// drawing USA
	al_draw_filled_rectangle(100 , 150 , 200 , 200 , al_map_rgb(128,128,128));  // sarzamin 1
	al_draw_filled_rectangle(200 , 150 , 300 , 200 , al_map_rgb(128,128,128));	// sarzamin 2
	al_draw_filled_rectangle(100 , 200 , 200 , 250 , al_map_rgb(128,128,128));	// sarzamin 7
	al_draw_filled_rectangle(200 , 200 , 300 , 250 , al_map_rgb(128,128,128));	// sarzamin 8
	al_draw_filled_rectangle(100 , 250 , 200 , 300 , al_map_rgb(128,128,128));	// sarzamin 13
	al_draw_filled_rectangle(100 , 300 , 200 , 350 , al_map_rgb(128,128,128));	// sarzamin 18
	al_draw_filled_rectangle(100 , 350 , 200 , 400 , al_map_rgb(128,128,128));	// sarzamin 22
	al_draw_filled_rectangle(100 , 400 , 200 , 450 , al_map_rgb(128,128,128));	// sarzamin 25
	al_draw_filled_rectangle(200 , 400 , 300 , 450 , al_map_rgb(128,128,128));	// sarzamin 26
	
	
	// drawing Europe
	
	al_draw_filled_rectangle(300 , 150 , 400 , 200 , al_map_rgb(200,0,0));	// sarzamin 3
	al_draw_filled_rectangle(400 , 150 , 500 , 200 , al_map_rgb(200,0,0));	// sarzamin 4
	al_draw_filled_rectangle(300 , 200 , 400 , 250 , al_map_rgb(200,0,0));	// sarzamin 9
	al_draw_filled_rectangle(400 , 200 , 500 , 250 , al_map_rgb(200,0,0));	// sarzamin 10
	al_draw_filled_rectangle(300 , 250 , 400 , 300 , al_map_rgb(200,0,0));	// sarzamin 14
	al_draw_filled_rectangle(400 , 250 , 500 , 300 , al_map_rgb(200,0,0));	// sarzamin 15
	
	// drawing Asia
	
	al_draw_filled_rectangle(500 , 150 , 600 , 200 , al_map_rgb(0,128,0));	// sarzamin 5
	al_draw_filled_rectangle(600 , 150 , 700 , 200 , al_map_rgb(0,128,0));	// sarzamin 5
	al_draw_filled_rectangle(500 , 200 , 600 , 250 , al_map_rgb(0,128,0));	// sarzamin 11
	al_draw_filled_rectangle(600 , 200 , 700 , 250 , al_map_rgb(0,128,0));	// sarzamin 12
	al_draw_filled_rectangle(500 , 250 , 600 , 300 , al_map_rgb(0,128,0));	// sarzamin 16
	al_draw_filled_rectangle(600 , 250 , 700 , 300 , al_map_rgb(0,128,0));	// sarzamin 17
	al_draw_filled_rectangle(500 , 300 , 600 , 350 , al_map_rgb(0,128,0));	// sarzamin 20
	al_draw_filled_rectangle(600 , 300 , 700 , 350 , al_map_rgb(0,128,0));	// sarzamin 21
	
	
	
	
	// drawing africa 
	
	al_draw_filled_rectangle(400 , 300 , 500 , 350 , al_map_rgb(255,255,0));	// sarzamin 19
	al_draw_filled_rectangle(300 , 350 , 400 , 400 , al_map_rgb(255,255,0));	// sarzamin 23
	al_draw_filled_rectangle(400 , 350 , 500 , 400 , al_map_rgb(255,255,0));	// sarzamin 24
	al_draw_filled_rectangle(300 , 400 , 400 , 450 , al_map_rgb(255,255,0));	// sarzamin 27
	al_draw_filled_rectangle(400 , 400 , 500 , 450 , al_map_rgb(255,255,0));	// sarzamin 28
	al_draw_filled_rectangle(300 , 450 , 400 , 500 , al_map_rgb(255,255,0));	// sarzamin 29
	
	for(int i = 1 ; i<=6 ; i++){
		for(double j =1.5 ; j<=4.5 ; j = j+0.5){
			al_draw_rectangle(i*100 , j*100 , i*100+100 , j*100+50 , al_map_rgb(0,0,0),2);
		}
	}
	
	
}
