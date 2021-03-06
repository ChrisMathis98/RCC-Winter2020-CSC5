/* 
 * File: main.cpp
 * Author: Christopher Mathis
 * Created on February 13, 2020
 * Purpose: War Version 1
 */

//System Libraries
#include <iostream>     //Input/Output
#include <ctime>        //Time
#include <cstdlib>      //Srand/Rand
#include <string>       //Strings
#include <vector>       //Vectors
using namespace std;    //Standard Name-Space Where System Libraries Exist

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimension

//Function Prototypes
bool isTrue(char);
int whoWon(int , int , int , int , vector<string>, int []);
int flipCard(int &, int &, int &, int &, vector<string>);
void validate(char);
void cards(int &, int &, int &, int &,vector<string>);
int whoWon(int &, int &, vector<string>, int [], int );
int lesser(int &, int &, vector<string>, int [], int );
int equal(int &, int &, int &, int &, vector<string>, int [], int, int);
int equal1(int &, int &, int &, int &, vector<string>,int [], int, int);
int equal2(int &, int &, int &, int &, vector<string>, int [], int, int);
int equal3(int &, int &, int &, int &, vector<string>, int [], int, int);
int equal4(int &, int& , int &, int &, vector<string>, int [], int, int);
int equal5(int &, int &, int &, int &, vector<string>, int [], int, int);
int equal6(int &, int &, int &, int &, vector<string>, int [], int, int);
int equal7(int &, int &, int &, int &, vector<string>, int [], int, int);
int equal8(int &, int &, int &, int &, vector<string>, int [], int, int);
int equal9(int &, int &, int &, int &, vector<string>, int [], int, int);
int equal10(int &, int &, int &, int &, vector<string>, int [], int, int);
int equal11(int &, int &, int &, int &, vector<string>, int [], int, int);
int flipCoin(vector<string>, int [], int, int, int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    char choice;
    unsigned int pRank, pSuit, cRank, cSuit;    //Rank and Suit Of Cards
    unsigned int nRounds;                       //Counters For Statistics
    string s;                                   //
    const int SIZE=4;                           //
    int counter[SIZE]={26, 26, 0, 0};           //
    vector<string> name;                        //
    
    //Initialize Variables
    nRounds=pRank=pSuit=cRank=cSuit=0;
    
    for(int i=0; i<2; i++){
        cout<<"Enter Name For Player "<<i+1<<endl;
        getline(cin,s);
        name.push_back(s);
        cout<<endl;
    }
    string w=" Won";
    name.push_back(name[0]+w);
    name.push_back(name[1]+w);
    
    //Process or map Inputs to Outputs
    whoWon(pRank, pSuit, cRank, cSuit, name, counter);
    
    //Process or map Inputs to Outputs
    
    //Display Outputs

    //Exit stage right!
    return 0;
}

bool isTrue(char choice){
    cout<<endl<<endl;
    cin>>choice;
    cout<<endl;
    if(choice!='Y' && choice!='y'){
        cout<<"Exiting Game.\n";
        exit(EXIT_FAILURE);
    }else{
    return true;
    }
}

int whoWon(int pRank, int pSuit, int cRank, int cSuit, vector<string> name, int counter[]){
    int a, b, c, d;
    a=b=c=d=0;
    string cnt;
    
    do{
    flipCard(pRank, pSuit, cRank, cSuit, name);
    whoWon(pRank, cRank, name, counter, a);
    lesser(pRank, cRank, name, counter, b);
    equal(pRank, pSuit, cRank, cSuit, name, counter, a, b);
    
    cnt=(counter[0]>0 && counter[1]>0)?"continue The Game, Flip A Card.\n":"Game Over.\n";
    cout<<cnt;
    }while(counter[0]>0 && counter[1]>0);
}

int flipCard(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name){
    srand(static_cast<unsigned int>(time(0)));
    char choice;
    
    cout<<endl;
    cout<<"To Flip The Card, Press Y.\n";
    cin>>choice;
    cout<<endl;
    
    validate(choice);
    
    pRank=rand()%13+1;
    pSuit=rand()%4+1;
    cRank=rand()%13+1;
    cSuit=rand()%4+1;
    
    pRank=rand()%13+1;
    pSuit=rand()%4+1;
    cRank=rand()%13+1;
    cSuit=rand()%4+1;
    
    cards(pRank, pSuit, cRank, cSuit, name);
}

