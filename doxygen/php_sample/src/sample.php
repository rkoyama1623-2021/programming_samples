<?php
/**
 ** @mainpage
 ** Doxygen説明用ソースコード
 */
 
/**
 ** @file Arithmetic.php
 ** @brief 四則演算関連の処理を集めたファイル
 */
 
/**
 ** @四則演算を行うクラス
 */
class Arithmetic
{
    /** 計算を何回行ったか */
    public $count = 0;
 
    /**
     ** @brief 足し算を行う関数
     ** @param x 項1
     ** @param y 項2
     ** @return xとyを足した結果
     */
    public function add($x, $y) {
        $this->count++;
        return($x + $y);
    }
}
 
/**
 ** @brief Arithmeticを継承したクラス<br>
 ** 説明用なので作成しただけ
 */
class ArithmeticPlus extends Arithmetic
{
}