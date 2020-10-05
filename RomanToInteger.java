public class Solution {
    public int romanToInt(String s) {
        if (s == null || s.isEmpty()) return 0;
         
        int i = 0;
        int num = 0;
        while (i < s.length()) {
            if (i <= s.length() - 2 && s.charAt(i) == 'I' && s.charAt(i + 1) == 'V') {
                num += 4;
                i += 2;
            } else if (i <= s.length() - 2 && s.charAt(i) == 'X' && s.charAt(i + 1) == 'L') {
                num += 40;
                i += 2;
            } else if (i <= s.length() - 2 && s.charAt(i) == 'C' && s.charAt(i + 1) == 'D') {
                num += 400;
                i += 2;
            } else if (i <= s.length() - 2 && s.charAt(i) == 'I' && s.charAt(i + 1) == 'X') {
                num += 9;
                i += 2;
            } else if (i <= s.length() - 2 && s.charAt(i) == 'X' && s.charAt(i + 1) == 'C') {
                num += 90;
                i += 2;
            } else if (i <= s.length() - 2 && s.charAt(i) == 'C' && s.charAt(i + 1) == 'M') {
                num += 900;
                i += 2;
            } else {
                num += toInteger(s.charAt(i));
                i++;
            }
        }
        return num;
    }
     
    private int toInteger(char roman) {
        int num = 0;
        switch(roman) {
            case 'I': num = 1;
                      break;
            case 'V': num = 5;
                      break;
            case 'X': num = 10;
                      break;
            case 'L': num = 50;
                      break;
            case 'C': num = 100;
                      break;
            case 'D': num = 500;
                      break;
            case 'M': num = 1000;
                      break;
        }
        return num;
    }
}