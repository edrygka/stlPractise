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
int k = 0;

int main(int argc, const char * argv[]) {
    // insert code here...
    string newStr;
    list<char> repiatList, nrList;
    
    cin >> newStr;
    
    vector<char> newArr(newStr.length());
    vector<char>::iterator it1, it2;
    for(int i = 0; i < newArr.size(); i++){
        newArr[i] = newStr[i];
    }
    sort(newArr.begin(), newArr.end());
    copy( newArr.begin(), newArr.end(), ostream_iterator<char>(cout," / ") );
    cout << endl;
    int index = 0;
    it1 = newArr.begin();
    while(it1 < newArr.end()){
        index++;
        if(it1+1 == newArr.end()){
            // if the element is last - put into nrList
            nrList.push_back(*(it1+1));
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
    
    copy( nrList.begin(), nrList.end(), ostream_iterator<char>(cout," _ ") );
    cout << endl;
    copy( repiatList.begin(), repiatList.end(), ostream_iterator<char>(cout," ~ ") );
    
    cout << "\nHello, World!" << endl;
    return 0;
}


