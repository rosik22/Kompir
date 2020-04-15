#!/usr/bin/env python3

class SchoolMember:
    def __init__(self,name,age):
        self.name = name
        self.age = age

class Teacher(SchoolMember):
    def __init__(self,name,age,salary):
        super().__init__(name,age)
        self.salary = salary
        self.courses = {}
    
    def getSalary(self):
        return self.salary

    def addCourse(self,signature,courseName):
        self.courses[signature] = courseName
    
    def getCourses(self):
        for key, value in self.courses.items():
            print(key, value)

class Student(SchoolMember):
    def __init__(self,name,age):
        super().__init__(name,age)
        self.courses = {}

    def attendCourse(self,signature,year):
        self.gradesYear = {}
        self.courses[signature] = self.gradesYear
        self.courses[signature]['grade'] = []
        self.courses[signature]['year'] = year
    
    def addGrade(self,signature,grade):
        if signature in self.courses.keys():
            self.courses[signature]['grade'].append(grade)
    
    def getCourses(self):
        for key, value in self.courses.items():
            print(key, value)

    def getAvgGrade(self,signature):
        temp = self.courses[signature]['grade']
        sum = 0
        for x in temp:
            sum += x
        return "{:.2f}".format(sum/len(temp))

A = Teacher('Andonov',30,3000)
print(A.getSalary())
A.addCourse('CSB220','Python')
A.addCourse('CKS300', 'Database')
A.getCourses()

B = Student('Ivan', 16)
B.attendCourse('CITB200',2013)
B.addGrade('CITB200',6)
B.addGrade('CITB200',3)
B.addGrade('CITB200',4)
B.attendCourse('BOT400',2014)
B.getCourses()
print(B.getAvgGrade('CITB200'))
