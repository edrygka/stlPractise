//
//  main.cpp
//  lab_STL
//
//  Created by Eduard on 16.04.2018.
//  Copyright © 2018 Macbook. All rights reserved.
//

#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int getSize(list<char> l){
    return (int)l.size();
}

void showList(list<char> l, string s){
    cout << "List with " << s << " elements = '";
    copy(l.begin(), l.end(), ostream_iterator<char>(cout,","));
    cout << "'" << endl;
}


void reverseOfList(list<char> l){
    l.reverse();
    showList(l, "reverse");
}

int main(int argc, const char * argv[]) {
    
    // Define variable
    list<char> repiatList, nrList;
    vector<char>::iterator it1;
    list<char>::iterator it2;
    int sizeOfString, index = 0, summary = 0;
    
    // Get from stdin size of string will entered user
    cout << "Input size of string " << endl;
    cin >> sizeOfString;
    cin.get();
    
    // Get string from stdin
    cout << "Input string " << endl;
    char name[sizeOfString];
    cin.getline (name, sizeOfString+1);
    vector<char> newArr(sizeof(name));
    
    // Transfer string from char to vector
    for(int i = 0; i < newArr.size(); i++){
        newArr[i] = name[i];
    }
    
    // Sort vector
    sort(newArr.begin(), newArr.end());
    
    cout << "First vector = '";
    copy( newArr.begin(), newArr.end(), ostream_iterator<char>(cout,"/") );
    cout << "'" << endl;
    it1 = newArr.begin();
    for(it1 = newArr.begin(); it1 < newArr.end(); it1++){
        nrList.push_back(*(it1));
        if(index == 0){
            index++;
            continue;
        }
        if(*(it1-1) == *it1){
            it2 = find(repiatList.begin(), repiatList.end(), *(it1));
            if(*it2 == *(it1-1)) {
                nrList.remove(*(it1-1));
            }
            else {
                repiatList.push_back(*(it1));
            }
        }
    }
    showList(nrList, "nonrepeat");
    showList(repiatList, "repeat");
    cout << getSize(nrList) << endl;
    reverseOfList(nrList);
    cout << "\nHello, World!" << endl;
    return 0;
}


