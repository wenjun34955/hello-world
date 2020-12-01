import numpy as np
a = np.array(
	[[0.5,0.2,0.3],
	[0.3,0.5,0.2],
	[0.2,0.3,0.5]])
b = np.array(
	[[0.5,0.5],
	[0.4,0.6],
	[0.7,0.3]])
pi = np.array([0.2,0.4,0.4])

h = ['盒子1','盒子2','盒子3']
o = ['红','白','红']

o2idx = {'红':0,'白':1}

T = len(o)
statenum = a.shape[0]

alpha = np.zeros((T,statenum))
path = np.zeros((T,statenum))

def vertibe(alpha,path,a,b,pi,o,o2idx):
	for t in range(T):
		for i in range(statenum):
			if t == 0:
				alpha[t][i] = pi[i]*b[i][o2idx[o[t]]]
				index = i
			else:
				score = 0
				for j in range(statenum):
					if alpha[t-1][j]*a[j][i]*b[i][o2idx[o[t]]] > alpha[t][i]:
						alpha[t][i] = alpha[t-1][j]*a[j][i]*b[i][o2idx[o[t]]]
					if alpha[t-1][j]*a[j][i] > score:
						score = alpha[t-1][j]*a[j][i]
						index = j
			path[t][i] = index
	return alpha,path,index

alpha,path,index = vertibe(alpha,path,a,b,pi,o,o2idx)
print(alpha)
print(path)
for t in list(range(T-2,0,-1)):
	index = int(path[t][index])
	print(h[index])






