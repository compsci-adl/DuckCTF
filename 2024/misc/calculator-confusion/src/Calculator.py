import os
import sys
import math


# Yoinked from https://www.geeksforgeeks.org/evaluate-the-value-of-an-arithmetic-expression-in-reverse-polish-notation-in-python/
# But then upgraded :)
def evaluate(expression):
	# splitting expression at whitespaces
	expression = expression.split(" ")
	# stack
	stack = []
	
	# iterating expression
	for ele in expression:

		# ele is a number
		if ele not in ["/", "*", "+", "-", "^", "%", "sin", "cos", "tan", "sqrt"]:
			stack.append(int(ele))
		
		# ele is an operator
		else:
			# For single input operations
			if ele in ["sin", "cos", "tan", "sqrt"]:
				value = stack.pop()
				
				if ele == "sin":
					stack.append(math.sin(value))
				
				elif ele == "cos":
					stack.append(math.cos(value))
				
				elif ele == "tan":
					stack.append(math.tan(value))
					
				elif ele == "sqrt":
					stack.append(math.sqrt(value))
				
			# For multi input operations
			else:
				# getting operands
				right = stack.pop()
				left = stack.pop()
				
				if ele == '+':
					stack.append(left + right)
				
				elif ele == '-':
					stack.append(left - right)
				
				elif ele == '*':
					stack.append(left * right)
				
				elif ele == '/':
					stack.append(left / right)
				
				elif ele == "^":
					stack.append(left ** right)
				
				elif ele == "%":
					stack.append(left % right)
				
				else:
					sys.exit(f"Unknown input: {ele}")
			
			# return final answer.
	return stack.pop()


print("\nCurrent operations are: + - * / ^ % sin cos tan sqrt")
for i in range(10):
	arr = input("Input your expression to be calculated: ")
	
	# calling evaluate()
	try:
		answer = evaluate(arr)
	except:
		print("Unknown input format\n")
		continue
	
	# If the answer is the expected one give them the flag.
	# There are two possible inputs because of the addition in the equation.
	print(f"= {answer if answer % 1 != 0 else int(answer)}\n")
	if arr == "127 38 sin / 16 13 2 ^ 3 14 3 / ^ - + / 8 sqrt %" or arr == "127 38 sin / 13 2 ^ 3 14 3 / ^ - 16 + / 8 sqrt %":
		print(os.environ["FLAG"])
		break



