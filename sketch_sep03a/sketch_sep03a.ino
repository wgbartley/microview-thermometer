#include <MicroView.h>
#include "Thermistor.h"

Thermistor Thermistor(A0, 10000);

MicroViewWidget *widget;

void setup() {
  Thermistor.begin();
  
  uView.begin();
  
  widget = new MicroViewGauge(23, 23, 60, 80, WIDGETSTYLE1);
  
  uView.clear(PAGE);
  
  Serial.begin(9600);
}

void loop() {
  int tempF = Thermistor.getTempF(true);
  
  uView.clear(PAGE);
  
  widget->reDraw();
  widget->setValue(tempF);
  
  uView.setFontType(3);
  uView.setCursor(39, 0);
  uView.print(tempF);
  
  uView.setFontType(0);
  
  uView.display();
  
  delay(100);
}
