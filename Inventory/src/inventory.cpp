
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
    // Check if the index is out of range
    if (index < 0 || index >= productNames.size())
    {
        throw std::out_of_range("Index is invalid!");
    }

    // Remove the product's attributes from the attributesMatrix
    attributesMatrix.removeAt(index);

    // Remove the product name from the productNames list
    productNames.removeAt(index);

    // Remove the product quantity from the quantities list
    quantities.removeAt(index);
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
    for (int i = 0; i < productNames.size(); i++)
    {
        for (int j = i + 1; j < productNames.size(); j++)
        {
            // Check if the product names and attributes are the same
            if (productNames.get(i) == productNames.get(j) &&
                attributesMatrix.getRow(i).toString() == attributesMatrix.getRow(j).toString())
            {
                // Merge the quantities
                quantities.set(i, quantities.get(i) + quantities.get(j));

                // Remove the duplicate product
                attributesMatrix.removeAt(j);
                productNames.removeAt(j);
                quantities.removeAt(j);

                // Adjust the index to account for the removed element
                j--;
            }
        }
    }
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
    int totalProducts = attributesMatrix.rows();
    int section1Size = (totalProducts * ratio) - static_cast<int>(totalProducts * ratio) > 0
                           ? static_cast<int>(totalProducts * ratio) + 1
                           : static_cast<int>(totalProducts * ratio);
    int section2Size = totalProducts - section1Size;

    // Add products to section1
    for (int i = 0; i < section1Size; i++)
    {
        section1.addProduct(attributesMatrix.getRow(i), productNames.get(i), quantities.get(i));
    }

    // Add products to section2
    for (int i = section1Size; i < totalProducts; i++)
    {
        section2.addProduct(attributesMatrix.getRow(i), productNames.get(i), quantities.get(i));
    }
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