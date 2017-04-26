#ifndef STRUCTURES_H
#define STRUCTURES_H
#define TILECOUNT 87

struct tile
{
    int ID;
    int availability;
    char top, right, bottom, left;
    int isShield;
    int isTemple;
    int isCity;
    int isCrossroad;
} ;
struct tileongrid
{
	int GID;
	int ID;
	int x;
	int y;
	

};
struct tile tiles [TILECOUNT];
struct tileongrid tilesongrid [900];
#endif
