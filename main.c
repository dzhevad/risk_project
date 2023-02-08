// library:     C:\Program Files (x86)\Embarcadero\Dev-Cpp\allegro\lib
// include:     C:\Program Files (x86)\Embarcadero\Dev-Cpp\allegro\include



#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<conio.h>

#include<allegro5/allegro.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>


#define LENGHT 800  // tool
#define WIDTH 650  //  arz

void draw_map();

void print();

void esmgozari(); 

void pakhsh_zamin(int tedad_bazikon);

int daryaft_sarbaz(int tedad_zamin , char bazikon ); 

void pakhsh_khodkar_sarbaz();

void jagozari_sarbaza1();

void jagozari_sarbaz2( char nobat , int tedad_sarbaz);

void nabard(char player);

void jabejayi(char nobat);

int tas();

void sort(int array[] , int size);

int check( int x , int y , char player );

int check_hamsaye(int x , int y , int i , int j);



struct  player1{
	int sarbaz ;
	int tedad_zamin;
}player1;

struct  player2{
	int sarbaz;
	int tedad_zamin;
}player2;

struct  player3{
	int sarbaz;
	int tedad_zamin;
}player3;

struct  player4{
	int sarbaz;
	int tedad_zamin;
}player4;

struct zamin{
	char esm[7][6][1];
	char malek[7][6][1] ;
	int tedad_sarbaz[7][6];
}zamin;

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
	ALLEGRO_FONT *font1 = al_load_ttf_font("arial.ttf" , 10 , 0);
	ALLEGRO_FONT *font2 = al_load_ttf_font("arial.ttf" , 15 , 0);
	ALLEGRO_MOUSE_STATE curstate;			// gereftan mogheiat mouse
	ALLEGRO_KEYBOARD_STATE keystate;		// gereftan keyboard 
	 
	

	// rgb = red + green + blue = (0-255) + (0 - 255) + (0 -255) 
	
	
	
	
	if(!al_init()){
		printf("Eror init!\n");
	}
	if(!display){
		printf("Eror Display!\n");
	}
	
	if(!font){
		printf("Eror font!\n");
	}
	
	if(!font1){
		printf("Eror font!\n");
	}
	if(!font2){
		printf("Eror font!\n");
	}
	if(!al_install_keyboard()){
		printf("Eror keyboard!\n");
	}
	if(!al_install_mouse()){
		printf("Eror keyboard!\n");
	}
	
	
	esmgozari();
	
	int tedad_bazikon = 0 ;
	
	
	
	
	do{
		al_clear_to_color(al_map_rgb(255,255,255));
		al_get_mouse_state(&curstate);
		
		al_draw_text(font , al_map_rgb(0,0,0) , 170 , 250 , 0 , "tedad bazikon ra moshakhas konid :");
		
		al_draw_filled_rectangle(200 , 300 , 300 , 400 ,al_map_rgb(0,255,0));	
		al_draw_text(font , al_map_rgb(0,0,0) , 240 , 340 , 0 , "2");
		if(curstate.x > 200 && curstate.x <300 && curstate.y>300 && curstate.y<400){
			if(al_mouse_button_down(&curstate,1)){
		 		tedad_bazikon = 2;
			}
		}
		
		
		al_draw_filled_rectangle(310 , 300 , 410 , 400 ,al_map_rgb(0,255,0));	
		al_draw_text(font , al_map_rgb(0,0,0) , 350 , 340 , 0 , "3");
		
		if(curstate.x > 310 && curstate.x <410 && curstate.y>300 && curstate.y<400){
			if(al_mouse_button_down(&curstate,1)){
		 		tedad_bazikon = 3;
			}
		}
		
		al_draw_filled_rectangle(420 , 300 , 520 , 400 ,al_map_rgb(0,255,0));	
		al_draw_text(font , al_map_rgb(0,0,0) , 460 , 340 , 0 , "4");
		
		if(curstate.x > 420 && curstate.x <520 && curstate.y>300 && curstate.y<400){
			if(al_mouse_button_down(&curstate,1)){
		 		tedad_bazikon = 4;
			}
		}
		
		
		al_flip_display();
	}while( tedad_bazikon == 0);
	
	
	
	switch (tedad_bazikon){
		case 2 :{
			player1.sarbaz = 30;
			player2.sarbaz = 30;
			break;
		}
		case 3 :{
			player1.sarbaz = 25;
			player2.sarbaz = 25;
			player3.sarbaz = 25;
			break;
		}
		case 4 :{
			player1.sarbaz = 20;
			player2.sarbaz = 20;
			player3.sarbaz = 20;
			player4.sarbaz = 20;
			break;
		}
	}
	
	
	
	pakhsh_zamin(tedad_bazikon);
	pakhsh_khodkar_sarbaz();
	
	
	
		

	
	jagozari_sarbaza1();
	

	int nobat=1;
	char tmp[10];
	
	for(nobat = 1 ; nobat <= tedad_bazikon ; nobat++){
		al_clear_to_color(al_map_rgb(255 , 255 ,255));
		
		al_get_mouse_state(&curstate);
		al_get_keyboard_state(&keystate);
		
		draw_map();
		print();
		
		al_draw_rectangle(350 , 50 , 470 , 100 , al_map_rgb(0,0,0),2);
		al_draw_text(font2 ,al_map_rgb(0,0,0) , 355 , 70 , 0 , "nobat bazikon");
		al_draw_text(font1 ,al_map_rgb(0,0,0) , 724 , 640 , 0 , "Press Esc to exit");
		
		al_flip_display();
		
		
		
		if(nobat == 1 && player1.tedad_zamin > 0 ){
			al_draw_text(font2 ,al_map_rgb(0,0,0) , 450 , 70 , 0 ,  "1");
			al_rest(1);
			
			itoa(nobat, tmp, 10);
			
			player1.sarbaz =  daryaft_sarbaz(player1.tedad_zamin , '1' );
			jagozari_sarbaz2(  '1' , player1.sarbaz);
			nabard('1');
			
			
			if(al_key_down(&keystate,ALLEGRO_KEY_ESCAPE)){
				break;
			}
		}
		if(nobat == 2 && player2.tedad_zamin > 0 ){
			al_draw_text(font2 ,al_map_rgb(0,0,0) , 450 , 70 , 0 ,  "2");
			
			
			itoa(nobat, tmp, 10);
			
			player2.sarbaz =  daryaft_sarbaz(player2.tedad_zamin , '2' );
			jagozari_sarbaz2(  '2' , player1.sarbaz);
			nabard('2');
			al_rest(1);
			if(al_key_down(&keystate,ALLEGRO_KEY_ESCAPE)){
				break;
			}
		}
		if(nobat == 3 && player3.tedad_zamin > 0 ){
			al_draw_text(font2 ,al_map_rgb(0,0,0) , 450 , 70 , 0 ,  "3");
			
			
			itoa(nobat, tmp, 10);
			
			player3.sarbaz =  daryaft_sarbaz(player3.tedad_zamin , '3' );
			jagozari_sarbaz2(  '3' , player1.sarbaz);
			nabard('3');
			al_rest(1);
			if(al_key_down(&keystate,ALLEGRO_KEY_ESCAPE)){
				break;
			}
		}
		if(nobat == 4 && player4.tedad_zamin > 0 ){
			al_draw_text(font2 ,al_map_rgb(0,0,0) , 450 , 70 , 0 ,  "4");
			
			
			itoa(nobat, tmp, 10);
			
			player4.sarbaz =  daryaft_sarbaz(player4.tedad_zamin , '3' );
			jagozari_sarbaz2(  '4' , player1.sarbaz);
			nabard('4');
			al_rest(1);
			if(al_key_down(&keystate,ALLEGRO_KEY_ESCAPE)){
				break;
			}
		}
		


		if(nobat == tedad_bazikon){
			nobat = 1;
		}
		
		if(al_key_down(&keystate,ALLEGRO_KEY_ESCAPE)){
			break;
		}
		
		
		if(player1.tedad_zamin == 29 || player2.tedad_zamin == 29 || player3.tedad_zamin ==29 || player4.tedad_zamin == 29){
			break;
		}
		
		al_flip_display();
		
		
		
	}
	
	
	
	while(!al_key_down(&keystate , ALLEGRO_KEY_ESCAPE)){
		al_get_keyboard_state(&keystate);
		
		draw_map();
		
		
		al_draw_filled_rectangle(350,300,550,350,al_map_rgb(255,255,255));
		
		
		if(player1.tedad_zamin == 29){
			al_draw_text(font , al_map_rgb(0,0,0) , 355 , 310 , 0 , "Player 1 Won!!!");
		}
		if(player2.tedad_zamin == 29){
			al_draw_text(font , al_map_rgb(0,0,0) , 355 , 310 , 0 , "Player 2 Won!!!");
		}
		if(player3.tedad_zamin == 29){
			al_draw_text(font , al_map_rgb(0,0,0) , 355 , 310 , 0 , "Player 3 Won!!!");
		}
		if(player4.tedad_zamin == 29){
			al_draw_text(font , al_map_rgb(0,0,0) , 355 , 310 , 0 , "Player 4 Won!!!");
		}
		
		al_flip_display();
	}





	al_destroy_display(display);
	al_destroy_font(font);
	al_destroy_font(font1);
	al_destroy_font(font2);
	
	
	return 0;
}


