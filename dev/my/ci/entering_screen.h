// MTE MK1 (la Churrera) v5.0
// Copyleft 2010-2014, 2020 by the Mojon Twins

switch (level) {
    // exterior
    case 0:
        // botas
        if ((n_pant == 26) && (inv_botas == 0)) Coloca_Objeto (14, 10, 5);
        break;
    // castillo
    case 1:
        // pinchos
        if ((n_pant == 24) && (flags[1] == 0)) Coloca_Objeto (14, 11, 8);
        break;
    // castillo
    case 2:
        // jetpack
        if ((n_pant == 0) && (inv_jetpack == 0)) Coloca_Objeto (14, 11, 8);
        break;
}