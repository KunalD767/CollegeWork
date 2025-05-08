package com.mycompany.hibernatecrud;

import java.io.Serializable;
import javax.persistence.*;

@Entity
@Table(name = "STUDENT")
public class Student implements Serializable {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;

    @Column(name = "COURSE")
    private String course;

    @Column(name = "ROLL_NUMBER")
    private int rollNumber;

    @Column(name = "STUDENT_NAME")
    private String studentName;

    public Student() {}

    public Student(String course, int rollNumber, String studentName) {
        this.course = course;
        this.rollNumber = rollNumber;
        this.studentName = studentName;
    }

    public int getId() {
        return id;
    }

    public String getCourse() {
        return course;
    }

    public void setCourse(String course) {
        this.course = course;
    }

    public int getRollNumber() {
        return rollNumber;
    }

    public void setRollNumber(int rollNumber) {
        this.rollNumber = rollNumber;
    }

    public String getStudentName() {
        return studentName;
    }

    public void setStudentName(String studentName) {
        this.studentName = studentName;
    }
}
