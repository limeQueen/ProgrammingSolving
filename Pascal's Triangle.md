[문제링크](https://leetcode.com/problems/pascals-triangle/description/)
```python
class Solution(object):
    def generate(self, numRows):
        ret = []

        if numRows >= 1:
            ret.append([1])
        if numRows >= 2:
            ret.append([1, 1])
        if numRows > 2:
            for l in range(2, numRows):
                row = [1]
                for idx in range(1, l):
                    row.append(ret[l-1][idx-1] + ret[l-1][idx])
                row.append(1)
                ret.append(row)

        return ret
```
> 새롭게 알게 된 것

python에서는 2차원 배열을 생성하든 1차원 배열을 생성하든 상관없이 빈 리스트를 지정하면 된다.   
```arr = []``` 한 다음 ```append()```로 하나씩 넣자!
