
const int c = 261;
const int cS = 277;
const int d = 294;
const int dS = 311;
const int e = 329;
const int f = 349;
const int fS= 370;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 466;
const int aL =220;
const int b = 494;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
const int aSL= 233;
const int gSL = 415;
 
const int buzzerPin = 8;
const int ledPin1 = 12;
const int ledPin2 = 13;
const int constante = 575;
const int black = constante*3/4;
const int corchea = constante*3/8;
const int semi = constante*3/16;
int counter = 0;
 
void setup()
{
  //Setup pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  beep(e,black*4);
  beep(d,black*3);
  beep(d,corchea);
  delay(corchea);
  beep(e,black*4);
  beep(d,black*3);
  beep(d,corchea);
  delay(corchea);
  beep(e,black*4);
  beep(d,black*3);
  beep(d,corchea);
  delay(corchea);
  beep(e,black*4);
  beep(d,black*3);
  beep(d,corchea);
  delay(corchea);
  beep(e,black*4);
  delay(black*4);
  delay(black);
  beep(dS,black);
}
 
void loop()
{
int i = 0,j=0;
for (j = 0; j < 2; j++) {
for (i = 0; i < 7;i++) {
firstSection(false,false);
}
firstSection(true,j==1);
}
for (i = 0; i < 7;i++) {
sndSection(false,false);
}
sndSection(true,false);
sndSection(false,false);
sndSection(true,true);
for (j = 0; j < 6; j++) {
thrdSection(false,false);
}
thrdSection(false,true);
for (j = 0; j < 7; j++) {
forthSection(false);
}
forthSection(true);
for (j = 0; j < 3; j++) {
fifthSection(false);
}
fifthSection(true);
fifthSection(false);
fifthSection(false);
 /*
  //Play first section
  firstSection();
 
  //Play second section
  secondSection();
 
  //Variant 1
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 350);  
  beep(a, 125);
  beep(cH, 500);
  beep(a, 375);  
  beep(cH, 125);
  beep(eH, 650);
 
  delay(500);
 
  //Repeat second section
  secondSection();
 
  //Variant 2
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 650);  
 
  delay(650); */
}
 
void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
 
  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }else
  {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }
 
  //Stop tone on buzzerPin
  noTone(buzzerPin);
 
  delay(50);
 
  //Increment counter
  counter++;
}
 
void firstSection(bool trans,bool up)
{ 
  delay(corchea);
  beep(dS,corchea);
  beep(e,corchea);
  if (trans) {
      beep(dS,corchea);
    } else {
      delay(corchea);
  }
  beep(cS,corchea);
  beep(aSL,semi);
  if (up) {
    beep(f,black);
  } else {
    beep(dS,black);
  }
}
 
void sndSection(bool trans,bool up)
{ 
  delay(corchea);
  beep(f,corchea);
  beep(fS,corchea);
  if (trans) {
      beep(f,corchea);
    } else {
      delay(corchea);
  }
  beep(dS,corchea);
  beep(cS,semi);
  if (up) {
    beep(g,black);
  } else {
    beep(f,black);
  }
}

 void thrdSection(bool trans,bool up)
{ 
  delay(corchea);
  beep(g,corchea);
  beep(gS,corchea);
  if (trans) {
      beep(g,corchea);
    } else {
      delay(corchea);
  }
  beep(f,corchea);
  beep(dS,semi);
  if (up) {
    beep(aS,black);
  } else {
    beep(g,black);
  }
}
 void forthSection(bool trans)
{ 
  delay(corchea);
  if (trans) {
    beep(gS,semi);
    delay(semi);
    beep(g,semi);
    delay(semi);
    beep(gS,semi);
    delay(semi);
    beep(gS,semi);
    delay(semi);
    beep(f,semi);
    delay(semi);
    beep(cH,black);
  } else {
    beep(aS,corchea);
    beep(b,corchea);
    delay(corchea);
    beep(gS,corchea);
    beep(fS,semi);
    beep(aS,black);
  }
}

 void fifthSection(bool var)
{ 
  if (var) {
    beep(gS,semi);
    delay(semi);
    beep(g,semi);
    delay(semi);
    beep(gS,semi);
    delay(semi);
    beep(g,semi);
    delay(semi);
    beep(gS,semi);
    delay(semi);
    beep(cH,black);
  } else {
    delay(corchea);
    beep(cH,corchea);
    beep(cSH,corchea);
    delay(corchea);
    beep(aS,corchea);
    beep(gS,semi);
    beep(cH,black);
  }
}