void draw_map(){
		ALLEGRO_FONT *font1 = al_load_ttf_font("arial.ttf" , 10 , 0);
		ALLEGRO_FONT *font2 = al_load_ttf_font("arial.ttf" , 15 , 0);
		al_clear_to_color(al_map_rgb(255,255,255));
		al_draw_rectangle(350 , 50 , 470 , 100 , al_map_rgb(0,0,0),2);
		al_draw_text(font2 ,al_map_rgb(0,0,0) , 355 , 70 , 0 , "nobat bazikon");
		al_draw_text(font1 ,al_map_rgb(0,0,0) , 724 , 640 , 0 , "Press Esc to exit");
	  
	// drawing darya 
	
	ALLEGRO_COLOR darya = al_map_rgb(0,255,255);
	
	al_draw_filled_rectangle(200 , 250 , 300 , 300 , darya );	
	al_draw_filled_rectangle(200 , 300 , 300 , 350 , darya );	
	al_draw_filled_rectangle(300 , 300 , 400 , 350 , darya );	
	al_draw_filled_rectangle(200 , 350 , 300 , 400 , darya );	
	al_draw_filled_rectangle(100 , 450 , 200 , 500 , darya );	
	al_draw_filled_rectangle(200 , 450 , 300 , 500 , darya );
	al_draw_filled_rectangle(500 , 350 , 600 , 400 , darya );	
	al_draw_filled_rectangle(600 , 350 , 700 , 400 , darya );	
	al_draw_filled_rectangle(500 , 400 , 600 , 450 , darya );	
	al_draw_filled_rectangle(600 , 400 , 700 , 450 , darya );
	al_draw_filled_rectangle(400 , 450 , 500 , 500 , darya );
	al_draw_filled_rectangle(500 , 450 , 600 , 500 , darya );	
	al_draw_filled_rectangle(600 , 450 , 700 , 500 , darya );
	
	

	// drawing USA
	
	ALLEGRO_COLOR amrica =  al_map_rgb(128,128,128);
	
	al_draw_filled_rectangle(100 , 150 , 200 , 200 , amrica );  // sarzamin 0.0
	al_draw_filled_rectangle(200 , 150 , 300 , 200 , amrica );	// sarzamin 0.1
	al_draw_filled_rectangle(100 , 200 , 200 , 250 , amrica );	// sarzamin 1.0
	al_draw_filled_rectangle(200 , 200 , 300 , 250 , amrica );	// sarzamin 1.1
	al_draw_filled_rectangle(100 , 250 , 200 , 300 , amrica );	// sarzamin 2.0
	al_draw_filled_rectangle(100 , 300 , 200 , 350 , amrica );	// sarzamin 3.0
	al_draw_filled_rectangle(100 , 350 , 200 , 400 , amrica );	// sarzamin 4.0
	al_draw_filled_rectangle(100 , 400 , 200 , 450 , amrica );	// sarzamin 5.0
	al_draw_filled_rectangle(200 , 400 , 300 , 450 , amrica );	// sarzamin 5.1
	
	
	// drawing Europe
	
	ALLEGRO_COLOR europe =  al_map_rgb(200,0,0);
	
	al_draw_filled_rectangle(300 , 150 , 400 , 200 , europe );	// sarzamin 0.2
	al_draw_filled_rectangle(400 , 150 , 500 , 200 , europe );	// sarzamin 0.3
	al_draw_filled_rectangle(300 , 200 , 400 , 250 , europe );	// sarzamin 1.2
	al_draw_filled_rectangle(400 , 200 , 500 , 250 , europe );	// sarzamin 1.3
	al_draw_filled_rectangle(300 , 250 , 400 , 300 , europe );	// sarzamin 2.2
	al_draw_filled_rectangle(400 , 250 , 500 , 300 , europe );	// sarzamin 2.3
	
	// drawing Asia
	
	ALLEGRO_COLOR asia = al_map_rgb(0,128,0);
	
	al_draw_filled_rectangle(500 , 150 , 600 , 200 , asia );	// sarzamin 0.4
	al_draw_filled_rectangle(600 , 150 , 700 , 200 , asia );	// sarzamin 0.5
	al_draw_filled_rectangle(500 , 200 , 600 , 250 , asia );	// sarzamin 1.4
	al_draw_filled_rectangle(600 , 200 , 700 , 250 , asia );	// sarzamin 1.5
	al_draw_filled_rectangle(500 , 250 , 600 , 300 , asia );	// sarzamin 2.4
	al_draw_filled_rectangle(600 , 250 , 700 , 300 , asia );	// sarzamin 2.5
	al_draw_filled_rectangle(500 , 300 , 600 , 350 , asia );	// sarzamin 3.4
	al_draw_filled_rectangle(600 , 300 , 700 , 350 , asia );	// sarzamin 3.5
	
	
	
	
	// drawing africa 
	
	ALLEGRO_COLOR africa = al_map_rgb(255,255,0); 
	
	al_draw_filled_rectangle(400 , 300 , 500 , 350 , africa );	// sarzamin 3.3
	al_draw_filled_rectangle(300 , 350 , 400 , 400 , africa );	// sarzamin 4.2
	al_draw_filled_rectangle(400 , 350 , 500 , 400 , africa );	// sarzamin 4.3
	al_draw_filled_rectangle(300 , 400 , 400 , 450 , africa );	// sarzamin 5.2
	al_draw_filled_rectangle(400 , 400 , 500 , 450 , africa );	// sarzamin 5.3
	al_draw_filled_rectangle(300 , 450 , 400 , 500 , africa );	// sarzamin 6.2
	
	

	
	
	for(int i = 1 ; i<=7 ; i++){
		for(int j =1 ; j<=6 ; j ++){
			al_draw_rectangle(j*100 , i*50+100 , j*100+100 , i*50+150 , al_map_rgb(0,0,0),2);	
		}
	}
	
	
}



