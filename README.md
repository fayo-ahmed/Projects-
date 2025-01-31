# Projects

This repository contains two projects:
1. Loan Application Portal
2. Pig Game with Process Scheduling Algorithms
3. Inventory Management System

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
(Due to technical issues, the search service is temporarily unavailable.)

Here’s a detailed and professional **README.md** for your Inventory Management System project. It explains the purpose, features, setup instructions, and usage of the system.

---

# 3. Inventory Management System

## Overview
This project is a **custom inventory management system** designed for a medium-sized hotel's restaurant and café. The system addresses the limitations of the hotel's current software, **Chromis**, by providing a stable, user-friendly, and efficient solution for tracking and managing inventory. It is built using **Python**, **Flask** for the backend, and **SQLite** for database management.

The system helps the hotel:
- Track inventory in real-time.
- Reduce operational costs and minimize wastage.
- Generate accurate financial reports.
- Improve workflow efficiency and guest satisfaction.

---

## Features
1. **Real-Time Inventory Tracking**:
   - Monitor stock levels in real-time.
   - Automatically alert staff when stock falls below the reorder level.

2. **User-Friendly Interface**:
   - Intuitive design for easy adoption by staff.
   - Minimal learning curve for new users.

3. **Financial Reporting**:
   - Generate detailed financial reports, including stock value and total sales.

4. **Product Management**:
   - Add, update, and delete products.
   - Categorize products (e.g., food, beverages).
   - Track supplier information for each product.

5. **Low Stock Alerts**:
   - Notify staff when inventory levels are low to prevent stockouts.

6. **Cost Optimization**:
   - Provide insights into inventory turnover and carrying costs.

---

## Technologies Used
- **Backend**: Python, Flask
- **Database**: SQLite
- **Frontend**: HTML, CSS (for templates)
- **Other Tools**: SQLAlchemy (optional for advanced database management)

---

## Setup Instructions

### Prerequisites
1. **Python 3.x**: Ensure Python is installed on your system.
2. **Flask**: Install Flask using pip.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/hotel-inventory-management.git
   cd hotel-inventory-management
   ```

2. Install dependencies:
   ```bash
   pip install flask
   ```

3. Initialize the database:
   - Run the application once to create the SQLite database (`hotel_inventory.db`).

4. Run the application:
   ```bash
   python app.py
   ```

5. Access the system:
   - Open your browser and go to `http://127.0.0.1:5000/`.

---

## Usage

### Home Page
- View all products in the inventory.
- Check for low stock alerts.
- Navigate to add, update, or delete products.

### Add Product
- Add new products with details like name, category, quantity, unit price, supplier, and reorder level.

### Update Product
- Edit existing product details.

### Delete Product
- Remove products from the inventory.

### Financial Reports
- View detailed financial reports, including stock value and total sales.

---

## Project Goals
1. **Enhance System Stability**: Ensure the system is reliable and free from crashes.
2. **Reduce Staff Learning Curve**: Simplify the interface for easy adoption.
3. **Optimize Inventory Tracking**: Provide real-time visibility into stock levels.
4. **Accurate Financial Reporting**: Generate precise financial reports for better decision-making.
5. **Boost Profitability**: Optimize inventory turnover and reduce carrying costs.

---

## Scope
### In Scope
- Custom inventory database.
- User-friendly interface.
- Real-time inventory tracking and low stock alerts.
- Financial reporting and cost optimization.

### Out of Scope
- Full property management system.
- Hardware procurement.
- Supplier negotiations.
- Previous data migration (except for initial data import).

---

## Contributing
Contributions are welcome! If you'd like to contribute, please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes.
4. Submit a pull request.

---
