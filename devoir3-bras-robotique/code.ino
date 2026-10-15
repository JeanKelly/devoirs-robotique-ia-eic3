#include <Servo.h>

Servo baz;      // Servo 1 : rotation gauche/droite
Servo zepol;    // Servo 2 : lever/baisser le bras
Servo pens;     // Servo 3 : ouvrir/fermer la pince

void setup() {
  baz.attach(9);
  zepol.attach(10);
  pens.attach(11);

  // Position de départ
  baz.write(90);
  zepol.write(90);
  pens.write(0);
}

void loop() {
  // Position 1 : tourner à gauche, baisser, ouvrir la pince
  baz.write(30);
  zepol.write(120);
  pens.write(90);
  delay(1500);

  // Fermer la pince
  pens.write(0);
  delay(1000);

  // Position 2 : tourner à droite, lever
  baz.write(150);
  zepol.write(60);
  delay(1500);

  // Ouvrir la pince
  pens.write(90);
  delay(1000);
}
