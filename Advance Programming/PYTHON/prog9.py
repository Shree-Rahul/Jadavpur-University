students = ['Alice', 'Bob', 'Charlie']
subjects = ['Math', 'Science', 'English']
marks = [90, 85, 92]

max_marks = [max(values) for values in zip(students, subjects, marks)]

print(max_marks)