#include <windows.h>
#include <iostream>
#include <string>

int main()
{
    int choice;
    std::string programName;
    HWND hwnd;

    std::cout << "Choose an option:\n";
    std::cout << "(1) Hide Window\n";
    std::cout << "(2) Show Window\n";

    std::cin >> choice; 
    std::cin.ignore(); 

    switch (choice) {
    case 1: 
        std::cout << "Enter the Window Name to hide: ";
        std::getline(std::cin, programName); 
        hwnd = FindWindowA(NULL, programName.c_str());
        if (hwnd == NULL) { 
            std::cout << "Program not found." << std::endl;
            return 1; 
        }
        ShowWindow(hwnd, SW_HIDE);
        UpdateWindow(hwnd);
        std::cout << "Window '" << programName << "' was hidden." << std::endl;
        break;
    case 2: 
        std::cout << "Enter the Window Name to show: ";
        std::getline(std::cin, programName); 
        hwnd = FindWindowA(NULL, programName.c_str()); 
        if (hwnd == NULL) { 
            std::cout << "Program not found." << std::endl;
            return 1; 
        }
        ShowWindow(hwnd, SW_SHOW); 
        UpdateWindow(hwnd);
        std::cout << "Window '" << programName << "' is now visible." << std::endl; 
        break;
    default:
        std::cout << "Invalid option selected." << std::endl;
        return 1; 
    }
    return 0; 
}
