#This is a function that returns a string equal to binary representation of any number in O(LogN) Time Complexity

def binary(x):
	if x==0:
		return ""
	if(x%2==0):
		return binary(x//2)+"0"
	else:
		return binary(x//2)+"1"
