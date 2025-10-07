class Solution {
    public int lengthOfLastWord(String s) {
        // Trim the string to remove leading and trailing spaces
        s = s.trim();
        
        // Find the last space in the trimmed string
        int lastSpaceIndex = s.lastIndexOf(' ');
        
        // The length of the last word is total length - index of last space - 1
        return s.length() - lastSpaceIndex - 1;
    }
}
