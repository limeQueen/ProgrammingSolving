[문제링크](https://leetcode.com/problems/assign-cookies/description/)

처음에는 python 특성상 for문에 조건문을 달 수가 없어 어떻게 푸나 했는데 while문으로 풀면 되는 거였다..!   
   
g와 s를 모두 오름차순으로 정렬하여 ```s[j] >= g[i]``` 일 때만 ```i+=1``` 하면 최대한 많은 아이를 만족시킬 수 있다.   
```python
class Solution(object):
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()

        i = 0
        j = 0
        ans = 0
        
        while i < len(g) and j < len(s):
            if s[j] >= g[i]:
                ans += 1
                i += 1
            j += 1
            
        return ans
```
