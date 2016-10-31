/**
 * cupcakes.cpp
 *
 * Mackenzie Francisco
 * mackfran
 *
 * EECS 183: Project 1
 *
 * This is a shopping list for a vanilla cupcake recipe!
 */
 
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Pluralizes a word if needed.
 *
 * Requires: singular is the form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 1.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           cout << pluralize("bag", "bags", 1);
 *           // prints "bag"
 *
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 *           // prints "pounds"
 */
string pluralize(string singular, string plural, int number);

int main() {
    const int CUPCAKES_PER_BATCH = 12;
    
    const double CUPS_FLOUR_NEEDED = 1.5;
    const int CUPS_FLOUR_PER_BAG = 20;
    const double FLOUR_PRICE = 3.09;
    
    const int CUPS_GRAN_SUGAR_PER_BAG = 10;
    const double GRAN_SUGAR_PRICE = 2.98;
    
    const double CUPS_BUTTER_NEEDED = 1.5;
    const int CUPS_BUTTER_PER_POUND = 2;
    const double BUTTER_PRICE = 2.50;
    
    const double CUPS_SOUR_CREAM_NEEDED = 0.5;
    const double SOUR_CREAM_PRICE = 1.29;
    
    const int EGGS_NEEDED = 3.0;
    const int EGGS_PER_DOZEN = 12.0;
    const double EGG_PRICE = 2.68;
    
    const double CUPS_POW_SUGAR_NEEDED = 2.5;
    const double CUPS_POW_SUGAR_PER_BAG = 5.5;
    const double POW_SUGAR_PRICE = 1.18;
    
    const double TEASPOONS_VANILLA_NEEDED = 4.5;
    const int TEASPOONS_VANILLA_PER_BOTTLE = 12;
    const double VANILLA_PRICE = 4.12;
    
    double numPeople = 0.0;
    double numBatches = 0.0;
    
    double cupsFlour = 0.0;
    double numBagsOfFlour = 0.0;
    double flourPrice = 0.0;
    
    double cupsGranSugar = 0.0;
    double numBagsOfGranSugar = 0.0;
    double granSugarPrice = 0.0;
    
    double cupsButter = 0.0;
    double numPoundsOfButter = 0.0;
    double butterPrice = 0.0;
   
    double cupsSourCream = 0.0;
    double numContainersOfSourCream = 0.0;
    double sourCreamPrice = 0.0;
    
    double numEggs = 0.0;
    double dozensOfEggs = 0.0;
    double eggPrice = 0.0;
    
    double cupsPowSugar = 0.0;
    double numBagsOfPowSugar = 0.0;
    double powSugarPrice = 0.0;
    
    double teaspoonsVanilla = 0.0;
    double numBottlesVanilla = 0.0;
    double vanillaPrice = 0.0;
    
    double totalCost = 0.0;
    
    cout << "How many people do you need to serve? ";
    cin >> numPeople;
    cout << endl << endl;
    
    // calculate number of batches needed
    numBatches = ceil(numPeople / CUPCAKES_PER_BATCH);
    
    cout << "You need to make: " << numBatches << " " << pluralize("batch",
            "batches", numBatches) << " of cupcakes" << endl << endl;
    
    // calculate bags of flour needed and price
    cupsFlour = numBatches * CUPS_FLOUR_NEEDED;
    numBagsOfFlour = ceil(cupsFlour / CUPS_FLOUR_PER_BAG);
    flourPrice = numBagsOfFlour * FLOUR_PRICE;
    
    // calculate bags of granulated sugar needed and price
    cupsGranSugar = numBatches;
    numBagsOfGranSugar = ceil(cupsGranSugar / CUPS_GRAN_SUGAR_PER_BAG);
    granSugarPrice = numBagsOfGranSugar * GRAN_SUGAR_PRICE;
    
    // calculate pounds of butter needed and price
    cupsButter = numBatches * CUPS_BUTTER_NEEDED;
    numPoundsOfButter = ceil(cupsButter / CUPS_BUTTER_PER_POUND);
    butterPrice = numPoundsOfButter * BUTTER_PRICE;
    
    // calculate containers of sour cream needed and price
    cupsSourCream = numBatches * CUPS_SOUR_CREAM_NEEDED;
    numContainersOfSourCream = ceil(cupsSourCream);
    sourCreamPrice = numContainersOfSourCream * SOUR_CREAM_PRICE;
    
    // calculate dozens of eggs needed and price
    numEggs = numBatches * EGGS_NEEDED;
    dozensOfEggs = ceil(numEggs / EGGS_PER_DOZEN);
    eggPrice = dozensOfEggs * EGG_PRICE;
    
    // calculate bags of powdered sugar needed and price
    cupsPowSugar = numBatches * CUPS_POW_SUGAR_NEEDED;
    numBagsOfPowSugar = ceil(cupsPowSugar / CUPS_POW_SUGAR_PER_BAG);
    powSugarPrice = numBagsOfPowSugar * POW_SUGAR_PRICE;
    
    // calculate bottles of vanilla needed and price
    teaspoonsVanilla = numBatches * TEASPOONS_VANILLA_NEEDED;
    numBottlesVanilla = ceil(teaspoonsVanilla / TEASPOONS_VANILLA_PER_BOTTLE);
    vanillaPrice = numBottlesVanilla * VANILLA_PRICE;
    
    // calculate total expected cost of ingredients
    totalCost = flourPrice + granSugarPrice + butterPrice + sourCreamPrice +
                eggPrice + powSugarPrice + vanillaPrice;
    
    cout << "Shopping List for \"Best Ever\" Vanilla Cupcakes" << endl;
    cout << "----------------------------------------------" << endl;
    
    cout << "   " << numBagsOfFlour << " "
         << pluralize("bag", "bags", numBagsOfFlour) << " of flour" << endl;
    cout << "   " << numBagsOfGranSugar << " "
         << pluralize("bag", "bags", numBagsOfGranSugar)
         << " of granulated sugar" << endl;
    cout << "   " << numPoundsOfButter << " "
         << pluralize("pound", "pounds", numPoundsOfButter)
         << " of butter" << endl;
    cout << "   " << numContainersOfSourCream << " "
         << pluralize("container", "containers", numContainersOfSourCream)
         << " of sour cream" << endl;
    cout << "   " << dozensOfEggs << " dozen" << " eggs" << endl;
    cout << "   " << numBagsOfPowSugar << " "
         << pluralize("bag", "bags", numBagsOfPowSugar) << " of powdered sugar"
         << endl;
    cout << "   " << numBottlesVanilla << " "
         << pluralize("bottle", "bottles", numBottlesVanilla) << " of vanilla"
         << endl << endl;
    
    cout << "Total expected cost of ingredients: $" << totalCost << endl <<
            endl;
    cout << "Have a great party!";

    return 0;
}

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}


