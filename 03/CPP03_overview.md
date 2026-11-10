# C++ Module 03 — Inheritance

This module builds a family of robot classes in C++98. You start with one class that manages a robot's state, then reuse that state and behavior through inheritance. The optional final exercise shows what happens when two inheritance paths lead to the same base class.

| Exercise | Class | Initial HP | Initial energy | Attack damage | Main concept |
|---|---|---:|---:|---:|---|
| ex00 — Aaaaand... OPEN! | ClapTrap | 10 | 10 | 0 | Object state and member functions |
| ex01 — Serena, my love! | ScavTrap | 100 | 50 | 20 | Single inheritance and a specialized attack |
| ex02 — Repetitive work | FragTrap | 100 | 100 | 30 | Reusing behavior from the same base class |
| ex03 — Now it's weird! | DiamondTrap | 100 | 50 | 30 | Multiple and virtual inheritance |

## ex00 — ClapTrap

ClapTrap stores a name, hit points, energy points, and attack damage. An attack or repair requires positive health and energy and consumes one energy point. Taking damage reduces health to a minimum of zero and does not consume energy. Repair adds to current health.

The attack target is a string. The method prints the damage the attacker would deal; it does not modify another robot. Zero attack damage is the expected starting value for ClapTrap.

## ex01 — ScavTrap

ScavTrap publicly inherits from ClapTrap. Its constructor passes the name to the base constructor and configures the inherited state. It defines its own attack message and adds guardGate().

The base constructor runs first. On destruction, ScavTrap's destructor runs first, followed by ClapTrap's. The derived class uses the state in its own base subobject, so there is no need to redeclare the health, energy, or damage members.

## ex02 — FragTrap

FragTrap also inherits directly from ClapTrap. It adds highFivesGuys() and uses different starting stats. It can reuse ClapTrap::attack(): the same method that reports 0 damage for a standalone ClapTrap reports 30 when called on a FragTrap because it reads the state of the object it is called on.

## ex03 — DiamondTrap (optional)

DiamondTrap publicly inherits from ScavTrap and FragTrap. If both inherit ClapTrap normally, a DiamondTrap contains two separate ClapTrap base subobjects. In this exercise, both paths use virtual inheritance so DiamondTrap contains just one shared ClapTrap subobject.

- The most-derived constructor, DiamondTrap's, initializes the shared ClapTrap with the supplied name plus `_clap_name`. DiamondTrap also stores its own original name. The whoAmI() method prints both.
- Construction starts with the shared ClapTrap, then the direct bases in their declaration order, then DiamondTrap. Destruction reverses that order.
- The direct base constructors can write to the same inherited stats. Set the final combination after they run: 100 HP and 30 damage from FragTrap's defaults, and 50 energy from ScavTrap's defaults.
- Select ScavTrap's attack with `using ScavTrap::attack;` or an explicit forwarding method. The selected method still reads the shared stats of the DiamondTrap, so it reports 30 damage.
- The two name members are intentional. Inside DiamondTrap, an unqualified `_name` refers to its own name. `ClapTrap::_name` identifies the base name if that member is accessible. The `-Wshadow` and `-Wno-shadow` flags control warnings; they do not change name lookup.

## Copying inherited state

A copy constructor initializes a new object, including its base subobject. A copy assignment operator updates an existing object. When writing assignment yourself, call `ClapTrap::operator=(other)` to reuse the code that copies the current base state. A damaged robot with 43 energy is copied with 43 energy, regardless of its class's starting value.

For DiamondTrap, copy the shared ClapTrap state once and also copy the separate DiamondTrap name. Multiple assignment messages during copy construction can indicate repeated writes to the same base; they do not mean multiple ClapTrap subobjects were constructed.

## Build and test

Use `c++ -Wall -Wextra -Werror -std=c++98` and keep each exercise in its own directory with its Makefile and required source files.

- Check initial stats through behavior: a fresh DiamondTrap survives 99 damage and its 51st consecutive attack is refused.
- Verify that attacks and repairs are refused at zero health or zero energy.
- Check DiamondTrap's two names, both inherited abilities, and the ScavTrap attack message with 30 damage.
- Use constructor and destructor logs to verify that each DiamondTrap creates and destroys its ClapTrap base once.
- Copy and assign a robot after changing its state. Verify both names and current stats, then change one copy to check that the objects remain independent.

Source: 42 C++ Module 03 subject. AI assistance was used for concept explanations, code review, test suggestions, and preparing this overview.
