import glob

def calibrate(filename):
	f = open(filename, 'r')
	f.readline() #discard first line
	data = []
	for line in f.readlines():
		liner = line[1:].split()
		mapped = map(int,liner)
		data.append(mapped)

	#print data[0:5]
	return data

def findAverages(data):
	avg = []
	for i in range(0,11):
		s = 0.
		for j in range(0,len(data)-1):
			s += data[j][i]
		avg.append(s/len(data))
	return avg
	#print avg

def findAll():
	g = glob.glob("*rpm.txt")
	for name in g:
		print name,
		avg = findAverages(calibrate("0rpm.txt"))
		print ['%.2f' % elem for elem in avg]

findAll()