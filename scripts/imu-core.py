import struct

def hexToSignedInt(x):
	return ~ (0xffff - int(x,16))+1


def convertIMUOneLiner(oneLiner):
	oneLiner = oneLiner.rstrip()
	if oneLiner[0] != '>':
		print "Not the correct start ",oneLiner[0:6],"..."
		return
	if len(oneLiner) != 1+9*4:
		print "Not the correct length ", len(oneLiner), "!=",1+9*4
		return

	dataHex = [oneLiner[i:i+4] for i in range(1,len(oneLiner),4)]
	
	
	dataInt = map(hexToSignedInt,dataHex)


	return dataInt
print convertIMUOneLiner(">FF64FF8BFF22FF9C003F0088FEF2FDE80028")