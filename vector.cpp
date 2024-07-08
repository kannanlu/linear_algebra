#include "vector.hpp"
#include <cassert>
#include <cmath>

Vector::Vector(const Vector& other_vector) {
    size = other_vector.get_size();
    data = new double [size];
    for (int ii=0; ii<size; ii++) {
        data[ii] = other_vector.data[ii];
    }
}

Vector::Vector(int n) {
    assert(n > 0);
    size = n;
    data = new double [size];
    for (int ii=0; ii<size; ii++) {
        data[ii] = 0.0;
    }
}

// override destructor to free memory correctly
Vector::~Vector() {
    delete[] data;
}

int Vector::get_size() const {
    return size;
}

double& Vector::operator[](int ii) {
    assert(ii>-1);
    assert(ii<size);
    return data[ii];
}

double Vector::read(int ii) const {
    assert(ii>-1);
    assert(ii<size);
    return data[ii];
}

Vector& Vector::operator=(const Vector& other_vector) {
    assert(size == other_vector.size);
    for (int ii=0;ii<size;ii++) {
        data[ii] = other_vector.data[ii];
    }
    return *this;
}

Vector Vector::operator+() const {
    Vector v(size);
    for (int ii=0; ii<size; ii++) {
        v[ii] = data[ii];
    }
    return v;
}

Vector Vector::operator-() const {
    Vector v(size);
    for (int ii=0; ii<size; ii++) {
        v[ii] = -data[ii];
    }
    return v;
}

Vector Vector::operator+(const Vector& v1) const {
    assert(size == v1.size);
    Vector v(size);
    for (int ii=0; ii<size; ii++) {
        v[ii] = data[ii] + v1.data[ii];
    }
    return v;
}

Vector Vector::operator-(const Vector& v1) const {
    assert(size == v1.size);
    Vector v(size);
    for (int ii=0; ii<size; ii++) {
        v[ii] = data[ii] - v1.data[ii];
    }
    return v;
}

Vector Vector::operator*(double a) const {
    Vector v(size);
    for (int ii=0; ii<size; ii++) {
        v[ii] = data[ii] * a;
    }
    return v;
}

double Vector::calc_norm(int p = 2) const {
    double norm_val, sum = 0.0;
    for (int ii=0; ii<size; ii++) {
        sum += pow(fabs(data[ii]), p);
    }
    norm_val = pow(sum, 1.0/((double) p));
    return norm_val;
}

int length(const Vector& v) {
    return v.size;
}