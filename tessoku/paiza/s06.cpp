#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793238

int a, b, x, y, r, t, L;
int repX = 0, repY = 0;
double X, Y, distX, distY, tmpX, tmpY;

double sign(double A){
    return (A>0)-(A<0);
}

int main(){
    cin >> a >> b >> x >> y >> r >> t >> L;
    double resX = X, resY = Y;
    distX = abs(L * cos(1.0*t /180 * PI));
    distY = abs(L * sin(1.0*t /180 * PI));
    // cout << distX << " " << distY << endl;
    // cout << ceil(distX) << " " << ceil(distY) << endl;
    repX = (int)ceil(distX + (1.0*a/2-r)) / (a-2*r);
    repY = (int)ceil(distY + (1.0*b/2-r)) / (b-2*r);
    resX = distX + (1.0*a/2-r) - (a-2*r) * repX;
    resY = distY + (1.0*b/2-r) - (b-2*r) * repY;
    cout << resX << " " << resY << endl;
    tmpX = sign(cos(1.0*t /180 * PI)) * (resX - (1.0*a/2-r));
    tmpY = sign(sin(1.0*t /180 * PI)) * (resY - (1.0*b/2-r));
    cout << tmpX << " " << tmpY << endl;
    if(sign(cos(1.0*t /180 * PI)) * sign((repX % 2)) > 0){
        tmpX = sign(cos(1.0*t /180 * PI)) * (1.0*a/2-r) - tmpX;
    }
    if(sign(sin(1.0*t /180 * PI)) * sign((repY % 2)) > 0){
        tmpY = sign(sin(1.0*t /180 * PI)) * (1.0*b/2-r) - tmpY;
    }
    cout << tmpX << " " << tmpY << endl;
    X = x + tmpX;
    Y = y + tmpY; 
    // X = resX + x;
    // Y = resY + y;

    // if(X<r) X = 

    // X = L * cos(t /180 * PI) + x;
    // Y = L * sin(t /180 * PI) + y;

    // while(resX < r){
    //     resX += a - r;
    //     repx++;
    // }
    // while(resY < r){
    //     resY += b - r;
    //     repy++;
    // }

    // while(resX > a - r){
    //     resX -= a - r;
    //     repx++;
    // }
    // while(!(resY < b - r)){
    //     resY -= b - r;
    //     repy++;
    // }

    // if(repx % 2 == 1) x = (a - r) - resX;
    // if(repy % 2 == 1) y = (b - r) - resY;
    cout << repX << " " << repY << endl;
    cout << X << " " << Y << endl;
    return 0;
}