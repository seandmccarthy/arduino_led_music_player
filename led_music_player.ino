int ledCount = 8;
int ledBytes[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0xf0};

int dataPin = 2;
int latchPin = 3;
int clockPin = 4;
int soundPin = 5;
/*             c1  d1  e1  f1  g1  a2  b2  c2  d2  e2  f2  g2  c3    cs1 ds1 es1 fs1 gs1 as2 */
int notes[] = {261,293,329,349,392,440,493,523,587,659,698,783,880,  277,311,349,370,415,465};

int majors  = 13;

int minim      = 800;
int crotchet   = minim/2;
int quaver     = minim/4;
int semiquaver = minim/8;

int c1 = 0;
int cs1 = 13;
int d1 = 1;
int ds1 = 14;
int e1 = 2;
int eb1 = 14;
int f1 = 3;
int fs1 = 15;
int g1 = 4;
int gs1 = 16;
int a2 = 5;
int as2 = 18;
int b2 = 6;
int bb2 = 18; 
int c2 = 7;
int d2 = 8;
int REST = 99;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(soundPin, OUTPUT);
}

void lightLeds(int data) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}

void unLightLeds() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin, HIGH);
}

void play(int note, int duration) {
  if (note == REST){
    delay(duration);
  }
  else {
    int idx = note % majors;
    lightLeds(ledBytes[idx]);
    tone(soundPin, notes[note], duration);
    delay(duration);
    unLightLeds();
  }
}

void play_many(int stanza[], int length) {
  for (int i=0; i<length-1; i+=2) {
    play(stanza[i], stanza[i+1]);
  }
}

void happyBirthday() {
  int stanza1[] = {c1, quaver, c1, quaver, d1, crotchet, c1, crotchet, f1, crotchet, e1, crotchet, REST, quaver};
  int stanza2[] = {c1, quaver, c1, quaver, d1, crotchet, c1, crotchet, g1, crotchet, f1, crotchet, REST, quaver};
  int stanza3[] = {c1, quaver, c1, quaver, c2, crotchet, a2, crotchet, f1, crotchet, e1, crotchet, d1, crotchet, REST, quaver};
  int stanza4[] = {as2, quaver, as2, quaver, a2, crotchet, f1, crotchet, g1, crotchet, f1, minim};
  play_many(stanza1, 14);
  play_many(stanza2, 14);
  play_many(stanza3, 16);
  play_many(stanza4, 12);
}

void twinkle() {
  play(c1, crotchet);
  play(c1, crotchet);
  play(g1, crotchet);
  play(g1, crotchet);
  play(a2, crotchet);
  play(a2, crotchet);
  play(g1, minim);
  play(f1, crotchet);
  play(f1, crotchet);
  play(e1, crotchet);
  play(e1, crotchet);
  play(d1, crotchet);
  play(d1, crotchet);
  play(c1, minim);

  play(g1, crotchet);
  play(g1, crotchet);
  play(f1, crotchet);
  play(f1, crotchet);
  play(e1, crotchet);
  play(e1, crotchet);
  play(d1, minim);
  play(g1, crotchet);
  play(g1, crotchet);
  play(f1, crotchet);
  play(f1, crotchet);
  play(e1, crotchet);
  play(e1, crotchet);
  play(d1, minim);
  play(c1, crotchet);
  play(c1, crotchet);
  play(g1, crotchet);
  play(g1, crotchet);
  play(a2, crotchet);
  play(a2, crotchet);
  play(g1, minim);

  play(f1, crotchet);
  play(f1, crotchet);
  play(e1, crotchet);
  play(e1, crotchet);
  play(d1, crotchet);
  play(d1, crotchet);
  play(c1, crotchet);
}

void scale() {
  play(c1, crotchet);
  play(d1, crotchet);
  play(e1, crotchet);
  play(f1, crotchet);
  play(g1, crotchet);
  play(a2, crotchet);
  play(b2, crotchet);
  play(c2, crotchet);
  play(b2, crotchet);
  play(a2, crotchet);
  play(g1, crotchet);
  play(f1, crotchet);
  play(e1, crotchet);
  play(d1, crotchet);
  play(c1, crotchet);
}

void loop() {
  delay(2000);
  //scale();
  happyBirthday();
  //trouble();
}
