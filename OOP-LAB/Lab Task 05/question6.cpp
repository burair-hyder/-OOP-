#include <iostream>

using namespace std;

class GraphicsEngine {
public:
    GraphicsEngine() {
        cout << "Initializing Graphics Engine...\n";
    }
    void render() {
        cout << "Displaying visuals on screen...\n";
    }
};

class InputHandler {
public:
    InputHandler() {
        cout << "Setting up Input Handler...\n";
    }
    void processInput() {
        cout << "Capturing and interpreting user input...\n";
    }
};

class PhysicsEngine {
public:
    PhysicsEngine() {
        cout << "Starting Physics Engine...\n";
    }
    void updatePhysics() {
        cout << "Simulating physics calculations...\n";
    }
};

class GameEngine {
private:
    GraphicsEngine graphics;
    InputHandler input;
    PhysicsEngine physics;

public:
    GameEngine() {
        cout << "Booting up Game Engine...\n";
    }
    void runGameLoop() {
        cout << "Beginning Main Game Loop...\n";
        input.processInput();
        physics.updatePhysics();
        graphics.render();
        cout << "Ending Game Cycle...\n";
    }
};

int main() {
    GameEngine game;
    game.runGameLoop();
    return 0;
}
