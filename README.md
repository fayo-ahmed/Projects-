# Projects

This repository contains two projects:
1. **Loan Application Portal**
2. **Pig Game with Process Scheduling Algorithms**

---

## 1. Loan Application Portal

### Overview
The **Loan Application Portal** is a web application that allows users to submit loan applications, check the status of their applications, and update application statuses. It is built using **Flask** for the backend and **JavaScript** for the frontend.

### Features
- **Submit Loan Application**: Users can submit their name and zipcode to apply for a loan.
- **Check Application Status**: Users can check the status of their application using their application number.
- **Update Application Status**: Admins can update the status of an application (e.g., `received`, `processing`, `accepted`, `rejected`).
- **View All Applications**: Admins can view all submitted applications for testing and debugging purposes.

### Technologies Used
- **Backend**: Flask (Python)
- **Frontend**: HTML, CSS, JavaScript
- **Database**: In-memory storage (for simplicity during development)

### Setup Instructions
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/projects-folder.git
   cd projects-folder/Loan-Application-Portal
   ```

2. **Install Dependencies**:
   ```bash
   pip install flask
   ```

3. **Run the Application**:
   ```bash
   python app.py
   ```

4. **Access the Application**:
   Open your browser and navigate to `http://localhost:5000`.

---

## 2. Pig Game with Process Scheduling Algorithms

### Overview
The **Pig Game with Process Scheduling Algorithms** is a simulation of the classic Pig dice game integrated with process scheduling algorithms (FCFS, SJF, Round Robin). It is implemented in **C++** and **Verilog**, with real-time testing on **FPGA boards**.

### Features
- **Pig Game Simulation**: Simulates the Pig dice game with multiple players.
- **Scheduling Algorithms**: Implements FCFS, SJF, and Round Robin algorithms to manage player turns.
- **Performance Metrics**: Evaluates waiting time, fairness, and efficiency of scheduling algorithms.
- **FPGA Integration**: Real-time testing and validation on FPGA boards.

### Technologies Used
- **Programming Languages**: C++, Verilog
- **Hardware**: FPGA boards
- **Tools**: Simulation tools for Verilog and C++

### Setup Instructions
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/projects-folder.git
   cd projects-folder/Pig-Game
   ```

2. **Compile and Run C++ Code**:
   ```bash
   g++ pig_game.cpp -o pig_game
   ./pig_game
   ```

3. **Run Verilog Simulation**:
   Use a Verilog simulator (e.g., ModelSim) to run the Verilog code and test the game logic.

4. **FPGA Testing**:
   Upload the Verilog code to an FPGA board for real-time testing.

---