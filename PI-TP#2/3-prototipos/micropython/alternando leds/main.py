from machine import Pin

L1 = Pin(4, Pin.OUT, value = 0)
L2 = Pin(5, Pin.OUT, value = 0)
L3 = Pin(6, Pin.OUT, value = 0)
L4 = Pin(7, Pin.OUT, value = 0)

pulsador = Pin(15, Pin.IN, Pin.PULL_UP) # Pin 15 como entrada para pulsador, actico resistencia PULL_UP

def encender_verdes() : # Funcion para encender Leds verdes
    L1 = Pin(4, Pin.OUT, value = 0)
    L2 = Pin(5, Pin.OUT, value = 1)
    L3 = Pin(6, Pin.OUT, value = 0)
    L4 = Pin(7, Pin.OUT, value = 1)

def encender_rojas() :  # Funcion para encender Leds rojos
    L1 = Pin(4, Pin.OUT, value = 1)
    L2 = Pin(5, Pin.OUT, value = 0)
    L3 = Pin(6, Pin.OUT, value = 1)
    L4 = Pin(7, Pin.OUT, value = 0)

while True :
    alternar = pulsador.value()
    if alternar == False : #Si se pulsa el boton, enciende LEDs verdes
        encender_verdes()
    else :
        encender_rojas()