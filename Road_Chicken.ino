#include <Arduboy2.h>
#include "Maps.h"
Arduboy2 arduboy;

void drawworld() {
  for(int y = 0; y < WorldHeight; y++) {
    for(int x = 0; x < WorldLength; x++) {
      arduboy.drawBitmap(x * TILE_SIZE, y * TILE_SIZE, tiles[Map[y][x]], TILE_SIZE, TILE_SIZE, WHITE);
      
    }
  }
}

void Game()
{
  switch( gamestate ){
    case Game_Title:
      arduboy.pollButtons();
      arduboy.clear();
      arduboy.setCursor(29,30);
      arduboy.print(F("Road Chicken"));
      arduboy.display();
      if(arduboy.justPressed(A_BUTTON))
      {
        gamestate = Game_Play;
      }
      break;
      case Game_Play:
        arduboy.clear();
        drawworld();
        arduboy.display();
  }
}

void setup()
{
  arduboy.setFrameRate(30);
  arduboy.pollButtons();
  arduboy.clear();
  arduboy.begin();
  arduboy.display();
}

void loop()
{
  arduboy.clear();
  Game();
  arduboy.display();
}

