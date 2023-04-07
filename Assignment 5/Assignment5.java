import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;

import java.io.File;  
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Assignment5{
	String fileName;
	ArrayList<String> inputData;
	HashMap<String, ArrayList<String>> grammar;

	public Assignment5(String fileName){
		this.fileName = fileName;
		this.inputData = readInputFromFile();
		this.grammar = formGrammarFromInputData();
	}

	public ArrayList<String> readInputFromFile(){
		ArrayList<String> inputData = new ArrayList<String>();
		try{
			File file = new File(this.fileName);
			Scanner myReader = new Scanner(file);
			while(myReader.hasNextLine()){
				String data = myReader.nextLine();
	        	inputData.add(data);
      		}
      		myReader.close();
		}
		catch(FileNotFoundException e) {
			System.out.println("An error occurred.");
      		e.printStackTrace();
		}
		return inputData;
	}

	public HashMap<String, ArrayList<String>> formGrammarFromInputData(){
		HashMap<String, ArrayList<String>> grammar = new HashMap<String, ArrayList<String>>();

		boolean isNextWordVariable = false;
		String currentVariableName = "";
		String production = "";
		for(int i = 0;i < this.inputData.size();i++){
			if(this.inputData.get(i).equals("{")){
				isNextWordVariable = true;
			}
			else if(isNextWordVariable){
				ArrayList<String> productions = new ArrayList<String>();
				grammar.put(this.inputData.get(i), productions);
				currentVariableName = inputData.get(i);
				isNextWordVariable = false;
			}
			else if(this.inputData.get(i).equals(";")){
				ArrayList<String> productions = grammar.get(currentVariableName);
				productions.add(production);
				production = "";
			}
			else if(!this.inputData.get(i).equals("}")){
				production += " " + this.inputData.get(i);
			}
		}

		return grammar;
	}

	public String randomSentence(){
		return randomSentence("<start>");
	}

	public String randomSentence(String variable){
		return variable;
	}

	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the Grammar File Name: ");
		String fileName = s.next();

		Assignment5 rsg = new Assignment5(fileName);
		rsg.randomSentence();

		for(HashMap.Entry<String,ArrayList<String>> entry : rsg.grammar.entrySet()){
			String variable = entry.getKey();
			System.out.println(variable);
			ArrayList<String> productions = entry.getValue();
			for(int i = 0;i < productions.size();i++){
				System.out.println(productions.get(i));
			}
			System.out.println();
		}
	}
}