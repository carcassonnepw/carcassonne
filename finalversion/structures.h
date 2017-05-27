#ifndef STRUCTURES_H
#define STRUCTURES_H
#define TILECOUNT 93


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
 struct roadsstruct
{
	int RID;
        int start;
	int tilers[TILECOUNT*4];
	int points;
};

struct neighbours
{
    int tid;
    int rid;
    int did;
    int lid;
    
};
struct twoints {
	int a;
	int b;
};
struct tile tiles [TILECOUNT];


struct tileongrid tilesongrid [900];
#endif
