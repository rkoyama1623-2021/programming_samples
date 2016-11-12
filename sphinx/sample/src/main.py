# -*- coding: utf-8 -*-
import sys

def main(name, age=None):
    """Greeting function.

    :param name: Your name.
    :param age: Youre age. (option)
    """
    print "hello, " + name

    if age is not None:
        print "You are " + age
