#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <stdexcept>

#include "PhoneticFinder.hpp"
using namespace std;



string phonetic::find(string text, string word) {
    if(word =="")throw out_of_range{"Wrong input, cant search empty word."};
    string originWord =word;
    string ans;
    string ans2;
    int counter=0;
    transform(word.begin(),word.end(),word.begin(),::tolower);  //change the word we search to lowercase.
    for (int i = 0; i<text.length(); ++i) {   //run on all the text.
        if(text[i]!= ' ') {
            ans.append(1u,text[i]);   //append a char to new string.
        }
        if(text[i]== ' ' || i==text.length()-1){   //each word in the text.
            if(ans.length()==word.length()){
                ans2 = ans;
                transform(ans.begin(),ans.end(),ans.begin(),::tolower);
                for(int i =0;i<word.length();++i){
                   counter+=equalsChar(ans[i],word[i]);
                }
               if(counter==word.length()){
                   return ans2;
               }

            }
            ans.clear();  //clean the string.
            counter=0;
        }
    }
   throw out_of_range{"Did not find the word " + originWord + " in the text"};
    return "";

}

int equalsChar(char a,char b){
    if( (b=='w' || b=='v') && (a=='w' || a=='v')) return 1;
    if( (b=='g' || b=='j') && (a=='g' || a=='j')) return 1;
    if( (b=='s' || b=='z') && (a=='s' || a=='z')) return 1;
    if( (b=='t' || b=='d') && (a=='t' || a=='d')) return 1;
    if( (b=='o' || b=='u') && (a=='o' || a=='u')) return 1;
    if( (b=='i' || b=='y') && (a=='i' || a=='y')) return 1;
    if( (b=='b' || b=='f'|| b=='p') && (a=='b' || a=='f' || a=='p')) return 1;
    if( (b=='c' || b=='k'|| b=='q') && (a=='c' || a=='k' || a=='q')) return 1;
    if(a==b) return 1;
    return 0;
}

