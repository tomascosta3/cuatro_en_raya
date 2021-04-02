#include <iostream>
#include "menu.h"
using namespace std;

int main() {
    Menu* menu = new Menu();
    menu -> iniciar();
    delete menu;
    return 0;
}
