class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        ugly_array = [0 for i in xrange(n)]
        ugly_array[0] = 1
        t2 = t3 = t5 = 0
        index = 1
        while index < n:
            ugly_array[index] = min(ugly_array[t2] * 2, min(ugly_array[t3]*3, ugly_array[t5] * 5))
            if ugly_array[index] == ugly_array[t2] * 2:
                t2 += 1
            if ugly_array[index] == ugly_array[t3] * 3:
                t3 += 1
            if ugly_array[index] == ugly_array[t5] * 5:
                t5 += 1
            index += 1
        return ugly_array[index - 1]
        
