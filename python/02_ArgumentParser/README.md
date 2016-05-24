# bash completion with python

## dependancies
[argcomplete](https://argcomplete.readthedocs.io/en/latest/)

```
pip install argcomplete
activate-global-python-argcomplete
```
## how to use
first, make python script usig `argparse` package.
second, add following code.
```
import argcomplete, argparse
parser = argparse.ArgumentParser()
...
argcomplete.autocomplete(parser)
```
Then bash setting.
All you have to do is to execute following command in bash.

```
eval "$(register-python-argcomplete tab_completion.py)"
```

(`tab_completion.py` must be in directory in ${PATH})
