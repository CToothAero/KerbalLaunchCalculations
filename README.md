# KerbalLaunchCalculations

Kerbal Space Program (KSP) is a space exploration based game where the player constructs and launches rockets to achieve certain objectives.

At launch several calculations need to be made for mission design. Chief among these, at least for me, are thrust-to-weight ratio (TWR) and delta V (dV).

THis program is intended to allow the user to supply information for stages including initial mass, final/dry mass, rockets, and quantity of rockets. The program will then use this information to calculate the throttle coefficients necessary to achieve stock TWRs of 1, 1.25, 1.5, and 2.0.

Initial version:
Focus on calculating TWR/throttle coefficients
Limit to one Stage

Next Steps:
Add calculation for launch stage's delta vee value.
Add multiple stage support.
Calculate total delta vee capability.
Given total delta vee, suggest potential round-trip/one-way missions.
