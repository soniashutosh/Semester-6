import java.lang.String;

class Employee{
	// Instance member variables
	String firstName;
	String lastName;
	double monthlySalary;

	// Default constructor
	Employee(){ }

	// Overloaded constructer as required ...
	Employee(String firstName,String lastName, double monthlySalary){
		this.firstName = firstName;
		this.lastName = lastName;
		this.monthlySalary = monthlySalary;
	}

	// Set Methods
	void setFirstName(String firstName){
		this.firstName = firstName;
	}

	void setLastName(String lastName){
		this.lastName = lastName;
	}

	void setMonthlySalary(double monthlySalary){
		this.monthlySalary = monthlySalary;
	}

	// Get Methods
	String getFirstName(){
		return this.firstName;
	}

	String getLastName(){
		return this.lastName;
	}

	double getMonthlySalary(){
		return this.monthlySalary;
	}
}

public class ProgramPracticeAssignment{
	public static void main(String []args){
		Employee firstEmployee = new Employee("Ashutosh","Soni",50000.50);
		Employee secondEmployee = new Employee();
		secondEmployee.setFirstName("Sailendra");
		secondEmployee.setLastName("Sonkar");
		secondEmployee.setMonthlySalary(45000.23);

		// For first Employee
		System.out.print("Yearly Salary of "+ firstEmployee.getFirstName()+ "  "+firstEmployee.getLastName()+" is :  ");
		System.out.println(12*(firstEmployee.getMonthlySalary()));
		double newSalary = 1.1*12*firstEmployee.getMonthlySalary();
		System.out.println("Yearly Salary after 10% hike becomes : "+ newSalary);

		// For second Employee
		System.out.print("Yearly Salary of "+ secondEmployee.getFirstName()+ " "+ secondEmployee.getLastName()+ " is : ");
		System.out.println(12*(secondEmployee.getMonthlySalary()));
		newSalary = 1.1*12*secondEmployee.getMonthlySalary();
		System.out.println("Yearly Salary after 10% hike becomes : "+ newSalary);
	}
}