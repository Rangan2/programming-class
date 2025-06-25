class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        similarity_counter =  defaultdict(list)
        for input_str in strs:
            temp_str = ""
            temp_str = str(sorted(input_str))
            similarity_counter[temp_str].append(input_str)
        empty_list = []      
        for key,val in similarity_counter.items():
            empty_list.append(val)
        return empty_list