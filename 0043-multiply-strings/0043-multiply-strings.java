class Solution {
    public String multiply(String num1, String num2) {
        // If either number is 0, the product is 0
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }

        int n1 = num1.length();
        int n2 = num2.length();
        int[] result = new int[n1 + n2];

        // Multiply each digit from num1 and num2
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int digit1 = num1.charAt(i) - '0';
                int digit2 = num2.charAt(j) - '0';
                int mul = digit1 * digit2;

                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;          // store the last digit
                result[i + j] += sum / 10;             // carry
            }
        }

        // Convert result array to string, skipping leading zeros
        StringBuilder sb = new StringBuilder();
        for (int num : result) {
            if (!(sb.length() == 0 && num == 0)) { // skip leading zeros
                sb.append(num);
            }
        }

        return sb.toString();
    }
}
