
def calibrate(filename):
	f = open(filename, 'r')
	f.readline() #discard first line
	data = []
	for line in f.readlines():
		liner = line.split()
		mapped = map(int,liner)
		data.append(mapped)

	print data[0:5]

calibrate("0rpm.txt")