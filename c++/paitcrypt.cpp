/**
*
*   @title:     crypt
*   @author:    Paitorocxon (Fabian Müller)
*   @created:   20.11.2018
*   @version:   1.0
*   
*/

//Paitcrypt © 2018 Paitorocxon aka Fabian Müller

//Runs under the Mozilla Public License 2.0

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



bool is_number(const std::string& s){ //some shit i stole from the internet. I don't have the time to do everything... c'mon...
	return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

int main(int argc, char* argv[]) {

	int mainI = 0;
	int salt = 0;
	int cot = 0;
    
	std::string cryptedPassword = "";
	std::string str = "";
	
    
    
    if (argc < 3) { //check if the fucking user gave this application some arguments
            std::cout << "Excuse me, but you forgot to give me a password and the associated salt!\nUsage is <password> <salt> (The salt can only be 0-999999999)\n";
            exit(0);
    } else { 
        if (is_number(argv[2])){
            str = argv[1];
            salt = std::stoi(argv[2]);
        } else {
            cout << "uhm... i hope you know that the salt you gave me '" << argv[2] << "' is not a number :/\n";
            exit(0); 
        }
    }
    
	// First step in encrypting
	for(std::string::size_type i = 0; i < str.size(); ++i) {
		cryptedPassword += std::to_string(int(str[i]));
		mainI++;
	}
    
    
	// Second step in encrypting
	str = cryptedPassword;
	cryptedPassword = "";
	for(std::string::size_type i = 0; i < str.size(); ++i) {
		cryptedPassword += std::to_string(int(str[i]));
		mainI++;
	}
    
    
	// Third step in encrypting
	str = cryptedPassword;
	cryptedPassword = "";
	for(std::string::size_type i = 0; i < str.size(); ++i) {
		int x = str[i] - '0';
		cot = x * mainI + salt;
		cryptedPassword += int(cot);
		mainI++;
	}

    
    
	// Last but not least! Fourth step in encrypting
	str = cryptedPassword;
	cryptedPassword = "";
	for(std::string::size_type i = 0; i < str.size(); ++i) {
		int ia = (int)str[i];
		char cha = str[i]+'0';
		cryptedPassword += std::to_string(ia) ;
	}
    
    
	//No! Wait! This is the last step! ugh... idk... drank to much... again...
	str = cryptedPassword;
	cryptedPassword = "";
	for(std::string::size_type i = 0; i < str.size(); ++i) {
		int tmp = int(str[i] - '0') + 65;
		cryptedPassword += int(str[i] - '0'+65);
		mainI++;
	}
	
	//Yeah then spit it out.
	cout << cryptedPassword;
	return 0; 
} 
