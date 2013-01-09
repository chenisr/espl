import os, os.path, sys, getpass, shlex,subprocess

home=os.getenv('HOME')

def getcwd():
    "like os.getcwd(), but collapses the home directory prefix into ~"
    cwd = os.getcwd()
    if cwd.startswith(home):
        cwd = '~'+cwd[len(home):]
    return cwd

while True:
    print "%s@%s>" % (getpass.getuser(), getcwd()),

    argv = None
    try:
        argv = shlex.split(raw_input())
    except EOFError:
        print
        break                             # end of file from user, e.g. Ctrl-D
    for i in range (0,len(argv)):
      if argv[i].startswith("$"):
	argv[i]=os.getenv(argv[i][1:],"")
    if not argv:
        continue # empty command
    if argv[0] in ['exit', 'quit', 'bye']:
        break
    elif argv[0]=='cd':
        try:
            os.chdir(os.path.expanduser(argv[1])) # expand ~ to home directory
        except IndexError:                   # no arguments, chdir to home dir
            os.chdir(home)
        except OSError, s:
            print >>sys.stderr, "chdir: %s" % s
    elif '>' in argv:
      ind=argv.index(">")
      f=open (argv[ind+1],'w')
      subprocess.call(argv[:ind],stdout=f)
    elif "<" in argv:
      ind=argv.index("<")
      f=open (argv[ind+1],'r')
      subprocess.call(argv[:ind],stdin=f)
    elif "|" in argv:
      ind=argv.index("|")
      p1 = subprocess.Popen(argv[:ind], stdout=subprocess.PIPE)
      p2 = subprocess.Popen(argv[ind+1:], stdin=p1.stdout)
    elif "=" in argv[0]:
      ind=argv[0].index("=")
      os.environ[argv[0][:ind]]=argv[0][ind+1:]
    elif argv[len(argv)-1]=="&":
      subprocess.Popen(argv[:len(argv)-1])
    else:
      try:
	subprocess.call(argv)
      except OSError:
	print "cannot run file"
	
# goodbye message
goodbye = "have a good sunny day, see you back soon"
print "*"+"-"*(len(goodbye)+2)+"*"
print "| %s |" % goodbye
print "*"+"-"*(len(goodbye)+2)+"*" 
