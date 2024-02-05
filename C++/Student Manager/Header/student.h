/*
    File:   student.h
    Author: Thanh Tam
    Date:   19/1/2024
    Description: This header file declare functions and macro for file student.cpp
*/
#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>

typedef enum{
    NAM,
    NU
}GioiTinh;


class Student{
    private:
        string  ten;
        int tuoi;
        GioiTinh gioiTinh;
        float diemToan;
        float diemLy;
        float diemHoa;
        
    public:

}


#endif