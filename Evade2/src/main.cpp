#include "Game.h"

BViewPort   *gViewPort;
BGameEngine *gGameEngine;

GGame *gGame;
//TOptions *gOptions;

/** @file
 * \brief Main entry point for game engine.
 *
 * Initializes the engine and runs the main event loop.
 */
extern "C" void app_main() {
  gGame = new GGame();
  gGame->Run();
}

int main() {
  app_main();
  return 0;
}

