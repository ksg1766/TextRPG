#pragma once

#define SAFE_DELETE(p) if(p) {delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p; p = nullptr;}

enum PlayerClass {
	전사 = 1,
	마법사,
	도적,
};

typedef enum PlayerState {
	정상,
	중독,
}STATE;