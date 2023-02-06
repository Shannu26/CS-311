import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.HashMap;
import java.util.Arrays;

class Assignment1{
	public static void main(String args[]){
		Scanner reader = new Scanner(System.in);
		System.out.print("Enter the file name: ");
		String fileName = reader.next();
		ArrayList<String> input = readInputFromFile(fileName);
		tokenizeAndPrintOutput(input);
	}

	private static ArrayList<String> readInputFromFile(String fileName){
		ArrayList<String> input = new ArrayList<String>();
		
		try {
      		File inputFile = new File(fileName);
      		Scanner reader = new Scanner(inputFile);
      		while (reader.hasNextLine()) {
        		String data = reader.nextLine();
        		for(String s: data.split(" ")){
        			s = s.trim();
        			input.add(s.toLowerCase());
        		}
      		}
      		reader.close();
    	} 
    	catch (FileNotFoundException e) {
      		System.out.println("An error occurred.");
      		e.printStackTrace();
    	}
    	return input;
	}

	public static void tokenizeAndPrintOutput(ArrayList<String> input){
		String[] keywordArray = {"if", "else", "while", "for"};
		HashSet<String> keywords = new HashSet<String>(Arrays.asList(keywordArray));
		String[] specialArray = {"(", ")", "[", "]", "+", "-", "/", "*", ";", "=", "==", "<", ">", "<=", ">=", "{", "}"};
		HashSet<String> specials = new HashSet<String>(Arrays.asList(specialArray));
		String[] dataTypeArray = {"int", "char", "float", "double"};
		HashSet<String> dataTypes = new HashSet<String>(Arrays.asList(dataTypeArray));

		HashMap<String, ArrayList<Object>> tokensCount = new HashMap<String, ArrayList<Object>>();

		for(String s: input){
			if(tokensCount.containsKey(s)){
				ArrayList<Object> tokenInfo = tokensCount.get(s);
				tokenInfo.set(0, (int) tokenInfo.get(0) + 1);
			}
			else{
				ArrayList<Object> tokenInfo = new ArrayList<Object>();
				tokenInfo.add(1);
				if(keywords.contains(s)){
					tokenInfo.add("Keyword");
				}
				else if(specials.contains(s)){
					tokenInfo.add("Special Char");
				}
				else if(dataTypes.contains(s)){
					tokenInfo.add("Data Type");
				}
				else if(s.chars().allMatch(Character::isDigit)){
					tokenInfo.add("Number");
				}
				else{
					tokenInfo.add("Identifier");
				}
				tokensCount.put(s, tokenInfo);
			}
		}

		for(HashMap.Entry<String, ArrayList<Object>> entry: tokensCount.entrySet()){
			String token = entry.getKey();
			ArrayList<Object> tokenInfo = entry.getValue();
			System.out.println(token + " " + tokenInfo.get(0) + " " + tokenInfo.get(1));
		}
	}
}