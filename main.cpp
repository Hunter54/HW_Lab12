#include <iostream>


template <class T> class complex{
private:
    T re;
    T im;

public:
    complex add(T c);
    complex add(complex c);
    T real();
    T imag();
    void setReal(T c);
    complex(T r=0, T i=0):re{r},im{i}
    {};
    complex(const complex <T> &rhs):complex(rhs.re,rhs.im)
    {};


};
typedef complex<int> complexi;

void Assert(bool expression, const char* message) {
    if (!expression) {
        std::cout << "Assertion failed: " << message << std::endl;
    }
}

void testComplexClass1() {
    complexi c{1, 2};

    Assert(c.real()==1, "Real part mismatch");
    Assert(c.imag()==2, "Imag part mismatch");
}

void testComplexClass2() {
    complexi c1{1, 2}, c2{2, 3};

    Assert(c1.add(c2).real()==3, "Addition: real part mismatch");
    Assert(c1.real()==1, "Addition: operand has been modified");
    Assert(c2.add(c1).imag()==5, "Addition: imag part mismatch");
    Assert(c2.real()==2, "Addition: operand has been modified");
}

void testComplexClass3() {
    complexi c{1, 2};

    Assert(c.add(2).real()==3, "Scalar addition: real part mismatch");
    Assert(c.add(2).imag()==2, "Scalar addition: imag part mismatch");
    Assert(c.real()==1, "Scalar addition:operand has been changed");
    Assert(c.imag()==2, "Scalar addition:operand has been changed");
}

void testComplexClass4() {
    complexi c1, c2{2}, c3{3,4}, c4{0, 1}, c5=c2;

    Assert(c1.real()==0 && c1.imag()==0, "c1 mis-initialized.");
    Assert(c2.real()==2 && c2.imag()==0, "c2 mis-initialized.");
    Assert(c3.real()==3 && c3.imag()==4, "c3 mis-initialized.");
    Assert(c4.real()==0 && c4.imag()==1, "c4 mis-initialized.");
    Assert(c5.real()==2 && c5.imag()==0, "c5 mis-initialized.");
}

void f(complexi c) {
    std::cout << "Aha... copy ctor has been called." << std::endl;
    c.setReal(-1);
}

void g(complexi& c) {
    std::cout << "Oohoo.. no ctor has been called." << std::endl;
    c.setReal(-1);
}

void testComplexClass5() {
    complexi c{3, 4};
    f(c);
    Assert(c.real()==3 && c.imag()==4, "c has been modified.");
    g(c);
    Assert(c.real()==-1 && c.imag()==4, "c not been modified.");
}

int main() {
    testComplexClass1();
    testComplexClass2();
    testComplexClass3();
    testComplexClass4();
    testComplexClass5();
    return 0;
}

template <class T> complex<T> complex<T>::add(T c) {
    complex<T> h{re+c,im};
    return h;
}

template <class T> complex<T> complex<T>::add(complex c){
    complex<T> h{re+c.re,im+c.im};
    return h;
}

template <class T> T complex<T>::real() {
    return re;
}

template <class T> T complex<T>::imag() {
    return im;
}

template <class T> void complex<T>::setReal(T c) {
    re=c;
}