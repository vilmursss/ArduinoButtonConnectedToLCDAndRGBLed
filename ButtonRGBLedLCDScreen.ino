/* Arduino button connected to the RGB led and LCD screen */
    
#include <LiquidCrystal.h>

  int inputPin = 2;               // Input pin for button
  int btnState = LOW;             // Variable for button state
  int btnPressed = LOW;             // Variable to button press
  int state = 0;                  // Variable to describe RGB led color
    
  int redPin = 4;                // Led pins
  int greenPin = 3;
  int bluePin = 6;
    
  LiquidCrystal lcd(1, 7, 11, 10, 9, 8);
    
void setup() 
{
  pinMode(inputPin, INPUT);     // Setup pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Nothing pressed yet!");
}
     
void loop()
{
  btnPressed = digitalRead(inputPin);
  if(btnPressed == HIGH && btnState == LOW)
  {
    btnState == HIGH;
    buttonPressed();    
  } 
}

    
void setColor(int red, int green, int blue)  // set color for RGB
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
          
  delay(300);
  btnState = LOW;          
}

void buttonPressed()   // Choose the color for RBG, when the button is pressed
{
  state++;
  Serial.println("Button Pressed!");
  
  switch (state) {
    case 1:
      setColor(0, 255, 0); // green
      lcd.clear();
      lcd.print("Button pressed once!");
      break;
    case 2:
      setColor(0, 0, 255);  // blue
      lcd.clear();
      lcd.print("Button pressed twice!");
      break;
    case 3:
      setColor(255, 0, 0);  // red
      lcd.clear();
      lcd.print("ALARM ALARM THIRD TIME!!"); 
      state = 0;
      break;
    default:
      break;
  }
}
