#include <raylib.h>
#include <raymath.h>
#include <string.h>
#include <stdlib.h>
#include "elements.h"


element create_button( 
    Vector2 start,
    size_t width, 
    size_t height, 
    Color color, 
    Color text_color, 
    char* text, 
    size_t font_size,
    void (*action)(char* txt)
){
    button b = malloc(sizeof(struct _Button));
    if (b == NULL){
        return NULL;
    }
    b->start = start;
    b->width = width;
    b->height = height;
    b->color = color;
    b->text_color = text_color;
    b->text = text;
    b->hovering = false;
    b->clicked = false;
    b->font_size = font_size;

    b->text_pos = (Vector2){
        b->start.x + b->width/2 - MeasureText(b->text, b->font_size )/2, 
        b->start.y + b->height/2 - b->font_size/2
    };
    b->action = action;
    element e = malloc(sizeof(struct _element));
    if (e == NULL){
        free(b);
        return NULL;
    }
    e->tag = BTN;
    e->page = MAIN_PAGE;
    e->btn = b;
    e->visible = true;
    e->enabled = true;
    return e;

}

element create_input(
    Vector2 start,
    size_t width, 
    size_t height,
    Color color1,
    Color color2,
    char* text,
    size_t font_size

){
    input_form i = malloc(sizeof(struct _Input));
    if (i == NULL){
        return NULL;
    }
    i->start = start;
    i->width = width;
    i->height = height;
    i->color1 = color1;
    i->color2 = color2;
    strcpy(i->text, text);
    i->font_size = font_size;   
    element e = malloc(sizeof(struct _element));
    if (e == NULL){
        free(i);
        return NULL;
    }
    e->tag = IN;
    e->page = MAIN_PAGE;
    e->in = i;
    e->visible = true;
    e->enabled = true;
    return e;
}