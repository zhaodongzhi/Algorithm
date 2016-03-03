/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    
        int diff = 0;
        for (int i = 0; i < numsSize; ++i) {
            diff ^= nums[i];
        }

        diff &= -diff;

        *returnSize = 2;
        int* ret = (int*)malloc(2*sizeof(int));
        ret[0] = 0;
        ret[1] = 0;
        
        for (int i = 0; i < numsSize; ++i)
        {
            if ((nums[i] & diff) == 0) 
            {
                ret[1] ^= nums[i];
            }
            else
            {
                ret[0] ^= nums[i];
            }
        }
        return ret;
}
