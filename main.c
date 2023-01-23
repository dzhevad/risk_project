// library:     C:\Program Files (x86)\Embarcadero\Dev-Cpp\allegro\lib
// include:     C:\Program Files (x86)\Embarcadero\Dev-Cpp\allegro\include



#include <stdio.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_image.h>
#include <stdlib.h>

#define LENGHT 600  // tool
#define WIDTH 350  //  arz



int main(void) {
	al_init();
	ALLEGRO_DISPLAY *display = NULL;
	display = al_create_display(LENGHT , WIDTH);
	
	
	
	
	
	if(!al_init()){
		printf("Eror init. \n");
		return 0;
	}
	if(!display){
		printf("Eror display. \n");
		return 0;
	}
	
	
	
	
	
	// rgb = red + green + blue = (0-255) + (0 - 255) + (0 -255) 
	
	
	
	while(1){
		al_clear_to_color(al_map_rgb(255 , 255 ,255));
		
		
		al_flip_display();
	}	
	
	
	
	return 0;
}




/*void draw_map(){
	ALLEGRO_COLOR black = al_map_rgb(0,0,0);
	al_draw_rectangle()
}*/


/*for(int i= 0 ; i++ ; i<6){
			for(int j=0 ; j++ ; j<7){
				al_draw_rectangle(100*i , 50*j , 100*i+100 , 50*j+50 ,al_map_rgb(255,0,0));
			}
		}*/