void print(){
	ALLEGRO_FONT *font = al_load_ttf_font("arial.ttf" , 15 , 0);
	ALLEGRO_FONT *font1 = al_load_ttf_font("arial.ttf" , 10 , 0);
	char tmp[10];
	for(int i = 1 ; i<=7 ; i++){
		for(int j =1 ; j<=6 ; j ++){
			if(zamin.esm[i-1][j-1][0] != 'D'){
				tmp[0] = '\0';
				al_draw_text(font1 ,al_map_rgb(0,0,0) , j*100+5 , i*50+105 , 0 , "player ");
		
				itoa(zamin.tedad_sarbaz[i-1][j-1], tmp, 10);
				
				al_draw_text(font ,al_map_rgb(0,0,0) , j*100+50 , i*50+120 , 0 ,tmp);
				
				al_draw_text(font1 ,al_map_rgb(0,0,0) , j*100+40 , i*50+110 , 0 , zamin.malek[i-1][j-1]);
			}
		}
	}
}


void esmgozari(){
	
	// Usa		Black 
	
	zamin.esm[0][0][0] = 'B';	// 0
	zamin.esm[0][1][0] = 'B';	// 1
	zamin.esm[1][0][0] = 'B';	// 6
	zamin.esm[1][1][0] = 'B';	// 7
	zamin.esm[2][0][0] = 'B';	// 12
	zamin.esm[3][0][0] = 'B';	// 18
	zamin.esm[4][0][0] = 'B';	// 24
	zamin.esm[5][0][0] = 'B';	// 30
	zamin.esm[5][1][0] = 'B';	// 31
	
	// Europe	Red  
	
	zamin.esm[0][2][0] = 'R';	// 2
	zamin.esm[0][3][0] = 'R';	// 3
	zamin.esm[1][2][0] = 'R';	// 8
	zamin.esm[1][3][0] = 'R';	// 9
	zamin.esm[2][2][0] = 'R';	// 14
	zamin.esm[2][3][0] = 'R';	// 15
	
	// Asia		Green	
	
	zamin.esm[0][4][0] = 'G';	// 4
	zamin.esm[0][5][0] = 'G';	// 5
	zamin.esm[1][4][0] = 'G';	// 10
	zamin.esm[1][5][0] = 'G';	// 11
	zamin.esm[2][4][0] = 'G';	// 16
	zamin.esm[2][5][0] = 'G';	// 17
	zamin.esm[3][4][0] = 'G';	// 22
	zamin.esm[3][5][0] = 'G';	// 23
	
	// Africa	Yellow
	
	zamin.esm[3][3][0] = 'Y';	// 21
	zamin.esm[4][2][0] = 'Y';	// 26
	zamin.esm[4][3][0] = 'Y';	// 27
	zamin.esm[5][2][0] = 'Y';	// 32
	zamin.esm[5][3][0] = 'Y';	// 33
	zamin.esm[6][2][0] = 'Y';	// 38
	
	// Darya 	D
	
	zamin.esm[2][1][0] = 'D';	// 13
	zamin.esm[3][1][0] = 'D';	// 19
	zamin.esm[3][2][0] = 'D';	// 20
	zamin.esm[4][1][0] = 'D';	// 25
	zamin.esm[4][4][0] = 'D';	// 28
	zamin.esm[4][5][0] = 'D';	// 29
	zamin.esm[5][4][0] = 'D';	// 34
	zamin.esm[5][5][0] = 'D';	// 35
	zamin.esm[6][0][0] = 'D';	// 36
	zamin.esm[6][1][0] = 'D';	// 37
	zamin.esm[6][3][0] = 'D';	// 39
	zamin.esm[6][4][0] = 'D';	// 40
	zamin.esm[6][5][0] = 'D';	// 41
	
	
	
}


