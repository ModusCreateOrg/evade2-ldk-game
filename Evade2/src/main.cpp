#include "Game.h"

BViewPort   *gViewPort;
BGameEngine *gGameEngine;

GGame *gGame;
#ifdef __MODUS_TARGET_NETWORK_DISPLAY__
#include "NetworkDisplay/NetworkDisplay.h"
#endif
/** @file
 * \brief Main entry point for game engine.
 *
 * Initializes the engine and runs the main event loop.
 */
// app_main
extern "C" void app_main(char *fileName) {
  gGame = new GGame();
#ifdef __MODUS_TARGET_NETWORK_DISPLAY__
  NetworkDisplay *display = (NetworkDisplay*)&gDisplay;
//    const char *fileName = "/home/jgarcia/modite-rgb.ini";
#endif
  gGame->Run();
  delete gGame;
}



int main(int argc, char *argv[]) {
  app_main(argv[0]);
  return 0;
}
