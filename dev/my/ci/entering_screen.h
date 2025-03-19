// MTE MK1 (la Churrera) v5.0
// Copyleft 2010-2014, 2020 by the Mojon Twins

switch (level) {
    // exterior
    case 0:
        // llave 1
        if ((n_pant == 25) && (llaves_recogidas < 1)) Coloca_Objeto (18, 10, 5, 128);
        // botas
        if ((n_pant == 26) && (inv_botas == 0)) Coloca_Objeto (14, 10, 5, 128);
        // puerta castillo
        if ((n_pant == 31) && (puertas_abiertas == 0)) Coloca_Objeto (15, 12, 2, 8);
        break;
    // castillo
    case 1:
        // pinchos
        if ((n_pant == 24) && (flags[1] == 0)) Coloca_Objeto (14, 11, 8, 128);
        break;
    // castillo
    case 2:
        // jetpack
        if ((n_pant == 0) && (inv_jetpack == 0)) Coloca_Objeto (14, 11, 8, 128);
        break;
}