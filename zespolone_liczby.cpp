#include <iostream>

using namespace std;

class Zespolone {
    friend ostream& operator<<(ostream& os, const Zespolone &N);
    friend istream& operator>>(istream& is, Zespolone &N);
    private:
        double real;
        double imag;
    public:
    Zespolone (double x_coord=0, double y_coord=0): real(x_coord), imag(y_coord) {}
    void ViewNumber();
    Zespolone operator+ (Zespolone &N);
    Zespolone operator* (Zespolone &N);

};

void Zespolone::ViewNumber() {
  cout << "The number is: \n" << real << " + " << imag << "j" << endl;
}

Zespolone Zespolone::operator+ (Zespolone &N) {
  Zespolone result;
  result.real = real + N.real;
  result.imag = imag + N.imag;
  return result;
}

Zespolone Zespolone::operator* (Zespolone &N) {
  Zespolone result;
  result.real = real*N.real + (-1*imag*N.imag);
  result.imag = imag*N.real + real*N.imag;
  return result;
}

ostream& operator<<(ostream& os,const Zespolone &N) {
  if (N.imag >=0) {
  os << "Liczba wynosi: \n" << N.real << "+" << N.imag << "j" << endl;
  }
  if (N.imag <0) {
  os << "Liczba wynosi: \n" << N.real << N.imag << "j" << endl;
  }
  return os;
}

istream& operator>>(istream& is, Zespolone &N) {
  cout << "Podaj czesc rzeczywista liczby: " << endl;
  is >> N.real;
  cout << "\nPodaj czesc urojona liczby: " << endl;
  is >> N.imag;
  return is;
  
}


int main()
{
  Zespolone A,B,C,D;
  cin >> A;
  cin >>B;
  C = A + B;
  cout << C;
  D = A * B;
  cout << D; 
  return 0;
}