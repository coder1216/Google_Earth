#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
#define PI 3.1415926
int main(){
    ofstream out_file;
    out_file.open("bonus.kml",ofstream::out);
    out_file<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\
    <kml xmlns=\"http://earth.google.com/kml/2.0\"> <Document>";
    int phi=0;
    double a=0.001;
    double sgmx=-118.2913436;
    double sgmy=34.0212453;
    out_file<<"<Placemark><Point><coordinates>"<<sgmx<<", "<<sgmy<<
    "</coordinates></Point></Placemark>";
    
    while(phi++<720){
        double x=2*a*cos(phi * PI/180.)+a*cos(2*phi * PI/180.);
        double y=2*a*sin(phi * PI/180.)-a*sin(2*phi * PI/180.);
        out_file<<"<Placemark><Point><coordinates>"<<x+sgmx<<", "<<y+sgmy<<
        "</coordinates></Point></Placemark>";
    }
    out_file<<"</Document></kml>";
    
    return 0;
    
}