void validate(char choice){
    while(choice!='Y' && choice!='y'){
        cout<<"Invalid Entry, Please Press Y To Flip The Card.\n";
        cin>>choice;
        cout<<endl;
    }
}

void cards(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name){
    cout<<name[0]<<" Played ";
        switch(pRank){
            case 1:cout<<"Ace ";break;
            case 2:cout<<"Two ";break;
            case 3:cout<<"Three ";break;
            case 4:cout<<"Four ";break;
            case 5:cout<<"Five ";break;
            case 6:cout<<"Six ";break;
            case 7:cout<<"Seven ";break;
            case 8:cout<<"Eight ";break;
            case 9:cout<<"Nine ";break;
            case 10:cout<<"Ten ";break;
            case 11:cout<<"Jack ";break;
            case 12:cout<<"Queen ";break;
            case 13:cout<<"King ";break;
        }
        switch(pSuit){
            case 1:cout<<"Of Clubs.\n";break;
            case 2:cout<<"Of Diamonds.\n";break;
            case 3:cout<<"Of Hearts.\n";break;
            case 4:cout<<"Of Spades.\n";break;
        }
    
    cout<<name[1]<<" Played ";
        switch(cRank){
            case 1:cout<<"Ace ";break;
            case 2:cout<<"Two ";break;
            case 3:cout<<"Three ";break;
            case 4:cout<<"Four ";break;
            case 5:cout<<"Five ";break;
            case 6:cout<<"Six ";break;
            case 7:cout<<"Seven ";break;
            case 8:cout<<"Eight ";break;
            case 9:cout<<"Nine ";break;
            case 10:cout<<"Ten ";break;
            case 11:cout<<"Jack ";break;
            case 12:cout<<"Queen ";break;
            case 13:cout<<"King ";break;
        }
        switch(cSuit){
            case 1:cout<<"Of Clubs.\n";break;
            case 2:cout<<"Of Diamonds.\n";break;
            case 3:cout<<"Of Hearts.\n";break;
            case 4:cout<<"Of Spades.\n";break;
        }
        cout<<endl;
}

int whoWon(int &pRank, int &cRank, vector<string> name, int counter[], int a){
    if(pRank>cRank){
        counter[0]--;
        counter[1]--;
        a+=2;
        
        cout<<name[2]<<" This Round!\n"<<endl;
        //Counters
        counter[2]++;
        counter[3]+=0;
        counter[0]+=a;
        counter[1]+=0;
        cout<<name[0]<<" Has "<<counter[0]<<" Cards.\n";
        cout<<name[1]<<" Has "<<counter[1]<<" Cards.\n";
        cout<<endl;
    }
}

int lesser(int &pRank, int &cRank, vector<string> name, int counter[], int b){
    if(pRank<cRank){
        counter[0]--;
        counter[1]--;
        b+=2;
        
        cout<<name[3]<<" This Round!\n"<<endl;
        //Counters
        counter[2]+=0;
        counter[3]++;
        counter[0]+=0;
        counter[1]+=b;
        cout<<name[0]<<" Has "<<counter[0]<<" Cards.\n";
        cout<<name[1]<<" Has "<<counter[1]<<" Cards.\n";
        cout<<endl;
    }
}

int equal(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name, int counter[], int a, int b){
    if(pRank==cRank){
        counter[0]--;
        counter[1]--;
        
        equal1(pRank, pSuit, cRank, cSuit, name, counter, a, b);
        equal2(pRank, pSuit, cRank, cSuit, name, counter, a, b);
        equal3(pRank, pSuit, cRank, cSuit, name, counter, a, b);
        equal4(pRank, pSuit, cRank, cSuit, name, counter, a, b);
        equal5(pRank, pSuit, cRank, cSuit, name, counter, a, b);
        equal6(pRank, pSuit, cRank, cSuit, name, counter, a, b);
        equal7(pRank, pSuit, cRank, cSuit, name, counter, a, b);
        equal8(pRank, pSuit, cRank, cSuit, name, counter, a, b);
        equal9(pRank, pSuit, cRank, cSuit, name, counter, a, b);
        equal10(pRank, pSuit, cRank, cSuit, name, counter, a, b);
        equal11(pRank, pSuit, cRank, cSuit, name, counter, a, b);
    }
}

