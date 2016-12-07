[source](http://qiita.com/termoshtt/items/0103803c40331c77c727)

install [https://github.com/boostorg/boost](https://github.com/boostorg/boost)

```bash
git clone --recursive git@github.com:boostorg/boost.git
cd boost
./bootstrap.sh
./b2 toolset=gcc link=static,shared address-model=64 --with-python install -j 8
```
