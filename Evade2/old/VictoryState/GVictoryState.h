#ifndef GVICTORYSTATE_H
#define GVICTORYSTATE_H

#include <BGameEngine.h>

class GVictoryState : public BGameEngine {
public:
  explicit GVictoryState(GGameState *aGameState);
  ~GVictoryState() OVERRIDE;
};

#endif
