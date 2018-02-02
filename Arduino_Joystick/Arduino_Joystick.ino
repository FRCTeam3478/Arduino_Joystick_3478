//Prueba para múltiples switches. 

#include <Joystick.h>

////crea el objeto de joystick
Joystick_ Joystick;

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 9;
int index = 0;

int lastButtonState[12] = {0,0,0,0,0,0,0,0,0,0,0,0};  //ultimos estados
int Buttons_map[12] = {0,1,2,3,4,5,6,7,8,9,10,11}; //botones a ller del joystick (0 aqui es el boton 1, 1 el 2, etc)
int Pins_map[12] = {9,8,7,6,5,4,3,2,A3,A2,A1,A0};  //pines del arduino

////////////codigo de setup/////////////
void setup() {
  // Initialize Button Pins
  for( index = 0; index < 12; index++){
    pinMode(Pins_map[index], INPUT_PULLUP);
  }
  // Initialize Joystick Library
  Joystick.begin();
}
///////////////////////////////////////


/////////codigo principal///////////////////
void loop() {
  for ( index = 0; index < 12; index++)  //checa todos los botones
  {
    int currentButtonState = !digitalRead(Pins_map[index]);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(Buttons_map[index], currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(10);
}
////////////////////////////////////////

