#include "../../../../core/include/ray.h"
#include "../../../../core/include/vec3.h"
#include<iostream> 


int main() {
    //lienzo 
    int columnas = 250;
    int filas = 250;

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

    for(int i=0; i<filas; i++){
        float porcentaje_g = float(filas -1-i)/(filas-1); 
        int g = porcentaje_g*255;
        //movimiento en v 
        float v_cordenada = bottom +(top-bottom)*(i+0.5)/filas;
        for(int j=0; j<columnas; j++){
            float porcentaje_r = float(columnas-1-j)/(columnas-1);
            int r = porcentaje_r*255;
            //movimiento en u
            float u_cordenada = left + (right-left)*(j+0.5)/columnas;


            //crear rayos orthographic ---------------------------------------------
            point3 ray_origen = origen + (u_cordenada*u) + (v_cordenada*v);
            //crear rayos perspectiva ----------------------------------------------
            vec3 ray_direction = w +(u*u_cordenada)+(v*v_cordenada);

            //impresion rayo.  -----------------------------------------------------
            ray rayo_columna(origen,ray_direction);

            //formula cuadratica (solo discriminante) 
            //d.(e-c)**2 - (d.d) (e-c)**2-r**2
            vec3 oc = origen - centro_esfera;
            float a = dot(ray_direction, ray_direction);
            float b = dot(ray_direction, oc);
            float c = dot(oc, oc) - (radio_esfera * radio_esfera);
            float discriminante = (b * b) - (a * c);
            //imprimir hohoho
            if(discriminante >= 0){
                std::cout << "10 10 10\n";
            }
            else{
                std::cout << "300 300 300\n";
                //std::cout << r << ' ' << g << " 0\n"; 
            }
        }
    }

    return 0; 
}