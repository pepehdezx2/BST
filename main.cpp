//
//  main.cpp
//  abb
//
//  Created by Pepe Hdez hdez on 10/2/18.
//  Copyright © 2018 Pepe Hdez hdez. All rights reserved.
//

#include <iostream>
#include"BST.h"
using namespace std;
//int main(){
//    int level, height;
//    BST abb;
//    abb.add(8);
//    abb.add(6);
//    abb.add(3);
//    abb.add(2);
//    abb.add(4);
//    abb.add(7);
//    abb.add(12);
//    abb.add(10);
//    abb.add(11);
//    abb.add(14);
//    abb.add(13);
//    abb.add(16);
//    abb.ancestors(16);

//    abb.add(16);
//    abb.add(8);
//    abb.add(4);
//    abb.add(2);
//    abb.add(1);
//    abb.add(3);
//    abb.add(6);
//    abb.add(5);
//    abb.add(7);
//    abb.add(12);
//    abb.add(10);
//    abb.add(9);
//    abb.add(11);
//    abb.add(14);
//    abb.add(13);
//    abb.add(15);
//    abb.add(24);
//    abb.add(20);
//    abb.add(18);
//    abb.add(17);
//    abb.add(19);
//    abb.add(22);
//    abb.add(21);
//    abb.add(23);
//    abb.add(28);
//    abb.add(26);
//    abb.add(25);
//    abb.add(27);
//    abb.add(30);
//    abb.add(29);
//    abb.add(31);
//    abb.ancestors(7);
//    level=abb.whatLevelamI(2);
//    cout << level << endl;
//    height=abb.height();
//    cout << height << endl;
//    abb.print(5);
//    abb.print(2);
//    cout << abb.howmanynodes(1) << endl;
//    cout << abb.lowest() << endl;
//    return 0;
//}
int main(){
    BST abb;
    abb.add(16);
    abb.add(8);
    abb.add(4);
    abb.add(2);
    abb.add(1);
    abb.add(3);
    abb.add(6);
    abb.add(5);
    abb.add(7);
    abb.add(12);
    abb.add(10);
    abb.add(9);
    abb.add(11);
    abb.add(14);
    abb.add(13);
    abb.add(15);
    abb.add(24);
    abb.add(20);
    abb.add(18);
    abb.add(17);
    abb.add(19);
    abb.add(22);
    abb.add(21);
    abb.add(23);
    abb.add(28);
    abb.add(26);
    abb.add(25);
    abb.add(27);
    abb.add(30);
    abb.add(29);
    abb.add(31);
    cout << abb.lowest() << endl;
    cout << abb.descendants(12) << endl;
    return 0;
}
