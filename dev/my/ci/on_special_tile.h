// MTE MK1 (la Churrera) v5.0
// Copyleft 2010-2014, 2020 by the Mojon Twins

// INVENTARIO -> flags[30]
// mientras este tocando un tile especial el flags[1] se pone a 1, y cuando deja de tocarlo se pone a 0 (en player.h) para que no lance el if cada fotograma y cambie de objeto cada fotograma

// compruebo que el item de esta pantalla no esta a 0 (recogido)
// y que el flag 1 (tocando objeto especial) ya no esta activo
/*
if ((flags[n_pant] != 0) && (flags[31] != 1)) {
    Recoge_Objeto(n_pant);
}
*/

// DEBUG TO DO tengo que comprobar que el objeto ya no ha sido recogido?

// sfx
wyz_play_sound(5);

// dibujo el tile actualizado con el fondo
_x = p_tx; _y = p_ty; _t = 0; _n = 0; update_tile ();

// segun nivel y pantalla recojo el objeto que toque
switch (level) {
    // exterior
    case 0:
       // Llave 1
       if (n_pant == PANTALLA_LLAVE_1) {
           llaves_recogidas = 1;
       // botas
       } else if (n_pant == PANTALLA_BOTAS) {
           inv_botas = 1;
       }
    break;

    // castillo
    case 1:
        // pinchos
        flags[1] = 1;
    break;

    // catapumbas
    case 2:
        // jetpack
        inv_jetpack = 1;
    break;
}