#include <iostream>
#include "Core/Header/Engine.h"

int main() {
    ne::Engine engine;
    engine.startEngine();
    engine.run();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