// barresi 

void pakhsh_zamin(int tedad_bazikon){
	if(tedad_bazikon == 2 ){
		zamin.malek[0][0][0] = '1';
		zamin.malek[0][1][0] = '1';
		zamin.malek[1][0][0] = '1';
		zamin.malek[1][1][0] = '1';
		zamin.malek[2][0][0] = '1';
		zamin.malek[3][0][0] = '1';
		zamin.malek[0][2][0] = '1';
		zamin.malek[1][2][0] = '1';
		zamin.malek[0][3][0] = '1';
		zamin.malek[1][3][0] = '1';
		zamin.malek[2][3][0] = '1';
		zamin.malek[3][3][0] = '1';
		zamin.malek[4][3][0] = '1';
		zamin.malek[4][2][0] = '1';
		zamin.malek[3][4][0] = '1';

		zamin.malek[0][4][0] = '2';
		zamin.malek[0][5][0] = '2';
		zamin.malek[1][4][0] = '2';
		zamin.malek[1][5][0] = '2';
		zamin.malek[2][2][0] = '2';
		zamin.malek[4][0][0] = '2';
		zamin.malek[5][0][0] = '2';
		zamin.malek[5][1][0] = '2';
		zamin.malek[5][2][0] = '2';
		zamin.malek[5][3][0] = '2';
		zamin.malek[2][4][0] = '2';
		zamin.malek[2][5][0] = '2';
		zamin.malek[3][5][0] = '2';
		zamin.malek[6][2][0] = '2';
	}

	if(tedad_bazikon == 3 ){
		zamin.malek[0][0][0] = '1';
		zamin.malek[0][1][0] = '1';
		zamin.malek[1][4][0] = '1';
		zamin.malek[1][3][0] = '1';
		zamin.malek[2][0][0] = '1';
		zamin.malek[2][2][0] = '1';
		zamin.malek[4][0][0] = '1';
		zamin.malek[3][5][0] = '1';
		zamin.malek[5][0][0] = '1';

		zamin.malek[0][2][0] = '2';
		zamin.malek[0][3][0] = '2';
		zamin.malek[1][2][0] = '2';
		zamin.malek[1][1][0] = '2';
		zamin.malek[2][3][0] = '2';
		zamin.malek[2][4][0] = '2';
		zamin.malek[3][4][0] = '2';
		zamin.malek[3][3][0] = '2';
		zamin.malek[5][1][0] = '2';
		zamin.malek[5][3][0] = '2';

		zamin.malek[0][4][0] = '3';
		zamin.malek[0][5][0] = '3';
		zamin.malek[1][0][0] = '3';
		zamin.malek[1][5][0] = '3';
		zamin.malek[2][5][0] = '3';
		zamin.malek[4][2][0] = '3';
		zamin.malek[3][0][0] = '3';
		zamin.malek[4][3][0] = '3';
		zamin.malek[5][2][0] = '3';
		zamin.malek[6][2][0] = '3';

	}

	if(tedad_bazikon == 4 ){
		zamin.malek[0][0][0] = '1';
		zamin.malek[0][1][0] = '1';
		zamin.malek[1][2][0] = '1';
		zamin.malek[1][1][0] = '1';
		zamin.malek[2][5][0] = '1';
		zamin.malek[5][3][0] = '1';
		zamin.malek[4][0][0] = '1';

		zamin.malek[0][2][0] = '2';
		zamin.malek[0][3][0] = '2';
		zamin.malek[1][0][0] = '2';
		zamin.malek[1][5][0] = '2';
		zamin.malek[5][2][0] = '2';
		zamin.malek[5][1][0] = '2';
		zamin.malek[3][5][0] = '2';

		zamin.malek[0][4][0] = '3';
		zamin.malek[0][5][0] = '3';
		zamin.malek[2][0][0] = '3';
		zamin.malek[2][2][0] = '3';
		zamin.malek[5][0][0] = '3';
		zamin.malek[4][3][0] = '3';
		zamin.malek[3][4][0] = '3';
		
		zamin.malek[1][4][0] = '4';
		zamin.malek[1][3][0] = '4';
		zamin.malek[2][3][0] = '4';
		zamin.malek[2][4][0] = '4';
		zamin.malek[6][2][0] = '4';
		zamin.malek[3][0][0] = '4';
		zamin.malek[3][3][0] = '4';
		zamin.malek[4][2][0] = '4';
		
		

	}
	
}



