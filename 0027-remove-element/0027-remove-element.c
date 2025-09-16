int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // index to place the next element not equal to val
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i]; // move element forward
            k++;
        }
    }
    return k;
}
