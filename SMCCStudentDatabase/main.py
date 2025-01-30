def main():
  #This program will allow the user to enter student information and enroll them in courses and also pay tuition

  #FUNCTIONS
  #Function 1: printCourses()
  def printCourses(courseList):
    #print out each course from the list charging $1500 per course, print out total tuition balance
    print("\nThe courses you are taking are:\n")
    tuition = 0
    for i in range(len(courseList)):
      print(courseList[i]+"\n")
      tuition += 1500
    print("Your total tuition payment is $"+str(tuition))
  
  #Function 2: studentInfo()
  def studentInfo(fn,ln,g,d,a,e,p):
    print("\nStudent Info:\n")
    print("First Name:",fn.title()+"\n")
    print("Last Name:",ln.title()+"\n")
    
    gTitle = ""
    if(g == 1):
      gTitle = "Freshman"
    elif(g == 2):
      gTitle = "Sophomore"
    elif(g == 3):
      gTitle = "Junior"
    elif(g == 4):
      gTitle = "Senior"
   
    print("Grade:",gTitle+"\n")
    print("Date of Birth:",d+"\n")
    print("Address:",a+"\n")
    print("Email:",e+"\n")
    print("Phone Number:",p)



  #take in first name, last name, grade(as int for freshman through senior),DOB,address,email,phone
  f_name = input("Enter a first name: ")
  l_name = input("Enter a last name: ")
  grade = eval(input("Enter number grade(1 = Freshman, 2 = Sophomore, 3 = Junior, 4 = Senior): "))
  dob = input("Please enter your Date of birth (MM/DD/YYYY): ")
  address = input("Enter your address (number, street, town/city, State, zip): ")
  email = input("Enter email: ")
  phone = input("Enter phone number (### - ### - ####): ")

  #make a list of courses offered through SMCC
  courses = ["CAD Graphics 101", "Mechanical Design 110", "Introduction to Human Services 120", "General Chemistry 101", "Network Fundamentals 230", "Programming in C++ 310" ]

  #Print the courses with course number starting at 3001
  #3001 CAD Graphics 101
  #3002 Mechanical...

  #My idea(doesnt work)
  #for course in courses:
   # print("300"+(courses.index(course)+1),+"\t"+str(course))

  for i in range(len(courses)):
    print(str(3000+i+1)+":\t"+courses[i])

  num = eval(input("How many courses do you want to enroll in?: "))

  studentCourses = []
  for i in range(num):
    courseNum = eval(input("Enter the course number: "))
    for i in range(len(courses)):
      if(courseNum == 3000 + (i+1)):
       studentCourses.append(courses[i])
   
  printCourses(studentCourses)

  studentInfo(f_name,l_name,grade,dob,address,email,phone)

main()