int daryaft_sarbaz(int tedad_zamin , char bazikon ){
	int i = tedad_zamin/3;
	// amrica
	if(zamin.malek [0][0][0] == bazikon && zamin.malek[0][1][0] == bazikon && zamin.malek[1][0][0] == bazikon && zamin.malek[1][1][0] == bazikon && zamin.malek[2][0][0] == bazikon && zamin.malek[3][0][0] == bazikon && zamin.malek[4][0][0] == bazikon && zamin.malek[5][0][0] == bazikon&& zamin.malek[5][1][0] == bazikon ){
		i = i+3;
	}
	// europe
	if( zamin.malek[0][2][0] == bazikon && zamin.malek[0][3][0] == bazikon && zamin.malek[1][2][0] == bazikon && zamin.malek[1][3][0] == bazikon && zamin.malek[2][2][0] == bazikon && zamin.malek[2][3][0] == bazikon ){
		i = i + 4 ;
	}
	// asia
	if( zamin.malek[0][4][0] == bazikon &&zamin.malek[0][5][0] == bazikon && zamin.malek[1][4][0] == bazikon && zamin.malek[1][5][0] == bazikon && zamin.malek[2][4][0] == bazikon && zamin.malek[2][5][0] == bazikon && zamin.malek[3][4][0] == bazikon && zamin.malek[3][5][0] == bazikon ){
		i = i + 4;
	}
	// africa
	if( zamin.malek[3][3][0] == bazikon && zamin.malek[4][2][0] == bazikon && zamin.malek[4][3][0] == bazikon && zamin.malek[5][2][0] == bazikon && zamin.malek[5][3][0] == bazikon && zamin.malek[6][2][0] == bazikon ){
		i = i + 4;
	}
	return i;
}






