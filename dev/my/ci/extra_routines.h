// MTE MK1 (la Churrera) v5.0
// Copyleft 2010-2014, 2020 by the Mojon Twins

switch (n_pant) {
    // nariz
    case 27:
        if (p_tx == 8) {
            // reproduzco sonido
            wyz_play_sound(3);
            
    level = 1;
    n_pant = 24;
    gpx = 1 << 4; p_x = gpx << FIXBITS;
    gpy = 5 << 4; p_y = gpy << FIXBITS;
    warp_to_level = success = 1;
    playing = 0;

/*
playing = 0;
    n_pant = 26;
    gpx = 5 << 4; p_x = gpx << FIXBITS;
    gpy = 7 << 4; p_y = gpy << FIXBITS;
//    warp_to_level = success = 1;
success = 1;
*/
/*
// suelto el objeto
flags[30] = 0;
// muestro el objeto en el inventario
RedibujaInventario();
*/
        }
        break;
}
