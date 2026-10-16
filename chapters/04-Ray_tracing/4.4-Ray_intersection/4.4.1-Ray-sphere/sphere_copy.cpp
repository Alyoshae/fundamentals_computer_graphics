#include "../../../../core/include/ray.h"
#include "../../../../core/include/vec3.h"
#include<iostream> 


int main() {
    //lienzo 
    int columnas = 2000;
    int filas = 2000;

    //base ortonormal con origen en eye point(origen). 
    point3 origen = {0,0,0};
    vec3 u = {0,1,0};
    vec3 v = {1,0,0};
    vec3 w = {0,0,-1};

    //limites de lienzo e interpolacion 
    float left =  -1.0f;
    float right = 1.f; 
    float top = 1.f; 
    float bottom = -1.0f; 

    //esfera 
    point3 centro_esfera = {0,0,-10};
    float radio_esfera = 6; 


    //formato ppm 
    std::cout << "P3\n" << columnas << ' ' << filas << "\n255\n";

    float v_cordenada, u_cordenada, a, b, c, discriminante;
    point3 ray_origen;
    vec3 ray_direction, oc;

    for(int i=0; i<filas; i++){
        //movimiento en v 
        v_cordenada = bottom +(top-bottom)*(i+0.5)/filas;
        for(int j=0; j<columnas; j++){
            //movimiento en u
            u_cordenada = left + (right-left)*(j+0.5)/columnas;

            //crear rayos orthographic ---------------------------------------------
            ray_origen = origen + (u_cordenada*u) + (v_cordenada*v);
            //crear rayos perspectiva ----------------------------------------------
            ray_direction = w +(u*u_cordenada)+(v*v_cordenada);

            //impresion rayo.  -----------------------------------------------------
            ray rayo_columna(origen,ray_direction);

            //formula cuadratica (solo discriminante) 
            oc = origen - centro_esfera;
            a = dot(ray_direction, ray_direction);
            b = dot(ray_direction, oc);
            c = dot(oc, oc) - (radio_esfera * radio_esfera);
            discriminante = (b * b) - (a * c);
            //imprimir hohoho
            std::cout<<((discriminante) ? ("10 10 10\n"): ("300 300 300\n"));
        }
    }

    return 0; 
}