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

void reverseOfList(list<char> l){
    l.reverse();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Input size of string " << endl;
    int sizeOfString;
    cin >> sizeOfString;
    cin.get();
    cout << "Input string " << endl;
    //string newStr;
    list<char> repiatList, nrList;
    char name[sizeOfString];
    cin.getline (name, sizeOfString);
    vector<char> newArr(sizeof(name));
    vector<char>::iterator it1, it2;
    for(int i = 0; i < newArr.size(); i++){
        newArr[i] = name[i];
    }
    sort(newArr.begin(), newArr.end());
    cout << "First vector = '";
    copy( newArr.begin(), newArr.end(), ostream_iterator<char>(cout,"/") );
    cout << "'" << endl;
    int index = 0;
    it1 = newArr.begin();
    while(it1 < newArr.end()){
        index++;
        if(*it1 == *(newArr.end()-1)){
            // if the element is last - put into nrList
            nrList.push_back(*(it1));
            break;
        }
        if(*it1 == *(it1+1)){
            // if we have two same elements, let's calculate how many are there
            int count = 0;
            for(it2 = newArr.begin()+index; it2 < newArr.end(); it2++){
                // count contains how many equals elements
                if(*it2 == *(it2+1)) count++;
                else break;
            }
            repiatList.push_back(*it1);
            // delete all the same elements from newArr
            newArr.erase(newArr.begin()+index-1, newArr.begin()+index+count);
            it1++;
        } else {
            // if elements are not equal
            nrList.push_back(*it1);
            it1++;
        }
    }
    cout << "List with nonrepeat elements = '";
    copy( nrList.begin(), nrList.end(), ostream_iterator<char>(cout,"_") );
    cout << "'" << endl << "List with repeat elements = '";
    copy( repiatList.begin(), repiatList.end(), ostream_iterator<char>(cout,"-") );
    cout << "'" << endl;
    cout << getSize(repiatList) << endl;
    reverseOfList(nrList);
    for (list<char>::iterator it=nrList.begin(); it!=nrList.end(); ++it)
        cout << *it;
    cout << "\nHello, World!" << endl;
    return 0;
}


