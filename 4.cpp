#include <iostream>
#include <memory>
#include <string>

class Inventory {
private:
    std::unique_ptr<std::string[]> items; 
    size_t size;                         
    size_t capacity;                      

public:
    Inventory() : items(nullptr), size(0), capacity(0) {}

    void addItem(const std::string& item) {
        if (size >= capacity) {
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            std::unique_ptr<std::string[]> new_items(new std::string[new_capacity]);
            
            for (size_t i = 0; i < size; ++i) {
                new_items[i] = std::move(items[i]);
            }
            
            items = std::move(new_items); 
            capacity = new_capacity;    
        }
        items[size++] = item; 
    }

    void displayInventory() const {
        std::cout << "Inventory (" << size << " items):\n";
        for (size_t i = 0; i < size; ++i) {
            std::cout << "  " << i + 1 << ". " << items[i] << "\n";
        }
    }
};

int main() {
    Inventory inv;
    inv.addItem("Steel Sword");
    inv.addItem("Healing Potion");
    inv.addItem("Dragon Shield");
    inv.addItem("Magic Amulet");

    inv.displayInventory();

    return 0;
}
