# calculate-fuel
Advent of Code Day 1 - Calculates the total fuel required to lift a launch a (very large) rocket (C++)  

https://adventofcode.com/

Calculates the total fuel required to launch a rocket with a large number of modules, taking into account the mass of the fuel.
The masses of all modules are provided in Module-Masses.txt, included in the repository.

Uses a simple formula for the mass of fuel: mass of fuel = mass of module / 3 - 2  
This is then repeated to calculate the fuel required to lift the fuel added so far. Any mass that would require negative fuel is treated as requiring zero fuel.
