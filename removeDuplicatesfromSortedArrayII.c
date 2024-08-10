int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize <= 2) 
        return numsSize;

    int uniq_i = 2;
    
    for (int i = 2; i < numsSize; i++)
    {
        if (nums[i] != nums[uniq_i - 2])
        {
            nums[uniq_i] = nums[i];
            uniq_i++;
        }
    }
    return uniq_i;
}
