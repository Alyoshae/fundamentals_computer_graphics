#include "../../../../core/include/ray.h"
#include "../../../../core/include/vec3.h"
#include<iostream> 


int main() {
    //lienzo 
    int columnas = 260;
    int filas = 300;

    //base ortonormal con origen en e. 
    point3 origen = {0,0,0};
    vec3 u = {0,1,0};
    vec3 v = {1,0,0};
    vec3 w = {0,0,-1};

    //limites de lienzo e interpolacion 
    float left = columnas - columnas - 0.5;
    float right = columnas + 0.5; 
    float top = filas + 0.5; 
    float bottom = filas - filas - 0.5; 

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
            //crear rayos 
            point3 ray_origen = origen + (u_cordenada*u) + (v_cordenada*v);
            ray rayo_columna(ray_origen, w);

            std::cout << r << ' ' << g << " 0\n"; 
        }
    }

    return 0; 
}