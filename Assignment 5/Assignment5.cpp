#include <bits/stdc++.h>
#include <cstdlib>
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

		~Assignment5(){
			cout << "Destructing Class Variables\n";
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

			list<string> productions;
			bool isNextWordVariable = false;
			string currentVariableName = "";
			string production = "";

			for (auto itr: this->inputData){
				if(itr.compare("{") == 0){
					isNextWordVariable = true;
				}
				else if(isNextWordVariable){
					currentVariableName = itr;
					isNextWordVariable = false;
				}
				else if(itr.compare(";") == 0){
					productions.push_back(production);
					production = "";
				}
				else if(itr.compare("}") != 0){
					if(production.compare("") != 0) production += " ";
					production += itr;
				}
				else{
					list<string> productionsToAdd;
					for(auto i: productions){
						productionsToAdd.push_back(i);
					}

					grammar[currentVariableName] = productionsToAdd;
					productions.clear();
				}
			}

			return grammar;
		}

		string randomSentence(){
			return randomSentence("<start>");
		}

		string randomSentence(string variable){
			list<string> productions = this->grammar.at(variable);
			
			int value = rand() % productions.size();
			for(auto itr: productions){
				if(value == 0){
					string sentence = "";
					stringstream ss(itr);
					string word;
					while(ss >> word){
						if(this->grammar.find(word) != this->grammar.end()){
							sentence += randomSentence(word);
						}
						else{
							sentence += word;
							sentence += " ";
						}
					}
					return sentence;
				}
				value--;
			}
			return "";
		}

		friend ostream &operator<<(ostream &output, const Assignment5 &asg) { 
        	output << "\nGrammar Definition:\n\n";  
        	for(auto itr: asg.grammar){
        		string variable = itr.first;
        		list<string> productions = itr.second;
        		output << "\tVariable: " << variable << "\n";
        		output << "\tProductions:\n";
        		for(auto it: productions){
        			output << "\t\t" << it << "\n";
        		}
        		output << "\n";
        	}
        	return output;         
      	}

};

int main(){
	srand(time(0));
	string filename;
	cout << "Enter the Grammar File Name: ";
	cin >> filename;
	Assignment5 asg(filename);
	cout << asg;
	cout << "Sentence 1: ";
	cout << asg.randomSentence();
	cout << "\nSentence 2: ";
	cout << asg.randomSentence();
	cout << "\nSentence 3: ";
	cout << asg.randomSentence() << "\n";
}