// MTE MK1 (la Churrera) v5.0
// Copyleft 2010-2014, 2020 by the Mojon Twins

switch (level) {
    // exterior
    case 0:
        if ((n_pant == 24) && (p_tx == 8)) {
            // catapumbas top izquierda
            CambiaNivel(2,0,1,5);
        }
        else if ((n_pant == 31) && (p_tx == 13)) {
            // castillo puerta
            CambiaNivel(1,24,2,5);
        }
    break;
    
    // castillo
    case 1:
        if ((n_pant == 24) && (p_tx == 1)) {
            // exterior puerta castillo
            CambiaNivel(0,31,12,4);
        }
        else if ((n_pant == 31) && (p_tx == 9) && (p_ty == 8)) {
            // catapumbas centro (tendra que ser derecha)
            CambiaNivel(2,2,4,7);
        }
    break;
    
    // catapumbas
    case 2:
        if ((n_pant == 0) && (p_ty == 3)) {
            // exterior izq
            CambiaNivel(0,16,4,5);
        }
        else if ((n_pant == 2) && (p_tx == 9)) {
            // castillo trampilla
            CambiaNivel(1,31,7,8);
        }
    break;
}