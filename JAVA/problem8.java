import java.util.Stack;

public class problem8 {
    public static boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stack.isEmpty() || !isMatchingPair(stack.pop(), c)) {
                    return false;
                }
            }
        }
        
        return stack.isEmpty();
    }
    
    private static boolean isMatchingPair(char opening, char closing) {
        return (opening == '(' && closing == ')')
                || (opening == '{' && closing == '}')
                || (opening == '[' && closing == ']');
    }

    public static void main(String[] args) {
        String input = "(({}))";
        boolean output = isValid(input);
        System.out.println(output);
    }
}
