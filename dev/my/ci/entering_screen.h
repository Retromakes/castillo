// MTE MK1 (la Churrera) v5.0
// Copyleft 2010-2014, 2020 by the Mojon Twins

switch (level) {
    // exterior
    case 0:
        if ((n_pant == 26) && (inv_botas == 0)) Coloca_Objeto (15, 10, 5);
    // castillo
    case 1:
        if ((n_pant == 24) && (flags[1] == 0)) Coloca_Objeto (15, 11, 8);
}