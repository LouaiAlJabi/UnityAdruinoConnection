bool lightOn = false;

void setup() {

  Serial.begin(9600); // set up the port
  pinMode(LED_BUILTIN, OUTPUT); // have the light be the output
}

void loop() {
  if(Serial.available())
  {
    char c = Serial.read(); // check the button pressed

    if(c)
    {
      if(c == 'A')
      {
        lightOn = true; // light up on pressing A
      }
      else if (c == 'Z')
      {
        lightOn = false; // light off on pressing Z
      }

      c = NULL; // clear state
    }
  }

  if(lightOn)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("on");
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("off");
  }

  delay(1000); // one second delay between entries
}
