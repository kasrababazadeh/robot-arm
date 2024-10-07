# Robotic Arm Simulation

This project is a simple 3D simulation of a robotic arm implemented using OpenGL and GLUT. The robotic arm features adjustable shoulder and elbow joints that can be controlled via keyboard inputs, allowing users to simulate picking up an object.

## Features

- 3D representation of a robotic arm with two segments (shoulder and elbow).
- Real-time control of the arm's movements using keyboard inputs.
- Visual representation of a "ball" (object) that can be picked up by the arm.

## Requirements

To compile and run this project, you need the following:

- A C++ compiler (e.g., `g++`)
- OpenGL
- GLUT (OpenGL Utility Toolkit)

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/kasrababazadeh/robot-arm-simulation.git
   cd robotic-arm-simulation

2. **Compile the project:**
   ```bash
   g++ -o robot_arm robot_arm.cpp -lGL -lGLU -lglut

3. **Run the simulation:**
   ```bash
   ./robot_arm

## Controls

Use the following keys to control the robotic arm:

- **`s`**: Rotate shoulder clockwise.
- **`S`**: Rotate shoulder counterclockwise.
- **`e`**: Rotate elbow clockwise (up to 180 degrees).
- **`E`**: Rotate elbow counterclockwise (down to 0 degrees).
- **`x`**: Simulate picking up the object (green torus).
- **`c`**: Release the object (reset torus position).
- **`Esc`**: Exit the application.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Acknowledgements

- OpenGL and GLUT for providing the graphics framework.
- Community resources for guidance on OpenGL programming.
