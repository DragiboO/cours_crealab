#include <Arduino.h>

/*  Variable du potentiometre */
int poten = 0;

/* Constantes pour les broches du capteur de distance */
const byte TRIGGER_PIN = 12; // Broche TRIGGER
const byte ECHO_PIN = 13;    // Broche ECHO

/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;


void setup() {
    Serial.begin(9600);

    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);

    /* Initialise les broches */
    pinMode(TRIGGER_PIN, OUTPUT);
    digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
    pinMode(ECHO_PIN, INPUT);

}


void loop() {
    /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
    long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);

    /* 3. Calcul la distance à partir du temps mesuré */
    float distance_mm = measure / 2.0 * SOUND_SPEED;

    /* Affiche les résultats en mm */

    Serial.print(F("Distance: "));
    Serial.print(distance_mm);
    Serial.println(F("mm"));

    /* Lecture de la valeur du potentiomètre avec un conversion de la valeur pour obtenir une valeur entre 1 et 4 */
    poten = analogRead(A0) / 341 + 1;
    Serial.println(poten);

    /* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
    delay(100);

    /* Reset de l'allumage des leds */
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);

    /* Conditions pour allumer les différentes leds */
    if (distance_mm <= 1000 * poten) {
    digitalWrite(2, HIGH);
    }
    if (distance_mm <= 500 * poten) {
    digitalWrite(3, HIGH);
    }
    if (distance_mm <= 250 * poten) {
    digitalWrite(4, HIGH);
    }
    if (distance_mm <= 150 * poten) {
    digitalWrite(5, HIGH);
    }
    if (distance_mm <= 100 * poten) {
    digitalWrite(6, HIGH);
    }
    if (distance_mm >= (50 * poten) && distance_mm <= (75 * poten)) {
    digitalWrite(8, HIGH);
    delay(100);
    digitalWrite(8,LOW);
    delay(100);
    }
    if (distance_mm <= 50 * poten) {
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    delay(50);
    digitalWrite(9,LOW);
    delay(50);
    digitalWrite(8, LOW);
    delay(50);
    digitalWrite(9, HIGH);
    delay(50);
    digitalWrite(9,LOW);
    delay(50);
    }
}