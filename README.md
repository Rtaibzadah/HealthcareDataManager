# PatientNurseManagementSystem

## Project Overview
This project is a command-line system built in C to manage patient and nurse records in a healthcare setting. It allows nurses to add patient information securely while providing consultants with the ability to manage nurse records. The project implements input validation, file handling, and data encryption using a Caesar cipher for security purposes.

## Features
- **User Authentication**: Nurses and consultants must log in to access the system.
- **Patient Management**: Nurses can add new patients to the system with details such as height, weight, and other health data.
- **Nurse Management**: Consultants can add, delete, and modify nurse credentials.
- **Data Encryption**: Patient and nurse data is stored in encrypted files for security.
- **Input Validation**: The system ensures that only valid data types are accepted for all fields (e.g., numeric values for weight).

## Program Structure
The project contains two main functionalities:
1. **Patient Record Management**: Nurses can securely add patient information that is stored in an encrypted file.
2. **Nurse Record Management**: Consultants can manage the nurse credentials (add, delete, modify) using a secure authentication process.

## Technologies Used
- **C Programming Language**: Core logic and implementation.
- **File Handling**: Storing patient and nurse data in text files.
- **Caesar Cipher**: Used for basic encryption of sensitive data.
- **Standard Libraries**: `stdio.h`, `string.h`, `ctype.h`.

## How to Run the Program
1. Clone the repository:
    ```bash
    git clone https://github.com/Rtaibzadah/HealthcareDataManager.git
    cd PatientNurseManagementSystem
    ```
2. Compile the program using GCC or any C compiler:
    ```bash
    gcc -o management_system patient_nurse_management_system.c
    ```
3. Run the executable:
    ```bash
    ./management_system
    ```


## How the Program Works
1. **Nurse Authentication**: Nurses must log in with their ID and password. The system verifies the credentials from a stored file.
2. **Patient Data Entry**: After login, nurses can enter new patient details such as first name, last name, date of birth, height, weight, and a comment. All data is encrypted and stored in a file.
3. **Consultant Management**: Consultants can manage nurse records, adding, deleting, or modifying credentials.

## Future Enhancements
- Improve the encryption algorithm for more robust security.
- Add functionality for patient record modification and deletion.
- Implement a GUI for easier interaction.

## License
There is none :)

---
