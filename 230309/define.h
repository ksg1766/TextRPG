#pragma once

#define SAFE_DELETE(p) if(p) {delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p; p = nullptr;}

enum PlayerClass {
	���� = 1,
	������,
	����,
};

typedef enum PlayerState {
	����,
	�ߵ�,
}STATE;