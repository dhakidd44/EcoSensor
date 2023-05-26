/*
  Titre      : Titre du programme
  Auteur     : Ernest Samuel Andre
  Date       : 16/05/2023
  Description: Une description du programme
  Version    : Ce programme consiste a lire des donnees de capteurs de temperature, de lumiere et de monoxide
              de carbone pour esuite les envoyes dans une base de donnees afin de prendre des desiscions et pour
              controler l environnement autour de notre objet
*/

// Class pour le capteur de temperature LM35
#ifndef LM35_SENSOR_HPP
#define LM35_SENSOR_HPP
#include <Arduino.h>

class LM35Sensor
{
private:
  int pin;

public:
  LM35Sensor(int pin);

  float readTemperature(int tempValue);
};

#endif 