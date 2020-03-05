#This program converts a string representing a binary number into decimal and returns in integer form in O(N) Time Complexity
#Where N is the length of the string

def decimal(x):
	tot = 0
	for i in x:
		tot = tot*2
		if(i!='0'):
			tot+=1
	return tot
