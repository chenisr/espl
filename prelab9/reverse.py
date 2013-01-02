import sys

if __name__ == '__main__':
  x=len(sys.argv)
  while (x>1):
    print(sys.argv[x-1])
    x=x-1
    