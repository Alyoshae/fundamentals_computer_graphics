#include <iostream>

int columns = 400;
int rows = 600;

int main() {
    std::cout << "P3\n" << columns << ' ' << rows << "\n255\n";

    //imagen ppm 
    for(int i=0; i<rows; i++){
        //normalizar 0 - 1 
        float porcentaje_g = float(rows -1-i)/(rows-1);
        //escalar 
        int g = porcentaje_g*255;
        for(int j=0; j<columns; j++){
            float porcentaje_r = float(columns-1-j)/(columns-1);
            int r = porcentaje_r*255;
            std::cout << r << ' ' << g << " 0\n"; 
        }
    }

    return 0; 
}