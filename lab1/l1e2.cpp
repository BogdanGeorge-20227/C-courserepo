#include <iostream>
#include <string>
#define upper_lower_difference ((int)'a'-'A'); //We aim to shift the characters to uppercase one by one, thus we need the value in difference between the two sets in the ASCII char table

int main(){
    std:: string input,reverse_input; 
    int vowelcount=0;
    std::cin>> input;
    for(int i=0;i<=input.length();i++){
        if(i!=0)reverse_input+=input[input.length()-i]; //building the reverse by adding the letters in inverse, omitting the \n at the end with the if condiftion
    }
    for(int i=0;i<=input.length();i++){
        if(input[i]<='z' && input[i]>='a') input[i]=input[i]-upper_lower_difference; //if the char is lowercase, it gets brought to uppercase
        if(input[i]=='A'||input[i]=='E'||input[i]=='I'||input[i]=='U'||input[i]=='O')vowelcount++; //conveniently, all letters checked are guaranteed to be uppercase
    }
    std::cout<<"uppercase input: "<<input<<std::endl;
    std::cout<<"vowel count: "<<vowelcount<<std::endl;
    std::cout<<"reverse input: "<<reverse_input<<std::endl;
    return 0;
}