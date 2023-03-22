print("1. Interpretation")
print("Python is an interpreted programming language.")
print("Intertreter interprets the code line by line during execution and stops the execution if it finds an error in the code.")
print("Languages like Java/C are compiler based languages where we have to do 2 steps: first step is to compile the code which generates machine language code, second step is to run the code.")
print()

print("2. Boolean Expressions")
first = 100
second = 200
if first == second: print("Both are equal.")
else: print("Both are not equal.")
print("Boolean expressions work in the same way as other langugaes like Java/C. But, they differ in the syntax. For example, to include else if, we use 'else if' in Java whereas we use 'elif' in Python. Also, '&&' in Java == 'and', '||' in Java == 'or'.")
print()

print("3. Short Circuit Evaluation")
if True or 2 == 3: print("2 == 3 won't get executed since the 1st condtion is already True.")
else: print("This line won't be executed.")
print("Short Circuit Evaluation means skipping execution of some conditions in an expression if we know the result of the expression before that condtion.")
print("This is similar to other langugaes.")
print()

print("4. Numeric Types")
a = 20
b = 40.60
print("Type of a: ", type(a))
print("Type of b: ", type(b))
print("Python doesn't need implicit declaration of type of variable. It will declare the variable type required based on the value we assign to it. Whereas in Java/C we need to specify the type of variable explicitly.")
print()

print("5. Strings")
c = "I am a string"
print("Type of c: ", type(c))
print("Python doesn't need implicit declaration of type of variable. It will declare the variable type required based on the value we assign to it. Whereas in Java/C we need to specify the type of variable explicitly.")
print()

print("6. Arrays")
import array
D = array.array('i', [1,2,3,4,5,6])
for d in D:
	print(d, end=" ")
print()
print("There is no specific data type of array in Python. But we can implement it using array package which we have to import. Whereas in Java/C we can create an array using the inbuilt functionality. The size of array is static in both Python and Java/C.")
print()

print("7. Lists")
L = [1, 1.2, "three"] 
for l in L:
	print(l, end=" ")
print()
print("It is similar to array type. But, the only difference is lists can hold multiple data types whereas array can hold only single data type elements. Whereas in Java/C we can only have elements of same type. The size of list is dynamic i.e; we can change the size of list by adding or removing elements from it.")
print()

print("8. Tuples")
T = (1, 1.2, "three")
for t in T:
	print(t, end=" ")
print()
print("It is similar to list. But, the only difference is lists are mutable whereas tuples are immutatble.")
print()

print("9. Slicing")
print("Slicing the list from index 1 to index 2", L[1:3])
print("We can use slicing to access subpart of the list/tuple/string. We can do this by specifying start index, end index and step. This feature is not present in Java/C.")
print()

print("10. Index Range Checking")
print()

print("11. Dictionaries")
D = {"name": "Sasank", "age": 23, "cars": ["BMW", "Lamborghini"]}
print(D)
print("In Python we can create dictionaries easily by just defining them as key-value pairs. In Java, to implement Dictionaries we need to use HashMap or TreeMap which are implementations of Dictionary abstract class.")
print()

print("12. IF Statement")
num = 56
if num < 20: print("Low")
elif num < 60: print("Mid")
else: print("High")
print("The working of IF statements are similar to Java/C. But, the only difference is in Python we use 'elif' whereas in Java/C we use 'else if'.")
print()

print("13. SWITCH Statement")
print("Python doesn't have a switch statement whereas Java/C has a switch statement. But, we can implement it using else-if ladder.")
print()

print("14. FOR Loop")
L = [1, 2, 3, 4, 5, 6]
for i in range(len(L)):
	print(L[i], end = " ")
print()
print("The syntax of FOR loop in python using either range() function or iterating over the elements of a list. In Java we can also do both these versions by using for() or forEach().")
print()

print("15. WHILE Loop")
i = 0
while i != len(L):
	print("L[i]", end=" ")
	i += 1
print()
print("WHILE loop in python is similar to Java/C in both syntax and implementation. It executes the statements inside the loop until the condition provided in the loop is true.")
print()

print("16. Indentation To Denote Code Blocks")
print("We use indentation to define code blocks. We don't have {} in python as we have in Java/C. So, to group the statements we want to execute if a condition is true or in a loop or in a function we indent them.")
print()

print("17. Type Binding")
print()

print("18. Type Checking")
print()

print("19. Functions")
print()

print("20. Set")
print()