#include <stdlib.h>
 
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i;
    int j;
    int *ret_arr = (int *)malloc(2 *sizeof(int));
    
    if(ret_arr == NULL)
    {
        *ret_arr = 0;
        return NULL;
    }
    i = 0;
    while (i < numsSize)
    {
        j = i + 1;
        while (j < numsSize)
        {
            if (nums[i] + nums[j] == target)
            {
                *returnSize = 2;
                ret_arr[0] = i;
                ret_arr[1] = j;
                return ret_arr;
            }
            j++;
        }
        i++;
    }
    *returnSize = 0;
    free(ret_arr);

    return NULL;
}
