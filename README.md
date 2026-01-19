# CircuitBuilder

An educational digital logic circuit simulator that teaches boolean logic and circuit design through interactive drag-and-drop gameplay.

## Demo

https://github.com/koensakamoto/CircuitBuilder/assets/circuit-builder-demo.mp4

> **Note**: Watch the video above to see CircuitBuilder in action - building logic gates, connecting circuits, and testing with truth tables!

## How It Works

CircuitBuilder is a visual learning tool where students build digital circuits by dragging logic gates onto a canvas and connecting them with wires. The application simulates the circuit in real-time, showing how signals flow through gates and produce outputs.

### Educational Gameplay

1. **Drag & Drop Interface**: Students select logic gates from a toolbar and place them on the workspace
2. **Wire Connections**: Click and drag to connect gate inputs and outputs, creating circuit paths
3. **Input Controls**: Toggle input switches to test different signal combinations
4. **Live Simulation**: Watch as signals propagate through the circuit with visual feedback
5. **Truth Table Generation**: Automatically generates truth tables to verify circuit behavior

### Learning Objectives

- **Boolean Logic**: Understanding AND, OR, NOT operations and their combinations
- **Circuit Design**: Learning to build complex circuits from basic gates
- **Problem Solving**: Designing circuits to meet specific requirements
- **Digital Systems**: Foundation concepts for computer science and engineering

## Logic Gates Available

- **AND Gate**: Output true only when all inputs are true
- **OR Gate**: Output true when at least one input is true
- **NOT Gate**: Output opposite of input (inverter)
- **NAND Gate**: AND gate followed by NOT (universal gate)
- **NOR Gate**: OR gate followed by NOT (universal gate)
- **XOR Gate**: Output true when inputs differ (exclusive or)
- **XNOR Gate**: Output true when inputs are the same

## Educational Features

### Interactive Learning
- **Visual Feedback**: Gates light up when active, wires show signal flow
- **Real-time Testing**: Immediate results when changing inputs
- **Error Prevention**: Interface prevents invalid connections

### Assessment Tools
- **Truth Tables**: Automatic generation for circuit verification
- **Circuit Analysis**: Step-by-step signal tracing through complex circuits
- **Design Challenges**: Built-in problems like half-adders and multiplexers

### Progressive Complexity
Students start with simple single-gate circuits and advance to:
- **Combinational Logic**: Multiple gates working together
- **Arithmetic Circuits**: Half-adders, full-adders
- **Control Logic**: Multiplexers, decoders
- **Complex Systems**: Multi-bit operations

## Tech Stack

- **Frontend**: Qt 6 (C++) for responsive desktop interface
- **Containerization**: Docker for cross-platform deployment
- **Testing**: Comprehensive test suite ensuring circuit logic accuracy
- **CI/CD**: Automated testing and deployment pipeline

## Getting Started

```bash
# Clone and run with Docker
git clone https://github.com/koensakamoto/CircuitBuilder.git
cd CircuitBuilder
docker-compose up circuitbuilder
```

## Example Learning Exercise

### Building a Half-Adder

1. **Objective**: Create a circuit that adds two binary digits
2. **Components Needed**:
   - 2 Input switches (A, B)
   - 1 XOR gate (for Sum)
   - 1 AND gate (for Carry)
   - 2 Output indicators

3. **Student Process**:
   - Drag XOR gate onto canvas
   - Drag AND gate below it
   - Connect input A to both gates
   - Connect input B to both gates
   - Connect XOR output to Sum indicator
   - Connect AND output to Carry indicator

4. **Testing**: Toggle inputs to verify truth table:
   - 0+0 = Sum:0, Carry:0
   - 0+1 = Sum:1, Carry:0
   - 1+0 = Sum:1, Carry:0
   - 1+1 = Sum:0, Carry:1

This hands-on approach makes abstract boolean concepts tangible and intuitive for students learning digital logic fundamentals.