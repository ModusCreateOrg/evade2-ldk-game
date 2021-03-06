#include "Game.h"
#include "GCreditsProcess.h"
#include "GCreditsPlayfield.h"

GCreditsState::GCreditsState(GGameState *aGameState) : BGameEngine(gViewPort) {
  mFont16 = new BFont(gResourceManager.GetBitmap(FONT_16x16_SLOT), FONT_16x16);
  mPlayfield = new GCreditsPlayfield(aGameState);
  AddProcess(new GCreditsProcess());

  gWidgetTheme.Configure(
      WIDGET_TEXT_BG, COLOR_TEXT_BG,
      WIDGET_TITLE_FONT, mFont16,
      WIDGET_TITLE_FG, COLOR_TEXT,
      WIDGET_TITLE_BG, -1,
      WIDGET_WINDOW_BG, gDisplay.renderBitmap->TransparentColor(),
      WIDGET_WINDOW_FG, gDisplay.renderBitmap->TransparentColor(),
      WIDGET_END_TAG);

  gDisplay.SetColor(COLOR_TEXT, 255, 255, 255);
  gDisplay.SetColor(COLOR_TEXT_BG, 255, 92, 93);

#ifdef ENABLE_AUDIO
  //gSoundPlayer.PlayMusic(1);
#endif
}

GCreditsState::~GCreditsState() {
  delete mPlayfield;
  delete mFont16;
  mPlayfield = ENull;
}

