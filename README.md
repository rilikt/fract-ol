# 🌀 Fractol – Interactive Fractal Renderer in C

This project is an introduction to computer graphics through **fractal generation**, using the **MiniLibX** library in C. The goal was to render beautiful, zoomable fractals and manage user interaction through mouse and keyboard events.

It was a fun way to apply math and complex numbers to visuals, and also the first time working with a graphical rendering loop in C.

---

## 🎯 Features

- Rendered both **Mandelbrot** and **Julia** sets
- Smooth **zooming with the mouse wheel**
- Dynamic Julia sets with customizable parameters via CLI
- Colored rendering to visualize fractal depth and iterations
- Graceful window management (ESC key, window close button)

---

## ⚙️ Usage

### 🛠️ Build

```bash
make
```

### 🚀 Run

```bash
./fractol mandelbrot
./fractol julia
./fractol julia <real_part> <imaginary_part>
```

### 💡 Example

```bash
./fractol julia -0.8 0.156
```

---

## 🖱️ Controls

- **Scroll**: Zoom in/out around cursor
- **Arrow keys**: Move viewport (bonus)
- **ESC**: Exit the program
- **Close button**: Graceful shutdown

---

## 🖌️ Bonus Features

- Added a **third fractal type** (e.g., Burning Ship)
- **Mouse-centric zoom** for intuitive navigation
- View shifting with arrow keys
- Animated **color shifting** for psychedelic effect