int equal1(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name, int counter[],int a, int b){
    if(pRank==cRank && counter[0]>4 && counter[1]>4){
        cout<<"It's War!\n";
        cout<<"Both Place 3 Cards Face Down.\n";
        cout<<"Each Flip Another Card.\n";
        cout<<endl;
        
        counter[0]-=3;
        counter[1]-=3;
        a+=8, b+=8;
        
        flipCard(pRank, pSuit, cRank, cSuit, name);
        whoWon(pRank, cRank, name, counter, a);
        lesser(pRank, cRank, name, counter, b);
        equal(pRank, pSuit, cRank, cSuit, name, counter, a, b);
    }
}

int equal2(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name, int counter[], int a, int b){
    if(pRank==cRank && counter[0]==4){
        cout<<"It's War!\n";
        cout<<"Both Place 3 Cards Face Down.\n";
        cout<<"Each Flip Another Card.\n";
        cout<<endl;
        
        counter[0]-=3;
        counter[1]-=3;
        a+8, b+=8;
        
        flipCard(pRank, pSuit, cRank, cSuit, name);
        whoWon(pRank, cRank, name, counter, a);
        lesser(pRank, cRank, name, counter, b);
        equal(pRank, pSuit, cRank, cSuit, name, counter, a, b);
    }
}

int equal3(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name, int counter[], int a, int b){
    if(pRank==cRank && counter[1]==4){
        cout<<"It's War!\n";
        cout<<"Both Place 3 Cards Face Down.\n";
        cout<<"Each Flip Another Card.\n";
        cout<<endl;

        counter[0]-=3;
        counter[1]-=3;
        a+=8, b+=8;
        
        flipCard(pRank, pSuit, cRank, cSuit, name);
        whoWon(pRank, cRank, name, counter, a);
        lesser(pRank, cRank, name, counter, b);
        equal(pRank, pSuit, cRank, cSuit, name, counter, a, b);
    }
}

int equal4(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name, int counter[], int a, int b){
    if(pRank==cRank && counter[0]==3){
        cout<<"It's War!\n";
        cout<<name[0]<<" Can Only Put 2 Cards Down, "<<name[1]<<" Will Put 3 Cards Face Down.\n";
        cout<<"Each Flip Another Card.\n";
        cout<<endl;

        counter[0]-=2;
        counter[1]-=3;
        a+=7, b+=7;
        
        flipCard(pRank, pSuit, cRank, cSuit, name);
        whoWon(pRank, cRank, name, counter, a);
        lesser(pRank, cRank, name, counter, b);
        equal(pRank, pSuit, cRank, cSuit, name, counter, a, b);
    }
}

int equal5(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name, int counter[], int a , int b){
    if(pRank==cRank && counter[1]==3){
        cout<<"It's War!\n";
        cout<<name[1]<<" Can Only Put 2 Cards Down, "<<name[0]<<" Will Put 3 Cards Face Down.\n";
        cout<<"Each Flip Another Card.\n";
        cout<<endl;

        counter[0]-=3;
        counter[1]-=2;
        a+=7, b+=7;
       
        flipCard(pRank, pSuit, cRank, cSuit, name);
        whoWon(pRank, cRank, name, counter, a);
        lesser(pRank, cRank, name, counter, b);
        equal(pRank, pSuit, cRank, cSuit, name, counter, a, b);
    }
}

int equal6(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name, int counter[], int a, int b){
    if(pRank==cRank && counter[0]==2){
        cout<<"It's War!\n";
        cout<<name[0]<<" Can Only Put 1 Card Down, "<<name[1]<<" Will Put 3 Cards Face Down.\n";
        cout<<"Each Flip Another Card.\n";
        cout<<endl;

        counter[0]-=1;
        counter[1]-=3;
        a+=6, b+=6;
        
        flipCard(pRank, pSuit, cRank, cSuit, name);
        whoWon(pRank, cRank, name, counter, a);
        lesser(pRank, cRank, name, counter, b);
        equal(pRank, pSuit, cRank, cSuit, name, counter, a, b);
    }
}

