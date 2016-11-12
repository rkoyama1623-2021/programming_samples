# -*- coding: utf-8 -*-
import sys

def main(name, age=None):
    """Greeting function.
    check `here for detail <http://thomas-cokelaer.info/tutorials/sphinx/docstring_python.html>`_

    .. function:: main.main(name, age = None)

    :param name: Your name.
    :param age: Youre age. (option)

    :param arg1: description
    :param arg2: description
    :type arg1: type description
    :type arg1: type description
    :return: return description
    :rtype: the return type description

    """
    print "hello, " + name

    if age is not None:
        print "You are " + age
