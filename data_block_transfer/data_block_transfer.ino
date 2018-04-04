#include "data_block.h"

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
}

void loop() {

  int v = analogRead(0);

  db_f0 = map(v, 0, 1023, 0, 1000);
  db_f1 = map(v, 0, 1023, 0, 1000);
  db_f2 = map(v, 0, 1023, 0, 1000);
  db_f3 = map(v, 0, 1023, 0, 1000);
  db_f4 = map(v, 0, 1023, 0, 1000);
  db_f5 = map(v, 0, 1023, 0, 1000);
  db_f6 = map(v, 0, 1023, 0, 1000);
  db_f7 = map(v, 0, 1023, 0, 1000);
  db_f8 = map(v, 0, 1023, 0, 1000);
  db_f9 = map(v, 0, 1023, 0, 1000);
  db_f10 = map(v, 0, 1023, 0, 1000);
  db_f11 = map(v, 0, 1023, 0, 1000);
  
  db_i0 = 2000;
  db_i1 = 3000;
  db_i2 = 4000;
  db_i3 = 5000;
  
  db_b0 = 123;
  db_b1 = 124;
  db_b2 = 125;
  db_b3 = 126;
  db_b4 = 127;
  db_b5 = 128;
  db_b6 = 129;
  db_b7 = 130;

  process_message(Serial);

}

void send_data_block(Stream &port) {
  pack_data_block();
  for (int i = 0; i < BLOCKSIZE; i++) {
    port.write(data_block[i]);
  }
}

void process_message(Stream &port) {
  if (port.available() > 0) {

    char b = port.read();
    
    switch (b) {
      case '0':
        digitalWrite(13, LOW);        
      break;
    
      case '1':
        digitalWrite(13, HIGH);
      break;
    }

    send_data_block(port);
    port.flush();
  }
}



