#ifndef COFFEE_H
#define COFFEE_H

#include <string>

/**
 * @file Coffee.h
 * @brief Abstract base class for coffee objects
 * @author Tom
 * @date 12 June 2025
 */

/**
 * @class Coffee
 * @brief Abstract base class representing a coffee item
 */
class Coffee {
public:
    /**
     * @brief Default constructor for Coffee
     */
    Coffee();
    
    /**
     * @brief Virtual destructor for Coffee
     */
    virtual ~Coffee();
    
    /**
     * @brief Get the price of the coffee
     * @return double The price of the coffee
     */
    virtual double GetPrice() const = 0;
    
    /**
     * @brief Set the price of the coffee
     * @param price The new price to set
     * @return double The updated price
     */
    virtual double SetPrice(double price) = 0;
    
    /**
     * @brief Make/prepare the coffee
     * @return bool True if successful
     */
    virtual bool Brew (std::string coffeeType) const = 0;
};

#endif // COFFEE_H