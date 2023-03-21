
long T0=0;
long tmeta=0;
int massi;
bool salida = false;

bool vuelta1c1 = false;
bool vuelta1c2 = false;
bool C1 = true;
bool C2 = true;

long laptime1 = 0;
long laptime2 = 0;

int vueltas1=0;
int vueltas2=0;

long tmeta1=0;
long tmeta2=0;


char StartBT;
long senal1=0;
long senal2=0;

void setup() {
  
  Serial.begin(9600);

  pinMode(2,INPUT);
  pinMode(3,INPUT);
  
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

 /* digitalWrite(4,HIGH);
  delay(1000);
  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(7,HIGH);
  delay(1000);
  
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  
  T0=millis();*/
  
}

void loop() {

/*salida de carrera y bandera roja*/

if (StartBT == 'p'){
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  
  vuelta1c1=false;
  vuelta1c2=false;
  salida=false;
  

}


if (Serial.available()){

  StartBT=Serial.read();
}

if (StartBT == 's' && salida==false){

  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  
  digitalWrite(4,HIGH);
  delay(1000);
  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(7,HIGH);
  
  massi=random(700,1500);
  delay(massi);
 
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  
  vuelta1c1=true;
  vuelta1c2=true;
  salida=true;
  
  tmeta2=millis();
  tmeta1=tmeta2;
  

}
  
/* COCHE 1*/
if ((digitalRead(2) == HIGH && C1==false) || (vuelta1c1==true)) {
    laptime1=millis()-tmeta1;
    tmeta1=millis();
    vueltas1 = vueltas1 + 1;
    /*Serial.println(vueltas-1);*/
    senal1=laptime1*100+1;
    if(vuelta1c1==false){Serial.println(senal1);}
    C1=true;
    vuelta1c1=false;
  }
  
 if (digitalRead(2) == LOW || vuelta1c1==true) {
   C1=false;
 }


/*COCHE 2*/
if ((digitalRead(3) == HIGH && C2==false) || (vuelta1c2==true)) {
    laptime2=millis()-tmeta2;
    tmeta2=millis();
    vueltas2 = vueltas2 + 1;
    /*Serial.println(vueltas-1);*/
    senal2=laptime2*100+2;
    if(vuelta1c2==false){Serial.println(senal2);}
    C2=true;
    vuelta1c2=false;
  }
  
 if (digitalRead(3) == LOW || vuelta1c2==true) {
   C2=false;
 }
    
}
