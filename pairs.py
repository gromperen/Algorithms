#finds all pairs in array where a_i | a_j and i<j

def findpairs(a):
	count = 0
	vals = []
	freqs = {}
	for i in range(0, max(a)+1):
		freqs[i] = a.count(i)
	for i in range(0, len(a)-1):
		freqs[a[i]] -= 1
		for j in range(a[i], max(a)+1, a[i]):
			for k in range(0,freqs.get(j)):
				vals.append([a[i], j])
				
	for val in vals:
		print(val)


findpairs([2, 1, 3, 3, 4, 5, 6,10])
