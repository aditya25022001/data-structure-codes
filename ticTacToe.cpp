                // header files iostream for the main function and random for selectiong random numbers/


#include <iostream>
#include<random>



using namespace std;


                //global variables


char main_matrix[3][3], flag='y', flag1='y';
int i, j, m, n, p, k, l, z, t, b, rx, ro, cx, co, dx, dc, v1, v2, v3, v4, v5, v6, q, w;



                //display of indices i.e the local address for the user to enter at the time of gameplay



int displayInit(){
    cout <<"*******************Welcome to Tic Tac Toe by Aditya********************"<<endl<<"***********For indices, note down, since displayed once only***********";
    cout << endl;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++)
            cout << "(" << i << "," << j << ")" << " ";
        cout << endl;
    }
    cout << "In this game the computer will be an 'o' and you will be 'x' " <<endl <<  "Best of LUCK!!! ";
    return 0;
}


                //filled matrix display or the game progress so far and also for user that he may not fill same place again and again


int display()
{
    cout << endl;
    for (i = 0; i < 3; i++){
        for (p = 0; p < 3; p++){
            if (main_matrix[i][p] != 'x' && main_matrix[i][p] != 'o'){
                cout << "_" << " ";
            }
            else{
                cout << main_matrix[i][p] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}


                   //checking rows 


int checkRows(){
    rx=ro = 0;
    for(i = 0; i < 3; i++){
        for (p = 0; p < 3; p++){
            if (main_matrix[p][i] == 'x')
                rx++;
            else{
                if (main_matrix[p][i]=='o'){
                    ro++;
                }
            }
        }
        if (ro != 3 && rx != 3 && b == 8){
            cout << endl << "IT'S A TIE";
            return 2;
        }
        if (rx == 3){
            cout << endl << "YOU WON!!!!" << endl << "CONGRATULATIONS";
            return 1;
            break;
        }
        else{
            if (ro == 3){
                cout << endl << "COMPUTER WON!!!!" << endl << "BETTER LUCK NEXT TIME!";
                return 1;
                break;
            }
            else{
                ro=rx = 0;
            }
        }
    }
    return 0;
}



                   //checking columns



int checkColumns(){
    cx=co = 0;
    for (i = 0; i < 3; i++){
        for (p = 0; p < 3; p++){
            if (main_matrix[i][p] == 'x')
                cx++;
            else{
                if (main_matrix[i][p] == 'o'){
                    co++;
                }
            }
        }
        if (co != 3 && cx != 3 && b == 8){
            cout << endl << "IT'S A TIE";
            return 2;
        }
        if (cx == 3){
            cout << endl << "YOU WON!!!!" << endl << "CONGRATULATIONS";
            return 1;
            break;
        }
        else{
            if (co == 3){
                cout << endl << "COMPUTER WON!!!!" << endl << "BETTER LUCK NEXT TIME!";
                return 1;
                break;
            }
            else{
                co = cx = 0;
            }
        }
    }
    return 0;
}



                   //checking diagonals



int checkDiagonals(){
    dx=dc = 0;
    for (i = 0; i < 3; i++){
        for (p = 0; p < 3; p++){
            if (i == p && main_matrix[i][p] == 'x'){
                dx++;
            }
            else{
                if (i == p && main_matrix[i][p] == 'o')
                    dc++;
            }
        }
    }
    if (dc != 3 && dx != 3 && b == 8){
        cout << endl << "IT'S A TIE";
        return 2;
    }
    if (dx == 3){
        cout << endl << "YOU WON!!!!" << endl << "CONGRATULATIONS";
        return 1;
    }
    else{
        if (dc == 3){
            cout << endl << "COMPUTER WON!!!!" << endl << "BETTER LUCK NEXT TIME";
            return 1;
        }
        else{
            dx = dc = 0;
            for (i = 0; i < 3; i++){
                for (p = 0; p < 3; p++){
                    if (i + p == 2 && main_matrix[i][p] == 'x'){
                        dx++;
                    }
                    else{
                        if (i + p == 2 && main_matrix[i][p] == 'o')
                            dc++;
                    }
                }
            }
        }
        if (dx == 3){
            cout << endl << "YOU WON!!!!" << endl << "CONGRATULATIONS";
            return 1;
        }
        if (dc == 3){
            cout << endl << "COMPUTER WON!!!" << endl << "BETTER LUCK NEXT TIME";
            return 1;
        }
        if (dc != 3 && dx != 3 && b == 8){
            cout << endl << " IT'S A TIE ";
            return 2;
        }
    }
    return 0;
}



                   //computer chance might be very long to read and may be somewhat childish...



int playComputer(int f){
    if (f<3){
        while (flag1 == 'y'){
            t = rand() % 3;
            z = rand() % 3;
            if (main_matrix[t][z] == 'o' || main_matrix[t][z] == 'x'){
            }
            else{
                main_matrix[t][z] = 'o';
                flag1 = 'n';
            }
        }
        flag1 = 'y';
    }
                                //for just intelligence of the computer     
    else{
    
        // case one.... subscript 00


        if (q == 0 && w == 0){
            if (main_matrix[q][w] == 'x' && main_matrix[q][w + 1] == 'x' && main_matrix[q][w + 2] != 'x' && main_matrix[q][w + 2] != 'o'){    //1
                main_matrix[q][w + 2] = 'o';
            }
            else{
                if (main_matrix[q][w] == 'x' && main_matrix[q + 1][w] == 'x' && main_matrix[q + 2][w] != 'x' && main_matrix[q + 2][w] != 'o'){   //2
                    main_matrix[q + 2][w] = 'o';
                }
                else{
                    if (main_matrix[q][w] == 'x' && main_matrix[q + 1][w + 1] == 'x' && main_matrix[q + 2][w + 2] != 'x' && main_matrix[q + 2][w + 2] != 'o'){   //3
                        main_matrix[q + 2][w + 2] = 'o';
                    }
                    else{
                        if (main_matrix[q][w] == 'x' && main_matrix[q][w + 2] == 'x' && main_matrix[q ][w + 1] != 'x' && main_matrix[q][w + 1] != 'o'){   //4
                            main_matrix[q][w + 1] = 'o';
                        }
                        else{
                            if (main_matrix[q][w] == 'x' && main_matrix[q + 1][w] != 'x' && main_matrix[q + 2][w] == 'x' && main_matrix[q + 1][w] != 'o'){   //5
                                main_matrix[q + 1][w] = 'o';
                            }
                            else{
                                if (main_matrix[q][w] == 'x' && main_matrix[q + 2][w +2] == 'x' && main_matrix[q + 1][w + 1] != 'x' && main_matrix[q + 1][w + 1] != 'o'){   //6
                                    main_matrix[q + 1][w + 1] = 'o';
                                }
                                else{
                                    while (flag1 == 'y'){
                                        t = rand() % 3;
                                        z = rand() % 3;
                                        if (main_matrix[t][z] == 'o' || main_matrix[t][z] == 'x')
                                        {
                                        }
                                        else{
                                            main_matrix[t][z] = 'o';
                                            flag1 = 'n';
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


                                //case two....  subscript 11


        if (q == 1 && w == 1)
        {
            if (main_matrix[q][w] == 'x' && main_matrix[q - 1][w - 1] == 'x' && main_matrix[q + 1][w + 1] != 'x' && main_matrix[q + 1][w + 1] != 'o')  //1
            {
                main_matrix[q + 1][w + 1] = 'o';
            }
            else
            {
                if (main_matrix[q][w] == 'x' && main_matrix[q + 1][w - 1] == 'x' && main_matrix[q - 1][w + 1] != 'x' && main_matrix[q - 1][w + 1] != 'o')   //2
                {
                    main_matrix[q - 1][w + 1] = 'o';
                }
                else
                {
                    if (main_matrix[q][w] == 'x' && main_matrix[q - 1][w + 1] == 'x' && main_matrix[q + 1][w - 1] != 'x' && main_matrix[q + 1][w - 1] != 'o')   //3
                    {
                        main_matrix[q + 1][w - 1] = 'o';
                    }
                    else
                    {
                        if (main_matrix[q][w] == 'x' && main_matrix[q + 1][w + 1] == 'x' && main_matrix[q - 1][w - 1] != 'x' && main_matrix[q - 1][w - 1] != 'o')  ///4
                        {
                            main_matrix[q - 1][w - 1] = 'o';
                        }
                        else
                        {
                            if (main_matrix[q][w] == 'x' && main_matrix[q - 1][w] == 'x' && main_matrix[q + 1][w] != 'x' && main_matrix[q + 1][w] != 'o')     ///5
                            {
                                main_matrix[q + 1][w] = 'o';
                            }
                            else
                            {
                                if (main_matrix[q][w] == 'x' && main_matrix[q+1][w] == 'x' && main_matrix[q-1][w] != 'x' && main_matrix[q-1][w] != 'o')    //6
                                {
                                    main_matrix[q-1][w] = 'o';
                                }
                                else
                                {
                                    if (main_matrix[q][w] == 'x' && main_matrix[q][w-1] == 'x' && main_matrix[q][w+1] != 'x' && main_matrix[q][w+1] != 'o')   //7
                                    {
                                        main_matrix[q][w+1] = 'o';
                                    }
                                    else
                                    {
                                        if (main_matrix[q][w] == 'x' && main_matrix[q][w+1] == 'x' && main_matrix[q][w-1] != 'x' && main_matrix[q][w-1] != 'o')   //8
                                        {
                                            main_matrix[q][w-1] = 'o';
                                        }
                                        else
                                        {
                                            while (flag1 == 'y')
                                            {
                                                t = rand() % 3;
                                                z = rand() % 3;
                                                if (main_matrix[t][z] == 'o' || main_matrix[t][z] == 'x')
                                                {
                                                }
                                                else
                                                {
                                                    main_matrix[t][z] = 'o';
                                                    flag1 = 'n';
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


                                // case three subscripts  10
        
        
        if (q == 1 && w == 0)
        {
            if (main_matrix[q][w] == 'x' && main_matrix[q - 1][w] == 'x' && main_matrix[q + 1][w] != 'x' && main_matrix[q + 1][w] != 'o')  //1
            {
                main_matrix[q + 1][w] = 'o';
            }
            else
            {
                if (main_matrix[q][w] == 'x' && main_matrix[q + 1][w] == 'x' && main_matrix[q - 1][w] != 'x' && main_matrix[q - 1][w] != 'o')   //2
                {
                    main_matrix[q - 1][w] = 'o';
                }
                else
                {
                    if (main_matrix[q][w] == 'x' && main_matrix[q][w + 1] == 'x' && main_matrix[q][w + 2] != 'x' && main_matrix[q][w +2] != 'o')   //3
                    {
                        main_matrix[q][w +2] = 'o';
                    }
                    else
                    {
                        if (main_matrix[q][w] == 'x' && main_matrix[q][w + 2] == 'x' && main_matrix[q][w + 1] != 'x' && main_matrix[q][w + 1] != 'o')  ///4
                        {
                            main_matrix[q][w + 1] = 'o';
                        }
                        else
                        {
                            while (flag1 == 'y')
                            {
                                t = rand() % 3;
                                z = rand() % 3;
                                if (main_matrix[t][z] == 'o' || main_matrix[t][z] == 'x')
                                {
                                }
                                else
                                {
                                    main_matrix[t][z] = 'o';
                                    flag1 = 'n';
                                }
                            }
                        }
                    }
                }
            }
        }


                                    //case four subscript 20
        
        
        if (q == 2 && w == 0)
        {
            if (main_matrix[q][w] == 'x' && main_matrix[q][w + 1] == 'x' && main_matrix[q][w + 2] != 'x' && main_matrix[q][w + 2] != 'o')    //1
            {
                main_matrix[q][w + 2] = 'o';
            }
            else
            {
                if (main_matrix[q][w] == 'x' && main_matrix[q - 1][w] == 'x' && main_matrix[q - 2][w] != 'x' && main_matrix[q - 2][w] != 'o')   //2
                {
                    main_matrix[q - 2][w] = 'o';
                }
                else
                {
                    if (main_matrix[q][w] == 'x' && main_matrix[q - 1][w + 1] == 'x' && main_matrix[q - 2][w + 2] != 'x' && main_matrix[q - 2][w + 2] != 'o')   //3
                    {
                        main_matrix[q - 2][w + 2] = 'o';
                    }
                    else
                    {
                        if (main_matrix[q][w] == 'x' && main_matrix[q][w + 2] == 'x' && main_matrix[q][w + 1] != 'x' && main_matrix[q][w + 1] != 'o')   //4
                        {
                            main_matrix[q][w + 1] = 'o';
                        }
                        else
                        {
                            if (main_matrix[q][w] == 'x' && main_matrix[q - 1][w] != 'x' && main_matrix[q - 2][w] == 'x' && main_matrix[q - 1][w] != 'o')   //5
                            {
                                main_matrix[q - 1][w] = 'o';
                            }
                            else
                            {
                                if (main_matrix[q][w] == 'x' && main_matrix[q - 2][w + 2] == 'x' && main_matrix[q - 1][w + 1] != 'x' && main_matrix[q - 1][w + 1] != 'o')   //6
                                {
                                    main_matrix[q - 1][w + 1] = 'o';
                                }
                                else
                                {
                                    while (flag1 == 'y')
                                    {
                                        t = rand() % 3;
                                        z = rand() % 3;
                                        if (main_matrix[t][z] == 'o' || main_matrix[t][z] == 'x')
                                        {
                                        }
                                        else
                                        {
                                            main_matrix[t][z] = 'o';
                                            flag1 = 'n';
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


                                                    //case five  subscript 01


        if (q == 0 && w == 1)
        {
            if (main_matrix[q][w] == 'x' && main_matrix[q][w-1] == 'x' && main_matrix[q][w+1] != 'x' && main_matrix[q][w+1] != 'o')  //1
            {
                main_matrix[q][w+1] = 'o';
            }
            else
            {
                if (main_matrix[q][w] == 'x' && main_matrix[q + 1][w] == 'x' && main_matrix[q +2][w] != 'x' && main_matrix[q +2][w] != 'o')   //2
                {
                    main_matrix[q +2][w] = 'o';
                }
                else
                {
                    if (main_matrix[q][w] == 'x' && main_matrix[q][w + 1] == 'x' && main_matrix[q][w -1] != 'x' && main_matrix[q][w -1] != 'o')   //3
                    {
                        main_matrix[q][w -1] = 'o';
                    }
                    else
                    {
                        if (main_matrix[q][w] == 'x' && main_matrix[q+2][w] == 'x' && main_matrix[q+1][w] != 'x' && main_matrix[q+1][w] != 'o')  ///4
                        {
                            main_matrix[q+1][w] = 'o';
                        }
                        else
                        {
                            while (flag1 == 'y')
                            {
                                t = rand() % 3;
                                z = rand() % 3;
                                if (main_matrix[t][z] == 'o' || main_matrix[t][z] == 'x')
                                {
                                }
                                else
                                {
                                    main_matrix[t][z] = 'o';
                                    flag1 = 'n';
                                }
                            }
                        }
                    }
                }
            }
        }


                                                                    //case six subscript 22


        if (q == 2 && w == 2)
        {
            if (main_matrix[q][w] == 'x' && main_matrix[q][w - 1] == 'x' && main_matrix[q][w - 2] != 'x' && main_matrix[q][w - 2] != 'o')    //1
            {
                main_matrix[q][w - 2] = 'o';
            }
            else
            {
                if (main_matrix[q][w] == 'x' && main_matrix[q - 1][w] == 'x' && main_matrix[q - 2][w] != 'x' && main_matrix[q - 2][w] != 'o')   //2
                {
                    main_matrix[q - 2][w] = 'o';
                }
                else
                {
                    if (main_matrix[q][w] == 'x' && main_matrix[q - 1][w - 1] == 'x' && main_matrix[q - 2][w - 2] != 'x' && main_matrix[q - 2][w - 2] != 'o')   //3
                    {
                        main_matrix[q - 2][w - 2] = 'o';
                    }
                    else
                    {
                        if (main_matrix[q][w] == 'x' && main_matrix[q][w - 2] == 'x' && main_matrix[q][w - 1] != 'x' && main_matrix[q][w - 1] != 'o')   //4
                        {
                            main_matrix[q][w - 1] = 'o';
                        }
                        else
                        {
                            if (main_matrix[q][w] == 'x' && main_matrix[q - 1][w] != 'x' && main_matrix[q - 2][w] == 'x' && main_matrix[q - 1][w] != 'o')   //5
                            {
                                main_matrix[q - 1][w] = 'o';
                            }
                            else
                            {
                                if (main_matrix[q][w] == 'x' && main_matrix[q - 2][w - 2] == 'x' && main_matrix[q - 1][w - 1] != 'x' && main_matrix[q - 1][w - 1] != 'o')   //6
                                {
                                    main_matrix[q - 1][w - 1] = 'o';
                                }
                                else
                                {
                                    while (flag1 == 'y')
                                    {
                                        t = rand() % 3;
                                        z = rand() % 3;
                                        if (main_matrix[t][z] == 'o' || main_matrix[t][z] == 'x')
                                        {
                                        }
                                        else
                                        {
                                            main_matrix[t][z] = 'o';
                                            flag1 = 'n';
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


                                                //case seven  subscript  21


        if (q == 2 && w == 1)
        {
            if (main_matrix[q][w] == 'x' && main_matrix[q - 1][w] == 'x' && main_matrix[q -2][w] != 'x' && main_matrix[q -2][w] != 'o')  //1
            {
                main_matrix[q -2][w] = 'o';
            }
            else
            {
                if (main_matrix[q][w] == 'x' && main_matrix[q -2][w] == 'x' && main_matrix[q - 1][w] != 'x' && main_matrix[q - 1][w] != 'o')   //2
                {
                    main_matrix[q - 1][w] = 'o';
                }
                else
                {
                    if (main_matrix[q][w] == 'x' && main_matrix[q][w + 1] == 'x' && main_matrix[q][w -1] != 'x' && main_matrix[q][w -1] != 'o')   //3
                    {
                        main_matrix[q][w -1] = 'o';
                    }
                    else
                    {
                        if (main_matrix[q][w] == 'x' && main_matrix[q][w -1] == 'x' && main_matrix[q][w + 1] != 'x' && main_matrix[q][w + 1] != 'o')  ///4
                        {
                            main_matrix[q][w + 1] = 'o';
                        }
                        else
                        {
                            while (flag1 == 'y')
                            {
                                t = rand() % 3;
                                z = rand() % 3;
                                if (main_matrix[t][z] == 'o' || main_matrix[t][z] == 'x')
                                {
                                }
                                else
                                {
                                    main_matrix[t][z] = 'o';
                                    flag1 = 'n';
                                }
                            }
                        }
                    }
                }
            }
        }


                                                        //case eight  subscript 02


        if (q == 0 && w == 2)
        {
            if (main_matrix[q][w] == 'x' && main_matrix[q][w - 1] == 'x' && main_matrix[q][w - 2] != 'x' && main_matrix[q][w - 2] != 'o')    //1
            {
                main_matrix[q][w - 2] = 'o';
            }
            else
            {
                if (main_matrix[q][w] == 'x' && main_matrix[q + 1][w] == 'x' && main_matrix[q + 2][w] != 'x' && main_matrix[q + 2][w] != 'o')   //2
                {
                    main_matrix[q + 2][w] = 'o';
                }
                else
                {
                    if (main_matrix[q][w] == 'x' && main_matrix[q + 1][w - 1] == 'x' && main_matrix[q + 2][w - 2] != 'x' && main_matrix[q + 2][w - 2] != 'o')   //3
                    {
                        main_matrix[q + 2][w - 2] = 'o';
                    }
                    else
                    {
                        if (main_matrix[q][w] == 'x' && main_matrix[q][w - 2] == 'x' && main_matrix[q][w - 1] != 'x' && main_matrix[q][w - 1] != 'o')   //4
                        {
                            main_matrix[q][w - 1] = 'o';
                        }
                        else
                        {
                            if (main_matrix[q][w] == 'x' && main_matrix[q + 1][w] != 'x' && main_matrix[q + 2][w] == 'x' && main_matrix[q + 1][w] != 'o')   //5
                            {
                                main_matrix[q + 1][w] = 'o';
                            }
                            else
                            {
                                if (main_matrix[q][w] == 'x' && main_matrix[q + 2][w - 2] == 'x' && main_matrix[q + 1][w - 1] != 'x' && main_matrix[q + 1][w - 1] != 'o')   //6
                                {
                                    main_matrix[q + 1][w - 1] = 'o';
                                }
                                else
                                {
                                    while (flag1 == 'y')
                                    {
                                        t = rand() % 3;
                                        z = rand() % 3;
                                        if (main_matrix[t][z] == 'o' || main_matrix[t][z] == 'x')
                                        {
                                        }
                                        else
                                        {
                                            main_matrix[t][z] = 'o';
                                            flag1 = 'n';
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


                                                    // case nine final subscript 12


        if (q == 1 && w == 2)
        {
            if (main_matrix[q][w] == 'x' && main_matrix[q - 1][w] == 'x' && main_matrix[q + 1][w] != 'x' && main_matrix[q + 1][w] != 'o')  //1
            {
                main_matrix[q + 1][w] = 'o';
            }
            else
            {
                if (main_matrix[q][w] == 'x' && main_matrix[q + 1][w] == 'x' && main_matrix[q - 1][w] != 'x' && main_matrix[q - 1][w] != 'o')   //2
                {
                    main_matrix[q - 1][w] = 'o';
                }
                else
                {
                    if (main_matrix[q][w] == 'x' && main_matrix[q][w - 1] == 'x' && main_matrix[q][w - 2] != 'x' && main_matrix[q][w - 2] != 'o')   //3
                    {
                        main_matrix[q][w - 2] = 'o';
                    }
                    else
                    {
                        if (main_matrix[q][w] == 'x' && main_matrix[q][w - 2] == 'x' && main_matrix[q][w - 1] != 'x' && main_matrix[q][w - 1] != 'o')  ///4
                        {
                            main_matrix[q][w - 1] = 'o';
                        }
                        else
                        {
                            while (flag1 == 'y')
                            {
                                t = rand() % 3;
                                z = rand() % 3;
                                if (main_matrix[t][z] == 'o' || main_matrix[t][z] == 'x')
                                {
                                }
                                else
                                {
                                    main_matrix[t][z] = 'o';
                                    flag1 = 'n';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    display();
    flag1 = 'y';
    return 0;
}


                            //input function for user chance
        

int playUser()
{
    cout << endl;
    while (flag == 'y')
    {
        cout << endl << "enter the index you want to play (according to the indices shown above in the matrix): ";
        cin >> k >> l;
        if (k >= 3 || k < -1 || l < -1 || l >= 3||main_matrix[k][l]=='x'||main_matrix[k][l]=='o')
        {
            cout << endl << '\a' << "either you entered wrong indices or pre occupied field....re-enter: ";
        }
        else
        {
            q = k;
            w = l;
            flag = 'n';
        }
    }
    main_matrix[k][l] = 'x';
    display();
    flag = 'y';
    return 0;
}


                                //initiating the chance


int initChance()
{
    v1=v2=v3=v4=v5=v6=0;
    b = 0;
    while (b <= 8)
    {
        if (b % 2 == 0)
        {
            playUser();
            if (b >= 4)
            {
                v1 = checkRows();
                if (v1 != 1 && v1!=2)
                {
                    v2 = checkColumns();
                    if (v2 != 1 && v2 != 2)
                    {
                       v3 = checkDiagonals();
                    }
                }
            }
        }
        else
        {
            playComputer(b);
            if (b >= 5)
            {
                v4 = checkRows();
                if (v4 != 1 && v4 != 2)
                {
                    v5 = checkColumns();
                    if (v5 != 1 && v5 != 2)
                    {
                        v6 = checkDiagonals();
                    }
                }
            }
        }
        if (v1 == 1|| v2 == 1|| v3 == 1|| v4==1|| v5==1|| v6==1)
            break;
        b++;
    }
    return 0;
}


                        //main function


int main()
{
    displayInit();
    initChance();
    return 0;
}