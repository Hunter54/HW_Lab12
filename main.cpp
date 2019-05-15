#include <iostream>

template <class T,class U> class Complex{
private:
    T r;
    U i;

public:
    Complex add(Complex c);
    T real();
    U imag();
    Complex(T r, U i);


};
typedef Complex<int,int> complexi;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

template <class T,class U> Complex<T,U> Complex<T,U>::add(Complex c) {

}

template <class T,class U> Complex<T,U>::Complex(T r, U i):r{r},i{i} {
    std::cout<<"Constructor called";
}

template <class T,class U> T Complex<T,U>::real() {
    return real;
}

template <class T,class U> U Complex<T,U>::imag() {
    return imag;
}