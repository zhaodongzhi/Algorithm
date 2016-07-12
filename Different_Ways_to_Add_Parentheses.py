class Solution:
    # @param {string} input
    # @return {integer[]}
    def diffWaysToCompute(self, input):
        result = []
        if "*" not in input and "+" not in input and "-" not in input:
            result.append(int(input))
        else:
            for i in xrange(len(input)):
                if input[i] == "*":
                    for left in self.diffWaysToCompute(input[:i]):
                        for right in self.diffWaysToCompute(input[i+1:]):
                            result.append(left * right)
                elif input[i] == "+":
                    for left in self.diffWaysToCompute(input[:i]):
                        for right in self.diffWaysToCompute(input[i+1:]):
                            result.append(left + right)
                elif input[i] == "-":
                    for left in self.diffWaysToCompute(input[:i]):
                        for right in self.diffWaysToCompute(input[i+1:]):
                            result.append(left - right)
        return result
            
        
