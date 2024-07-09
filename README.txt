# oop2_project
Final project in the OOP2 course

// -------------------------------------------------- -------

# Written by:
- Daniel Errol. ID - 311603534.
- Yohanan Shevdron. ID - 203223078.

// -------------------------------------------------- -------

# About this Program:

This program is the fish-eat-fish game, complete with graphics. It uses the SFML library for graphics, sounds, and fonts.

// -------------------------------------------------- -------

# Files We Created:

- Resource.h - Singleton class:
  - Manages all program resources, including textures, audio, texts, and fonts.
  - Loads resources once and provides access throughout the program.
  - Responsible for playing sounds.

- Menu.h/cpp - Displays the main menu before the game starts and after it ends.
  - Submodules:
    - Command.h/cpp - Abstract class for all types of buttons.
    - NewGame.h/cpp - Inherits from the Command class.
    - Help.h/cpp - Inherits from the Command class.
    - Records.h/cpp - Inherits from the Command class and handles displaying the records table.

- GameObject.h/cpp - Abstract class for all game objects.
  - Submodules:
    - IsEaten.h/cpp - Abstract class for game objects that can be eaten.
      - Inherits: Gift.h, **Fish.h.
        - Gift.h has sub-inheritances: GiftFreeze.h, **GiftSpeed.h.
    - Obstacle.h/cpp - Class for static obstacles.

- Controller.h/cpp - Main class that manages the game and menu logic.

- Level.h/cpp - Abstract class for level data.
  - Level1.h/cpp - Manages the first level, including object movement, collision detection, level transitions, and game termination. Inherits from Level.
    - (Our game currently has one level, but it is designed for easy addition of more levels.)
  - ControllerLevel.h/cpp - Manages level execution.

- Fish.h/cpp - Inherits from IsEaten and represents fish objects.
  - Subclasses:
    - FishEaten.h/cpp - Manages fish collision logic.
      - Subclasses: SmallFish.h/cpp, **MediumFish.h/cpp.
    - MediumFish.h/cpp - Represents medium-sized fish that are not always eaten.
    - SmallFish.h/cpp - Represents small fish that are always eaten.
    - ObstacleFish.h/cpp - Represents a fish that ends the game if collided with.
    - Player.h/cpp - Manages player-specific logic and collisions.

// -------------------------------------------------- -------

# Main Data Structure:

The main data is stored in several vectors of unique_ptr.

// -------------------------------------------------- -------

# Notable Algorithm:

The fish are added  with increasing difficulty.
// -------------------------------------------------- -------

# Known Bugs:

Due to invisible collision frames, it may appear that the player's fish did not collide with a shark, but a collision actually occurred.

// -------------------------------------------------- -------

# Remarks:

We used the Command design pattern both for creating game levels and for the menu, and also whis the class resources  (Singleton).