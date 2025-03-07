// MTE MK1 (la Churrera) v5.0
// Copyleft 2010-2014, 2020 by the Mojon Twins
/*
// reproduzco sonido
wyz_play_sound(3);
// suelto el objeto
flags[30] = 0;
*/

/*
void Coloca_Objeto(unsigned int n_obj, unsigned int x_obj, unsigned int y_obj) {
    _x = x_obj; _y = y_obj; _t = flags[n_obj]; _n = 128; update_tile ();
}

void Coloca_Obstaculo(unsigned int sprite_obs, unsigned int x_obs, unsigned int y_obs) {
    _x = x_obs; _y = y_obs; _t = sprite_obs; _n = 8; update_tile ();
}

void Coloca_Walkable(unsigned int sprite_obs, unsigned int x_obs, unsigned int y_obs) {
    _x = x_obs; _y = y_obs; _t = sprite_obs; _n = 0; update_tile ();
}

void Vacia(unsigned int x_obs, unsigned int y_obs) {
    _x = x_obs; _y = y_obs; _t = _n = 0; update_tile ();
}

void EscribeTextoPantalla(void) {
    _x = 0; _y = 23; _t = 79;
    _gp_gen = textos_pantallas[n_pant];
    print_str ();
}

void EscribeTexto(char *frase) {
    _x = 0; _y = 23; _t = 79;
    _gp_gen = frase;
    print_str ();
}
*/

void CambiaNivel(unsigned int nivel_destino, unsigned int pantalla_destino, unsigned int x_inicio, unsigned int y_inicio) {
    level = nivel_destino;
    n_pant = pantalla_destino;
    gpx = x_inicio << 4; p_x = gpx << FIXBITS;
    gpy = y_inicio << 4; p_y = gpy << FIXBITS;
    warp_to_level = success = 1;
    playing = 0;
}