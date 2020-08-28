infilename=input("입력 파일 이름:")
outfilename=input("출력 파일 이름:")

infile=open(infilename,'r')
outfile=open(outfilename,'w')

sum=0
count=0

for line in infile:
     dailySale=int(line)
     sum=sum+dailySale
     count=count+1

outfile.write("총매출="+str(sum)+'\n')
outfile.write("평균 일매출="+str(sum/count))

infile.close()
outfile.close()
