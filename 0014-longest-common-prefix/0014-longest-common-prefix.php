<?php
class Solution {

/**
 * @param String[] $strs
 * @return String
 */
function longestCommonPrefix($strs) {
    if (empty($strs)) return "";

    // Take the first string as reference
    $prefix = $strs[0];

    // Compare with every other string
    for ($i = 1; $i < count($strs); $i++) {
        $current = $strs[$i];
        $j = 0;

        // Compare characters until mismatch
        while ($j < strlen($prefix) && $j < strlen($current) && $prefix[$j] === $current[$j]) {
            $j++;
        }

        // Trim prefix to the matched part
        $prefix = substr($prefix, 0, $j);

        // If prefix becomes empty, no common prefix exists
        if ($prefix === "") return "";
    }

    return $prefix;
}
}
?>
