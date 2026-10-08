#pragma once

#include <iostream> 
#include <cmath> 

class vec3{
    public: 
        //Constructores
        vec3() : v{0,0,0} {}
        vec3(double a, double b, double c) : v{a,b,c} {}
        //Lectura 
        double x() const{return v[0];}
        double y() const{return v[1];}
        double z() const{return v[2];}
        //Asignación
        vec3& operator+=(const vec3&);
        vec3& operator*=(double);
        vec3& operator/=(double); 
        //Magnitud al cuadrado y magnitud 
        double mag_cuad() const{return(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);}
        double mag() const{return(std::sqrt(mag_cuad()));}
        //corchetes
        double operator[](int i) const {return(v[i]);}
        double& operator[](int i) {return(v[i]);}
        //valores
        double v[3];
};

//ayuda. 
using point3 = vec3;

vec3& vec3::operator+=(const vec3& w){
    v[0]+=w.v[0];
    v[1]+=w.v[1];
    v[2]+=w.v[2];
    return *this; 
}

vec3& vec3::operator*=(double e){
    v[0]*=e;
    v[1]*=e;
    v[2]*=e;
    return *this;
}

vec3& vec3::operator/=(double e){
    return *this *= 1/e;
}

std::ostream& operator<<(std::ostream& out, const vec3& v){
    return out << '[' << v.x() << ' ' << v.y() << ' ' << v.z() << ']'; 
}

inline vec3 operator+(const vec3& u, const vec3& v){
    return(vec3{u.v[0]+v.v[0], u.v[1]+v.v[1], u.v[2]+v.v[2]});
}

inline vec3 operator-(const vec3& u, const vec3& v){
    return(vec3{u.v[0]-v.v[0],u.v[1]-v.v[1],u.v[2]-v.v[2]});
}

inline vec3 operator*(const vec3& v, double e){
    vec3 wilver = v; 
    wilver*=e;
    return(wilver);
}

inline vec3 operator*(const vec3& u, const vec3& v){
    return vec3(u.v[0]*v.v[0],u.v[1]*v.v[1],u.v[2]*v.v[2]);
}

inline vec3 operator*(double u, const vec3& v){
    return v * u;
}

inline vec3 operator/(const vec3& v, double e){
    return v*(1/e);
}

inline double dot(const vec3& u, const vec3& v){
    return(u.v[0]*v.v[0]+u.v[1]*v.v[1]+u.v[2]*v.v[2]);
}

inline vec3 cruz(const vec3& u, const vec3& v) {
    return vec3(u.v[1] * v.v[2] - u.v[2] * v.v[1], u.v[2] * v.v[0] - u.v[0] * v.v[2], u.v[0] * v.v[1] - u.v[1] * v.v[0]);
}
inline vec3 unit(const vec3& v){
    return v / v.mag();
}
