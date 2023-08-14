#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int sizeOfWords=0;
    string words[10];
    string antonyms[10];
    int i;
    ifstream readWords("word.txt");
    ifstream readAntonyms("antonym.txt");
    ifstream readParagraph("paragraph.txt");

    i=0;
    while(!readWords.eof()){
        readWords>>words[i];
    i++;
    }
sizeOfWords=i;
    i=0;
    while(!readAntonyms.eof()){
         readAntonyms>>antonyms[i];
    i++;
    }

    bool flag=false;
    string paragraph="";
    while(!readParagraph.eof()){
         string temp="";
         readParagraph>>temp;
         for(int j=0;j<sizeOfWords;j++){
                if(temp==words[j]){
                    paragraph=paragraph+" "+antonyms[j];
                flag=false;
                j=sizeOfWords;
                }
                else
                    {
                    flag=true;
                    }
         }
         if(flag){
            paragraph=paragraph+" "+temp;
         }
    }


    cout<<paragraph;

    return 0;
}
