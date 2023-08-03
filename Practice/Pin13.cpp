// C++ code
// blinking internal LED
//https://www.youtube.com/watch?v=fJWR7dBuc18

int Port = 13;

void setup()
{
  pinMode(Port, OUTPUT);
}

void loop()
{
  digitalWrite(Port, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(Port, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}