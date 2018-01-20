int incomeByte[7];
int data;
int z = 0;
int sum;
unsigned long error;


void setup() {
  Serial.begin(2400);
}

void loop() {
  //Serial.print("abc");
  while (Serial.available() > 0) {

    data = Serial.read();
    if (data == 170) {
      z = 0;
      incomeByte[z] = data;
    }
    else {
      z++;
      incomeByte[z] = data;
    }
    if (z == 6)
    {
      sum = incomeByte[1] + incomeByte[2] + incomeByte[3] + incomeByte[4];

      if (incomeByte[5] == sum && incomeByte[6] == 255 )
      {

        // Serial.print("Data OK! |");
        for (int k = 0; k < 7; k++)
        {
          Serial.print(incomeByte[k]);
          Serial.print("|");
        }

        Serial.print(" Vo=");
        float vo = (incomeByte[1] * 256.0 + incomeByte[2]) / 1024.0 * 5.00;
        Serial.print(vo, 3);
        Serial.print("v | ");
        float c = vo * 700;

        Serial.print(" PM2.5 = ");
        Serial.print(c, 2);
        Serial.print("ug/m3 ");
        Serial.println();
      }
      else {
        z = 0;
        Serial.flush();
        data = 0;
        for (int m = 0; m < 7; m++) {
          incomeByte[m] = 0;
        }
      }
      z = 0;
    }
  }
}
