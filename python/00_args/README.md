# args in python
You can give python function in several way.
you can view the sample as follows:
```
python args.py
```

## type of argument

```python
def apply_test(normal, default=1, *args, **kwargs):
    print "normal:" , normal
    print "default:", default
    print "args:", args
    print "kwargs:", kwargs
```

In this function,
1. `normal` is standard argument.
1. `default` is default argument.
1. `args` is variable-length argument.
1. `kwargs` is variable-length keyward argument.

You must put these arguments in this order.

## way of giving arguments
Following results are all the same.
```
apply_test(1,2,3,4,kwargs=5)
apply_test(*[1,2,3,4],kwargs=5)
apply_test(1,2,3,4,**{'kwargs':5})
apply_test(*[1,2,3,4],**{'kwargs':5})
```
