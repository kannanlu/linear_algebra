#ifndef VECTORHEADER
#define VECTORHEADER

class Vector
{
private:
    double* data;
    int size;
public:
    // override copy constructor to really copy the data
    Vector(const Vector& other_vector);
    Vector(int n);
    // destructor
    ~Vector();
    int get_size() const;
    double& operator[](int ii);
    // read only entry retrieving
    double read(int ii) const;
    Vector& operator=(const Vector& other_vector);
    Vector operator+() const;
    Vector operator-() const;
    Vector operator+(const Vector& v1) const;
    Vector operator-(const Vector& v1) const;
    Vector operator*(double a) const;
    double calc_norm(int p = 2) const;
    friend int length(const Vector& v);
};

#endif