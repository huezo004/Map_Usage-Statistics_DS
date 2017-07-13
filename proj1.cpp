#include<string>
#include<iomanip>
#include<iostream> 
#include<cctype>
#include<fstream>
#include<map>
#include<vector>
#include<utility>
#include <cstdlib>
#include<algorithm>
using namespace std; 


bool myfunction( const pair<string, int>& i, const pair<string,int>& j );

bool myfunctionTwo( const pair<string, int>& ii, const pair<string,int>& jj );


int main(){
  string chars=""; 
  string word="";
  string number="";   
  char c;
  int f =1;

  std::map<string,int>numMap;
  std::map<string,int>charMap;
  std::map<string,int>wordMap;
  std::map<string,int>charCount;

  std::map<string,int>::iterator it;
  std::map<string,int>::iterator ic; 
  std::map<string,int>::iterator il;

  std::vector<pair<string,int>> charVec;
  std::vector<pair<string,int>> numVec;
  std::vector<pair<string,int>> wordVec;
  
while(cin.get(c)){

    chars=c;
   
    if(c=='\t')
      chars="\\t";
    
    if(c =='\n')
      chars="\\n";
  
    it=charMap.find(chars);

   if(it==charMap.end())
     charMap.insert(std::pair<string,int>(chars,f));
 else   
   ++charMap[chars];

//chars.clear();
 
  if(isdigit(c))
     number= number+c;

  if(isalpha(c)){
    if(isupper(c))
      c=tolower(c);
     word= word+c;
  }
   if(!isdigit(c)){
   
   ic=numMap.find(number);

  if(ic==numMap.end())
      numMap.insert(std::pair<string,int>(number,f));
      
    else
    ++numMap[number];

    number.clear();
   }
  if(!isalpha(c)){
    
    il=wordMap.find(word);

    if(il==wordMap.end())
      wordMap.insert(std::pair<string,int>(word,f));

    else
      ++wordMap[word];
      word.clear();
  }  

 }
  
 
//ENTERING INFO INTO CHAR MAP
 
 for(std::map<string,int>:: iterator iy= charMap.begin(); iy!=charMap.end(); ++iy){
    charVec.push_back(std::make_pair(iy->first, iy->second));//insert pair into vector
}
 //SORTING CHARMAP
  std:: sort(charVec.begin(), charVec.end(), myfunction); 
  std:: reverse(charVec.begin(), charVec.end());

int loopc=0;  
int limit=0;
 if(charVec.size()>=10)
   limit=10;
 else
   limit=charVec.size();
 
cout<<"Total "<<charVec.size()<<" different characters, "<<limit<<" most used characters:"<<endl;

//RESIZING TO PRINT NO > THAN 10
 if(limit==10)
   charVec.resize(10);

//PRINTING CHARMAP
 int counter=0;  
  for(std::vector<pair<string,int>>:: iterator u= charVec.begin(); u!=charVec.end(); ++u){
    cout<<"No. "<<counter<<":"<<u->first;
    cout.setf(ios::right);
    cout.width(10);
    cout<<u->second<<endl;
    counter++; 
}

//ENTERING INFO TO WORDMAP
for(std::map<string,int>::iterator iu=wordMap.begin(); iu!= wordMap.end(); ++iu){
  wordVec.push_back(std::make_pair(iu->first, iu->second));
 }

//SORTING WORDEMAP
std::sort(wordVec.begin(), wordVec.end(), myfunctionTwo);
std::reverse(wordVec.begin(), wordVec.end());

 int limitw=0;
 if(wordVec.size()>=10)
   limitw=10;
 else
   limitw=wordVec.size()-1;
 
//PRINTING WORD MAP
cout<<"Total "<<wordVec.size()-1<<" different words, "<<limitw<<" most used words:"<<endl;

//RESIZING TO PRING NO > THAN 10 
 if(limitw==10)
   wordVec.resize(11);
 
int countern=0;
for(std::vector<pair<string,int>>:: iterator p= ++wordVec.begin(); p!=wordVec.end(); ++p){
  cout<<"No. "<<countern<<":"<<p->first;
  cout.setf(ios::right);
  cout.width(10);
  cout<<p->second<<endl;
   countern++;
 }
 
//ENTERING INFO INTO NUMBERMAP 
for(std::map<string,int>::iterator iu=numMap.begin(); iu!= numMap.end(); ++iu){
  numVec.push_back(std::make_pair(iu->first, iu->second)); 
 }

//SORTING NUMBER MAP
 std::sort(numVec.begin(), numVec.end(), myfunctionTwo);
 std::reverse(numVec.begin(), numVec.end());

 int limitn=0; 

 if(numVec.size()>=10)
   limitn=10;
 else
   limitn=numVec.size()-1;
  
//PRINTING NUMBER MAP
cout<<"Total "<<numVec.size()-1<<" different numbers, "<<limitn<<" most used numbers:"<<endl;

//RESIZING TO PRINT NO > 10
 if(limitn==10)
   numVec.resize(11);
 
int counterd=0;
for(std::vector<pair<string,int>>:: iterator k= ++numVec.begin(); k!=numVec.end(); ++k){
  cout<<"No. "<<counterd<<":"<<k->first;
  cout.setf(ios::right);
  
  cout.width(10);
  cout<<k->second<<endl;
  counterd++; 
}


}//end of main  
 

bool myfunction( const pair<string, int>& i, const pair<string, int>& j ){ //return i.second < j.second;

  //  if(i.second==j.second)
  //return false; 

  return  i.second<j.second;
}

bool myfunctionTwo( const pair<string, int>& ii, const pair<string, int>& jj ){ //return i.second < j.second;
   
return  ii.second<jj.second;

}
