@echo off


if [%1]==[help] goto :help

set game=castillo
set cpc_gfx_mode=0

if [%1]==[justcompile] goto :compile
if [%1]==[clean] goto :clean

cd ..\script
if not exist %game%.spt goto :noscript
echo Compilando script
..\utils\msc3_mk1.exe %game%.spt 36 > nul
copy msc.h ..\dev\my > nul
copy msc-config.h ..\dev\my > nul
copy scripts.bin ..\dev\ > nul
:noscript
cd ..\dev

if [%1]==[justscripts] goto :compile

echo Convirtiendo mapa (el 99 final es el tile de cerrojo)
REM multilevel
REM ..\utils\mapcnv.exe ..\map\mapa0.map assets\mapa.h 8 4 15 10 15 packed
..\utils\mapcnvbin.exe ..\map\mapa0.map ..\bin\mapa_bolts0.bin 8 4 15 10 99 packed >nul
..\utils\mapcnvbin.exe ..\map\mapa1.map ..\bin\mapa_bolts1.bin 8 4 15 10 99 packed >nul
..\utils\mapcnvbin.exe ..\map\mapa2.map ..\bin\mapa_bolts2.bin 8 4 15 10 99 packed >nul

..\utils\apultra.exe ..\bin\mapa_bolts0.bin ..\bin\mapa_bolts0c.bin >nul
..\utils\apultra.exe ..\bin\mapa_bolts1.bin ..\bin\mapa_bolts1c.bin >nul
..\utils\apultra.exe ..\bin\mapa_bolts2.bin ..\bin\mapa_bolts2c.bin >nul

del ..\bin\mapa_bolts?.bin >nul
REM fin multilevel

echo Convirtiendo enemigos/hotspots
REM multilevel
REM ..\utils\ene2h.exe ..\enems\enems0.ene assets\enems.h
..\utils\ene2bin_mk1.exe ..\enems\enems0.ene ..\bin\enems_hotspots0.bin 2 >nul
..\utils\ene2bin_mk1.exe ..\enems\enems1.ene ..\bin\enems_hotspots1.bin 2 >nul
..\utils\ene2bin_mk1.exe ..\enems\enems2.ene ..\bin\enems_hotspots2.bin 2 >nul

..\utils\apultra.exe ..\bin\enems_hotspots0.bin ..\bin\enems_hotspots0c.bin >nul
..\utils\apultra.exe ..\bin\enems_hotspots1.bin ..\bin\enems_hotspots1c.bin >nul
..\utils\apultra.exe ..\bin\enems_hotspots2.bin ..\bin\enems_hotspots2c.bin >nul

del ..\bin\enems_hotspots?.bin >nul
REM fin multilevel

if [%1]==[nogfx] goto :compile

echo Importando GFX
..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=chars greyordered in=..\gfx\font.png out=..\bin\font.bin silent > nul
REM multilevel
REM ..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=strait2x2 greyordered in=..\gfx\work.png out=..\bin\work.bin silent > nul
..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=strait2x2 greyordered in=..\gfx\work0.png out=..\bin\tileset0.bin >nul
..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=strait2x2 greyordered in=..\gfx\work1.png out=..\bin\tileset1.bin >nul
..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=strait2x2 greyordered in=..\gfx\work2.png out=..\bin\tileset2.bin >nul

..\utils\apultra.exe ..\bin\tileset0.bin ..\bin\tileset0c.bin >nul
..\utils\apultra.exe ..\bin\tileset1.bin ..\bin\tileset1c.bin >nul
..\utils\apultra.exe ..\bin\tileset2.bin ..\bin\tileset2c.bin >nul

del  ..\bin\tileset?.bin >nul
REM fin multilevel

REM multilevel
echo Converting behs
..\utils\behs2bin.exe ..\gfx\behs.txt ..\bin\behs0_1_2.bin >nul

..\utils\apultra.exe ..\bin\behs0_1_2.bin ..\bin\behs0_1_2c.bin >nul

del  ..\bin\behs0_1_2.bin >nul
REM fin multilevel

..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=sprites in=..\gfx\sprites.png out=..\bin\sprites.bin mappings=assets\spriteset_mappings.h pixelperfectm0 silent > nul

