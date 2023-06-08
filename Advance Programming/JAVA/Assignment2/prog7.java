/*
7. Take a String input that contains multiple words. Do the following: 
i) number of times 'a' appears 
ii) number of times "and" appears 
iii) whether it starts with "The" or not 
iv) put the String into an array of characters
v) display the tokens in the String (tokens are the substrings separated by space or @ or.) 
*/
import java.util.Scanner;
class manStr{
    private String str;
    private String tokens[];
    private char[]characters;
    
    public manStr(String str,String splitter){
        this.str = str;
        String tempStr = this.str.toLowerCase();
        this.tokens = tempStr.split(splitter);
    }
    void setStr(String str){
        this.str = str;
    }
    String getStr(){
        return this.str;
    }
    void show(){
        System.out.println("String is :"+this.str);
    }

    int aCount(){
        int count=0;
        String tempStr = this.str.toLowerCase();
        this.characters = tempStr.toCharArray();
        for(char c : characters)
        if(c == 'a')
            count++;
        return count;
    }

    void showTokens(){
        for(String s :tokens){
            System.out.print(s+" ");
        }
        System.out.println();
    }

    int andCount(){
        int count=0;
        // int i=0;
        // while(i<str.length()-2){
        //     char x = str.charAt(i);
        //     char y = str.charAt(i+1);
        //     char z = str.charAt(i+2);

        //     if(x == ' ' || y ==' ' || z == ' '){
        //         i++;
        //         continue;
        //     }
        //     if(x=='a' && y=='n' && z == 'd'){
        //         count++;
        //     }
        //     i++;
        // }
        for(String s : this.tokens){
            if(s.equals("and")) count++;
        }
        return count;
    }
    boolean stWithThe(){
        if(!tokens[0].equals("the"))
            return false;
        return true;
    }
    void showArrayOfChar(){
        System.out.println("Char Array of the given input :");
        // System.out.println("["+characters+"]");
        for(char x:characters)
            System.out.print(x+" ");
        System.out.println();

    }
}
class prog7 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String string ,splitter;


        System.out.println("Enter the input string : ");
        string = input.nextLine();
        System.out.println("Mention the Splitter :");
        splitter = input.nextLine();


        manStr S1 = new manStr(string , splitter);
        S1.show();
        System.out.println("Number of A's in the input string is : "+S1.aCount());
        System.out.println("Number of 'and's found in the input string is: " + S1.andCount());
        System.out.print("Checking starts with the or not : ");
        if(S1.stWithThe())
            System.out.println("Yes");
        else
            System.out.println("No");
        S1.showArrayOfChar();
        S1.showTokens();
        input.close();
    }
}