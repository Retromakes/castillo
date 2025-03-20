// MTE MK1 (la Churrera) v5.0
// Copyleft 2010-2014, 2020 by the Mojon Twins

// numero de puertas abiertas
unsigned char puertas_abiertas = 0;

// numero de llaves recogidas
unsigned char llaves_recogidas = 0;

// tiene las botas de saltar?
unsigned char inv_botas = 0;

// tiene el jetpack?
unsigned char inv_jetpack = 0;

// la flags[1] (definida en PLAYER_CAN_STEP_ON_FLAG en config.h) determina si puede matar al saltar sobre enemigos


// CONSTANTES (para debug van muy bien)
//if ((n_pant == 26) && (inv_botas == 0)) Coloca_Objeto (14, 10, 5, 128); // ubicacion DEBUG
#define PANTALLA_BOTAS 31
#define X_BOTAS 8
#define Y_BOTAS 5

//if ((n_pant == 25) && (llaves_recogidas < 1)) Coloca_Objeto (18, 10, 5, 128); // ubicacion DEBUG
#define PANTALLA_LLAVE_1 10
#define X_LLAVE_1 8
#define Y_LLAVE_1 4

//if ((n_pant == 24) && (flags[1] == 0)) Coloca_Objeto (14, 11, 8, 128); // ubicacion DEBUG
#define PANTALLA_PINCHOS 11
#define X_PINCHOS 6
#define Y_PINCHOS 7

#define PANTALLA_LLAVE_2 24
#define X_LLAVE_2 11
#define Y_LLAVE_2 7

#define PANTALLA_JETPACK 0
#define X_JETPACK 11
#define Y_JETPACK 8

