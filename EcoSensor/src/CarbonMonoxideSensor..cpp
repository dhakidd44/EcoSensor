/*
  Titre      : EcoSensor
  Auteur     : Ernest Samuel Andre
  Date       : 24/05/2023
  Description: Ce programme consiste a lire des donnees de capteurs de temperature, de lumiere et de monoxide
              de carbone pour esuite les envoyes dans une base de donnees afin de prendre des desiscions et pour
              controler l environnement autour de notre objet
  Version    : 0.0.1
*/

#include "CarbonMonoxideSensor.hpp"

CarbonMonoxideSensor::CarbonMonoxideSensor(int pin) : pin(pin) {}

float CarbonMonoxideSensor::calibrate(int sensorValue)
{
  float ppm = 0.0;
  if (sensorValue <= 20)
  {
    ppm = 0.0;
  }
  else if (sensorValue >= 1023)
  {
    ppm = 2000.0;
  }
  else
  {
    ppm = map(sensorValue, 20, 1023, 0, 2000);
  }
  return ppm;
}
