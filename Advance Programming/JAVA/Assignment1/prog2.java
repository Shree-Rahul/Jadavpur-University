public class prog2 {
    class Address {
        private String premisesNumber;
        private String street;
        private String city;
        private String pin;
        private String state;
    
        public Address(String premisesNumber, String street, String city, String pin, String state) {
            this.premisesNumber = premisesNumber;
            this.street = street;
            this.city = city;
            this.pin = pin;
            this.state = state;
        }
    
        public String getPremisesNumber() {
            return premisesNumber;
        }
    
        public void setPremisesNumber(String premisesNumber) {
            this.premisesNumber = premisesNumber;
        }
    
        public String getStreet() {
            return street;
        }
    
        public void setStreet(String street) {
            this.street = street;
        }
    
        public String getCity() {
            return city;
        }
    
        public void setCity(String city) {
            this.city = city;
        }
    
        public String getPin() {
            return pin;
        }
    
        public void setPin(String pin) {
            this.pin = pin;
        }
    
        public String getState() {
            return state;
        }
    
        public void setState(String state) {
            this.state = state;
        }
    }
    
    class Person {
        private String name;
        private Address address;
        private String phoneNumber;
        private String emailId;
    
        public Person(String name, Address address, String phoneNumber, String emailId) {
            this.name = name;
            this.address = address;
            this.phoneNumber = phoneNumber;
            this.emailId = emailId;
        }
    
        public String getName() {
            return name;
        }
    
        public void setName(String name) {
            this.name = name;
        }
    
        public Address getAddress() {
            return address;
        }
    
        public void setAddress(Address address) {
            this.address = address;
        }
    
        public String getPhoneNumber() {
            return phoneNumber;
        }
    
        public void setPhoneNumber(String phoneNumber) {
            this.phoneNumber = phoneNumber;
        }
    
        public String getEmailId() {
            return emailId;
        }
    
        public void setEmailId(String emailId) {
            this.emailId = emailId;
        }
    }
    
    class Student extends Person {
        private int rollNumber;
        private String courseOfStudy;
    
        public Student(String name, Address address, String phoneNumber, String emailId, int rollNumber, String courseOfStudy) {
            super(name, address, phoneNumber, emailId);
            this.rollNumber = rollNumber;
            this.courseOfStudy = courseOfStudy;
        }
    
        public int getRollNumber() {
            return rollNumber;
        }
    
        public void setRollNumber(int rollNumber) {
            this.rollNumber = rollNumber;
        }
    
        public String getCourseOfStudy() {
            return courseOfStudy;
        }
    
        public void setCourseOfStudy(String courseOfStudy) {
            this.courseOfStudy = courseOfStudy;
        }
    }
    
    class Faculty extends Person {
        private int employeeId;
        private String department;
        private String specialization;
    
        public Faculty(String name, Address address, String phoneNumber, String emailId, int employeeId, String department, String specialization) {
            super(name, address, phoneNumber, emailId);
            this.employeeId = employeeId;
            this.department = department;
            this.specialization = specialization;
        }
    
        public int getEmployeeId() {
            return employeeId;
        }
    
        public void setEmployeeId(int employeeId) {
            this.employeeId = employeeId;
        }
    
        public String getDepartment() {
            return department;
        }
    
        public void setDepartment(String department) {
            this.department = department;
        }
    
        public String getSpecialization() {
            return specialization;
        }
    
        public void setSpecialization(String specialization) {
            this.specialization = specialization;
            }
            }
            
            public class InstituteManagementSystem {
            public static void main(String[] args) {
            // Creating objects and setting attributes
            Address address = new Address("123", "Main Street", "City", "123456", "State");
            Student student = new Student("John Doe", address, "9876543210", "john@example.com", 101, "Computer Science");
            Faculty faculty = new Faculty("Jane Smith", address, "1234567890", "jane@example.com", 201, "Engineering", "Mechanical");



                // Displaying object details
    System.out.println("Student Details:");
    System.out.println("Name: " + student.getName());
    System.out.println("Roll Number: " + student.getRollNumber());
    System.out.println("Course of Study: " + student.getCourseOfStudy());
    System.out.println("Address: " + getAddressString(student.getAddress()));
    System.out.println("Phone Number: " + student.getPhoneNumber());
    System.out.println("Email ID: " + student.getEmailId());

    System.out.println();

    System.out.println("Faculty Details:");
    System.out.println("Name: " + faculty.getName());
    System.out.println("Employee ID: " + faculty.getEmployeeId());
    System.out.println("Department: " + faculty.getDepartment());
    System.out.println("Specialization: " + faculty.getSpecialization());
    System.out.println("Address: " + getAddressString(faculty.getAddress()));
    System.out.println("Phone Number: " + faculty.getPhoneNumber());
    System.out.println("Email ID: " + faculty.getEmailId());

    // Modifying the address of a person partially
    student.getAddress().setStreet("New Street");
    student.getAddress().setCity("New City");

    System.out.println();

    // Displaying modified address
    System.out.println("Updated Address for " + student.getName() + ": " + getAddressString(student.getAddress()));
}

private static String getAddressString(Address address) {
    return address.getPremisesNumber() + ", " + address.getStreet() + ", " + address.getCity() + ", " + address.getPin() + ", " + address.getState();
}

}
