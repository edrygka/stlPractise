//
//  main.cpp
//  lab_STL
//
//  Created by Eduard on 16.04.2018.
//  Copyright © 2018 Macbook. All rights reserved.
//

//#include <iostream>     // std::cin, std::cout
//
//int main () {
//    char name[256], title[256];
//
//    std::cout << "Please, enter your name: ";
//    std::cin.getline (name,256);
//
//    std::cout << "Please, enter your favourite movie: ";
//    std::cin.getline (title,256);
//
//    std::cout << name << "'s favourite movie is " << title;
//
//    return 0;
//}

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

//void showVector(

void reverseOfList(list<char> l){
    l.reverse();
    showList(l, "reverse");
}

int main(int argc, const char * argv[]) {
    
    // Define variable
    list<char> repiatList, nrList;
    vector<char>::iterator it1, it2;
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
    while(it1 < newArr.end()){
//        if((int)*it1 == 0) it1++;
        if(*it1 == *(newArr.end()-1)){
            // if the element is last - put into nrList
            nrList.push_back(*(it1));
            break;
        }
        if(*it1 == *(it1+1)){
            // if we have two same elements, let's calculate how many are there
            int count = 1;
            cout << "Start " << *it1 << endl;
            for(it2 = newArr.begin()+index; it2 < newArr.end(); it2++){
                // count contains how many equals elements
                if(*it2 == *(it2+1)) count++;
                else break;
            }
            summary += count;
            repiatList.push_back(*it1);
            // delete all the same elements from newArr
            //copy(newArr.begin()+index, newArr.begin()+index+count, ostream_iterator<char>(cout,"-"));
            //newArr.erase(newArr.begin()+index-1, newArr.begin()+index+count);
            it1 = newArr.begin()+index+summary;
            cout << "End " << *it1 << endl;
        } else {
            // if elements are not equal
            nrList.push_back(*it1);
            it1++;
        }
        index++;
    }
    showList(nrList, "nonrepeat");
    showList(repiatList, "repeat");
    //cout << getSize(nrList) << endl;
    //reverseOfList(nrList);
    cout << "\nHello, World!" << endl;
    return 0;
}


