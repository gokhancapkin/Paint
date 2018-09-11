#include<math.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
ALLEGRO_BITMAP *bmp,*arkaplan,*resim;
ALLEGRO_DISPLAY *display;
ALLEGRO_COLOR renk;
void renk_secimi();
int sekil_secimi();
void dosyalama();
void ciz(int);
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT ev;
ALLEGRO_MOUSE_STATE state;
int pos_x,pos_y  ;
int sekil=7;
bool done=FALSE;
int main(int argc, char **argv)
{	
	int width = 1000;
	int height = 700;
	
	ALLEGRO_DISPLAY *display = NULL;
	al_init();
	if(!al_init())
		return -1;

	display = al_create_display(width, height);

	if(!display)										
		return -1;
	
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_mouse();
	al_install_keyboard();
	al_clear_to_color(al_map_rgb(255,255,255));
	event_queue = al_create_event_queue();
	
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	
	renk=al_map_rgb(0,0,0);	
	ALLEGRO_BITMAP *resim = al_create_bitmap(1000,700);
	arkaplan=al_load_bitmap("arkaplan.png");
	while(!done)
	{
	    
		al_draw_bitmap(arkaplan,0,0,0);
		al_wait_for_event(event_queue, &ev);
		pos_x = ev.mouse.x;
 		pos_y = ev.mouse.y;
	
 
	al_get_mouse_state(&state);
	
	if(state.buttons & 1){
	if(pos_x>=5 && pos_x<=114 && pos_y>=4 && pos_y<=173){
	dosyalama();
	}
	if(pos_x>=5 && pos_x<=114 && pos_y>=460 && pos_y<=700){
	renk_secimi();
	}
	if(pos_x>=5 && pos_x<=114 && pos_y>=175 && pos_y<=457)
	sekil=sekil_secimi();
	if(pos_x>100)
	ciz(sekil);
	
	
	if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
    	done = true;	
	}
	
	al_flip_display();
	}
	
	
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);					
	return 0;
}
void dosyalama()
{
	int pos_x;
	int pos_y ;
	
	pos_x = ev.mouse.x;
	pos_y = ev.mouse.y;
	if(pos_x>=9 && pos_x<=112 && pos_y>=9 && pos_y<=100)
	{
		al_clear_to_color(al_map_rgb(255,255,255));
	}
	if(pos_x>=9 && pos_x<=54 && pos_y>=107 && pos_y<=170)
	{

	    
	}
	

	al_flip_display();
}
void renk_secimi()
{
	int pos_x;
	int pos_y ;
	
	al_init_primitives_addon();
	al_install_mouse();

	pos_x = ev.mouse.x;
	pos_y = ev.mouse.y;
	if(pos_x>=8 && pos_x<=55 && pos_y>=462 && pos_y<=504 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
	renk=al_map_rgb(255,170,170);	
	}
	
	if(pos_x>=66 && pos_x<=112 && pos_y>=462 && pos_y<=604 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
	renk=al_map_rgb(175,255,255);
	}
	
	if(pos_x>=8 && pos_x<=55 && pos_y>=510 && pos_y<=550 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
	renk=al_map_rgb(86,170,255);
	}
	if(pos_x>=66 && pos_x<=112 && pos_y>=510 && pos_y<=550 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
	renk=al_map_rgb(170,255,86);
	}if(pos_x>=8 && pos_x<=55 && pos_y>=556 && pos_y<=598 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
	renk=al_map_rgb(255,158,68);
	}
	if(pos_x>=66 && pos_x<=112 && pos_y>=556 && pos_y<=598 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
	renk=al_map_rgb(255,255,7);
	}
	if(pos_x>=8 && pos_x<=55 && pos_y>=603 && pos_y<=649 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
	renk=al_map_rgb(255,0,0);
	}
	if(pos_x>=66 && pos_x<=112 && pos_y>=603 && pos_y<=649 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
	renk=al_map_rgb(132,112,255);
	}
	if(pos_x>=8 && pos_x<=55 && pos_y>=654 && pos_y<=693 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
	renk=al_map_rgb(255,255,255);
	}
	if(pos_x>=66 && pos_x<=112 && pos_y>=654 && pos_y<=693 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
	renk=al_map_rgb(0,0,0);
	}

}
int sekil_secimi()
{
	int pos_x;
	int pos_y ;
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_mouse();

	pos_x = ev.mouse.x;
	pos_y = ev.mouse.y;
	if(pos_x>=8 && pos_x<=55 && pos_y>=177 && pos_y<=240 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
	sekil=1;//üçgen (içi boþ)
	}
	if(pos_x>=66 && pos_x<=112 && pos_y>=177 && pos_y<=240 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
	sekil=2;//üçgen (içi dolu)
	}
	if(pos_x>=8 && pos_x<=55 && pos_y>=247 && pos_y<=308 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
	sekil=3;//dikdörtgen (içi boþ)
	}
	if(pos_x>=66 && pos_x<=112 && pos_y>=247 && pos_y<=308 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
	sekil=4;//dikdörtgen (içi dolu)
	}
	if(pos_x>=8 && pos_x<=55 && pos_y>=313 && pos_y<=355 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
	sekil=5;//daire (içi boþ)
	}
	if(pos_x>=66 && pos_x<=112 && pos_y>=313 && pos_y<=355 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
	sekil=6;//daire (içi dolu)
	}
	if(pos_x>=8 && pos_x<=55 && pos_y>=411 && pos_y<=455 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
	sekil=7;//kalem
	}
	if(pos_x>=66 && pos_x<=112 && pos_y>=411 && pos_y<=455 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
	sekil=8;//silgi
	}
	if(pos_x>=8 && pos_x<=112 && pos_y>=361 && pos_y<=405 && ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
	sekil=9;//düz çizgi
	}
	return sekil;
	
}
void ciz(int sec_sekil)
{
	
	renk_secimi();
	int pos_x2=0,pos_y2=0,pos_x3=0,pos_y3=0;
			
			if(sec_sekil == 7)
			al_draw_filled_rectangle(pos_x, pos_y, pos_x + 4, pos_y + 4,renk);
			if(sec_sekil == 8)
			al_draw_filled_rectangle(pos_x, pos_y, pos_x + 25, pos_y + 25,al_map_rgb(255,255,255));
			if(sec_sekil == 1)
			 while(pos_x>118){
			 	renk_secimi();
    			ALLEGRO_EVENT ev;
    			al_wait_for_event(event_queue , &ev);
  				al_flush_event_queue(event_queue);
 				 do {
    				 al_wait_for_event(event_queue , &ev);
  					}
  				while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
  				pos_x = ev.mouse.x;
 				 pos_y = ev.mouse.y;
				  if(pos_x<118) break;
				al_flush_event_queue(event_queue);
 				do {
   				 al_wait_for_event(event_queue , &ev);
				 }
				 while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
				 pos_x2 = ev.mouse.x;
				 pos_y2 = ev.mouse.y;
				 if(pos_x2 < 118) break;
				 al_flush_event_queue(event_queue);
				 do {
				    al_wait_for_event(event_queue , &ev);
				 }
				 while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
				 pos_x3 = ev.mouse.x;
				 pos_y3 = ev.mouse.y;
				 if(pos_x3 < 118) break;
				 al_draw_triangle(pos_x,pos_y,pos_x2,pos_y2,pos_x3,pos_y3,renk,3);
				     al_flip_display();
					 
				    
				}
			if(sec_sekil == 2)
			while(pos_x>118){
			 	renk_secimi();
		    ALLEGRO_EVENT ev;
		    al_wait_for_event(event_queue , &ev);
		 	 al_flush_event_queue(event_queue);
		 	 do {
		     al_wait_for_event(event_queue , &ev);
		  		}
		 	 while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
		 	 pos_x = ev.mouse.x;
		 	 pos_y = ev.mouse.y;
		 	 if(pos_x<118) break;
			al_flush_event_queue(event_queue);
		 	do {
		    al_wait_for_event(event_queue , &ev);
			 }
			 while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
			 pos_x2 = ev.mouse.x;
			 pos_y2 = ev.mouse.y;
			 if(pos_x2 < 118) break;
			 al_flush_event_queue(event_queue);
			 do {
			    al_wait_for_event(event_queue , &ev);
			 }
			 while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
			 pos_x3 = ev.mouse.x;
			 pos_y3 = ev.mouse.y;
			 if(pos_x3 < 118) break;
			 al_draw_filled_triangle(pos_x,pos_y,pos_x2,pos_y2,pos_x3,pos_y3,renk);
		     al_flip_display();
			 
		    
			}
			if(sec_sekil == 3)
			{while(pos_x>118){
				al_wait_for_event(event_queue , &ev);
			al_flush_event_queue(event_queue);
			 ALLEGRO_EVENT ev;
    		 do {
		    al_wait_for_event(event_queue , &ev);
					 }
				 while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
					
	     	pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
			if(pos_x<118) break;
			
			al_flush_event_queue(event_queue);
			do {
		 		 al_wait_for_event(event_queue , &ev);
			}
			while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
			pos_x2 = ev.mouse.x;
			pos_y2 = ev.mouse.y;
		 	if(pos_x2<118) break;
		 	al_draw_rectangle(pos_x,pos_y,pos_x2,pos_y2,renk,5);
			 al_flip_display();
				    
					}
					}
					
			if(sec_sekil == 4)
			{while(pos_x>118){
				al_wait_for_event(event_queue , &ev);
			al_flush_event_queue(event_queue);
			 ALLEGRO_EVENT ev;
    		 do {
		    al_wait_for_event(event_queue , &ev);
					 }
				 while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
					
	     	pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
			if(pos_x<118) break;
			
			al_flush_event_queue(event_queue);
			do {
		 		 al_wait_for_event(event_queue , &ev);
			}
			while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
			pos_x2 = ev.mouse.x;
			pos_y2 = ev.mouse.y;
		 	if(pos_x2<118) break;
		 	al_draw_filled_rectangle(pos_x,pos_y,pos_x2,pos_y2,renk);
			 al_flip_display();
				    
					}
					}
			if(sec_sekil == 5)
			{while(pos_x>118){
			al_flush_event_queue(event_queue);
			 ALLEGRO_EVENT ev;
    		 do {
		    al_wait_for_event(event_queue , &ev);
					 }
				 while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
					
	     	pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
			if(pos_x<118) break;
			
			al_flush_event_queue(event_queue);
			do {
		 		 al_wait_for_event(event_queue , &ev);
			}
			while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
			pos_x2 = ev.mouse.x;
			pos_y2 = ev.mouse.y;
		 	if(pos_x2<118) break;
		 	al_draw_circle(pos_x,pos_y,sqrt((pos_x2-pos_x)*(pos_x2-pos_x)+(pos_y2-pos_y)*(pos_y2-pos_y)),renk,5);
			 al_flip_display();
				    
					}
					}
			
			if(sec_sekil == 6)
			{while(pos_x>118){
			 ALLEGRO_EVENT ev;
			 al_flush_event_queue(event_queue);
    		 do {
		    al_wait_for_event(event_queue , &ev);
					 }
				 while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
					
	     	pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
			if(pos_x<118) break;
			
			al_flush_event_queue(event_queue);
			do {
		 		 al_wait_for_event(event_queue , &ev);
			}
			while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
			pos_x2 = ev.mouse.x;
			pos_y2 = ev.mouse.y;
		 	if(pos_x2<118) break;
		 	al_draw_filled_circle(pos_x,pos_y,sqrt((pos_x2-pos_x)*(pos_x2-pos_x)+(pos_y2-pos_y)*(pos_y2-pos_y)),renk);
			 al_flip_display();
				    
					}
					}
			
			if(sec_sekil == 9)
			{
         		while(pos_x>118)
    {
         al_flush_event_queue(event_queue);
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
         
        if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if(ev.mouse.button & 1)
            {
                pos_x = ev.mouse.x;
                pos_y = ev.mouse.y;
            }
        }
         
        if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            if(ev.mouse.button & 1)
            {
                pos_x2 = ev.mouse.x;
                pos_y2 = ev.mouse.y;
                if(pos_x2 <118) break;
				al_draw_line(pos_x,pos_y,pos_x2,pos_y2,renk,5);
            }
        }
      
            al_flip_display();
}

}
}


