import sys
import random

if __name__ == '__main__':
  wordlib="long-words.txt"
  randomquote="./randomquote.sh"
  empty="\."	# we need something for the sed [set] when $guessed=""
  games=0

  try:
    f=open(wordlib,'r')
    word=random.choice(f.readlines())
    word2='-' * len(word)
    if (games>0) :
      print ("*** New Game! ***")
    games=games+1
    guessed=""
    if (len(sys.argv)>=2):
      bad2=sys.argv[1]
    else:	
      bad2=6
    print ("Guess a letter: ")
    guess=raw_input()
    bad=bad2
    while ((word != word2) and ( guess != "quit")):
      print guess
      if (guess in guessed):
	print ("Uh oh: You have already tried " + guess)
      else:
	if (len(guess)>1):
	  print ("Uh oh: You can only guess a single letter at a time")
	else:
	  if (guess > 'z'):
	      print ("Uh oh: Please only use lowercase letters for your guesses")
	  else:
	    if (guess in word):
	      print ("* Great! The letter \" "+guess+" appears in the word!")
	      for t in range (0,len(word)):
		if word[t] in guess:
		  word2=word2[:t]+guess+word2[t+1:]
	    else:
	      print ("* Nope," + guess + "does not appear in the word.")
	      bad=bad-1
	      if (bad==0):
		print ("** Uh oh: you've run out of steps. You're on the platform.. and <SNAP!>")
		print ("** The word you were trying to guess was"+ word)
		bad=bad2
		f=open(wordlib,'r')
		word=random.choice(f.readlines())
		word2='-' * len(word)
      print("steps from gallows:" + str(bad) + ", word so far: " + word2)
      print ("Guess a letter: ")
      guess=raw_input()
      
    if(word is word2):
      print ("you got it,the word was"+ word2)
  except IOError as e:
    print (sys.argv[0]+": Missing word library"+wordlib)
    print ("(online at http://www.intuitive.com/wicked/examples/long-words.txt")
    print ("save the file as " +wordlib+" and you're ready to play!)")
    sys.exit()

