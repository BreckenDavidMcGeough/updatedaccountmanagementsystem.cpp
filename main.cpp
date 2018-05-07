#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
typedef const unsigned long u64;
u64 generaterandomID(){
    int random = rand() % 1000000 + 10000000;
    return random;
}
void userpasswordhashingAlgorithm(string password){
    
}
struct userinformationStructure{
    u64 randomuserID = generaterandomID();
    string name;
    string username;
    string password;
};
enum labelstructureInfo{
    password = 1,
    username,
    name,
    userId
};
class Account{
private:
    vector<string> usernamesDatabase;
    vector<string> passwordsDatabase;
public:
    u64 getuserlocationKey(string username, string password){
        unsigned long key = 0;
        if(this->usernamesDatabase.size() == this->passwordsDatabase.size()){
            for(int i = 0; i <= this->usernamesDatabase.size()-1; i++){
                if(this->usernamesDatabase[i] == username && this->passwordsDatabase[i] == password){
                    key = i;
                }else{
                    if(i == this->usernamesDatabase.size()-1){
                        key = NULL;
                    }
                }
            }
        }
        u64 keytwo = key;
        return keytwo;
    }
    template<class dataType>
    void returnstructureInformation(string userUsername, string userPassword, userinformationStructure user, dataType input){
        labelstructureInfo userInput = input;
        switch(userInput){
            case password:
                cout << user.password << endl;
                break;
            case username:
                cout << user.username << endl;
                break;
            case name:
                cout << user.name << endl;
                break;
            case userId:
                cout << user.randomuserID << endl;
                break;
            default:
                cout << "ERROR" << endl;
                break;
        }
    }
    void createnewuserAccount(string username, string password){
        if(sizeof(username) != 0 && sizeof(password) != 0 && this->usernamesDatabase.size() == this->passwordsDatabase.size() && this->usernamesDatabase.size() > 1){
            for(int i = 0; i <= this->usernamesDatabase.size()-1; i ++){
                if(this->usernamesDatabase[i] == username && this->passwordsDatabase[i] == password){
                    cout << "ERROR" << endl;
                    break;
                }else{
                    if(i == this->usernamesDatabase.size()-1){
                        this->usernamesDatabase.push_back(username);
                        this->passwordsDatabase.push_back(password);
                        cout << "SUCCESS" << endl;
                    }
                }
            }
        }else{
            if(this->usernamesDatabase.size() < 1){
                this->usernamesDatabase.push_back(username);
                this->passwordsDatabase.push_back(password);
                cout << "SUCCESS" << endl;
            }
        }
    }
};
int main(){
    userinformationStructure test = {
        generaterandomID(),
        "brecken",
        "brecken",
        "brecken",
    };
    cout << "hello" << endl;
    Account testt;
    testt.createnewuserAccount(test.username, test.password);
}
