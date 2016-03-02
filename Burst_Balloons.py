lass Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size = len(nums)
        if size == 1:
            return nums[0]
        nums.insert(size,1)
        nums.insert(0,1)
        
        max_coins_array = [[ 0 for i in xrange(size+2)] for j in xrange(size+2)]
        
        for lens in xrange(1, size+1):
            for start in xrange(1, size+2-lens):
                end = start + lens - 1
                max_coins = 0
                for index in xrange(start, end + 1):
                    temp_max_coins = max_coins_array[start][index-1] + max_coins_array[index+1][end] + nums[start-1]*nums[index]*nums[end+1]
                    if temp_max_coins > max_coins:
                        max_coins = temp_max_coins
                max_coins_array[start][end] = max_coins
        
        return max_coins_array[1][size]
