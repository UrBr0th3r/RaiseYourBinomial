#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

int VectorToInt(vector<int> v)
{
    reverse(v.begin(), v.end());
    int decimal = 1;
    int total = 0;
    for (auto& it : v)
    {
        total += it * decimal;
        decimal *= 10;
    }
    return total;
}

int fattoriale(int a) {
    int f = 1;
    while(a > 0) {
        f = f * a;
        a--;
    }
    return f;
}


int main() {
    int n, nx, ny, c, r, a, b;
    string cs;
    string t, tx, ty;
    char binomio[200];
    char x[5] = "x";
    char y[5] = "y";
    vector <int> av;
    vector <int> bv;
    vector <int> nv;
    cout << "inserire il binomio. forma: (ax+by)^n" << endl;
    /* cout << "inserire a: ";
    cin >> a;
    cout << "inserire b: ";
    cin >> b;
    cout << "inserire n: ";
    cin >> n; */
    cin >> binomio;
    if(binomio[1] == x[0]) {
        a = 1;
    }
    else {
        for(int i = 1; i < 200; i++) {
            a = int(binomio[i]);
            a = a-48;
            if (a >= 0 && a <= 9) {
                av.push_back(a);
            }
            else {
                break;
            }
        }
        a = VectorToInt(av);
    }
    if(binomio[3+av.size()] == y[0]) {
        b = 1;
    }
    else {
        for(int i = 3+av.size(); i < 20; i++) {
            b = int(binomio[i]);
            b = b-48;
            if (b >= 0 && b <= 9) {
                bv.push_back(b);
            }
            else {
                break;
            }
        }
        b = VectorToInt(bv);
    }
    for(int i = 6+av.size()+bv.size(); i < 20; i++) {
        n = int(binomio[i]);
        n = n-48;
        if (n >= 0 && n <= 9) {
            nv.push_back(n);
        }
        else {
            break;
        }
    }
    n = VectorToInt(nv);
    cout << a << endl << b << endl << n << endl << endl;
    if(n > 13 || n < 0) {
        cout << "Valore non valido. Min 0; max 13" << endl;
        return 1;
    }
    nx = ny = n;
    if (n == 0) {
        cout << "1" << endl;
        return 0;
    }
    else {
        for(int p = 0; p <= n; p++) {
            if(p == 0 || p == n){
                c = 1;
            }
            else {
                c = fattoriale(n)/(fattoriale(p)*fattoriale(n - p));
            }
            c = c*pow(a, n-p)*pow(b, p);
            cs = to_string(c);
            if (cs == "1") {
                cs = "";
            }
            tx = "x^" + to_string(n-p);
            ty = "y^" + to_string(p);
            if(tx == "x^0") {
                tx = "";
            }
            if(ty == "y^0") {
                ty = "";
            }
            if(tx == "x^1") {
                tx = "x";
            }
            if(ty == "y^1") {
                ty = "y";
            }
            t = t + cs + tx + ty + " + ";
        }
    }
    t.erase(t.size() - 2);
    cout << t << endl;
    return 0;
}
