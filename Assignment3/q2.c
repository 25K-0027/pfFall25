#include <stdio.h>

/*
  Q2: Recursive spacecraft fuel tracker
  - Prints remaining fuel after each planet
  - Handles consumption, gravitational assist, solar recharge every 4th planet
  - Returns 1 if spacecraft completes journey, 0 if fuel exhausted
*/

int calculateFuel(int fuel, int consumption, int recharge, int solarBonus, int planet, int totalPlanets) {
    // Base cases
    if (fuel <= 0) {
        printf("Planet %d: Fuel depleted! Mission failed.\n", planet);
        return 0; // mission failed
    }
    if (planet > totalPlanets) {
        printf("Mission complete! Fuel remaining: %d\n", fuel);
        return 1; // mission success
    }

    // Fuel adjustment for this planet
    fuel -= consumption;       // fuel used for this stop
    fuel += recharge;          // gravitational assist
    if (planet % 4 == 0)       // solar recharge every 4th planet
        fuel += solarBonus;

    if (fuel < 0) fuel = 0;    // guard against negative fuel

    // Print remaining fuel
    printf("Planet %d: Fuel Remaining = %d\n", planet, fuel);

    // Recursive call for next planet
    return calculateFuel(fuel, consumption, recharge, solarBonus, planet + 1, totalPlanets);
}

int main() {
    // Example test case
    int initialFuel = 100;
    int consumption = 20;
    int recharge = 5;
    int solarBonus = 15;
    int totalPlanets = 6;

    printf("Starting Mission: Fuel = %d, Consumption per planet = %d, Recharge = %d, Solar bonus every 4th planet = %d\n\n",
            initialFuel, consumption, recharge, solarBonus);

    int success = calculateFuel(initialFuel, consumption, recharge, solarBonus, 1, totalPlanets);

    if (success)
        printf("\nThe spacecraft successfully completed its journey!\n");
    else
        printf("\nThe spacecraft ran out of fuel before completing the journey.\n");

    return 0;
}
