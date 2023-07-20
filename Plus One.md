[문제링크](https://leetcode.com/problems/plus-one/description/)

carry가 있는 경우, 없는 경우, 자릿 수가 늘어나는 경우를 잘 처리해주면 된다.
```python
class Solution(object):
    def plusOne(self, digits):
        length = len(digits)
        carry = 1

        for i in reversed(range(length)):
            if digits[i] + carry <= 9:
                digits[i] += carry
                carry = 0
            else:
                digits[i] = 0
                carry = 1
        
        if carry:
            digits.insert(0, 1)

        return digits
```
