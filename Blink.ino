

// seq 1 and 2 are the current LED
int seq1 = 0;
int seq2 = 13;
int goback = 0;
int goback2 = 1;

int setuppins(int count)
{
    while(count < 13)
    {
          pinMode(count, OUTPUT);
          count = count + 1;
    }
}
  
int blink(int lednum1 , int lednum2){
  digitalWrite(lednum1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(lednum2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(25);   
  digitalWrite(lednum1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(lednum2, LOW);    // turn the LED off by making the voltage LOW
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  setuppins(0);
}

// the loop function runs over and over again forever
void loop() {
  if(seq1 < 13 && goback == 0)
  {
     seq1++;
  }
  else if(seq1 == 13 && goback == 0)
  {
     seq1--;
     goback = 1;
  }
  else if(seq1 > 0 && goback == 1)
  {
     seq1--;
  }
  else if(seq1 == 0 && goback == 1)
  {
     seq1++;
     goback = 0;
  }
  else
  {
      seq1 = 10;
      goback = 0;
  }

  if(seq2 < 13 && goback2 == 0)
  {
     seq2++;
  }
  else if(seq2 == 13 && goback2 == 0)
  {
     seq2--;
     goback2 = 1;
  }
  else if(seq2 > 0 && goback2 == 1)
  {
     seq2--;
  }
  else if(seq2 == 0 && goback2 == 1)
  {
     seq2++;
     goback2 = 0;
  }
  else
  {
    seq2 = 10;
    goback2 = 0;
  }
  blink(seq1 , seq2);
}
