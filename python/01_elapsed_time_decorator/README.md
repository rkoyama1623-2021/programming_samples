# check elapsed time by decorator
In python, you can check elapsed time using decorator.

You can ran `check_elapsed_time.py` by as follows.
```
python check_elapsed_time.py
```

You can check how long your function took time.

## About Decorator
The code:
```
@elapsedTime
def sampleCode():
    hoge=[]
    for i in range(10**7):
        hoge.append(1)
    return hoge
```
is equivalent to

```python
def _sampleCode():
    hoge=[]
    for i in range(10**7):
        hoge.append(1)
    return hoge
def sampleCode():
    elapsedTime(_sampleCode)
```
