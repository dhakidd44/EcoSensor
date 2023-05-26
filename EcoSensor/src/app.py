# Ce programme consiste a recuperer des valeurs dans le moniteur serie d'un programme arduino 
# d un objet connecter et ensuite les convertir en float pour les inserer dans une base de donnee

import serial
import psycopg2
import time
from datetime import datetime

# Configuration de la base de données PostgreSQL
db_host = 'localhost'
db_port = 5432
db_name = 'ecosensordb'
db_user = 'postgres'
db_password = 'admin'

# Connection a la base de donnee
try:
    conn = psycopg2.connect(
        host=db_host,
        port=db_port,
        database=db_name,
        user=db_user,
        password=db_password
    )
    print("Connexion à la base de données réussie !")
except psycopg2.Error as e:
    print("Erreur lors de la connexion à la base de données PostgreSQL:", e)
    exit()
port = 'COM5'
baudrate = 9600

# Variables pour stocker les lignes
line1 = None
line2 = None
line3 = None

# Ouverture de la connexion série avec l'Arduino
ser = serial.Serial(port, baudrate)

while True:
    # Lecture des données des capteurs depuis l'Arduino
    line1 = ser.readline().decode().strip()  # Lecture de la première ligne
    line2 = ser.readline().decode().strip()  # Lecture de la deuxième ligne
    line3 = ser.readline().decode().strip()  # Lecture de la troisième ligne

        
   # Vérification et traitement des données
    if line1 and line2 and line3:

        value1 = float(line1)
        value2 = float(line2)
        value3 = float(line3)
   
        # variable pour stocker la date et l'heure actuelles
        date_enregistrement = datetime.now()

        # affichage de nos valeurs obtenues
        print("Valeur du capteur 1:", value1)
        print("Valeur du capteur 2:", value2)
        print("Valeur du capteur 3:", value3)
            
    else:
            # Les données ne sont pas complètes pour les trois capteurs
            print("Données incomplètes")

    # Insertion des données dans la table respective de notre base de donnees
    cursor = conn.cursor()
    cursor.execute("INSERT INTO mesure (id_capteur, valeur, date_enregistrement ) VALUES (%s, %s, %s)", (1, value1, date_enregistrement))
    cursor.execute("INSERT INTO mesure (id_capteur, valeur, date_enregistrement ) VALUES (%s, %s, %s)", (2, value2, date_enregistrement))
    cursor.execute("INSERT INTO mesure (id_capteur, valeur, date_enregistrement ) VALUES (%s, %s, %s)", (3, value3, date_enregistrement))
    conn.commit()
   
    # Vérifiez si les données ont été insérées dans la base de données
    cursor.execute("SELECT * FROM mesure")
    records = cursor.fetchall()
    print("Enregistrements dans la table mesures:")
    for record in records:
        print(record)

    # Fermeture du curseur
    cursor.close()
# Attente de 2 minutes avant de lire les prochaines données
    time.sleep(120)
    
# Fermeture de la connexion à la base de données
    # conn.close()
    # ser.close()