..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=sprites in=..\gfx\sprites_extra.png out=..\bin\sprites_extra.bin silent > nul
..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=sprites in=..\gfx\sprites_bullet.png out=..\bin\sprites_bullet.bin metasize=1,1 silent > nul

..\utils\png2scr.exe ..\gfx\title.png ..\gfx\title.scr > nul

..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=superbuffer in=..\gfx\marco.png out=..\bin\marco.bin silent > nul
..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=superbuffer in=..\gfx\ending.png out=..\bin\ending.bin silent > nul
..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=superbuffer in=..\gfx\title.png out=..\bin\title.bin silent > nul
..\utils\apack.exe ..\bin\title.bin ..\bin\titlec.bin > nul
..\utils\apack.exe ..\bin\marco.bin ..\bin\marcoc.bin > nul
..\utils\apack.exe ..\bin\ending.bin ..\bin\endingc.bin > nul

..\utils\mkts_om.exe platform=cpc mode=pals in=..\gfx\pal.png prefix=my_inks out=assets\pal.h silent > nul

if [%1]==[justassets] goto :end

:compile
echo Generating LUTs
..\utils\pasmo.exe assets\cpc_TrPixLutM%cpc_gfx_mode%.asm assets\trpixlut.bin
..\utils\apultra.exe assets\trpixlut.bin assets\trpixlutc.bin
..\utils\wyzTrackerParser.exe ..\mus\instrumentos.asm my\wyz\instrumentos.h
echo Compilando guego
zcc +cpc -m -vn -O3 -unsigned -crt0=crt.asm -zorg=1024 -lcpcrslib_fg -DCPC_GFX_MODE=%cpc_gfx_mode% -o %game%.bin tilemap_conf.asm mk1.c > nul
if %errorlevel% neq 0 goto :error
..\utils\printsize.exe %game%.bin
..\utils\printsize.exe scripts.bin

echo Construyendo Snapshot %game%.sna
del %game%.sna > nul
..\utils\cpctbin2sna.exe %game%.bin 0x400 -pc 0x400 -o %game%.sna


if [%2]==[andtape] goto :tape
if [%1]==[justcompile] goto :end

:clean
:tape
echo Construyendo cinta
..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal_loading.png mode=scr in=..\gfx\loading.png out=..\bin\loading.bin silent > nul
del ..\bin\loading.c.bin >nul 2>nul
..\utils\zx7.exe ..\bin\loading.bin ..\bin\loading.c.bin > nul
del ..\bin\%game%.c.bin >nul 2>nul
..\utils\zx7.exe %game%.bin ..\bin\%game%.c.bin > nul

..\utils\imanol.exe in=loader\loadercpc.asm-orig out=loader\loadercpc.asm ^
	scrc_size=?..\bin\loading.c.bin ^
	mainbin_size=?..\bin\%game%.c.bin ^
	loading_palette=!..\gfx\pal_loading.png ^
	loader_mode=%cpc_gfx_mode% > nul
..\utils\pasmo.exe loader\loadercpc.asm ..\bin\loader.bin  > nul

..\utils\imanol.exe in=loader\preloadercpc.asm-orig out=loader\preloadercpc.asm ^
	loader_size=?..\bin\loader.bin ^
	loader_mode=%cpc_gfx_mode% > nul
..\utils\pasmo.exe loader\preloadercpc.asm ..\bin\preloader.bin  > nul

del %game%.cdt > nul
..\utils\cpc2cdt.exe -r %game% -m cpc -l 1024 -x 1024 -p 2000 ..\bin\preloader.bin %game%.cdt
..\utils\cpc2cdt.exe -r LOADER -m raw1full -rl 740 -p 2000 ..\bin\loader.bin %game%.cdt
..\utils\cpc2cdt.exe -r SCR -m raw1full -rl 740 -p 2000 ..\bin\loading.c.bin %game%.cdt
..\utils\cpc2cdt.exe -r MAIN -m raw1full -rl 740 -p 2000 ..\bin\%game%.c.bin %game%.cdt

goto :end 

:error
echo Error
goto endend

:help
echo "compile.bat help|justcompile|clean|justscripts|justassets|nogfx"

:end
echo Hecho!

:endend
