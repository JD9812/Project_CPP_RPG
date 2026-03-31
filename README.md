#RPG Game (C++)

Is a modular RPG style game built in C++, using object-oriented design, templates, polymorphism, and dynamic memory management.

#Features
  - Diferent characters types
  - Abilities system
  - Multiple weapons
  - Team and Guild system
  - Character interface

#Concepts
  - C++
  - Object-Oriented Programming
  - Templates
  - Polymorphism
  - Dynamic memory management
  - Rule of five
  - Deep copy
  - Composition
  - Operators overloading

#Design
  - Character System
    - Characters inherit from abstract base:
        - class Character
          * attack and defense behaviour
          * health management
          * Interface for all characters
    - Template Based
        - class characterTpl
          * Different health behaviours
          * Base character behaviour
    - Character Types
        - Barbarian
          * 2 weapons
          * Use of ability
          * Attack scaling
        - Archer
          * Ranged attacker
          * Attack multiplier
          * Damage reduction
        - Rogue
          * 2 abilitites
          * Fast attacks
          * Dagger damage
  - Abilities System
        - Modify combat
          * Damage dealt and received
          * Health
  - Weapon System
        - Use structs to define weapons
          * inplicit conversion to calculate damage
  - Health System
        - Different health behaviours
  - Team/Guild System
        - Manage collections of characters
        - Add/remove members
        - Display team info

#How To Run
  - Visual Studio
      1. Open .sln file
      2. Build solution (Ctrl + Shift + B)
      3. Run program (F5)

#Future Improvements
  - Refactor dynamic arrays to use std::vector
  - Implement unique pointers
  - Implement turned base system
  - Add unit testing

#Author
  Juan Diego Correa Noy
