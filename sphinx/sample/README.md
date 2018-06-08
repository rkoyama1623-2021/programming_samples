http://qiita.com/Arvelt/items/45428c5f9661cec3f513

# make project
sphinx-apidoc -F -o ./documents_source ./src

# configure

`documents_source/conf.py`

```python
#sys.path.insert(0, os.path.abspath('.'))
sys.path.insert(0, os.path.abspath('../src'))
```
# update
sphinx-apidoc -f -o ./documents_source ./src

# publish
sphinx-build -a ./documents_source ./publish

