#include <iostream>
#include <string>
#include <stdexcept>
#include <math.h>
#include "figury.hpp"

using namespace std;
const double pi = 3.1415926535897932386426433832795; 

int main() {
    {
    cout << "punkty konstruktory:\n";
    punkt p1, p2(0, 2), p6(p2), p5 = p2;
    p1.pokaz();
    p2.pokaz();
    p6.pokaz();
    p5.pokaz();
    
    
    punkt p3(1, 2);
    cout << "obroty punktu (1, 2):\n";
    p3.obroc(p2, pi/3);
    p3.pokaz();
    p3.obroc(p2, pi/3);
    p3.pokaz();
    p3.obroc(p2, pi/3);
    p3.pokaz();
    punkt p4(0, 3);
    cout << "symetria wzg (0,3) i wzg osi:\n";
    p3.symetriawzgp(p4);
    p3.pokaz();
    p3.symetriawzgox();
    p3.pokaz();
    p3.symetriawzgoy();
    p3.pokaz();
    cout << "przesuniecie -1 -4 o wektor 0.5 -2.5:\n";
    wektor w(1.5, 1.5);
    p3.przesun(w);
    p3.pokaz();
    
    cout << "odcinki konstruktory:\n";
    cout << "niepoprawna deklaracja odcinka:\n";    
    try{
        odcinek odc2(p1, p1);
    } catch(invalid_argument const &e) {
        clog << e.what() << "\n";
    }
    odcinek odc(p1, p2);
    odcinek odc3(odc);
    odcinek odc4 = odc;
    odc.pokaz();
    odc3.pokaz();
    odc4.pokaz();
    odc4.przesun(w);
    odc4.pokaz();
    punkt p7(1,1);
    
    cout << "obrot tego odcinka:\n";
    odc.pokaz();
    odc.obroc(p7, pi);
    odc.pokaz();
    cout << "symetrie wzg (-1,0) i osi tego odcinka:\n";
    odc3.pokaz();
    punkt p8(-1, 0);
    odc3.symetriawzgp(p8);
    odc3.pokaz();
    odc3.symetriawzgox();
    odc3.pokaz();
    odc3.symetriawzgoy();
    odc3.pokaz();
    cout << "dlugosc odcinka:\n" << odc3.dlugosc() << "\n";
    punkt p9(1,1), p10(2,2), p11(3,3), p12(4,4);
    cout << "czy lezy na odcinku (1,1)-(3,3):\n";
    odcinek odc5(p9,p11);
    cout << odc5.czylezy(p10) << "\n";
    cout << odc5.czylezy(p11) << "\n";
    cout << odc5.czylezy(p12) << "\n";
    cout << "czy prostopadle i rownolegle:\n";
    odcinek odc6;
    odc.pokaz(), odc3.pokaz(), odc4.pokaz(), odc5.pokaz(), odc6.pokaz();
    cout << czyprostopadle(odc, odc3) << " " << czyrownolegle(odc, odc3) << "\n";
    cout << czyprostopadle(odc, odc4) << " " << czyrownolegle(odc, odc4) << "\n";
    cout << czyprostopadle(odc, odc5) << " " << czyrownolegle(odc, odc5) << "\n";
    cout << czyprostopadle(odc, odc6) << " " << czyrownolegle(odc, odc6) << "\n";
    cout << czyprzeciecie(odc, odc3) << "\n";
    punkt p13(2, 2), p14(2,0);
    odcinek odc7, odc8(p13, p14);
    cout << czyprzeciecie(odc7, odc8) << "\n";
    
    }


    cout << "trojkaty konstruktory:\n";
    punkt p1(1,1), p2(2,2), p3(3,3), p4(3, 1);
    punkt p5, p6(0,2), p7(0,-8);
    trojkat t1, t2(p1, p3, p4), t3(t2), t4 = t3;
    t1.pokaz();
    t2.pokaz();
    t3.pokaz();
    t4.pokaz();
    cout << "niepoprawne deklaracje trojkatow:\n";
        
    try{
        trojkat t5(p1, p2, p3);
    } catch(invalid_argument const &e) {
        clog << e.what() << "\n";
    }
    try{
        trojkat t6(p5, p6, p7);
    } catch(invalid_argument const &e) {
        clog << e.what() << "\n";
    }
    cout << "przesuniecie tego trojkata o wektor (1,1):\n";
    t1.pokaz();
    wektor w(1,1);
    t1.przesun(w);
    t1.pokaz();
    cout << "obroty:\n";
    t1.obroc(p5, pi/2);
    t1.pokaz();
    t1.obroc(p5, pi/2);
    t1.pokaz();
    t1.obroc(p5, pi/2);
    t1.pokaz();
    t1.obroc(p5, pi/2);
    t1.pokaz();
    cout << "symetrie wzg 0 i osi:\n";
    t1.symetriawzgp(p5);
    t1.pokaz();
    t1.symetriawzgox();
    t1.pokaz();
    t1.symetriawzgoy();
    t1.pokaz();
    cout << "pole: " << t1.pole() << " obwod: " << t1.obwod() << "\n";
    cout << "czy punkt wewnatrz trojkata:\n";
    punkt p8(1,1), p9(1.4,1.4), p10(2, 2);
    cout << t1.czypwewnatrz(p8) << "\n";
    cout << t1.czypwewnatrz(p9) << "\n";
    cout << t1.czypwewnatrz(p10) << "\n";
    cout << "rozlacznosc:\n";
    trojkat t5;
    t1.pokaz();
    t2.pokaz();
    t5.pokaz();
    cout << czyrozlaczne(t1,t2) << "\n";
    cout << czyrozlaczne(t1,t5) << "\n";
    cout << "zawieranie:\n";
    punkt p11(0,5), p12(5, 0);
    trojkat t6(p5, p11, p12);
    t1.pokaz();
    t6.pokaz();
    t5.pokaz();
    cout << czyzawiera(t1, t6) << "\n";
    cout << czyzawiera(t6, t1) << "\n";
    cout << czyzawiera(t6, t5) << "\n";
    
    return 0;
    
}