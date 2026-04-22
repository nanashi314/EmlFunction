#include <bits/stdc++.h>
using namespace std;
using z = complex<double>;
const double EPS = 1e-14;

z safe_log(z x) {
	if(abs(x) < EPS) return z(-INFINITY, 0.0);
	return log(x);
}

z safe_exp(z x) {
	if(isinf(x.real()) && x.real() < 0 && abs(x.imag()) < EPS) {
		return z(0.0, 0.0);
	}
	if(isinf(x.real()) && x.real() > 0 && abs(x.imag()) < EPS) {
		return z(INFINITY, 0.0);
	}
	return exp(x);
}

z Eml(z x, z y) {
	return safe_exp(x) - safe_log(y);
}

z One() {
	return z(1, 0);
}

z E() {
	return Eml(One(), One());
}

z Exp(z x) {
	return Eml(x, One());
}

z Ln(z x) {
	return Eml(One(), Eml(Eml(One(), x), One()));
}

z Zero() {
	return Ln(One());
}

z Minus(z x, z y) {
	return Eml(Ln(x), Exp(y));
}

z Neg(z x) {
	return Minus(Zero(), x);
}

z Plus(z x, z y) {
	return Minus(x, Neg(y));
}

z Mul(z x, z y) {
	return Exp(Plus(Ln(x), Ln(y)));
}

z Inv(z x) {
	return Exp(Neg(Ln(x)));
}

z Power(z x, z y) {
	return Exp(Mul(y, Ln(x)));
}

z Minus_one() {
	return Neg(One());
}

z Div(z x, z y) {
	return Mul(x, Inv(y));
}

z Sqrt(z x) {
	return Power(x, Div(One(), Plus(One(), One())));
}

z Imag_one() {
	return Sqrt(Minus_one());
}

z Pi() {
	return Mul(Inv(Imag_one()), Ln(Minus_one()));
}

z Cosh(z x) {
	return Div(Plus(Exp(x), Exp(Neg(x))), Plus(One(), One()));
}

z Sinh(z x) {
	return Div(Minus(Exp(x), Exp(Neg(x))), Plus(One(), One()));
}

z Cos(z x) {
	return Cosh(Mul(Imag_one(), x));
}

z Sin(z x) {
	return Div(Sinh(Mul(Imag_one(), x)), Imag_one());
}

int main() {
    cout << fixed << setprecision(12);

    double re_x, im_x;
    cin >> re_x >> im_x;
    z x(re_x, im_x);

    cout << "input x      = " << x << '\n';
    cout << '\n';

    cout << "One()        = " << One() << '\n';
    cout << "E()          = " << E() << '\n';
    cout << "Exp(x)       = " << Exp(x) << '\n';
    cout << "Ln(x)        = " << Ln(x) << '\n';
    cout << "Zero()       = " << Zero() << '\n';
    cout << "Minus(x,1)   = " << Minus(x, One()) << '\n';
    cout << "Neg(x)       = " << Neg(x) << '\n';
    cout << "Plus(x,1)    = " << Plus(x, One()) << '\n';
    cout << "Mul(x,2)     = " << Mul(x, z(2.0, 0.0)) << '\n';
    cout << "Inv(x)       = " << Inv(x) << '\n';
    cout << "Power(x,2)   = " << Power(x, z(2.0, 0.0)) << '\n';
    cout << "Minus_one()  = " << Minus_one() << '\n';
    cout << "Div(x,2)     = " << Div(x, z(2.0, 0.0)) << '\n';
    cout << "Sqrt(x)      = " << Sqrt(x) << '\n';
    cout << "Imag_one()   = " << Imag_one() << '\n';
    cout << "Pi()         = " << Pi() << '\n';
    cout << "Cosh(x)      = " << Cosh(x) << '\n';
    cout << "Sinh(x)      = " << Sinh(x) << '\n';
    cout << "Cos(x)       = " << Cos(x) << '\n';
    cout << "Sin(x)       = " << Sin(x) << '\n';
    cout << '\n';

    return 0;
}