void pakhsh_khodkar_sarbaz(){


	for(int i = 0 ; i<7 ; i++){
		for(int j=0  ; j<6 ; j++ ){
			switch(zamin.malek[i][j][0]){
				case  '1' :{
					zamin.tedad_sarbaz[i][j] = 1;
					player1.sarbaz--;
					break;
				}
				case  '2' : {
					zamin.tedad_sarbaz[i][j] = 1;
					player2.sarbaz--;
					break;
				}
				case  '3' : {
					zamin.tedad_sarbaz[i][j] = 1;
					player3.sarbaz--;
					break;
				}
				case  '4' : {
					zamin.tedad_sarbaz[i][j] = 1;
					player4.sarbaz--;
					break;
				}
			}	
		}
	}
}



void jagozari_sarbaza1( ){
	ALLEGRO_MOUSE_STATE curstate;
	int i , j;
	int a = 0;
	while(player1.sarbaz != 0 && player2.sarbaz != 0 && player3.sarbaz !=0 && player4.sarbaz != 0){

		a = 0;

		if(player1.sarbaz != 0){
			do{
				al_get_mouse_state(&curstate);
				if(curstate.x > 100 && curstate.x <700 && curstate.y>150 && curstate.y<500){
					if(al_mouse_button_down(&curstate,1)){
						i = (curstate.y-150)/50;
						j = (curstate.x-100)/100;
						a = check( i , j , '1' );
						if(a == 1){
							zamin.tedad_sarbaz[i][j]++;
							player1.sarbaz--;
						}
					}
				}
			}while( a != 1);
		}

		a = 0;

		if(player2.sarbaz != 0){
			do{
				al_get_mouse_state(&curstate);
				if(curstate.x > 100 && curstate.x <700 && curstate.y>150 && curstate.y<500){
					if(al_mouse_button_down(&curstate,1)){
						i = (curstate.y-150)/50;
						j = (curstate.x-100)/100;
						a = check( i , j , '2' );
						if(a == 1){
							zamin.tedad_sarbaz[i][j]++;
							player2.sarbaz--;
						}
					}
				}
			}while( a != 1);
		}

		a = 0;

		if(player3.sarbaz != 0){
			do{
				al_get_mouse_state(&curstate);
				if(curstate.x > 100 && curstate.x <700 && curstate.y>150 && curstate.y<500){
					if(al_mouse_button_down(&curstate,1)){
						i = (curstate.y-150)/50;
						j = (curstate.x-100)/100;
						a = check( i , j , '3' );
						if(a == 1){
							zamin.tedad_sarbaz[i][j]++;
							player3.sarbaz--;
						}
					}
				}
			}while( a != 1);
		}

		a = 0;

		if(player4.sarbaz != 0){
			do{
				al_get_mouse_state(&curstate);
				if(curstate.x > 100 && curstate.x <700 && curstate.y>150 && curstate.y<500){
					if(al_mouse_button_down(&curstate,1)){
						i = (curstate.y-150)/50;
						j = (curstate.x-100)/100;
						a = check( i , j , '4' );
						if(a == 1){
							zamin.tedad_sarbaz[i][j]++;
							player4.sarbaz--;
						}
					}
				}
			}while( a != 1);
		}

	}
}




