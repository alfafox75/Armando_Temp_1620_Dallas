//Display
  #include <LiquidCrystal_I2C.h> // libreria di gestione del display lcd
  LiquidCrystal_I2C lcd(0x27,20,4);

//Temp 1620 Dallas
#include <OneWire.h> 
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2 
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
int T; // dichiarazione variabile T=tempo

void setup() {
  Serial.begin(9600); 
  Serial.println("Dallas 1620 Temperature IC Control Library"); 
 
  // startup sensor library 
  sensors.begin(); 
  
  // setup LCD
  lcd.init(); 
  lcd.backlight();
}

void loop() {
  T=millis() / 1000; // assegno a T il secondo

  // richiesta temperatura
  sensors.requestTemperatures(); 

  if (T != millis() / 1000) { // ogni variazione di secondo leggo temperatura

  // visualizzo su seriale
  // Serial.print   --> scrive in sequenza
  // Serial.println --> scrive e alla fine va a capo
    Serial.print("Temperatura °C: "); 
    Serial.println(sensors.getTempCByIndex(0)); 
    
  // visualizzo su display
    lcd.clear(); // cancella il display
    lcd.setCursor(0, 0); // posiziona in colonna 0, riga 0
    lcd.print("hello, world!"); // scritta da mostrare sulla prima riga
    lcd.setCursor(0, 1); // posiziona in colonna 0, riga 1
    lcd.print(millis() / 1000);
    lcd.setCursor(0, 2); // posiziona in colonna 0, riga 2
    lcd.print("Temperatura ");
    lcd.print((char)223); // visualizzo il carattere ° sul display
    lcd.print("C:");
    lcd.setCursor(0, 3); // posiziona in colonna 0, riga 3
    lcd.print(sensors.getTempCByIndex(0));
  }  
}

