infile=open("proverbs.txt",'r')
for line in infile:
     line=line.rstrip()
     print(line)
     word_list=line.split()
     print(word_list)
     for word in word_list:
          print(word):
infile.close()
