#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <list>
#include <unordered_map>

using namespace std;

class Assignment5{
	public:
		string filename;
		list<string> inputData;
		unordered_map<string, list<string>> grammar;

		Assignment5(string filename){
			this->filename = filename;
			this->inputData = readInputFromFile();
			this->grammar = formGrammarFromInputData();
		}

		list<string> readInputFromFile(){
			list<string> inputData;
			string data;
			ifstream myReader(this->filename);

			while (getline (myReader, data)) {
  				inputData.push_back(data);
			}

			myReader.close();

			// list<string>::iterator it;
    		// for (it = inputData.begin(); it != inputData.end(); ++it){
    		// 	cout << *it << "\n";
    		// }
			
			return inputData;
		}

		unordered_map<string, list<string>> formGrammarFromInputData(){
			unordered_map<string, list<string>> grammar;

			bool isNextWordVariable = false;
			string currentVariableName = "";
			string production = "";

			for (auto itr: this->inputData){
				if(itr.compare("{") == 0){
					isNextWordVariable = true;
				}
				else if(isNextWordVariable){
					list<string> productions;
					grammar[itr] = productions;
					currentVariableName = itr;
					isNextWordVariable = false;
				}
				else if(itr.compare(";") == 0){
					list<string> productions = grammar.at(currentVariableName);
					productions.push_back(production);
					production = "";
				}
				else if(itr.compare("}") != 0){
					if(production.compare("") != 0) production += " ";
					production += itr;
				}
			}

			return grammar;
		}

		string randomSentence(){
			return randomSentence("<start>");
		}

		string randomSentence(string variable){
			list<string> productions = this->grammar.at(variable);
			cout << "Hello";
			list<string>::iterator it;
    		for (it = productions.begin(); it != productions.end(); ++it){
    			cout << *it << "\n";
    		}
			// int value = 0;
			// for(auto itr: productions){
			// 	if(value == 0){
			// 		cout << "Hello";
			// 		string sentence = "";
			// 		stringstream ss(itr);
			// 		string word;
			// 		while(ss >> word){
			// 			sentence += word;
			// 			sentence += " ";
			// 		}
			// 		return sentence;
			// 	}
			// 	value--;
			// }
			return "";
		}

};

int main(){
	Assignment5 asg("Grammar.txt");
	cout << asg.randomSentence();
}

	public String randomSentence(String variable){

		ArrayList<String> productions = this.grammar.get(variable);
		Random random = new Random();
		String production = productions.get(random.nextInt(productions.size()));
		String[] productionParts = production.split(" ");

		String sentence = "";
		for(int i = 0;i < productionParts.length;i++){
			if(this.grammar.containsKey(productionParts[i])){
				sentence += randomSentence(productionParts[i]);
			}
			else{
				sentence += productionParts[i];
			}
			if(i != productionParts.length - 1) sentence += " ";
		}
		return sentence;
	}