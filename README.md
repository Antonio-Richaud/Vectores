# Simulación de sistema vectorial 👾

Este proyecto simula un sistema simple con tres cuerpos que interactúan gravitacionalmente. La simulación se visualiza en una pantalla, mostrando las posiciones y velocidades de los cuerpos en tiempo real.

Archivos del Proyecto

- ThreeBody.cpp: Contiene la lógica principal de la simulación, incluyendo la definición de la estructura Body y las funciones para actualizar y visualizar los cuerpos.
- vec2.h: Define la estructura vec2 para representar vectores 2D, con operadores y funciones auxiliares para cálculos vectoriales.
- screen.h: Define la clase Screen para la visualización gráfica de los cuerpos celestes en la simulación.

## Requisitos

- Un compilador de C++ compatible con C++11 o superior.
- Bibliotecas estándar de C++.

## Compilación

Para compilar el proyecto, asegúrate de tener todos los archivos necesarios (ThreeBody.cpp, vec2.h, screen.h) en el mismo directorio.

- Luego, ejecuta el siguiente comando en la terminal:
    ```bash
    g++ -o simulacion main.cpp -std=c++11
    ```

### Ejecución
- Una vez compilado, puedes ejecutar el programa con el siguiente comando:
    ```bash
    ./simulacion
    ```

## Estructura del Código

### ThreeBody.cpp

- Body: Estructura que representa un cuerpo celeste, con atributos como radio, masa, posición, velocidad y aceleración.
- Constructores: Tres constructores para inicializar un Body con diferentes parámetros.
#### Métodos:
- setPos(float x, float y): Establece la posición del cuerpo.
- PulledBy(const Body& other): Calcula la atracción gravitatoria ejercida por otro cuerpo.
- Update(float dt): Actualiza la posición y velocidad del cuerpo en función del tiempo.
- Función Plot: Dibuja un cuerpo y su velocidad en la pantalla.
- Función main: Inicializa los cuerpos y la pantalla, y ejecuta la simulación en un bucle infinito.

### vec2.h

- Define la estructura vec2 para representar vectores en 2D.
- Sobrecarga de operadores para operaciones vectoriales como suma, resta, multiplicación y división.
- Métodos auxiliares como normalize para normalizar un vector.

### screen.h

- Define la clase Screen para manejar la visualización gráfica.
- Métodos para dibujar círculos y líneas en la pantalla, limpiar la pantalla y actualizar la visualización.

## Notas

- La constante de gravitación universal G se ha fijado en 1.0 para simplificar la simulación.
- La simulación se ejecuta en un bucle infinito. Puedes modificar el código para agregar condiciones de salida según tus necesidades.

---

**Conecta conmigo en alguna de mis redes sociales 🤓**

Si deseas seguir mi progreso o conectar conmigo, puedes hacerlo a través de mis redes sociales o visitar mi portafolio web:

[![LinkedIn](https://img.shields.io/badge/-LINKEDIN-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/antonio-richaud/)
[![X](https://img.shields.io/badge/-(Twitter)-000000?style=for-the-badge&logo=X&logoColor=white)](https://twitter.com/Antonio_Richaud)
[![Youtube](https://img.shields.io/badge/-YOUTUBE-D14836?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/@AntonioRichaud/)
[![TIKTOK](https://img.shields.io/badge/-TIKTOK-000000?style=for-the-badge&logo=tiktok&logoColor=white)](https://www.tiktok.com/@antonio_richaud)
[![Antonio-Richaud.com](https://img.shields.io/badge/-ANTONIORICHAUD.COM-8E2DE2?style=for-the-badge&logo=react&logoColor=white)](https://antonio-richaud.com/)

---