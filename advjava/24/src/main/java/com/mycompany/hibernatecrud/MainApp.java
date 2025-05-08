package com.mycompany.hibernatecrud;
public class MainApp {
    public static void main(String[] args) {
        studentDAO dao = new studentDAO();

        // Create
        Student s1 = new Student("MCA", 1, "Dinesh Rajput");
        Student s2 = new Student("PGDCP", 2, "Anamika Rajput");
        dao.createStudent(s1);
        dao.createStudent(s2);

        // Read
        Student fetched = dao.getStudent(s1.getId());
        System.out.println("Fetched: " + fetched.getStudentName() + " - " + fetched.getCourse());

        // Update
        fetched.setCourse("MDCP");
        dao.updateStudent(fetched);

        // List All
        System.out.println("All Students:");
        for (Student s : dao.listStudents()) {
            System.out.println(s.getId() + ": " + s.getStudentName() + " - " + s.getCourse());
        }

        // Delete
        dao.deleteStudent(fetched.getId());
    }
}
