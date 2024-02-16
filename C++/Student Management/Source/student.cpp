#include <student.hpp>

/*
 Description: This constructor initializes a Student object with the provided parameters..
 Input:
    name: The name of the student.
    age: The age of the student.
    gender: The gender of the student (Gender enum type).
    maths: The score in the mathematics subject.
    physics: The score in the physics subject.
    chemistry: The score in the chemistry subject.
 Output: None
*/
Student :: Student(string name, int age, Gender gender, float maths, float physics, float chemistry){
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->maths = maths;
    this->physics = physics;
    this->chemistry = chemistry;
    static int id = 1000;
    this->studentCode = id;
    id++;
}

/*
Description: This function sets the name of the student to the provided value.
Input: The name of student
Output: None
*/
void Student :: setName(string name){
    this->name = name;
}

/*
Description: This function sets the age of the student to the provided value.
Input: The age of student
Output: None
*/
void Student :: setAge(int age){
    this->age = age;
}

/*
Description: This function sets the gender of the student to the provided value.
Input: The gender of student
Output: None
*/
void Student :: setGender(Gender gender){
    this->gender = gender;
}

/*
Description: This function sets the mathematics score of the student to the provided value.
Input: The mathematics score of the student.
Output: None
*/
void Student :: setMathsScore(float maths){
    this->maths = maths;
}

/*
Description: This function sets the physics score of the student to the provided value.
Input: The physics score of the student.
Output: None
*/
void Student :: setPhysicsScore(float physics){
    this->physics = physics;
}

/*
Description: This function sets the chemistry score of the student to the provided value.
Input: The chemistry score of the student.
Output: None
*/
void Student :: setChemistryScore(float chemistry){
    this->chemistry = chemistry;
}

/*
Description: This function returns the name of the student.
Input: None
Output: The name of the student.
*/
string Student :: getName(){
    return this->name;
}

/*
Description: This function returns the age of the student.
Input: None
Output: The age of the student.
*/
int Student :: getAge(){
    return this->age;
}

/*
Description: This function returns the gender of the student.
Input: None
Output: The gender of the student.
*/
Gender Student :: getGender(){
    return this->gender;
}

/*
Description: This function returns the student code of the student.
Input: None
Output: The student code of the student.
*/
int Student :: getStudentCode(){
    return this->studentCode;
}

/*
Description: This function returns the mathematics score of the student.
Input: None
Output: The mathematics score of the student.
*/
float Student :: getMathsScore(){
    return this->maths;
}

/*
Description: This function returns the physics score of the student.
Input: None
Output: The physics score of the student.
*/
float Student :: getPhysicsScore(){
    return this->physics;
}

/*
Description: This function returns the chemistry score of the student.
Input: None
Output: The chemistry score of the student.
*/
float Student :: getChemistryScore(){
    return this->chemistry;
}

/*
Description: This function returns the average score of the student.
Input: None
Output: The average score of the student.
*/
float Student :: getAverageScore(){
    return (this->maths + this->physics + this->chemistry)/3;
}

/*
Description: This function determines the academic performance of the student based on their average score.
Input: None
Output: The academic performance of the student.
*/
AcademicPerformance Student :: getAcademicPerformance(){
    if(getAverageScore() >= 8)
        return DISTINCTION;
    else if(getAverageScore() >= 7)
        return CREDIT;
    else if(getAverageScore() >= 5)
        return AVERAGE;
    else
        return POOR;    
}