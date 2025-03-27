
#include "app/inventory.h"
// // -------------------- InventoryManager Method Definitions --------------------
InventoryManager::InventoryManager()
{
    // TODO
   
}

InventoryManager::InventoryManager(const List2D<InventoryAttribute> &matrix,
                                   const List1D<string> &names,
                                   const List1D<int> &quantities)
{
    // TODO
  
}

InventoryManager::InventoryManager(const InventoryManager &other)
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
    // TODO
        
}

void InventoryManager::removeProduct(int index)
{
    // TODO
   
}


//! tăng dần của cái gì
List1D<string> InventoryManager::query(string attributeName, const double &minValue,
                                       const double &maxValue, int minQuantity, bool ascending) const
{
    // TODO
   
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
    // TODO
   
}