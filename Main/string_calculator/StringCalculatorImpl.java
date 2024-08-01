package string_calculator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.util.List;


public class StringCalculatorImpl implements string_calculator {
	
	 @Override
	    public int add(String numbers) {
	        if (numbers.isEmpty()) {
	            return 0;
	        }
	        if (numbers.length() == 1 && Character.isDigit(numbers.charAt(0))) {
	            return Character.getNumericValue(numbers.charAt(0));
	        }

	        checkNegative(numbers);
	        String[] extractedNumbers = getTokens(numbers);
	        int sum = 0;
	        for (String token : extractedNumbers) {
	            if (!token.isEmpty()) {
	                try {
	                    int num = Integer.parseInt(token);
	                    if (num <= 1000) {
	                        sum += num;
	                    }
	                } catch (NumberFormatException e) {
	                    throw new IllegalArgumentException("Invalid input: " + token);
	                }
	            }
	        }
	        return sum;
	    }

	    @Override
	    public void checkNegative(String numbers) {
	    	
	    	 Pattern pattern = Pattern.compile("-\\d+");
	    	 Matcher matcher = pattern.matcher(numbers);
	    	  
	    	 List<String> negativeNumbers = new ArrayList<>();
	    	    
	    	 while (matcher.find()) {
	    	        negativeNumbers.add(matcher.group());
	    	    }

	   
	         if (!negativeNumbers.isEmpty()) {
	            StringBuilder msg = new StringBuilder("negative numbers not allowed ");
	            for (int i = 0; i < negativeNumbers.size(); i++) {
	                msg.append(negativeNumbers.get(i));
	                if (i < negativeNumbers.size() - 1) {
	                    msg.append(",");
	                }
	            }
	            throw new IllegalArgumentException(msg.toString());
	        }
	    }

	    @Override
	    public String[] getTokens(String numbers) {
	    	
	    	if(numbers.startsWith("//"))
	    	{
	    			
	    	String[] parts = numbers.split("\n",2);
	    	
	        String delimiters = ",";
	        delimiters = parts[0].substring(2).replace("][", ",").replace("[", "").replace("]", "");
	        parts[0] = "";
	        

	        
	        String userNumbers = parts[1].replaceAll("[" + delimiters + "]", ",");
	        
	        String[] tokens = userNumbers.split("," + "|\n");
	        return tokens;
	    	}
	    	
	        String[] tokens = numbers.split("," + "|\n");
	        return tokens;
	    	    
	    }

}

    
