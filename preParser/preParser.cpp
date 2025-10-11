#include "preParser.h"

vector<Chain> parseCommands_accTo_op(string input){
    vector<Chain> result;
    string currcommand = "";
    string op = "";

    for(size_t i = 0; i<input.length() ; i++){
        if(input[i] == ';'){
            result.push_back({currcommand , ";"});
            currcommand = "";
        }else if(input[i] == '&' && i+1 < input.length() && input[i+1] == '&'){
            result.push_back({currcommand , "&&"});
            currcommand = "";
            i++;
        }
        else if (input[i] == '|' && i+1 < input.length() && input[i+1] == '|'){
            result.push_back({currcommand , "||"});
            currcommand = "";
            i++;
        }else{
            currcommand += input[i];
        }
    }

    result.push_back({currcommand , ""});

    return result;
}

// int main(){
//     vector<Chain> res = parseCommands_accTo_op("ls -l; echo hello && pwd || date");
//     for(Chain r : res){
//         cout<<r.commands;
//         cout<<"   ";
//         cout<<r.op<<endl;
//     }
// }