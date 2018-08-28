#include <VirtualWire.h> //Libreria encargada de la comunicación RF.

char *controller; //Variable para guardar el comando que se enviará
int cable1 = A1; //Pin analogico Anillo de Seguridad 1
int cable2 = A2; //Pin analogico Anillo de Seguridad 2

void setup() {
    pinMode(13, OUTPUT); //Modo salida para el pin 13 (LED DEL ARDUINO)
    vw_set_ptt_inverted(true); //Requerido por el modulo
    vw_set_tx_pin(12); //Pin de transmision (TX)
    vw_setup(600); //Velocidad de Transmisión
}

void loop() {
    if (analogRead(cable1) != 1023 && analogRead(cable2) != 1023) {
        sendHighDanger();
    } else if (analogRead(cable1) != 1023) { //si la lectura del anillo de seguridad 1 no es igual a 1023 (5 volts) se envía una alerta
        sendLowDanger();
    } else if (analogRead(cable2) != 1023) { //si la lectura del anillo de seguridad 2 no es igual a 1023 (5 volts) se envía una alerta
        sendHighDanger();
    } else { //si ambos anillos se encuentran bien, enviamos comando 0
        sendOK();
    }
    delay(2000); //Espera de 2 segundos entre cada lectura.
}

/*
void sendOK();
Función encargada de enviar el comando 0 que indica que las lecturas
en ambos anillos de seguridad esta fuera de peligro. 
*/
void sendOK(){ 
    digitalWrite(13, 0);  //Apagar LED del arduino
    controller="0"; //set comando 0
    vw_send((uint8_t *)controller, strlen(controller));  //envio del comando
    vw_wait_tx(); //Esperar a que el mensaje se envie completamente
}

/*
void sendLowDanger();
Función encargada de enviar el comando 1 que indica que la lectura
del primer anillo de seguridad muestra que hay lava. 
*/
void sendLowDanger() {
    digitalWrite(13, 1); //encender LED del arduino
    controller = "1"; //set comando 1
    vw_send((uint8_t *)controller, strlen(controller));//envio del comando 
    vw_wait_tx(); //Esperar a que el mensaje se envie completamente
}

/*
void sendHighDanger();
Función encargada de enviar el comando 1 que indica que la lectura
del segundo anillo de seguridad muestra que hay lava. 
*/
void sendHighDanger() {
    digitalWrite(13, 1); //encender LED del arduino
    controller = "2"; //set comando 1
    vw_send((uint8_t *)controller, strlen(controller));//envio del comando 
    vw_wait_tx(); //Esperar a que el mensaje se envie completamente
}
