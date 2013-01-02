import sys

if __name__ == '__main__':
  y=sys.argv[1]
  f = open(y, 'r')
  w=open ("avg",'w')
  x=f.readline()
  x=f.readline()
  sum=0.0
  num=0.0
  while (x!=""):
    i=0
    z=len(x)-1
    grade=""
    while (x[z] != ','):
       grade=x[z]+grade
       z=z-1
    j=int(grade)   
    sum=sum+ j
    num=num+1	
    grade=""
    x=f.readline()
  avg=sum/num
  w.write(str(avg))