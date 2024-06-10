#include <cmath>  // Incluir la biblioteca cmath para usar la función sqrt

// Estructura para representar un vector 2D
struct vec2
{
    float x, y;

    // Constructor por defecto que inicializa x e y a 0.0
    vec2() : x(0.0f), y(0.0f) {}

    // Constructor que inicializa x e y con valores dados
    vec2(float x, float y) : x(x), y(y) {}

    // Constructor que inicializa x e y con el mismo valor
    vec2(float k) : x(k), y(k) {}

    // Sobrecarga del operador + para sumar dos vectores
    vec2 operator + (const vec2& v) const
    {
        return vec2(x + v.x, y + v.y);
    }

    // Sobrecarga del operador - para restar dos vectores
    vec2 operator - (const vec2& v) const
    {
        return vec2(x - v.x, y - v.y);
    }

    // Sobrecarga del operador * para el producto punto de dos vectores
    float operator * (const vec2& v) const
    {
        return x * v.x + y * v.y;
    }

    // Sobrecarga del operador * para escalar un vector por un escalar
    vec2 operator * (float k) const
    {
        return vec2(k * x, k * y);
    }

    // Sobrecarga del operador / para dividir un vector por un escalar
    vec2 operator / (float k) const
    {
        return vec2(x / k, y / k);
    }

    // Sobrecarga del operador += para sumar otro vector a este vector
    void operator += (const vec2& v)
    {
        x += v.x;
        y += v.y;
    }

    // Sobrecarga del operador -= para restar otro vector a este vector
    void operator -= (const vec2& v)
    {
        x -= v.x;
        y -= v.y;
    }

    // Sobrecarga del operador *= para escalar este vector por un escalar
    void operator *= (float k)
    {
        x *= k;
        y *= k;
    }

    // Sobrecarga del operador /= para dividir este vector por un escalar
    void operator /= (float k)
    {
        x /= k;
        y /= k;
    }

    // Sobrecarga del operador - para negar este vector
    vec2 operator - () const
    {
        return vec2(-x, -y);
    }

    // Función para calcular la magnitud cuadrada del vector
    float magnitude2() const
    {
        return x * x + y * y;
    }

    // Función para calcular la magnitud del vector
    float magnitude() const
    {
        return std::sqrt(magnitude2());
    }

    // Función para normalizar el vector
    void normalize()
    {
        float mag = magnitude();
        if (mag == 0.0f)
            return;
        *this /= mag;
    }
};

// Sobrecarga del operador * para escalar un vector por un escalar (orden inverso)
vec2 operator * (float k, const vec2& v)
{
    return v * k;
}