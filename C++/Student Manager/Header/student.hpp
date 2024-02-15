/*
    File:   student.h
    Author: Thanh Tam
    Date:   19/1/2024
    Description: This header file declare functions for file student.cpp
*/
#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <string>

using namespace std;

typedef enum{
    MALE,
    FEMALE
}Gender;

typedef enum{
    DISTINCTION,
    CREDIT,
    AVERAGE,
    POOR
}AcademicPerformance;

class Student{
    private:
        float maths;
        float physics;
        float chemistry;
        int studentCode;
        string name;
        int age;
        Gender gender;
    public:
        Student(string name = "", int age = 0, Gender gender = MALE, float maths = 0, float physics = 0, float chemistry = 0);               
        
        void setName(string name);
        void setAge(int age);
        void setGender(Gender gender);
        void setMathsScore(float maths);
        void setPhysicsScore(float physics);
        void setChemistryScore(float chemistry);

        string getName();
        Gender getGender();
        int getAge();
        int getStudentCode();
        float getMathsScore();
        float getPhysicsScore();
        float getChemistryScore();
        float getAverageScore();
        AcademicPerformance getAcademicPerformance();
};

#endif