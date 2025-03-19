// MTE MK1 (la Churrera) v5.0
// Copyleft 2010-2014, 2020 by the Mojon Twins
/*
// reproduzco sonido
wyz_play_sound(3);
// suelto el objeto
flags[30] = 0;
*/

void Coloca_Objeto(unsigned int n_tile, unsigned int x_obj, unsigned int y_obj, unsigned int comportamiento) {
    _x = x_obj; _y = y_obj; _t = n_tile; _n = comportamiento; update_tile ();
}

void CambiaNivel(unsigned int nivel_destino, unsigned int pantalla_destino, unsigned int x_inicio, unsigned int y_inicio) {
    level = nivel_destino;
    n_pant = pantalla_destino;
    gpx = x_inicio << 4; p_x = gpx << FIXBITS;
    gpy = y_inicio << 4; p_y = gpy << FIXBITS;
    warp_to_level = success = 1;
    playing = 0;
}