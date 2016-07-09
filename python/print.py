print "hoge","fuga"
print ("hoge"+" "+"fuga")

print "%s %s" % ("hoge","fuga")

print "{0} {1}".format("hoge","fuga")
l=["hoge","fuga"]
print "{0} {1}".format(*l)

print "{a} {b}".format(a="hoge",b="fuga")
d={"a":"hoge","b":"fuga"}
print "{a} {b}".format(**d)


class my_data:
    def __init__(self, a, b):
        self.a = a
        self.b = b
d = my_data('hoge', 'fuga')
print "{0.a} {0.b}".format(d)