void jagozari_sarbaz2( char nobat , int tedad_sarbaz){
	ALLEGRO_MOUSE_STATE curstate;
	int a = 0;
	int i,j;
	while(tedad_sarbaz != 0 ){
		a = 0;
		do{
			al_get_mouse_state(&curstate);
			if(curstate.x > 100 && curstate.x <700 && curstate.y>150 && curstate.y<500){
				if(al_mouse_button_down(&curstate,1)){
					i = (curstate.y-150)/50;
					j = (curstate.x-100)/100;
					a = check( i , j , nobat );
					if(a == 1){
						zamin.tedad_sarbaz[i][j]++;
						tedad_sarbaz--;
					}
				}
			}
		}while( a != 1);
	}



}



// barresi shavad


void nabard(char player){

	ALLEGRO_MOUSE_STATE curstate;
	ALLEGRO_KEYBOARD_STATE keystate;
	
	ALLEGRO_FONT *font = al_load_ttf_font("arial.ttf" , 15 , 0);
	int vaziat =0;
	int i , j ;
	int x,y;
	int a , b =0;
	int tas_hamle[3];
	int tas_defa[2];
	while (1){			//? zadan kelid exit 
		al_get_mouse_state(&curstate);
		
	//	al_draw_filled_rectangle(curstate.x , curstate.y , curstate.x+5 , curstate.y+5 , al_map_rgb(0,0,0));
		while(vaziat == 0){
			b = 0;
			al_get_mouse_state(&curstate);
			al_draw_filled_rectangle(200 , 520 , 250 , 550 , al_map_rgb(0,255,0));
			al_draw_text(font , al_map_rgb(0,0,0) , 203 , 523 , 0 , "continue");
			al_draw_filled_rectangle(260 , 520 , 310 , 550 , al_map_rgb(255,0,0));
			al_draw_text(font , al_map_rgb(0,0,0) , 263 , 523 , 0 , "Exit");
			al_flip_display();		
			if(curstate.x > 200 && curstate.x <250 && curstate.y>520 && curstate.y<550){
				if(al_mouse_button_down(&curstate,1)){
				//	printf("%d:%d",curstate.x ,curstate.y);
			 		a = 0;
			 		vaziat = 1;
			 		break;
				}
			}
			if(curstate.x > 260 && curstate.x <310 && curstate.y>520 && curstate.y<550){
				if(al_mouse_button_down(&curstate,1)){
					a=1;
					vaziat = 2;
				}
			}
			if(vaziat == 2){
				break;
			}
		}
		
		draw_map();
		print();
			
			
			
		while(a==0){
			al_get_mouse_state(&curstate);
			
		
			
			if(curstate.x > 100 && curstate.x <700 && curstate.y>150 && curstate.y<500){
				if(al_mouse_button_down(&curstate,1)){
					//	printf("%d:%d",curstate.x ,curstate.y);
					i = (curstate.y-150)/50;
					j = (curstate.x-100)/100;
					a = check( i , j ,player );
				}
			}
		}
		
		
		

		if(a == 1){
			while(b==0){
				al_get_mouse_state(&curstate);
				al_get_keyboard_state(&keystate);
				if( al_key_down(&keystate , ALLEGRO_KEY_PGUP)  && i>0){
					x = i-1 ;
					y = j;
					b = check_hamsaye(x,y,i,j);
				}
				if( al_key_down(&keystate , ALLEGRO_KEY_PGDN)  && i<5){
					x = i+1 ;
					y = j;
					b = check_hamsaye(x,y,i,j);
				}
				if( al_key_down(&keystate , ALLEGRO_KEY_LEFT)  && j>0){
					x = i ;
					y = j-1;
					b = check_hamsaye(x,y,i,j);
				}
				if( al_key_down(&keystate , ALLEGRO_KEY_RIGHT)  && j<5){
					x = i ;
					y = j+1;
					b = check_hamsaye(x,y,i,j);
				}
			
			if(b==1){
				printf("keyboard");
			}
			
			
			
			
			
			/*	if(curstate.x > 100 && curstate.x <700 && curstate.y>150 && curstate.y<500){
					if(al_mouse_button_down(&curstate,1)){
						//	printf("%d:%d",curstate.x ,curstate.y);
						i = (curstate.y-150)/50;
						j = (curstate.x-100)/100;
						b= check( i , j , player );
					}
				}*/
				
				if (b == 1){
					if(zamin.tedad_sarbaz[i][j]>1 && zamin.esm[x][y][0] != 'D' && zamin.malek[x][y][0] != player && check_hamsaye( x ,  y ,  i ,  j) == 1){
						tas_hamle[0] = tas();
						tas_hamle[1] = tas();
						tas_hamle[2] = tas();
						sort(tas_hamle , 3);

						tas_defa[0] = tas();
						tas_defa[1] = tas();
						sort(tas_defa , 2);
						
						// bad az andaktan tas
						if(tas_defa[0]>= tas_hamle[0]){
							zamin.tedad_sarbaz[i][j]--;
						}
						else{
							zamin.tedad_sarbaz[x][y]--;
						}
					
						if(zamin.tedad_sarbaz[i][j]>=3 && zamin.tedad_sarbaz[x][y]>1){
							if(tas_defa[1]>= tas_hamle[1]){
								zamin.tedad_sarbaz[i][j]--;
							}
							else{
								zamin.tedad_sarbaz[x][y]--;
							}
						}								
						if(zamin.tedad_sarbaz[x][y] == 0 ){
							zamin.malek[x][y][0] = player;
						}
					}
				}
				else{
					a = 0;
				}
				
			

			
					
				}
			}
		}
	}




