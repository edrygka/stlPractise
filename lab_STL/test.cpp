//
//  test.cpp
//  lab_STL
//
//  Created by Eduard on 14.06.2018.
//  Copyright © 2018 Macbook. All rights reserved.
//

//#include <stdio.h>
#include <iostream>     // std::cin, std::cout

int main () {
    char name[256], title[256];
    
    std::cout << "Please, enter your name: ";
    std::cin.getline (name,256);
    
    std::cout << "Please, enter your favourite movie: ";
    std::cin.getline (title,256);
    
    std::cout << name << "'s favourite movie is " << title;
    
    return 0;
}

