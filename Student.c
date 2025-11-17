// Student.c

Student* createStudent(char* name, int age, float grade) {
    Student* student = (Student*)malloc(sizeof(Student));
    student->name = strdup(name);
    student->age = age;
    student->grade = grade;
    return student;
}
void setName(Student* student, char* name) {
    free(student->name);
    student->name = strdup(name);
}
char* getName(Student student) {
    return strdup(student.name);
}
void setAge(Student* student, int age) {
    student->age = age;
}
int getAge(Student student) {
    return student.age;
}
void setGrade(Student* student, float grade) {
    student->grade = grade;
}
float getGrade(Student student) {
    return student.grade;
}
void disposeStudent(Student* student) {
    free(student->name);  //Pulisce tutti i puntatori dentro il record
    free(student);   //Pulisce il record
}
void printStudent(Student student) {
    printf("Name: %s, Age: %3d, Grade: %.2f\n", student.name, student.age, student.grade);
}
char* studentToCSV(Student student) {
    static char buffer[MAX_STRING_LENGTH];
    sprintf(buffer, "%s,%d,%.2f", student.name, student.age, student.grade);  //costruisce la stringa, assegna i campi e il risultato lo butta dentro al buffer. E' uguale alla printf
    return strdup(buffer);
}

Student* createFromCSV(char* csvLine) {  //riceve una riga dal file csv e costruisce lo studente
    Student* student;
    char** tokens = splitString(csvLine, ',');  //tokens è un vettore di stringhe
    char* name = tokens[0];
    int age = atoi(tokens[1]);
    float grade = atof(tokens[2]);
    student = createStudent(name, age, grade);
    disposeStringArray(tokens);
    return student;
}