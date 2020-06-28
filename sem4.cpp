#include <iostream>
#include <string>
#include <cctype>
#include<iomanip>
using namespace std; 
                                  
string engtomol (string,string[]);
string moltoeng (string,char[]);

char alpha[81] =
 {
'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0','@','$','-','+','=','/','.',',','?','!','"','(',')','&',':',';'
}; 
string morse[81] = 
{
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----",".--.-.","...-..-","-....-",".-.-.","-...-","-..-.",".-.-.-","--..--","..--..","-.-.--",".-..-.","-.--.","-.--.-",".-...","---...","-.-.-."
};
int main()
{
    char alpha[81] =
 {
'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0','@','$','-','+','=','/','.',',','?','!','"','(',')','&',':',';'
}; 
    string morse[81] =
 {
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----",".--.-.","...-..-","-....-",".-.-.","-...-","-..-.",".-.-.-","--..--","..--..","-.-.--",".-..-.","-.--.","-.--.-",".-...","---...","-.-.-."
};
    string text, morsecode;
    char choice;
    char repeat='y';
 
while (repeat=='y')
{
    cout << "\t\tSelect 1 to decode English text to Morse code.\n\n\t\tSelect 2 to encode Morse code to English text" << endl;
    cin >> choice;
    if (choice=='1')
    {
       // cout << "NOTE. DO NOT INPUT A NON ENGLISH CHARACTER. THIS TRANSLATOR EXCLUSIVELY TRANSLATES ENGLISH TEXTS (CAPITALIZED AND NON CAPITALIZED).\n";
        cout << "\tEnter a text to translate, each word seperated by a space if you want to translate more than one word: ";
        cin.get();
        getline(cin,text);
        cout << "\t\t\tTEXT: " << text << endl;
        cout << "\t\t\tMORSE CODE: " << engtomol(text, morse) << endl;
    } 
    
    else if (choice=='2')
    {
        cout << "\t\tEnter a morsecode to translate, each letter code seperated by a space"; 
		//If you want to translate more than one word, have 3 spaces between each word //(for example, ... --- ...   ... --- ...): ";
        cin.get();
        getline(cin,morsecode);
        cout << "\t\tMORSECODE: " << morsecode <<"\n"<< endl;
        cout << "\t\tTEXT: " << moltoeng (morsecode, alpha) <<"\n"<< endl;  
    }
    
    cout << "\t\tWould you like to continue? \n\t\tPress y to repeat.\n\t\t Press any other key to exit. ";
    cin >> repeat;
}
return 0;
}    

//text function to code
string engtomol (string text, string morse[])
{
    string result = " ";
    for(int i = 0; text[i] != 0; ++i)
	{
    	for(int j = 0; j < 81; ++j)
		{
    		if(text[i] == alpha[j])
			{
    			result = result + morse[j] + " ";
			}
		}
	}
return result; 
}

//code to text function
string moltoeng (string morsecode, char alpha[])
{
    string tran = "";
    string temp = "";
    for(int i = 0; ; ++i)
	{
    	if(morsecode[i] == ' ' || morsecode[i] == 0)
		{
    		
    		for(int j = 0; j < 81; ++j)
			{
    			if(morse[j] == temp)
				{
					temp = " ";
    				tran = tran + alpha[j];
				}
			}
			if(morsecode[i] == 0)
			break;
		}
		else
		{
			temp = temp + morsecode[i];
		}
	}
return tran; 
}
