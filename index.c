// Saving the provided C code into a .c file.

c_code = ""
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_ROWS 1000
#define MAX_PASSWORD_LENGTH 100

struct patients {
    char firstName[20];
    char lastName[20];
    char dob[9];
    char height[10];
    char waist[10];
    char weight[10];
    char comment[100];
};

// Function Prototypes
void validateString(char arr[]);
void validateDob(char arr[]);
void validateHeight(char arr[]);
int nursePass(void);
void emptyBuffer(void);
int addPatientFile(struct patients arrPatients[], int endArray);
char *encrypt(char arr[]);
int menu(void);
void menuFunction(int choice, struct patients arrPatients[], int endArray);

int main(void) {
    struct patients arrPatients[30];
    int endArray = 0;
    char arr[100];
    nursePass();
    int choice = menu();
    while(choice != 2) {
        menuFunction(choice, arrPatients, endArray);
        choice = menu();
    }
    printf("You have exited the program\\n");
    return 0;
}

void menuFunction(int choice, struct patients arrPatients[], int endArray) {
    switch(choice) {
        case 1:
            addPatientFile(arrPatients, endArray);
            break;
        case 2:
            printf("You have exited the program\\n");
            break;
        default:
            printf("Invalid choice\\n");
            break;
    }
}

int menu(void) {
    int choice;
    printf("<-----------------Main Menu--------------->\\n");
    printf("1 - Add a patient\\n");
    printf("2 - Exit\\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int addPatientFile(struct patients arrPatients[], int endArray) {
    struct patients newPatient;
    newPatient = arrPatients[endArray];
    printf("<---------------Enter Patient Details--------------->\\n");
    printf("Enter first name: ");
    emptyBuffer();
    validateString(newPatient.firstName);
    printf("Enter last name: ");
    validateString(newPatient.lastName);
    printf("Enter date of birth (ddmmyyyy): ");
    validateDob(newPatient.dob);
    printf("Enter height(cm): ");
    validateHeight(newPatient.height);
    printf("Enter waist(inches): ");
    validateHeight(newPatient.waist);
    printf("Enter weight(kg): ");
    validateHeight(newPatient.weight);
    printf("Enter comment: ");
    scanf("%[^\n]", newPatient.comment);
    endArray++;
    
    char filename[30];
    sprintf(filename, "%s%s.aow", newPatient.lastName, newPatient.dob);
    printf("File name is %s\\n", filename);
    
    FILE *fptr = fopen(filename, "w");
    if(fptr == NULL) {
        printf("Error opening file\\n");
        return 1;
    }
    
    encrypt(newPatient.firstName);
    encrypt(newPatient.lastName);
    encrypt(newPatient.dob);
    encrypt(newPatient.height);
    encrypt(newPatient.waist);
    encrypt(newPatient.weight);
    encrypt(newPatient.comment);
    
    fprintf(fptr, "%s \\n%s \\n%s \\n%s \\n%s \\n%s \\n%s", newPatient.firstName, newPatient.lastName,
            newPatient.dob, newPatient.height, newPatient.waist, newPatient.weight, newPatient.comment);
    fclose(fptr);
    return endArray;
}

void validateString(char arr[]) {
    while(!(scanf("%20[A-Za-z]", arr)) || getchar() == '\\n') {
        emptyBuffer();
        printf("Invalid input, please try again: ");
    }
}

void validateDob(char arr[]) {
    while(!(scanf("%8[0-9]", arr)) || strlen(arr) > 8 || getchar() == '\\n') {
        emptyBuffer();
        printf("Invalid input, please try again: ");
    }
}

void validateHeight(char arr[]) {
    while(!(scanf("%3[0-9]", arr)) || strlen(arr) > 3 || getchar() == '\\n') {
        emptyBuffer();
        printf("Invalid input, please try again: ");
    }
}

int nursePass(void) {
    printf("<-------------------Hello Nurse------------------->\\n");
    FILE *passwords = fopen("passwords.txt", "r");
    if(passwords == NULL) {
        printf("Error: File could not be opened\\n");
        return 1;
    }
    
    char arr[100];
    char password[MAX_PASSWORD_ROWS][MAX_PASSWORD_LENGTH];
    int line = 0;
    while(fgets(arr, MAX_PASSWORD_LENGTH, passwords) != NULL) {
        strcpy(password[line], arr);
        line++;
    }
    fclose(passwords);
    
    char nurseId[4];
    char nursePassword[20];
    char fullPass[MAX_PASSWORD_LENGTH];
    printf("Enter Nurse ID: ");
    scanf("%s", nurseId);
    printf("Enter Nurse PASSWORD: ");
    scanf("%s", nursePassword);
    sprintf(fullPass, "%s %s", nurseId, nursePassword);
    
    int valid = 0;
    for(int i = 0; i < line; i++) {
        if(strcmp(password[i], fullPass) == 0) {
            printf("Welcome...\\n");
            valid = 1;
            break;
        }
    }
    
    if(!valid) {
        printf("Incorrect details, please try again.\\n");
    }
    
    return 0;
}

void emptyBuffer(void) {
    while(getchar() != '\\n');
}

char *encrypt(char arr[]) {
    for(int i = 0; arr[i] != '\\0'; i++) {
        if(isalnum(arr[i])) {
            if(isalpha(arr[i])) {
                arr[i] = (islower(arr[i])) ? ((arr[i] - 'a' + 7) % 26 + 'a') : ((arr[i] - 'A' + 7) % 26 + 'A');
            } else if(isdigit(arr[i])) {
                arr[i] = (arr[i] - '0' + 7) % 10 + '0';
            }
        }
    }
    return arr;
}


// # Writing to a C file
file_path = '/mnt/data/patient_nurse_management_system.c'
with open(file_path, 'w') as c_file:
    c_file.write(c_code)

file_path
