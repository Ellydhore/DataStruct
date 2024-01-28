/*
    Author: Belleza, E.G.
    About Class:
    - Requires UTF-8 support to display properly.
    - Takes a vector of strings as the selections for the menu.
    - Draws a box around the menu selections.

    Note:
    - The outline of the box is hardcoded.
    - The width will be the length of the longest string from the input vector.
    - The height will be the number of selections (size of the vector).
    - See the constructor for the computation.
*/

#include <iostream>
#include <vector>
#include <string>

class DisplayMenu {
private:
    std::vector<std::string> selectionList;
    int width;
    int height;

    // Draws the top of the box
    void drawTop() {
        std::cout << u8"\u2554";
        for(int i = 0; i < this->width + 2; i++) {
            std::cout << u8"\u2550";
        }
        std::cout << u8"\u2557" << std::endl;
    }
    
    // Draws the bottom of the box
    void drawBottom() {
        std::cout << u8"\u255A";
        for(int i = 0; i < this->width + 2; i++) {
            std::cout << u8"\u2550";
        }
        std::cout << u8"\u255D" << std::endl;
    }
    
    // Draws the side edges of the box and prints the selections of the menu
    void drawSelections() {
        for(int i = 0; i < height; i++) {
            std::cout << u8"\u2551 " << this->selectionList[i];
            int addSpace = this->width - this->selectionList[i].length();
            for(int j = 0; j <= addSpace; j++) {
                std::cout << " ";
            }
            std::cout << u8"\u2551" << std::endl;
        }
    }

public:
    // Constructor
    DisplayMenu(const std::vector<std::string>& selections) : selectionList(selections) {
        // Calculate width: Check notes above for the reason
        this->width = 0;
        for(const auto& selection : selections) {
            if(selection.length() > (size_t)this->width) {
                this->width = selection.length();
            } 
        }

        // Calculate height
        this->height = selections.size();
    }

    void drawMenu() {
        drawTop();
        drawSelections();
        drawBottom();
    } 
};
