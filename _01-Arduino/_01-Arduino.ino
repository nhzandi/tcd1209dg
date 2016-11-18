void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  DDRB |= 0xFF;

  //all LOW, phi2 HIGH
  PORTB |= 0x04;
  PORTB &= ~(0x1B) ;
  
}

/*
 * B0 = SH
 * B1 = phi_1
 * B2 = phi_2
 * B3 = RS
 * B4 = CP
 */



void loop() {
   /*
  * phi_1 HIGH, phi_2 LOW
  * SH HIGH
  * SH LOW
  * phi_1 LOW, phi_2 HIGH  
  */
  PORTB |= 0x02;  //PHI_1 HIGH
  PORTB &= ~(0x04); //PHI_2 LOW

  PORTB |= 0x01;  //SH HIGH
  //DELAY
//  for(int i = 0 ; i < 1000 ; i++){}
  delayMicroseconds(4);
  PORTB &= ~(0x01); //SH LOW

//  PORTB &= ~(0x02); //PHI_1 LOW
//  PORTB |= 0x04;  //PHI_2 HIGH
delayMicroseconds(2);

  for(int i = 0 ; i < 2090 ; i++){
    //phi_1 LOW
    //phi_2 HIGH
    PORTB &= ~(0x02); //PHI_1 LOW
    PORTB |= 0x04;  //PHI_2 HIGH

  
    //RS HIGH
    PORTB |= 0x08; //RS HIGH
  
    //RS LOW
    PORTB &= ~(0x08); //RS LOW
    
    //CP HIGH
    PORTB |= 0x10;  //CP HIGH
    
    //CP LOW
    PORTB &= ~(0x10); //CP LOW
    
    //phi_1 HIGH
    //phi_2 LOW
    PORTB |= 0x02;  //PHI_1 HIGH
    PORTB &= ~(0x04); //PHI_2 LOW
    
  }
  
  
}
