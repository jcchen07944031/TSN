import os, glob
import subprocess

f = open('Total-TDMA-N.txt', 'r')
total_time = [float(line) for line in f.readlines()]
f.close()
with open('Total-TDMA-N.txt', 'w') as filetowrite:
	for i in range(300):
		filetowrite.write("0\n")
		
for i in range(20):
	process = subprocess.Popen("StreamReserve.exe", str(i))
	process.wait()
	f = open('TDMA-S2P1.txt', 'r')
	new_time = [float(line) for line in f.readlines()]
	f.close()
	f = open('Total-TDMA-N.txt', 'r')
	total_time = [float(line) for line in f.readlines()]
	f.close()
	for j in range(300):
		total_time[j] += (new_time[j] / 20)
	with open('Total-TDMA-N.txt', 'w') as filetowrite:
		for t in total_time:
			filetowrite.write("%f\n" % t)
	for filename in glob.glob("./TDMA*"):
		os.remove(filename) 

f = open('Total-TDMA-N.txt', 'r')
total_time = [float(line) for line in f.readlines()]
f.close()
with open('Total-TDMA-N.txt', 'w') as filetowrite:
	for i in range(300):
		filetowrite.write("%d %f\n" % (i, total_time[i]))