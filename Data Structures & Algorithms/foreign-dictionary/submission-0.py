class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        adj_set = {char: set() for word in words for char in word}
        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i+1]
            min_len = min(len(w1), len(w2))
            if len(w1) > len(w2) and w1[:min_len] == w2[:min_len]:
                return ""
            for ci in range(min_len):
                if w1[ci] != w2[ci]:
                    adj_set[w1[ci]].add(w2[ci])
                    break
        
        top_order: list[str] = []
        visited: list[str] = [''] * 26
        def dfs(char: str) -> bool:
            char_idx: int = ord(char) - 97
            if visited[char_idx] == 'v':
                return True
            if visited[char_idx] == 'c':
                return False

            visited[char_idx] = 'c'
            
            for adj_char in adj_set[char]:
                if not dfs(adj_char):
                    return False

            top_order.append(char)
            visited[char_idx] = 'v'
            return True

        for char in adj_set.keys():
            if not dfs(char):
                return ""
        return ''.join(reversed(top_order))