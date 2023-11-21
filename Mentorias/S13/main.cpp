#include "pc3.h"

int main(){
    CVector obj;

    obj.agregar ( new CCilindro (3 ,5));
    obj . agregar ( new CCono (7 ,8));
    obj . agregar ( new CEsfera (9));
    obj . agregar ( new CToro (10 ,11) );
    obj . agregar ( new CCono (12 ,13) );
    obj . agregar ( new CCono (21 ,22) );
    obj . agregar ( new CEsfera (23) );
    obj . agregar ( new CCilindro (45 ,55) );
    cout << obj;

    return 0;
}
