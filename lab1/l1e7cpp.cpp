#include <iostream>
#include <string>

#define Min_Length 8
struct criterion{
    bool crit_met=0;
    std::string fail_msg;
}criteria[5];

void criterion_init(){
    criteria[0].fail_msg="Password too short";
    criteria[1].fail_msg="Password must contain uppercase letter";
    criteria[2].fail_msg="Password must contain lowercase letter";
    criteria[3].fail_msg="Password must contain at least one digit";
    criteria[4].fail_msg="Password must contain special character";
}
int main(){
    criterion_init();
    std::string password;
    std::cin>>password;
    char lenPas=password.length();
    if(lenPas>Min_Length) criteria[0].crit_met=true; //since length also includes \n at the end, the password needs to be strictly longer than min_len
    for(int i=0; i<=lenPas;i++){ //using an online available ASCII table we can see each type of chars are grouped
        if((password[i]>='!' && password[i]<='/')||(password[i]>=':' && password[i]<='@')||(password[i]>='^' && password[i]<='`')||(password[i]>='{' && password[i]<='~')) criteria[4].crit_met=true; //this only makes sense with an ASCII table on hand, but it checks if the character password[i] is a special char
        if(password[i]>='0' && password[i]<='9')criteria[3].crit_met=true;
        if(password[i]>='a' && password[i]<='z')criteria[2].crit_met=true;
        if(password[i]>='A' && password[i]<='Z')criteria[1].crit_met=true;
}
bool strongPas=true, Weakpass_more_than_once=false; //the first is used to see if ANY criteria aren't met, the second ensures we don't print "weak password" for every failed criterion
for(int i=0;i<=4;i++){
    if(criteria[i].crit_met==false){
        if(!Weakpass_more_than_once){
            std::cout<<"Weak password"<<std::endl;
            Weakpass_more_than_once=true;
        }
        std::cout<<criteria[i].fail_msg<<std::endl;
        strongPas=false;
    }
}
if(strongPas) std::cout<<"Strong password";
return 0;
}