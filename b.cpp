#include <bits/stdc++.h>

using namespace std;

struct Expr {
    string s;
    Expr(string val) : s(val) {}
};

Expr Eml(Expr x, Expr y) {
    return Expr("Eml(" + x.s + ", " + y.s + ")");
}

Expr One() {
    return Expr("1");
}

Expr Exp(Expr x) {
    return Eml(x, One());
}

Expr Ln(Expr x) {
    return Eml(One(), Eml(Eml(One(), One()), x));
}

Expr Zero() {
    return Ln(One());
}

Expr E() {
    return Eml(One(), One());
}

Expr Minus(Expr x, Expr y) {
    return Eml(Ln(x), Exp(y));
}

Expr Neg(Expr x) {
    return Minus(Zero(), x);
}

Expr Plus(Expr x, Expr y) {
    return Minus(x, Neg(y));
}

Expr Mul(Expr x, Expr y) {
    return Exp(Plus(Ln(x), Ln(y)));
}

Expr Inv(Expr x) {
    return Exp(Neg(Ln(x)));
}

Expr Power(Expr x, Expr y) {
    return Exp(Mul(y, Ln(x)));
}

Expr Minus_one() {
    return Neg(One());
}

Expr Div(Expr x, Expr y) {
    return Mul(x, Inv(y));
}

Expr Sqrt(Expr x) {
    return Power(x, Div(One(), Plus(One(), One())));
}

Expr Imag_one() {
    return Sqrt(Minus_one());
}

Expr Pi() {
    return Mul(Inv(Imag_one()), Ln(Minus_one()));
}

Expr Cosh(Expr x) {
    return Div(Plus(Exp(x), Exp(Neg(x))), Plus(One(), One()));
}

Expr Sinh(Expr x) {
    return Div(Minus(Exp(x), Exp(Neg(x))), Plus(One(), One()));
}

Expr Cos(Expr x) {
    return Cosh(Mul(Imag_one(), x));
}

Expr Sin(Expr x) {
    return Div(Sinh(Mul(Imag_one(), x)), Imag_one());
}

int main() {
    Expr x("x");

    cout << "One():\n" << One().s << "\n\n";

    cout << "E():\n" << E().s << "\n\n";

    cout << "Exp(x):\n" << Exp(x).s << "\n\n";

    cout << "Ln(x):\n" << Ln(x).s << "\n\n";

    cout << "Zero():\n" << Zero().s << "\n\n";

    cout << "Minus(x, One()):\n" << Minus(x, One()).s << "\n\n";

    cout << "Neg(x):\n" << Neg(x).s << "\n\n";

    cout << "Plus(x, One()):\n" << Plus(x, One()).s << "\n\n";

    cout << "Mul(x, 2):\n" << Mul(x, Plus(One(), One())).s << "\n\n";

    cout << "Inv(x):\n" << Inv(x).s << "\n\n";

    cout << "Power(x, 2):\n" << Power(x, Plus(One(), One())).s << "\n\n";

    cout << "Minus_one():\n" << Minus_one().s << "\n\n";

    cout << "Div(x, 2):\n" << Div(x, Plus(One(), One())).s << "\n\n";

    cout << "Sqrt(x):\n" << Sqrt(x).s << "\n\n";

    cout << "Imag_one():\n" << Imag_one().s << "\n\n";

    cout << "Pi():\n" << Pi().s << "\n\n";

    cout << "Cosh(x):\n" << Cosh(x).s << "\n\n";

    cout << "Sinh(x):\n" << Sinh(x).s << "\n\n";

    cout << "Cos(x):\n" << Cos(x).s << "\n\n";

    cout << "Sin(x):\n" << Sin(x).s << "\n\n";

    return 0;
}
