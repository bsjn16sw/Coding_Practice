#include<iostream>
#include<string>
using namespace std;

string decompress(string str)
{
  static string output = "";
  int idx = 0;
  int br0 = 0, br1 = 0, num = 0;

  while(idx < str.length()){
    if((br0 = str.find('[', idx)) != npos){
      br1 = str.find(']', br0);
      num = str[br0 - 1];
      output += str.substr(br0 + 1, br1 - br0 - 1) * num;
      idx = br1;
    }
    else{
      if(br1 == 0){
        output += str;
        idx = str.length();
      }
      else{
        output += str.substr(br1 + 1, str.length() - br1 - 1);
        idx = 
      }
    }
  }
}