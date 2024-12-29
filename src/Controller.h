#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Header.h"

struct Controller
{
  public:
      // References to the objects and data needed to pour a drink
      Platform *plat;
      const Solenoid *solenoids;

      // Default constructor
      Controller();

      // Parameterized constructor
      Controller(Platform *arg_plat, Solenoid *arg_solenoids);

      // Housekeeping stuff
      void BootUp();

      // Make sure all the solenoids don't open simultaneously upon bootup
      void CloseAllSolenoids();

      // Outputs position of platform
      void ShowPosition();

      // Gets them shawties out on da flo
      void ErrBodyInTheClub(int* recipe);

      /*
      Calculates the most efficient movement path for pouring drink X relative to platform's current position
      Algorithm summary:
      - Calculate the furthest solenoid used in the recipe on both sides of the platform
      - Move to the furthest solenoid on the side whose furthest solenoid was the lesser distance of the two
      - If the initial move is to the right, sort the drink and duration lists descending
      - If the initial move is to the left, sort the drink and duration lists ascending
      - Execute the list of movements and pour durations in the list.
      */

      // Returns the length of a recipe array (excluding the -1 endstop)
      short int RecipeLen(int* recipe);

      // Returns whether the platform is already under a solenoid that's part of the recipe.
      // bool AlreadyUnder(short int size, short int platXPos, short int *xPosInRecipe);

      void TODO_1_or_so();
      void TODO_2_or_so();
};
#endif
