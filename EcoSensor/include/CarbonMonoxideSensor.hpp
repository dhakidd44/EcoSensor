/*
  Titre      : Titre du programme
  Auteur     : Ernest Samuel Andre
  Date       : 16/05/2023
  Description: Ce programme consiste a lire des donnees de capteurs de temperature, de lumiere et de monoxide
              de carbone pour esuite les envoyes dans une base de donnees afin de prendre des desiscions et pour
              controler l environnement autour de notre objet
  Version    : 0.0.1
*/

#ifndef CarbonMonoxideSensor_hpp
#define CarbonMonoxideSensor_hpp

#include <Arduino.h>

class CarbonMonoxideSensor
{
private:
  int pin;

public:
  CarbonMonoxideSensor(int pin);
  float calibrate(int sensorValue);
};
#endif