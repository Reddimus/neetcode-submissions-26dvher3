class Solution:
    def encode(self, strs: list[str]) -> str:
        return ''.join(str(len(s)) + "#" + s for s in strs)

    def decode(self, s: str) -> list[str]:
        strings = []
        i = 0

        while i < len(s):
            # Find string length
            j = i
            while s[j] != '#':
                j += 1
            str_len = int(s[i:j])

            # Append decoded string
            i = j + 1       # Set to start of string
            j = i + str_len # Set to end of string
            strings.append(s[i:j])
            i = j
        
        return strings