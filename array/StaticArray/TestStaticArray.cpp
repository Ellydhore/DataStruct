/*
    This is a tester for the StaticArray.cpp
*/
#include "StaticArray.cpp"
#include "../../misc/DisplayMenu.cpp"

void menuStaticArray() {
    std::vector<std::string> menuSelection;
    menuSelection.push_back("    Menu"); 
    menuSelection.push_back("[d] Display"); 
    menuSelection.push_back("[i] Insert"); 
    menuSelection.push_back("[r] Remove"); 
    menuSelection.push_back("[g] Get Element"); 
    menuSelection.push_back("[s] Get Size"); 
    menuSelection.push_back("[x] Exit Program"); 
    DisplayMenu dMenu(menuSelection);
    dMenu.drawMenu();
}

int main() {
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;
    StaticArray* array = new StaticArray(size);
    
    char choice;
    unsigned int position;
    int value;

    do {
        std::cout << std::endl;
        menuStaticArray();
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch(choice) {
            case 'd':
                array->display();
                break;
            case 'i':
                std::cout << "Enter position to insert: ";
                std::cin >> position;
                std::cout << "Enter value: ";
                std::cin >> value;
                array->insert(position, value);
                break;
            case 'r':
                std::cout << "Enter position to remove: ";
                std::cin >> position;
                std::cout << array->remove(position) << " was removed!" << std::endl;
                break;
            case 'g':
                std::cout << "Enter position to get element: ";
                std::cin >> position;
                std::cout << "The element on position " << position << " is " << array->get(position) << std::endl;
                break;           
             case 's':
                std::cout << "Size: " << array->getSize() << std::endl;    
                break;
            case 'x':
                std::cout << "YOU EXIT TEST STATIC ARRAY PROGRAM" << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    } while(choice != 'x');
    delete array;
}
