# Better solution:
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        
        out = []
        for i in sorted(intervals, key=lambda i: i.start):
            if out and i.start <= out[-1].end: # take care of first element
                                               # take care of merge/update end
                out[-1].end = max(out[-1].end, i.end)
            else:
                out.append(i)
        return out

# My solution:
# class Solution(object):
#     def merge(self, intervals):
#         """
#         :type intervals: List[Interval]
#         :rtype: List[Interval]
#         """
#         s_int = sorted(intervals, key=lambda x: x.start)
#         start, end, length, res = 0, 0, len(s_int), []
        
#         while end + 1 < length:
#             if s_int[end + 1].start > s_int[end].end:
#                 res.append([s_int[start].start, s_int[end].end])
#                 start = end = end + 1
                
#             elif s_int[end + 1].start <= s_int[end].end:
#                 if s_int[end + 1].end < s_int[end].end:
#                     s_int[end + 1].end = s_int[end].end
#                 end += 1
        
#         if s_int: res.append([s_int[start].start, s_int[end].end])
#         return res