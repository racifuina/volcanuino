#include <VirtualWire.h> //Libreria encargada de la comunicación RF.

void setup() {
    pinMode(13, OUTPUT); //Modo salida para el pin 13 (LED DEL ARDUINO)
    pinMode(3, OUTPUT); //Modo salida para el Pin de LED'S
    pinMode(6, OUTPUT); //Modo salida para el Pin del BUZZER
    vw_set_ptt_inverted(true); //Requerido por el modulo
    vw_set_rx_pin(12); //Pin de recepción (RX)
    vw_setup(600); //Velocidad de Transmisión
    vw_rx_start(); //Empezar la recepción de datos
}

void loop() {
    
    //VW_MAX_MESSAGE_LEN valor constante de longitud de mensajes de la libreria VirtualWire
    
    uint8_t buf[VW_MAX_MESSAGE_LEN]; //Buffer
    uint8_t buflen = VW_MAX_MESSAGE_LEN; //Longitud del Buffer
    
    if (vw_get_message(buf, &buflen)) { //Recepción del Buffer de comunicación
        if(buf[0]=='1'){ //si el buffer es igual a '1' se alerta a los pobladores y se activa el protocolo de alarma bajo
            alertPeopleLow();
        } else if(buf[0]=='2'){ //si el buffer es igual a '2' se alerta a los pobladores y se activa el protocolo de alarma alto
            alertPeopleHigh();
        } else { //de lo contrario se apagan las alarmas.
          allGood();
        }
    } 
}

/*
void allGood();
Función que indica que las lecturas
en ambos anillos de seguridad esta fuera de peligro. 

Apaga todos los sistemas de alarma
*/

void allGood() {
    digitalWrite(13, 0);
    digitalWrite(3, 0);
    digitalWrite(6, 0);
}
/*
void alertPeopleLow();
Función que indica que la lectura del primer anillo de seguridad muestra que hay actividad volcanica. 
*/

void alertPeopleLow() { 
    tone(6, 500, 200); //Activa el Buzzer en el pin 6 con una frecuencia de 500 Hz y 200 milisegundos de duración 
    //Encender LED's por 250 milisegundos
    digitalWrite(3, 1);
    digitalWrite(13, 1); 
    delay(250);
    //Apagar LED's por 250 milisegundos
    digitalWrite(3, 0);
    digitalWrite(13, 0);
    delay(250);
    //Encender LED's por 250 milisegundos
    digitalWrite(3, 1);
    digitalWrite(13, 1);
    delay(250);
    //Apagar LED's por 250 milisegundos
    digitalWrite(3, 0);
    digitalWrite(13, 0);
    delay(250);
    tone(6, 500, 200); //Activa el Buzzer en el pin 6 con una frecuencia de 500 Hz y 200 milisegundos de duración 
    //Encender LED's por 250 milisegundos
    digitalWrite(3, 1);
    digitalWrite(13, 1);
    delay(250);
    //Apagar LED's por 250 milisegundos
    digitalWrite(3, 0);
    digitalWrite(13, 0);
    delay(250);
    //Encender LED's por 250 milisegundos
    digitalWrite(3, 1);
    digitalWrite(13, 1);
    delay(250);
    //Apagar LED's por 20 milisegundos
    digitalWrite(3, 0);
    digitalWrite(13, 0);
    delay(20);
}

/*
void alertPeople();
Función que indica que la lectura del segundo anillo de seguridad muestra que hay actividad volcanica, activa todos los sistemas de seguridad y alarmas. 
*/

void alertPeopleHigh() { 
    tone(6, 1000, 500); //Activa el Buzzer en el pin 6 con una frecuencia de 1000 Hz y 500 milisegundos de duración 
    
    //Encender LED's por 250 milisegundos
    digitalWrite(3, 1);
    digitalWrite(13, 1); 
    delay(250);
    //Apagar LED's por 250 milisegundos
    digitalWrite(3, 0);
    digitalWrite(13, 0);
    delay(250);
    //Encender LED's por 250 milisegundos
    digitalWrite(3, 1);
    digitalWrite(13, 1);
    delay(250);
    //Apagar LED's por 250 milisegundos
    digitalWrite(3, 0);
    digitalWrite(13, 0);
    delay(250);
    tone(6, 1000, 500); //Activa el Buzzer en el pin 6 con una frecuencia de 1000 Hz y 500 milisegundos de duración 
    
    //Encender LED's por 250 milisegundos
    digitalWrite(3, 1);
    digitalWrite(13, 1);
    delay(250);
    //Apagar LED's por 250 milisegundos
    digitalWrite(3, 0);
    digitalWrite(13, 0);
    delay(250);
    //Encender LED's por 250 milisegundos
    digitalWrite(3, 1);
    digitalWrite(13, 1);
    delay(250);
    //Apagar LED's por 20 milisegundos
    digitalWrite(3, 0);
    digitalWrite(13, 0);
    delay(20);
}
