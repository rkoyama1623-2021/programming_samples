# logging
プログラム実行中の記録を取る。

記録の内容を、displayとfileの両方に出力したり、記録内容の重要度が高いものだけdisplayに表示し、重要度の低い情報はファイルに出力するだけなどといった設定ができる。

default では、debug,info,warning,error,criticalの５段階のレベルが用意されていて、どの程度重要度の低い情報まで記録するかを設定できる。

例えば、`logger=logging.getLogger()`のlevelが`logging.INFO`の場合、より優先度の低い`logger.DEBUG`の情報は取得されない。

`logger`は、階層構造にでき、`logging.handle`を追加すると、`logging.handle.level`以上の重要度の情報が`handloer`に渡される。

