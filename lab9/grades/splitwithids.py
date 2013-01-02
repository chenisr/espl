import sys

if __name__ == '__main__':
  y=sys.argv[1]
  f = open(y, 'r')
  w=open ("splited_grades_ids",'w')
  x=f.readline()
  x=f.readline()
  arr= [0] * 12 
  ids=[""] * 12
  while (x!=""):
    z=len(x)-1
    grade=""
    id=""
    while (x[z] != ','):
       grade=x[z]+grade
       z=z-1
    z=0
    while (x[z] != ','):
       id=id+x[z]
       z=z+1
    j=int(grade)
    arr[j]=arr[j]+1
    ids[j]=ids[j]+str(id)
    ids[j]=ids[j]+" "
    grade=""
    id=""
    x=f.readline()
  for i in range (0,11):
    w.write(str(i)+ ": ")
    w.write(str(arr[i])+"\n")
    w.write(str(i)+ "  IDS:    ")
    w.write(str(ids[i])+"\n")