int equal7(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name, int counter[], int a, int b){
    if(pRank==cRank && counter[1]==2){
        cout<<"It's War!\n";
        cout<<name[1]<<" Can Only Put 1 Card Down, "<<name[0]<<" Will Put 3 Cards Face Down.\n";
        cout<<"Each Flip Another Card.\n";
        cout<<endl;

        counter[0]-=3;
        counter[1]-=1;
        a+=6, b+=6;
        
        flipCard(pRank, pSuit, cRank, cSuit, name);
        whoWon(pRank, cRank, name, counter, a);
        lesser(pRank, cRank, name, counter, b);
        equal(pRank, pSuit, cRank, cSuit, name, counter, a, b);
    }
}

int equal8(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name, int counter[], int a, int b){
    if(pRank==cRank && counter[0]==1){
        cout<<"It's War!\n";
        cout<<name[0]<<" Cannot Put Any Cards Down, "<<name[1]<<" Will Put 3 Cards Face Down.\n";
        cout<<"Each Flip Another Card.\n";
        cout<<endl;

        counter[1]-=3;
        a+=5, b+=5;
        
        flipCard(pRank, pSuit, cRank, cSuit, name);
        whoWon(pRank, cRank, name, counter, a);
        lesser(pRank, cRank, name, counter, b);
        if(pRank==cRank){
            counter[0]--;
            flipCoin(name, counter, a, b, 0, 1);
            pRank=0, cRank=1;
        }
    }
}

int equal9(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name, int counter[], int a, int b){
    if(pRank==cRank && counter[1]==1){
        cout<<"It's War!\n";
        cout<<name[1]<<" Cannot Put Any Cards Down, "<<name[0]<<" Will Put 3 Cards Face Down.\n";
        cout<<"Each Flip Another Card.\n";
        cout<<endl;

        counter[0]-=3;
        a+=5, b+=5;
        
        flipCard(pRank, pSuit, cRank, cSuit, name);
        whoWon(pRank, cRank, name, counter, a);
        lesser(pRank, cRank, name, counter, b);
        if(pRank==cRank){
            counter[1]--;
            flipCoin(name, counter, a, b, 1, 0);
            pRank=0, cRank=1;
        }
    }
}

int equal10(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name, int counter[], int a, int b){
    if(pRank==cRank && counter[0]==0){
        cout<<"It's War!\n";
        cout<<name[0]<<" Cannot Put Any Cards Down, "<<name[1]<<" Will Put 3 Cards Face Down.\n";
        
        counter[1]-=3;
        a+=5, b+=5;
        
        flipCoin(name, counter, a, b, 0, 1);
    }
}

int equal11(int &pRank, int &pSuit, int &cRank, int &cSuit, vector<string> name, int counter[], int a, int b){
    if(pRank==cRank && counter[1]==0){
        cout<<"It's War!\n";
        cout<<name[1]<<" Cannot Put Any Cards Down, "<<name[0]<<" Will Put 3 Cards Face Down.\n";
        
        counter[0]-=3;
        a+=5, b+=5;
        
        flipCoin(name, counter, a, b, 1, 0);
    }
}

int flipCoin(vector<string> name, int counter[], int a, int b, int c, int d){
    srand(static_cast<unsigned int>(time(0)));
    unsigned int coin, flip;
    

    cout<<"Flip A Coin, Choose Heads(1) Or Tails(0).\n";

    //Choose Heads Or Tails
    cin>>flip;

    while(flip!=1 && flip!=0){
        cout<<"Invalid Entry, Please Choose Heads(1) Or Tails(0).\n";
        cin>>flip;
        cout<<endl;
    }

    //Flip Coin
    coin=rand()%2;
    cout<<coin<<endl<<endl;

    if(flip==coin){
        cout<<name[2]<<" The War!\n";
        counter[2]++;
        counter[3]+=0;
        counter[0]+=a;
        counter[1]+=0;
        cout<<name[c]<<" Has "<<counter[c]<<" Cards.\n";
        cout<<name[d]<<" Has "<<counter[d]<<" Cards.\n";
        cout<<endl;
    }
    else{
        cout<<name[3]<<" The War!\n";
        counter[2]+=0;
        counter[3]++;
        counter[0]+=0;
        counter[1]+=b;
        cout<<name[c]<<" Has "<<counter[c]<<" Cards.\n";
        cout<<name[d]<<" Has "<<counter[d]<<" Cards.\n";
        cout<<endl;
    }
}