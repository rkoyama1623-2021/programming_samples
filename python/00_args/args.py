# define function
print """
def apply_test(normal, default=1, *args, **kwargs):
    print "normal:" , normal
    print "default:", default
    print "args:", args
    print "kwargs:", kwargs
"""
def apply_test(normal, default=1, *args, **kwargs):
    print "normal:" , normal
    print "default:", default
    print "args:", args
    print "kwargs:", kwargs
print "args = [1, 2, 3, 4]"

# try giving args to function in several way.
args = [1, 2, 3, 4]
print ""

# 1
print "1. give args in standard way"
print ">>> apply_test(1,2,3,4)"
apply_test(1,2,3,4)

print ""

# 2
print "2. give args in list"
print "apply_test(*args) is equivalent to apply_test(1,2,3,4)"
print ">>> apply_test(*args)"
apply_test(*args)

print ""

# 3.
print "3. give keyward args in dictionary"
print ">>> kwargs = {'default': 5, 'etc': 100}"
kwargs = {'default': 5, 'etc': 100}
print "apply_test(1, **kwargs) is equivalent to apply_test(1,default=5,etc=100)"
print ">>> apply_test(1, **kwargs)"
apply_test(1, **kwargs)
