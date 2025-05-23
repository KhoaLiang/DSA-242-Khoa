
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
    // Return the number of rows in the attributesMatrix
    return attributesMatrix.rows();
}

List1D<InventoryAttribute> InventoryManager::getProductAttributes(int index) const
{
    // Check if the index is out of range
    if (index < 0 || index >= attributesMatrix.rows())
    {
        throw std::out_of_range("Index is invalid!");
    }

    // Return the attributes of the product at the given index
    return attributesMatrix.getRow(index);
}

string InventoryManager::getProductName(int index) const
{
    // Check if the index is out of range
    if (index < 0 || index >= productNames.size())
    {
        throw std::out_of_range("Index is invalid!");
    }

    // Return the name of the product at the given index
    return productNames.get(index);
}

int InventoryManager::getProductQuantity(int index) const
{
    // Check if the index is out of range
    if (index < 0 || index >= quantities.size())
    {
        throw std::out_of_range("Index is invalid!");
    }

    // Return the quantity of the product at the given index
    return quantities.get(index);
}

List2D<InventoryAttribute> InventoryManager::getAttributesMatrix() const
{
    // Return the entire attributes matrix
    return attributesMatrix;
}

List1D<string> InventoryManager::getProductNames() const
{
    // Return the list of product names
    return productNames;
}

List1D<int> InventoryManager::getQuantities() const
{
    // Return the list of product quantities
    return quantities;
}

void InventoryManager::updateQuantity(int index, int newQuantity)
{
    // TODO
    // Check if the index is out of range
    if (index < 0 || index >= quantities.size())
    {
        throw std::out_of_range("Index is invalid!");
    }

    // Update the quantity of the product at the given index
    quantities.set(index, newQuantity);
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
    List1D<string> resultNames;
    List1D<InventoryAttribute> resultAttribute;
    List1D<int> resultQuantity;

    int sizeOfListProduct = attributesMatrix.rows();
    // Iterate through all products
    for (int i = 0; i < sizeOfListProduct; i++)
    {
        // Get the attributes of the current product
        List1D<InventoryAttribute> attributes = attributesMatrix.getRow(i);

        // Find the attribute with the specified name
        // bool attributeFound = false;
        // double attributeValue = 0.0;
        for (int j = 0; j < attributes.size(); j++)
        {
            if (attributes.get(j).name == attributeName)
            {
                // attributeValue = attributes.get(j).value;
                // attributeFound = true;
                // break;
                resultNames.add(productNames.get(i));
                resultAttribute.add(attributes.get(j));
                resultQuantity.add(quantities.get(i));
            }
        }

        // // Skip if the attribute is not found
        // if (!attributeFound)
        // {
        //     continue;
        // }

        // // Check if the attribute value is within the range and the quantity is sufficient
        // if (attributeValue >= minValue && attributeValue <= maxValue && quantities.get(i) >= minQuantity)
        // {
        //     result.add(productNames.get(i)); // Add the product name to the result
        // }
    }

    int sizeOfResults = resultNames.size();
    for (int current = 1; current < sizeOfResults; current++)
    {
        InventoryAttribute keyAtt = resultAttribute.get(current);
        string keyName = resultNames.get(current);
        int keyQuantity = resultQuantity.get(current);

        int walker = current - 1;

        while (walker >= 0)
        {
            bool shouldSwap = false;

            // Xét giá trị thuộc tính trước
            if (ascending)
            {
                if (resultAttribute.get(walker).value > keyAtt.value)
                    shouldSwap = true;
                else if (resultAttribute.get(walker).value == keyAtt.value)
                {
                    // Nếu giá trị thuộc tính bằng nhau, xét số lượng sản phẩm
                    if (resultQuantity.get(walker) > keyQuantity)
                        shouldSwap = true;
                }
            }
            else // Trường hợp sắp xếp giảm dần
            {
                if (resultAttribute.get(walker).value < keyAtt.value)
                    shouldSwap = true;
                else if (resultAttribute.get(walker).value == keyAtt.value)
                {
                    // Nếu giá trị thuộc tính bằng nhau, xét số lượng sản phẩm
                    if (resultQuantity.get(walker) < keyQuantity)
                        shouldSwap = true;
                }
            }

            if (!shouldSwap)
                break;

            // Hoán đổi vị trí
            resultAttribute.set(walker + 1, resultAttribute.get(walker));
            resultNames.set(walker + 1, resultNames.get(walker));
            resultQuantity.set(walker + 1, resultQuantity.get(walker));

            walker--;
        }

        // Đặt phần tử tại vị trí chính xác
        resultAttribute.set(walker + 1, keyAtt);
        resultNames.set(walker + 1, keyName);
        resultQuantity.set(walker + 1, keyQuantity);
    }

    return resultNames;
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
    // Create new lists to hold the merged data
    // List2D<InventoryAttribute> mergedAttributesMatrix;
    // List1D<string> mergedProductNames;
    // List1D<int> mergedQuantities;

    InventoryManager Merge;

    Merge = inv1;
    

    // // Add all products from inv1 to the merged inventory
    // for (int i = 0; i < inv1.size(); i++)
    // {
    //     mergedAttributesMatrix.setRow(mergedAttributesMatrix.rows(), inv1.getProductAttributes(i));
    //     mergedProductNames.add(inv1.getProductName(i));
    //     mergedQuantities.add(inv1.getProductQuantity(i));
    // }

    // Add all products from inv2 to the merged inventory
    for (int i = 0; i < inv2.size(); i++)
    {
        // mergedAttributesMatrix.setRow(mergedAttributesMatrix.rows(), inv2.getProductAttributes(i));
        // mergedProductNames.add(inv2.getProductName(i));
        // mergedQuantities.add(inv2.getProductQuantity(i));
        Merge.addProduct(inv2.getProductAttributes(i), inv2.getProductName(i), inv2.getProductQuantity(i));
    }

    // // Create the merged inventory
    // InventoryManager mergedInventory(mergedAttributesMatrix, mergedProductNames, mergedQuantities);

    // // Remove duplicates from the merged inventory
    // mergedInventory.removeDuplicates();

    // return mergedInventory;
    return Merge;
}

void InventoryManager::split(InventoryManager &section1,
                             InventoryManager &section2,
                             double ratio) const
{
    int totalProducts = attributesMatrix.rows();
    if (totalProducts == 0)
    {
        return;
    }
    int L1 = section1.size();
    int L2 = section2.size();
    for (int i = 0; i < L1; i++)
    {
        section1.removeProduct(0);
    }
    for (int i = 0; i < L2; i++)
    {
        section2.removeProduct(0);
    }
    
    // int section1Size = (totalProducts * ratio) - static_cast<int>(totalProducts * ratio) > 0
    //                        ? static_cast<int>(totalProducts * ratio) + 1
    //                        : static_cast<int>(totalProducts * ratio);
    int section1Size = totalProducts * ratio + 0.98;
    int section2Size = totalProducts - section1Size;

    // Add products to section1
    for (int i = 0; i < section1Size; i++)
    {
        section1.addProduct(getProductAttributes(i), getProductName(i), getProductQuantity(i));
    }

    // Add products to section2
    for (int i = 0; i < section2Size; i++)
    {
        section2.addProduct(getProductAttributes(i+section1Size), getProductName(i+section1Size), getProductQuantity(i+section1Size));
    }
    
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