/**
 * @file Coffee.h
 * @brief Abstract base class for coffee objects
 * @author Tom
 * @date 12 June 2025
 */

/**
 * @class Coffee
 * @brief Abstract base class representing a coffee item
 * 
 * This class provides the interface for all coffee types in the cafe system.
 * It defines the basic operations that all coffee implementations must provide.
 */
class Coffee{
public:
    /**
     * @brief Default constructor for Coffee
     * 
     * Initializes a new Coffee object with default values.
     */
    Coffee() {}
    
    /**
     * @brief Virtual destructor for Coffee
     * 
     * Ensures proper cleanup of derived class objects when deleted
     * through a base class pointer.
     */
    virtual ~Coffee() {}
    
    /**
     * @brief Get the price of the coffee
     * 
     * Pure virtual function that must be implemented by derived classes
     * to return the price of the specific coffee type.
     * 
     * @return double The price of the coffee
     */
    virtual double GetPrice() const = 0;
    
    /**
     * @brief Set the price of the coffee
     * 
     * Pure virtual function that must be implemented by derived classes
     * to set the price of the specific coffee type.
     * 
     * @param price The new price to set for the coffee
     * @return double The updated price (for confirmation)
     */
    virtual double SetPrice(double price) const = 0;
    
    /**
     * @brief Make/prepare the coffee
     * 
     * Pure virtual function that must be implemented by derived classes
     * to handle the coffee preparation process.
     * 
     * @return bool True if coffee was successfully made, false otherwise
     */
    virtual bool MakeCoffee() const = 0;
    
private:
}; 
// End of Coffee.h