


//Ορισμός των Pins

int ENA = 6; //Ορισμός Pin της Δεξιάς Motor 
int IN1 = 4; //Pin ελέγχου
int IN2 = 7;

int ENB = 3; //Ορισμός Pin της Αριστερής Motor
int IN3 = 5;
int IN4 = 2;

int led = 13; //Ορισμός Pin του LED


//Ταχύτητα των Motors
#define ENASpeed 180
#define ENBSpeed 130



int Sensor1 = 0;
int Sensor2 = 0;
int Sensor3 = 0;
int Sensor4 = 0;
int Sensor5 = 0;




void setup() //κώδικας που θα εκτελεστεί μία φορά (προετοιμασία του ρομπότ για λειτουργία)
{

  //ρύθμιση του mode των pins(input ή output) 

  pinMode(ENA, OUTPUT); 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(led, OUTPUT);

  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  pinMode(Sensor4, INPUT);
  pinMode(Sensor5, INPUT);
  
}



void loop() //κώδικας που θα εκτελείται επαναλαμβανόμενα κατά τη λειτουργία του ρομπότ(βρόγχος)
{

  //Χρήση του analogWrite για κίνηση μηχανής στην ρυθμισμένη παραπάνω ταχύτητα
  analogWrite(ENA, ENASpeed);
  analogWrite(ENB, ENBSpeed);


  //"Διάβασμα" input των sensors:  LOW (ΜΑΥΡΗ γραμμή) ή HIGH (ΛΕΥΚΉ επιφάνεια)
  Sensor1 = digitalRead(8);
  Sensor2 = digitalRead(9);
  Sensor3 = digitalRead(10);
  Sensor4 = digitalRead(11);
  Sensor5 = digitalRead(12);
  

  //ορισμός προϋποθέσεων για κίνηση ΑΡΙΣΤΕΡΑ, ΔΕΞΙΑ ΚΑΙ ΜΠΡΟΣΤΑ

  if(Sensor5 == HIGH && Sensor4 == HIGH && Sensor2 == LOW && Sensor1 == LOW)
  {
    
    //στροφή ΑΡΙΣΤΕΡΑ
    //motor A κίνηση μπροστά
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    //motor B κίνηση πίσω
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    digitalWrite(led,HIGH); //το LED ανάβει
  }

  
  else if (Sensor5 == LOW && Sensor4 == LOW && Sensor2 == HIGH && Sensor1 == HIGH)
  {

    //στροφή ΔΕΞΙΑ
    //motor A κίνηση πίσω
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    //motor B κίνηση μπροστά
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    digitalWrite(led,HIGH); //το LED ανάβει
  }
  

  else if (Sensor3 == LOW && Sensor1 == HIGH && Sensor5 == HIGH )
   {

    //κίνηση ΜΠΡΟΣΤΑ
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    digitalWrite(led,LOW); //το LED σβήνει
   }

 
  else //σε οποιαδήποτε άλλη συνθήκη input των sensors
  {

    //ΑΚΙΝΗΤΟΠΟΙΗΣΗ
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
   }
}
