#include <MicroView.h>
#include "Thermistor.h"

Thermistor Thermistor(A0, 10000);

MicroViewWidget *widget;

void setup() {
  Thermistor.begin();
  
  uView.begin();
  
  //widget = new MicroViewGauge(32, 24, 60, 80, WIDGETSTYLE1);
  widget = new MicroViewGauge(30, 24, 60, 80, WIDGETSTYLE1);
  
  //uView.setFontType(3);
  uView.clear(PAGE);
  
  Serial.begin(9600);
}

void loop() {
  int tempF = Thermistor.getTempF(true);
  
  uView.clear(PAGE);
  widget->reDraw();
  widget->setValue(tempF);
  uView.display();
  
//  uView.clear(PAGE);
//  uView.setCursor(32, 0);
//  uView.print(tempF);


  uView.display();
  
  delay(100);
}
