//Här inkluderar jag servo libraryt
#include <Servo.h>

//Här tilldelar jag variabelnamn
int buttonred;
int buttongre;
int buttonblu;
int buttonyel;
int posx = 90;
int posy = 90;

//Här tilldelas servona namn
Servo pin2;
Servo pin3;

//Här fäster jag servona till olika pins och sätts till sina default positioner, vilket (som tilldelat innan) är 90 grader.
void setup() {
  pin2.attach(2);
  pin2.write(posx);
  pin3.attach(3);
  pin3.write(posy);
}

void loop() {

 //Medans den röda knappen är nedtryckt och den första servon inte har överstigit 180 grader, läggs det till en grad på x-axeln. Servon läser sedan x-axeln och roterar den till rätt vinkel. Sedan kommer en delay och efter det återställs knappen till LOW läget. 
  buttonred = (digitalRead(11));
  while (buttonred == HIGH && posx < 180) {
    posx += 1;
    pin2.write(posx);
    delay(15);
    buttonred = LOW;
  }
  //Medans den gröna knappen är nedtryckt och den första servon inte har understigit 0 grader, tas det bort en en grad på x-axeln. Servon läser sedan x-axeln och roterar den till rätt vinkel. Sedan kommer en delay och efter det återställs knappen till LOW läget.
  buttongre = (digitalRead(10));
  while (buttongre == HIGH && posx > 0) {
    posx = posx - 1;
    pin2.write(posx);
    delay(15);
    buttongre = LOW;
  }
  //Medans den gula knappen är nedtryckt och den andra servon inte har överstigit 180 grader, läggs det till en grad på y-axeln. Servon läser sedan y-axeln och roterar den till rätt vinkel. Sedan kommer en delay och efter det återställs knappen till LOW läget.
  buttonyel = (digitalRead(9));
  while (buttonyel == HIGH && posy < 180) {
    posy += 1;
    pin3.write(posy);
    delay(15);
    buttonyel = LOW;
  }
  //Medans den blåa knappen är nedtryckt och den andra servon inte har understigit 0 grader, tas det bort en grad på y-axeln. Servon läser sedan y-axeln och roterar den till rätt vinkel. Sedan kommer en delay och efter det återställs knappen till LOW läget.
  buttonblu = (digitalRead(8));
  while (buttonblu == HIGH && posy > 0) {
    posy = posy - 1;
    pin3.write(posy);
    delay(15);
    buttonblu = LOW;
  }
}
