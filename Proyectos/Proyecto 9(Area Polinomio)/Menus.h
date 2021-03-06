// ---------------------------------------------------------------------------

#ifndef MenusH
#define MenusH
// ---------------------------------------------------------------------------
#include <iostream>
#include "UPoliVector.h"
#include "UPoliPtr.h"
#include "UPoliSm.h"
#include "UPoliListaPtr.h"
#include "UPoliListaSm.h"
#include "UMemoria.h"

using namespace std;

void menuSm(CSMemoria* m, PoliSm *p);
void menuVector(PoliVector *p);
void menuPtr(PoliPtr *p);
void menuListaPtr(PoliListaPtr *p);
void menuListaSm(PoliListaSm *p);

#endif
