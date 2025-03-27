
#include "app/inventory.h"
// // -------------------- InventoryManager Method Definitions --------------------
InventoryManager::InventoryManager():attributesMatrix(), productNames(), quantities()
{
    // TODO
    
}

InventoryManager::InventoryManager(const List2D<InventoryAttribute> &matrix,
                                   const List1D<string> &names,
                                   const List1D<int> &quantities)
                                   : attributesMatrix(matrix), productNames(names), quantities(quantities)
{
    // TODO
}

InventoryManager::InventoryManager(const InventoryManager &other): attributesMatrix(other.attributesMatrix), productNames(other.productNames), quantities(other.quantities)
{
    // TODO
}

int InventoryManager::size() const
{
    // TODO
  
}

List1D<InventoryAttribute> InventoryManager::getProductAttributes(int index) const
{
    // TODO
  
}

string InventoryManager::getProductName(int index) const
{
    // TODO
    
}

int InventoryManager::getProductQuantity(int index) const
{
    // TODO
 
}

void InventoryManager::updateQuantity(int index, int newQuantity)
{
    // TODO
  
}

void InventoryManager::addProduct(const List1D<InventoryAttribute> &attributes, const string &name, int quantity)
{
    // Add the new product's attributes to the attributesMatrix
    attributesMatrix.setRow(attributesMatrix.rows(), attributes);

    // Add the product name to the productNames list
    productNames.add(name);

    // Add the product quantity to the quantities list
    quantities.add(quantity);
}

void InventoryManager::removeProduct(int index)
{
    // TODO
   
}


//! tăng dần của cái gì
List1D<string> InventoryManager::query(string attributeName, const double &minValue,
                                       const double &maxValue, int minQuantity, bool ascending) const
{
    List1D<string> result;

    // Iterate through all products
    for (int i = 0; i < attributesMatrix.rows(); i++)
    {
        // Get the attributes of the current product
        List1D<InventoryAttribute> attributes = attributesMatrix.getRow(i);

        // Find the attribute with the specified name
        bool attributeFound = false;
        double attributeValue = 0.0;
        for (int j = 0; j < attributes.size(); j++)
        {
            if (attributes.get(j).name == attributeName)
            {
                attributeValue = attributes.get(j).value;
                attributeFound = true;
                break;
            }
        }

        // Skip if the attribute is not found
        if (!attributeFound)
        {
            continue;
        }

        // Check if the attribute value is within the range and the quantity is sufficient
        if (attributeValue >= minValue && attributeValue <= maxValue && quantities.get(i) >= minQuantity)
        {
            result.add(productNames.get(i)); // Add the product name to the result
        }
    }

    // Sort the result if ascending is true
    if (ascending)
    {
        // Simple bubble sort for demonstration purposes
        for (int i = 0; i < result.size() - 1; i++)
        {
            for (int j = 0; j < result.size() - i - 1; j++)
            {
                if (result.get(j) > result.get(j + 1))
                {
                    // Swap the elements
                    string temp = result.get(j);
                    result.set(j, result.get(j + 1));
                    result.set(j + 1, temp);
                }
            }
        }
    }

    return result;
}


void InventoryManager::removeDuplicates()
{
    // TODO
   
}
//! Hàm này có gọi removeDuplicates hay không
InventoryManager InventoryManager::merge(const InventoryManager &inv1,
                                         const InventoryManager &inv2)
{
    // TODO

    

    
}

void InventoryManager::split(InventoryManager &section1,
                             InventoryManager &section2,
                             double ratio) const
{
    // TODO
   
}

List2D<InventoryAttribute> InventoryManager::getAttributesMatrix() const
{
    // TODO
    
}

List1D<string> InventoryManager::getProductNames() const
{
    // TODO
   
}

List1D<int> InventoryManager::getQuantities() const
{
    // TODO
   
}

string InventoryManager::toString() const
{
    stringstream ss;
    ss << "InventoryManager[\n";
    ss << "  AttributesMatrix: " << attributesMatrix.toString() << ",\n";
    ss << "  ProductNames: " << productNames.toString() << ",\n";
    ss << "  Quantities: " << quantities.toString() << "\n";
    ss << "]";
    return ss.str();
}