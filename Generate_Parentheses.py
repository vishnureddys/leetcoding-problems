# Given n pairs of parentheses, write a function to
# generate all combinations of well-formed parentheses.


class Solution:
      def generateParenthesis(self, n: int) -> List[str]:
        final_list = []
        parenthesis_stack = [(n , n, [])]
        
        while parenthesis_stack:
            open_parens, close_parens, buffer = parenthesis_stack.pop()
            if open_parens == 0 and close_parens == 0:
                final_list.append("".join(buffer))
                
            if open_parens > 0:
                buffer.append("(")
                parenthesis_stack.append((open_parens - 1, close_parens, buffer.copy()))
                buffer.pop()
                
            if open_parens < close_parens:
                buffer.append(")")
                parenthesis_stack.append((open_parens, close_parens - 1, buffer.copy()))
        
        
        return final_list