#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#define PI 3.14159265358979323846
#define R 5.000000
#define r 1.000000
#define a 4.000000
#define OX -118.289003
#define OY   34.021087
using namespace std;

int main()
{
    ofstream ofile2("Spirogragh2.kml", ofstream::out);
    ofile2 << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>" << endl;
    ofile2 << "<kml xmlns=\"http://earth.google.com/kml/2.0\">"<< endl;
    ofile2 << "	<Document>" << endl;
    ofile2 << "		<Style id = \"z1\">" << endl;
    ofile2 << "			<IconStyle > <Icon > <href > http://www.google.com/intl/en_us/mapfiles/ms/micons/blue-dot.png</href > </Icon > </IconStyle >" << endl;
    ofile2 << "		</Style>" << endl;
    ofile2 << "		<Style id=\"mLine\">" << endl;
    ofile2 << "			<LineStyle><color>ff00ffaa</color><width>0.7</width></LineStyle>" << endl;
    ofile2 << "			<PolyStyle><color>03ffffff</color></PolyStyle>" << endl;
    ofile2 << "		</Style>" << endl;
    ofile2 << "		<Placemark><name>SGM124</name><styleUrl>#z1</styleUrl><Point><coordinates>"<<OX<<','<<OY<<"</coordinates></Point></Placemark>" << endl;
    
    ofstream ofile1("Spirogragh1.kml", ofstream::out);
    ofile1 << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>" << endl;
    ofile1 << "<kml xmlns=\"http://earth.google.com/kml/2.0\">" << endl;
    ofile1 << "	<Document>" << endl;
    ofile1 << "		<Style id = \"z1\">" << endl;
    ofile1 << "			<IconStyle > <Icon > <href > http://www.google.com/intl/en_us/mapfiles/ms/micons/blue-dot.png</href > </Icon > </IconStyle >" << endl;
    ofile1 << "		</Style>" << endl;
    ofile1 << "		<Placemark><name>SGM124</name><styleUrl>#z1</styleUrl><Point><coordinates>" << OX << ',' << OY << "</coordinates></Point></Placemark>" << endl;
    
    double xx = 0.000000;
    double yy = 0.000000;
    
    for (double t = 0.01;t < PI * 10;t+=0.01)
    {
        xx = OX + 0.001700*((R + r)*cos((r / R)*t) - a*cos((1.000000 + r / R)*t));
        yy = OY + 0.001700*((R + r)*sin((r / R)*t) - a*sin((1.000000 + r / R)*t));
        
        ofile1 << "		<Placemark><name>t=" << t << "</name><styleUrl>#z1</styleUrl><Point><coordinates>"<< setiosflags(ios::fixed) << setprecision(6) << xx << ',' << yy << "</coordinates></Point></Placemark>" << endl;
        
        ofile2 << "		<Placemark><name>t=" << t << "</name><styleUrl>#mLine</styleUrl><LineString><extrude>1</extrude><tessellate>1</tessellate><altitudeMode>absolute</altitudeMode><coordinates>-118.289025,34.021142,80 " <<setiosflags(ios::fixed) <<setprecision(6) << xx << ',' << yy << ",80</coordinates></LineString></Placemark>"<< endl;
        
    }
    ofile2 << "	</Document>" << endl;
    ofile2 << "</kml> " << endl;
    ofile2.close();
    ofile1 << "	</Document>" << endl;
    ofile1 << "</kml> " << endl;
    ofile1.close();
    cout <<"Complete generating Spirogragh1.kml and Spirogragh2.kml"<<endl;
    system("pause");
    return 0;
}
