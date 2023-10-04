<p align="center">
	<br>
    <img src="https://i.imgur.com/5f6te3x.png" alt="SQLemk Logo" width="100">
    <h3 align="center">SQLemk</h3>
    <br>
</p>

**SQLemk** is a cutting-edge project that **simulates SQL language in C++**. The application allows users to **execute SQL commands like creating tables, inserting records, and more, all within C++**. 

This project was developed as part of a course at the **Faculty of Cybernetics, Statistics, and Economic Informatics (CSIE)** within **Bucharest University of Economic Studies (ASE)**. It's designed for the subject **Object-Oriented Programming (OOP)**.

# Application Features 💪

## ✅ Command Functionality
Execute a myriad of SQL commands in C++:

- **CREATE TABLE**: Generates a new table.
- **DROP TABLE**: Removes an existing table.
- **DISPLAY TABLE**: Shows the table structure.
- **INSERT INTO**: Adds new data.
- **DELETE FROM**: Removes data.
- **SELECT**: Fetches data.
- **UPDATE**: Modifies data.
- **IMPORT/EXPORT**: Handles data via CSV files.
- **PRESETS**: Provides database templates.
  
  > Use `HELP [command_name]` for more details on each command.

## 🏢 Preset Databases
Includes ready-to-use database templates for:

- **Company**: Manages employees, departments, projects.
- **School**: Handles students, teachers, classes.
- **Library**: Takes care of books, subscribers, loans.
- **Store**: Controls products, customers, orders.
- **Game**: Covers players, items, inventory.

## 🖥️ Script Execution
Run `.sql` script files by executing:

    `SQLemk.exe script1.sql [script2.sql] ...`

## 😊 Auto-Save
The auto-save feature remembers table structures for future use.

## 📁 Record Import/Export
Utilize `.csv` files for importing and exporting data.

## 📄 Logging
Tracks all user activity, complete with time-stamps and errors.

# Additional Features 📜

- Class Implementation
  - Privacy-respected attributes.
  - Various constructors.
  - Accessor functions.
- File Types
  - `.txt`, `.csv`, `.bin` files.
- STL Utilization
  - Use of vectors, sets.

The application also throws exceptions for all possible error scenarios.

# Installation 📝

1. Clone the GitHub repository.
2. Compile the source code with a C++ compiler.
3. Run the generated executable.

> For IDEs like Visual Studio or CLion, download the project directly from the Releases section.

# Compatibility 💻

SQLemk runs on Windows, Linux, and MacOS. A compiler supporting at least C++14 is required.

# License 🪪
Licensed under the [MIT License](LICENSE).
