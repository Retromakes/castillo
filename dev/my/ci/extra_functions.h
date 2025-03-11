// MTE MK1 (la Churrera) v5.0
// Copyleft 2010-2014, 2020 by the Mojon Twins
/*
// reproduzco sonido
wyz_play_sound(3);
// suelto el objeto
flags[30] = 0;
*/

void Coloca_Objeto(unsigned int n_tile, unsigned int x_obj, unsigned int y_obj) {
    _x = x_obj; _y = y_obj; _t = n_tile; _n = 128; update_tile ();
}

void CambiaNivel(unsigned int nivel_destino, unsigned int pantalla_destino, unsigned int x_inicio, unsigned int y_inicio) {
    level = nivel_destino;
    n_pant = pantalla_destino;
    gpx = x_inicio << 4; p_x = gpx << FIXBITS;
    gpy = y_inicio << 4; p_y = gpy << FIXBITS;
    warp_to_level = success = 1;
    playing = 0;
}


void Recoge_Objeto() {
    // sfx
    wyz_play_sound(5);

    // dibujo el tile actualizado con el fondo de la zona (tile 1)
    _x = p_tx; _y = p_ty; _t = 1; _n = 0; update_tile ();

    // tengo q comprobar que objeto cojo para hacer lo que toque aqui
    // si estamos en el level 0 seran las botas, que no hay otro objeto a recoger
    if (level == 0) inv_botas = 1;
    // si estamos en el level 1 seran los pinchos, que no hay otro objeto a recoger
    if (level == 1) flags[1] = 1;
    
    // debug jetpack en nivel 1
    if (level == 1) inv_jetpack = 1;
}
