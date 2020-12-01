from math import log
from numpy import array
from numpy import argmax

def beam_search_decoder(data,beam_size):
	sequence = [[[],0.0]]
	for item in data:
		candidate = []
		for i in range(len(sequence)):
			path,score = sequence[i]
			for j in range(item.shape[0]):
				candidate.append([path+[j],score+item[j]])
		ordered = sorted(candidate,key=lambda tup:tup[1],reverse=True)
		sequence = ordered[:beam_size]
	return sequence

data = [[0.1, 0.2, 0.3, 0.4, 0.5],
		[0.5, 0.4, 0.3, 0.2, 0.1],
		[0.1, 0.2, 0.3, 0.4, 0.5],
		[0.5, 0.4, 0.3, 0.2, 0.1],
		[0.1, 0.2, 0.3, 0.4, 0.5],
		[0.5, 0.4, 0.3, 0.2, 0.1],
		[0.1, 0.2, 0.3, 0.4, 0.5],
		[0.5, 0.4, 0.3, 0.2, 0.1],
		[0.1, 0.2, 0.3, 0.4, 0.5],
		[0.5, 0.4, 0.3, 0.2, 0.1]]
#data = [[0.4, 0, 0.6], [0.4, 0, 0.6]]
data = array(data)
# decode sequence
result = beam_search_decoder(data, 3)
print(result)