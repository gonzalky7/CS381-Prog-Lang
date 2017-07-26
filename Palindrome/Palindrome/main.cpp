#include <iostream> // library that contain basic input/output functions
#include <fstream>  // library that contains file input/output functions
#include <cctype>

using namespace std;

bool palindromeCheck(string);

int main()
{
    string substring;
    int k, l, i,z;
    int array_size = 4000; // define the size of  array
    string * array = new string[array_size];
    
    string arr2[4000];
    
    ifstream fin("palindromes.txt");
    
       /* -------------Done read file and filling array -------------------*/
    while (!fin.eof()) {
        fin >> array[i];
        i++;
    }
    
    fin.close();
  
    
    /*--------------------Getting rid of spaces and putting into lowercase---------------------- */
    
    z = 0;
    for(k = 0; k <= i; k++)
    {
        string currWord = array[k];

        for ( l = 0; l < currWord.length(); ++l) {
            if (ispunct(currWord[l]) == false) {
                //cout << currWord[l] <<endl;
                arr2[z] += tolower(currWord[l]);
            }
        }
        z++;
    }

       /*------------------------------END---------------------------- */
    
    
    /*-----------------------------PALINDROME STUFFFFFFFFFF---------------------- */
  
    for(int beg = 0; beg < z; beg++){
        substring = "";
        for(int end = beg; end < z; end++){
            substring += arr2[end];
            if(substring.length() > 1){
                
                if(palindromeCheck(substring)){ //this will return true or false and either execute inside or go back out into the for loops
                    for(int i = beg; i <= end; i++){
                         cout << arr2[i] <<" ";
                    }
                     cout << "-- location:"<<beg << " ";
                    cout << std::endl;
                }
            }
        }
    }
    delete[] array;
    
       
    return 0;
}

bool palindromeCheck(string str){//we are sending in the strings we built and seeing if the small strings  are palindromes
    //std::cout << "got here" << std::endl;
    int beg = 0;
    int end = str.length()-1;
    while(beg <= end){
        if(str[beg] != str[end]){ //we have start at the beginning and end of string and see if they are == if not we return false and keep building string
            return false;
        }
        beg++; //if they do equal we keep going through string and seeing if they equal
        end--;
    }
    return true;
}




