#ifndef SOUND_H
#define SOUND_H

#include "Types.h"

const BYTE SFX_PLAYER_SHOOT = 0;
const BYTE SFX_ENEMY_SHOOT = 1;
const BYTE SFX_PLAYER_HIT_BY_ENEMY = 2;
const BYTE SFX_NEXT_ATTRACT_SCREEN = 3;
const BYTE SFX_NEXT_ATTRACT_CHAR = 4;
const BYTE SFX_ENEMY_EXPLODE = 5;
const BYTE SFX_SPEED_BOOST = 6;
const BYTE SFX_ENEMY_FLYBY = 7;
const BYTE SFX_BOSS_EXPLODE = 8;

// 0 INTRO_SONG ✓
// 1 STAGE_1_SONG ✓
// 2 STAGE_1_BOSS_SONG ✓
// 3 STAGE_2_SONG ✓
// 4 STAGE_2_BOSS_SONG ✓
// 5 STAGE_3_SONG ✓
// 6 STAGE_3_BOSS_SONG ✓
// 7 STAGE_4_SONG ✓ (Fix tone portamento)
// 8 STAGE_4_BOSS_SONG ✓
// 9 STAGE_5_SONG ✓
// 10 GAME_OVER_SONG ✓
// 11 GET_READY_SONG ✓
// 12 NEXT_WAVE_SONG ✓


// SONGS
const BYTE INTRO_SONG = 0;
const BYTE STAGE_1_SONG = 1;
const BYTE STAGE_1_BOSS_SONG = 2;
const BYTE STAGE_2_SONG = 3;
const BYTE STAGE_2_BOSS_SONG = 4;
const BYTE STAGE_3_SONG = 5;
const BYTE STAGE_3_BOSS_SONG = 6;
const BYTE STAGE_4_SONG = 7;
const BYTE STAGE_4_BOSS_SONG = 8;
const BYTE STAGE_5_SONG = 9;
const BYTE GAME_OVER_SONG = 10;
const BYTE GET_READY_SONG = 11;
const BYTE NEXT_WAVE_SONG = 11;

class Sound {
public:
  static void init();
  // TODO: getSize() a temp function that is only meant to be
  //       used for development to allow us to determine the size
  //       of a particular score and will be removed before launch.
  static long getSize();
  static void play_sound(BYTE id);
  static void stfu();
  static void play_score(BYTE id);
};
#endif
