# 📊 PageRank en C

## 🧠 Descripción

Este proyecto implementa el algoritmo **PageRank**, una técnica fundamental para la clasificación de nodos dentro de un grafo, ampliamente conocida por su uso en motores de búsqueda.

La implementación busca evaluar si un ranking basado en la **estructura del grafo** puede mejorar la clasificación tradicional basada únicamente en la cantidad de enlaces, introduciendo un enfoque que prioriza la **calidad de las referencias**.

En la era de la información, donde el acceso eficiente a datos es crucial, PageRank surge como una solución robusta para la organización y búsqueda de información. Basado en **cadenas de Markov**, este algoritmo estima la relevancia de un nodo considerando la probabilidad de referencia a él a través de enlaces.

Este proyecto fue desarrollado en el contexto de la materia **Diseño de Sistemas con Procesadores**, explorando la aplicación práctica de este algoritmo en C.

---

## ⚙️ Características

* Implementación del algoritmo PageRank desde cero en C
* Soporte para dos tipos de entrada:

  * 📌 Matrices de adyacencia (`.txt`)
  * 📌 Listas de enlaces
* Lectura dinámica de archivos
* Cálculo iterativo hasta convergencia (ε)
* Uso de factor de amortiguación (α)

---

## 🗂️ Estructura del proyecto

```
.
├── main.c
├── Makefile
├── pagerank_subfunctions.h
├── files_handling.h
├── matrix_handling.h
├── vector_handling.h
├── Lista.txt
├── Matrix.txt
├── Matrix2.txt
├── Matrix3.txt
├── Matrix4.txt
├── Matrix5.txt
```

---

## 📥 Formato de entrada

### 🔹 Opción 1: Matriz

Archivo `.txt` con una matriz de adyacencia:

```
0 1 0 0
1 0 1 0
0 1 0 1
0 0 1 0
```

---

### 🔹 Opción 2: Lista

Formato:

```
N
fila columna valor
fila columna valor
...
```

📌 Donde:

* `N` = número de nodos
* `fila` → nodo origen
* `columna` → nodo destino
* `valor` → peso del enlace

⚠️ Si un enlace no aparece, se asume valor 0.

---

## 🚀 Compilación y ejecución

Este proyecto usa **Makefile**.

### 🔧 Compilar:

```bash
make
```

### 🐞 Compilar en modo debug:

```bash
make main-debug
```

### ▶️ Ejecutar:

```bash
./main
```

### 🧹 Limpiar:

```bash
make clean
```

---

## 🧮 Parámetros del algoritmo

En `main.c`:

```c
#define ALPHA 0.85
#define EPSILON 0.001
```

* **ALPHA (α):** Factor de amortiguación
* **EPSILON (ε):** Criterio de convergencia

---

## 🧪 Archivos de prueba

* `Matrix4.txt` → matriz no estocástica (para validar robustez)
* `Lista.txt` y `Matrix5.txt` → representan el mismo grafo
* `Matrix2.txt`, `Matrix3.txt` → casos de prueba adicionales

---

## 📚 Fundamento teórico

El algoritmo PageRank modela la navegación en la web como una **cadena de Markov**, donde:

* Cada nodo representa una página
* Las transiciones dependen de los enlaces
* El ranking corresponde al estado estacionario del sistema

---

## 👨‍💻 Autores

* Juan David Aarón Parra, Jose Esteban Robayo y Eugenio Vega
* Proyecto académico – Pontificia Universidad Javeriana

---

## 📌 Notas

* El programa detecta automáticamente el tipo de archivo
* Es importante respetar el formato de entrada
* El algoritmo puede no funcionar correctamente si el formato es inválido

---

## ✨ Futuras mejoras

* Visualización de grafos
* Optimización de memoria
* Paralelización del cálculo
* Interfaz gráfica

---

## 💡 Agradecimientos

Gracias por revisar este proyecto 🙌
Si tienes sugerencias o encuentras errores, ¡no dudes en contribuir!
