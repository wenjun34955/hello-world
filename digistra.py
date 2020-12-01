import math
adjacency = {
	'A':{'B':12,'C':math.inf,'D':math.inf,'E':math.inf,'F':16,'G':14},
	'B':{'A':12,'C':10,'D':math.inf,'E':math.inf,'F':7,'G':math.inf},
	'C':{'A':math.inf,'B':10,'D':3,'E':5,'F':6,'G':math.inf},
	'D':{'A':math.inf,'B':math.inf,'C':3,'E':4,'F':math.inf,'G':math.inf},
	'E':{'A':math.inf,'B':math.inf,'C':5,'D':4,'F':2,'G':8},
	'F':{'A':16,'B':7,'C':6,'D':math.inf,'E':2,'G':9},
	'G':{'A':14,'B':math.inf,'C':math.inf,'D':math.inf,'E':8,'F':9}
}

dict1 = {'D':0}
dict2 = {'A':math.inf,'B':math.inf,'C':3,'E':4,'F':math.inf,'G':math.inf}
#step1
#dict1 = {'D':0,'C':3}
#dict2 = {'A':min(adjacency['A']['C']+dict1['C'],orgin),'B':math.inf,'E':4,'F':math.inf,'G':math.inf}
#update

while(len(dict2)>0):
	tempscore = math.inf
	for key2 in dict2:
		if dict2[key2] < tempscore:
			tempscore = dict2[key2]
			tempkey = key2
	dict2.pop(tempkey)
	dict1[tempkey] = tempscore
	for key2 in dict2:
		for key1 in dict1:
			if dict2[key2] > adjacency[key2][key1] + dict1[key1]:
				dict2[key2] = adjacency[key2][key1] + dict1[key1]

print(dict1)
