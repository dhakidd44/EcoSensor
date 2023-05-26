#include <Arduino.h>
#include "LM35Sensor.hpp"
#include "LightAmbientSensor.hpp"
#include "CarbonMonoxideSensor.hpp"
#include <iostream>
#include <SPI.h>

const int LM35_PIN = A0;
const int LIGHT_AMBIENT_PIN = A2;
const int CARBON_MONOXIDE_PIN = A3;
/*
  Titre      : Titre du programme
  Auteur     : Ernest Samuel Andre
  Date       : 16/05/2023
  Description: Ce programme consiste a lire des donnees de capteurs de temperature, de lumiere et de monoxide
              de carbone pour esuite les envoyes dans une base de donnees afin de prendre des desiscions et pour
              controler l environnement autour de notre objet
  Version    : 0.0.1
*/

// declaration des onjets utilises
LM35Sensor lm35(LM35_PIN);
LightAmbientSensor lightAmbient(LIGHT_AMBIENT_PIN);
CarbonMonoxideSensor carbonMonoxide(CARBON_MONOXIDE_PIN);

void setup()
{
  // initialisation du moniteur
  Serial.begin(9600);
}

void loop()
{
  
  int sensorValue = analogRead(CARBON_MONOXIDE_PIN);
  int tempValue = analogRead(LM35_PIN);
  int lightValue = analogRead(LIGHT_AMBIENT_PIN);

  // Lecture des valeurs des capteurs et insertion dans la base de données
  float temperature = lm35.readTemperature(tempValue);
  float lightLevel = lightAmbient.readLightLevel(lightValue);
  float ppm = (carbonMonoxide.calibrate(sensorValue)/4);

  Serial.println(temperature); // Donnee de temperature en celcius
  Serial.println(lightLevel);  // Donnee de lumiere en pourcentage
  Serial.println(ppm);         // Donnee de carbon monixide en ppm
  delay(10000);
}
