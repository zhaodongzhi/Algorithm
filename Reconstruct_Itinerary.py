from collections import defaultdict
class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        addjust_tickets = defaultdict(list)
        for from_addr, to_addr in sorted(tickets)[::-1]:
            addjust_tickets[from_addr] += to_addr,
        result, stack = [], ['JFK']
        while stack:
            while addjust_tickets[stack[-1]]:
                stack += addjust_tickets[stack[-1]].pop(),
            result += stack.pop(),
        return result[::-1]
        
