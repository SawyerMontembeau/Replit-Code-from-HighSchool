def main():
  courses = {
    '0087561' : "Signals & Systems Fourier Analysis",
    '075322' : "Soviet Hisory from 1785 - Present",
    '235681' : "Multivariable Calculus III",
    '0089892' : "Geographical analysis with Differentiable Equations"
  }

  #for key value in dictionary.items()
  def print_courses(courseDictionary):
    for id, course in  courseDictionary.items():
      print("\nCourse ID: " + id)
      print("Course Name: " + course)


  studentBody = []

  student_01 = {
    'first': "John",
    'last': "Doe",
    'grade' : "Freshman",
    'id' : "987654",
    'email' : "jdoe@rsu21.net",
    'classes' : ["Signals & Systems Fourier Analysis", "Soviet Hisory from 1785 - Present"]
  }

  studentBody.append(student_01)

  student_00 = {}
  totStudents = eval(input("How many students? "))
  for i in range(totStudents):
    fname = input("First Name? ")
    lname = input("Last Name? ")
    grade = input("Grade? ")
    id = input("ID? ")
    email = input("Email? ")
    classes = eval(input("How many Classes? "))
    studentClasses = []
    print_courses(courses)


  for i in range(classes):
    courseNum = input("What course #? ")
    studentClasses.append(courses[courseNum])
  student = {
    'first' : fname,
    'last' : lname,
    'grade' : grade,
    'id' : id,
    'email' : email,
    'classes' : studentClasses
  }
  studentBody.append(student)


  def printListOfDictionaries(listOfDictionaries):
    for dictionary in listOfDictionaries:
      fullName = dictionary['first'].title(), dictionary['last'].title()
      print("Name: "+fullName)
      print("Grade: "+ dictionary['grade'])
      print("ID: "+ dictionary['id'])
      print("Email: "+dictionary['email'])
      print("Classes: ")
      for c in dictionary['classes']:
        print(c)
      
  
main() 