[문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/12916?language=python3)

```python
def solution(s):
    pcnt = 0
    ycnt = 0

    for e in s:
        if e == 'p' or e == 'P':
            pcnt += 1
        if e == 'y' or e == 'Y':
            ycnt += 1
    
    return pcnt == ycnt
```