void jabejayi(char nobat){
	ALLEGRO_MOUSE_STATE curstate;
	int i,j;
	int x,y;
	int a = 0 , b = 0;
	while ( a == 0){
		al_get_mouse_state(&curstate);
		if(curstate.x > 100 && curstate.x <700 && curstate.y>150 && curstate.y<500){
			if(al_mouse_button_down(&curstate,1)){
				i = (curstate.y-150)/50;
				j = (curstate.x-100)/100;
				a = check( i , j , nobat );
			}
		}
	}
	
	while ( b == 0){
		al_get_mouse_state(&curstate);
		if(curstate.x > 100 && curstate.x <700 && curstate.y>150 && curstate.y<500){
			if(al_mouse_button_down(&curstate,1)){
				x = (curstate.y-150)/50;
				y = (curstate.x-100)/100;
				b = check( x , y , nobat );
			}
		}
	}
	if(a == 1 && b==1){
		zamin.tedad_sarbaz[i][j]--;
		zamin.tedad_sarbaz[x][y]++;
	}
}







int tas(){
    int a;
    srand(time(0));
    a = rand()%6 + 1;
    return a;
}





void sort(int array[] , int size) {
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j< size-i-1 ; j++){
        	if(array[j] < array[j+1] ){
        		int temp = array[j+1];
        		array[j+1] = array[j];
				array[j] = temp; 
			}
		}
	}
}




int check( int x , int y , char player ){
	
	if (zamin.malek[x][y][0] == player){
		return 1;
	}
	else {
		return 0;
	}
}


int check_hamsaye(int x , int y , int i , int j){
	if( x == i-1 && y == j){
		return 1;
	}
	else if( x == i+1 && y == j){
		return 1;
	}
	else if( x == i && y == j-1){
		return 1;
	}
	else if( x == i && y == j+1){
		return 1;
	}
	else {
		return 0;
	}	
}




