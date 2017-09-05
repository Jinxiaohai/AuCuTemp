#!/usr/bin/env python3


"""generate the data list"""

# dirName = "/home/jinxiaohai/jinxiaohai/forwardBackward/aucu/ampt_0_"
dirName = "/home/xiaohai/Program/AuCu/chargeAmpt/data/ampt_0_"
baseName1 = "/eccentricity.txt"
baseName2 = "/ampt/ana/ampt.dat"

fileObjectEpsilon = open("./epsilon.list", "w")
fileObjectaAmpt = open("./ampt.list", "w")

for i in range(3):
    epsilonData = dirName + str(i) + baseName1
    amptData = dirName + str(i) + baseName2
    fileObjectEpsilon.write(epsilonData + '\n')
    fileObjectaAmpt.write(amptData + '\n')

fileObjectEpsilon.close()
fileObjectaAmpt.close()
