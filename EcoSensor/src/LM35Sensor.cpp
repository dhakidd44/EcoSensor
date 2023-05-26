// LM35Sensor.cpp

/*
  Titre      : Titre du programme
  Auteur     : Ernest Samuel Andre
  Date       : 16/05/2023
  Description: Ce programme consiste a lire des donnees de capteurs de temperature, de lumiere et de monoxide
              de carbone pour esuite les envoyes dans une base de donnees afin de prendre des desiscions et pour
              controler l environnement autour de notre objet
  Version    : 0.0.1
*/

#include "LM35Sensor.hpp"

LM35Sensor::LM35Sensor(int pin)
{
    pin = pin;
} // dans la pin entre parethese on met la broche

float LM35Sensor::readTemperature(int tempValue)
{
    {
        int rawValue = analogRead(pin);
        float temperature1 = (rawValue / 4095.0) * 5.0;
        float temperature2 = temperature1 * 100.0;
        return temperature2;
    }
}