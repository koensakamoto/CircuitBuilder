# CircuitBuilder

A **Qt-based educational game** for learning digital logic circuits through interactive, level-based challenges.


## Overview

CircuitBuilder teaches digital logic by letting players **build and test circuits** using drag-and-drop logic gates. You'll progress through **12 levels**, each with increasing complexity, designing circuits to match given truth tables.

Perfect for students learning digital logic, computer science fundamentals, or anyone curious about how computers process information at the gate level.

## 🚀 Key Features

### 🔌 **Core Gameplay**
- **Interactive Logic Gates** — AND, OR, NOT, NAND, NOR, XOR, XNOR
- **Drag-and-Drop Building** — Snap-to-grid workspace for clean layouts  
- **Real-Time Evaluation** — Instantly test your circuit against the expected truth table
- **Level Progression** — From basic gates to multi-gate, three-input logic

### 📚 **Educational Tools**
- **Truth Table Display** — See the required input/output behavior
- **Hint System** — Level-specific guidance if your solution fails
- **Signal Flow Animation** — Visual feedback during evaluation
- **Intro Explanations** — Learn logic concepts as you go

### 🎨 **User Interface**
- **Grid Workspace** — Organize gates neatly with snapping
- **Box2D Physics** — Realistic gate movement and deletion animations
- **Tool Modes** — Wire mode, delete mode, and normal mode
- **Level Selection Menu** — Play sequentially or jump to specific levels

## 🛠️ Getting Started

### **Prerequisites**
- **Qt 5.x or Qt 6.x**
- **C++17** compatible compiler
- **Box2D** (included in repo)

### **Build Instructions**

#### **Using Qt Creator** (Recommended)
```bash
# Open the project in Qt Creator
qtcreator CircuitBuilder.pro

# Configure your build kit
# Build: Ctrl+B (⌘+B on Mac)
# Run: Ctrl+R (⌘+R on Mac)
```

#### **Using Command Line**
```bash
qmake CircuitBuilder.pro
make
./CircuitBuilder
```

## 🎮 How to Play

### **Basic Workflow**
1. **Launch the game** and choose **Start Game** or select a specific level
2. **Add gates** from the toolbar to the workspace
3. **Connect gates**:
   - Enable **wire mode** 🔗
   - Click a gate's output → click the target gate's input
4. **Toggle inputs** to test different signal states
5. **Evaluate your circuit**:
   - Click **Evaluate Circuit** ⚡
   - Watch the signal animation and compare results
6. **Advance or retry**:
   -  Pass → move to next level
   -  Fail → view hints and adjust your design

### **Controls & Tools**

| Tool | Action | Description |
|------|--------|-------------|
| 🖱️ **Drag** | Move gates around workspace | Snaps to grid automatically |
| 🔗 **Wire Mode** | Connect gate outputs to inputs | Creates logical connections |
| 🗑️ **Delete Mode** | Remove gates or connections | Click to delete |
| 🧹 **Clear** | Remove all gates | Start fresh |
| 🏠 **Menu** | Return to level selection | Save progress |

### **Tips for Success**
- 💡 Start simple — test basic connections before building complex circuits
- 📊 Study the truth table carefully before designing
- 🔄 Use the hint system if stuck — it provides specific guidance
- ⚡ Toggle input gates to manually test your circuit logic

## 📈 Level Breakdown

| Levels | Difficulty | Focus | Skills Learned |
|--------|------------|-------|----------------|
| **1–2** | 🟢 Beginner | Direct connections, NOT gate | Basic signal flow |
| **3–8** | 🟡 Intermediate | All standard gates | AND, OR, NAND, NOR, XOR, XNOR |
| **9–12** | 🔴 Advanced | Multi-gate circuits | Complex logic, 3-input challenges |

### **Sample Level Progression**
- **Level 1**: Simple wire (input → output)
- **Level 3**: AND gate logic
- **Level 7**: XOR implementation using basic gates
- **Level 12**: Complex 3-input majority function

## 📁 Project Structure

```
CircuitBuilder/
├── 📄 main.cpp                 # Application entry point
├── 🖥️ mainwindow.{h,cpp,ui}    # Main UI and view logic
├── 🔧 Circuit.{h,cpp}          # Circuit model and evaluation
├── ⚡ Gate.{h,cpp}             # Logic gate implementation
├── 📊 TruthTable.{h,cpp}       # Truth table data structure
├── 🎛️ draggablebutton.{h,cpp}  # Interactive gate UI elements
├── 🎯 Box2D/                   # Physics engine (included)
├── 🖼️ rsc.qrc                  # Resource images
└── ⚙️ CircuitBuilder.pro       # Qt
