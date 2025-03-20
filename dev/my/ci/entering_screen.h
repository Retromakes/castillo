// MTE MK1 (la Churrera) v5.0
// Copyleft 2010-2014, 2020 by the Mojon Twins

switch (level) {
    // exterior
    case 0:
        // llave 1
        if ((n_pant == PANTALLA_LLAVE_1) && (llaves_recogidas < 1)) Coloca_Objeto (18, X_LLAVE_1, Y_LLAVE_1, 128); // ubicacion final
        // botas
        if ((n_pant == PANTALLA_BOTAS) && (inv_botas == 0)) Coloca_Objeto (14, X_BOTAS, Y_BOTAS, 128); // ubicacion final
        // puerta castillo
        if ((n_pant == 31) && (puertas_abiertas == 0)) Coloca_Objeto (15, 12, 2, 8);
        // llave 2 bajo malo en agujero
        if ((n_pant == PANTALLA_LLAVE_2) && (llaves_recogidas < 2)) Coloca_Objeto (18, X_LLAVE_2, Y_LLAVE_2, 128); // ubicacion final
        break;
    // castillo
    case 1:
        // pinchos
        if ((n_pant == PANTALLA_PINCHOS) && (flags[1] == 0)) Coloca_Objeto (14, X_PINCHOS, Y_PINCHOS, 128); // ubicacion final
        break;
    // castillo
    case 2:
        // jetpack
        if ((n_pant == PANTALLA_JETPACK) && (inv_jetpack == 0)) Coloca_Objeto (14, X_JETPACK, Y_JETPACK, 128);
        break;
}