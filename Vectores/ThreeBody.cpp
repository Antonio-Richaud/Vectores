#include <iostream>
#include "screen.h"
#include "vec2.h"

// Estructura para representar un cuerpo celeste
struct Body
{
    float r;      // Radio del cuerpo
    float m;      // Masa del cuerpo
    vec2 pos;     // Posición del cuerpo
    vec2 vel;     // Velocidad del cuerpo
    vec2 acc;     // Aceleración del cuerpo

    // Constructor por defecto
    Body() : r(0.2f), m(1.0f), pos(0), vel(0), acc(0) {}

    // Constructor que inicializa la masa y calcula el radio basado en la masa
    Body(float m) : m(m), r(0.2f * cbrt(m)), pos(0), vel(0), acc(0) {}

    // Constructor que inicializa la masa y el radio
    Body(float m, float r) : r(r), m(m), pos(0), vel(0), acc(0) {}

    // Función para establecer la posición del cuerpo
    void setPos(float x, float y)
    {
        pos.x = x;
        pos.y = y;
    }

    // Función para calcular la atracción gravitatoria ejercida por otro cuerpo
    void PulledBy(const Body& other)
    {
        const float G = 1.0f;  // Constante de gravitación universal
        float dist = sqrt((pos - other.pos) * (pos - other.pos));
        acc += G * other.m * (other.pos - pos) / dist / dist / dist;
    }

    // Función para actualizar la posición y velocidad del cuerpo
    void Update(float dt)
    {
        vel += dt * acc;
        pos += dt * vel;
        acc = 0;
    }
};

// Función para plotear el cuerpo y su velocidad en la pantalla
void Plot(const Body& body, Screen& scr)
{
    vec2 O = body.pos;
    vec2 X = body.pos + 0.5f * body.vel;

    scr.PlotCircle(body.pos.x, body.pos.y, body.r);
    scr.PlotLine(O.x, O.y, X.x, X.y);

    vec2 a = (O - X);
    a.normalize();
    a *= 0.1f;
    vec2 b = {a.y, -a.x};

    scr.PlotLine(X.x, X.y, X.x + a.x + b.x, X.y + a.y + b.y);
    scr.PlotLine(X.x, X.y, X.x + a.x - b.x, X.y + a.y - b.y);
}

int main()
{
    Screen scr(0, 0, 200);

    constexpr float dt = 1.0 / 100.0f;  // Intervalo de tiempo

    const int n = 3;  // Número de cuerpos en el sistema solar
    Body solarSystem[n];

    // Inicialización de los cuerpos celestes
    solarSystem[0].pos = {-0.97000436f, 0.24308753f};
    solarSystem[0].vel = {0.4662036850f, 0.4323657300f};
    solarSystem[0].m = 1.0f;
    solarSystem[0].r = 0.1f;

    solarSystem[1].pos = {0.0f, 0.0f};
    solarSystem[1].vel = {-0.93240737f, -0.86473146f};
    solarSystem[1].m = 1.0f;
    solarSystem[1].r = 0.1f;

    solarSystem[2].pos = {0.97000436f, -0.24308753f};
    solarSystem[2].vel = {0.4662036850f, 0.4323657300f};
    solarSystem[2].m = 1.0f;
    solarSystem[2].r = 0.1f;

    while (true)
    {
        scr.Clear();

        // Calcular las fuerzas gravitatorias entre los cuerpos
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                solarSystem[j].PulledBy(solarSystem[i]);
            }
        }

        // Actualizar las posiciones y velocidades de los cuerpos
        for (int i = 0; i < n; i++)
            solarSystem[i].Update(dt);

        // Plotear los cuerpos en la pantalla
        for (int i = 0; i < n; i++)
            Plot(solarSystem[i], scr);

        scr.Draw();  // Dibujar la pantalla actualizada

        // Imprimir las velocidades de los cuerpos
        for (auto body : solarSystem)
            printf("%+16.8f %+16.8f\n", body.vel.x, body.vel.y);
    }

    return 0;
}
