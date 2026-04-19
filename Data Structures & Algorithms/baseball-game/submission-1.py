class Solution:
    def calPoints(self, operations: List[str]) -> int:
        stack: list[int] = []
        for op in operations:
            if op == '+' and len(stack) > 1:
                stack.append(stack[-1] + stack[-2])
            elif op == 'D' and len(stack):
                stack.append(stack[-1] * 2)
            elif op == 'C' and len(stack):
                stack.pop()
            else:
                try:
                    stack.append(int(op))
                except ValueError:
                    pass
        return sum(stack)