#define DEBUGME

#include "Evade2.h"

#define SHOW_FPS
#undef SHOW_FPS

#ifdef SHOW_FPS
long previousTime = 0;
uint8_t fps = 0, fpsCounter = 0;
#endif

// Global variables.
Arduboy2Core arduboy;
UBYTE game_mode;

// using const saves RAM - we know what the frame rate is, so we may as well
// hard code it, saving the RAM in the process.
static const BYTE eachFrameMillis = 1000 / FRAMERATE;
// We only need this one variable to track when to idle() while waiting for the
// next frame to start.
static ULONG nextFrameStart = 0;

static void initRandomSeed() {
  power_adc_enable(); // ADC on

  // do an ADC read from an unconnected input pin
  ADCSRA |= _BV(ADSC); // start conversion (ADMUX has been pre-set in boot())
  while (bit_is_set(ADCSRA, ADSC)) {
  } // wait for conversion complete

  randomSeed(((unsigned long)ADC << 16) + micros());

  power_adc_disable(); // ADC off
}

static BOOL pressed(UBYTE buttons) {
  return (arduboy.buttonsState() & buttons) == buttons;
}

static void flashlight() {
  if (!pressed(UP_BUTTON)) {
    return;
  }
  arduboy.sendLCDCommand(OLED_ALL_PIXELS_ON); // smaller than allPixelsOn()
  arduboy.digitalWriteRGB(RGB_ON, RGB_ON, RGB_ON);

  // prevent the bootloader magic number from being overwritten by timer 0
  // when a timer variable overlaps the magic number location, for when
  // flashlight mode is used for upload problem recovery
  power_timer0_disable();

  while (true) {
    arduboy.idle();
  }
}

void setup(void) {
#ifdef DEV
  Serial.begin(9600);
  Serial.print("initialized\n");
  Serial.flush();
#elif INIT_SERIAL
  Serial.begin(9600);
  Serial.print("initialized\n");
  Serial.flush();
#endif
  // initiate arduboy instance
  arduboy.boot();
  // flashlight();
  // arduboy.invert(FALSE);
  initRandomSeed();

  Sound::init();
  /*
    Blank screen by calling display twice (with clear flag set), cheaper than having a dedicated function
  */
  Graphics::display(TRUE);
  Graphics::display(TRUE);
  Starfield::init();
  ProcessManager::init();
  ObjectManager::init();

#ifdef ENABLE_MODUS_LOGO
  ProcessManager::birth(Logo::entry);
#else
  ProcessManager::birth(Splash::entry);
#endif
  nextFrameStart = millis();
}

void loop(void) {
  ULONG now = millis();
  // pause render until it's time for the next frame
  if (now < nextFrameStart) {
    arduboy.idle();
    return;
  }
  nextFrameStart = now + eachFrameMillis;

  Controls::run();
  Camera::move();
  if (game_mode == MODE_GAME || game_mode == MODE_NEXT_WAVE) {
    Player::before_render();
  }
#ifdef ENABLE_MODUS_LOGO
  if (game_mode != MODE_LOGO) {
    Starfield::render();
  }
#else
  Starfield::render();
#endif
  ProcessManager::run();
  ObjectManager::run();
  if (game_mode == MODE_GAME || game_mode == MODE_NEXT_WAVE) {
    // process player bullets
    Bullet::run();
    // process enemy bullets
    EBullet::run();
    if (game_mode != MODE_NEXT_WAVE) {
      // process wave status
      Game::run();
    }
    // handle any player logic needed to be done after guts of game loop (e.g. render hud, etc.)
    Player::after_render();
  }

#ifdef SHOW_FPS
  fpsCounter++;
  long actualTime = millis();
  if ((fpsCounter % FRAMERATE) == 0) {
    if (previousTime != 0) {
      fps = (FRAMERATE * 1000 / (actualTime - previousTime));
    }
    previousTime = actualTime;
    fpsCounter = 0;
  }

  Font::printf(60, 5, "%d", fps);
#endif

  // then we finaly we tell the arduboy to display what we just wrote to the
  // display
  // TODO instead of erasing the entire screen to black here, maybe we can erase the stars and lines
  Graphics::display(TRUE);
}
