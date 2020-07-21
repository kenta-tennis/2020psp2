# 課題4 レポート

bb35319024 篠隈健太

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明

6: ID、性別、身長の構造体sampleを宣言

80~103: 必要なIDを聞いてそれが構造体sampleにあればそのIDと性別、身長を出力

106: なければ"No data"と出力

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```
bb35319024@DESKTOP-N8LSJ1E MINGW64 ~/Desktop/2020psp2/k04 (master)
$ ./k04.exe
input the filename of sample heights ?:C:\Users\bb35319024\Desktop\2020psp2\sample\heights.csv
the filename of sample heights: C:\Users\bb35319024\Desktop\2020psp2\sample\heights.csv
file close error

## 修正履歴

[comment #20200721 sonoda]

```
sample[a-1].gender = g;
```

というのが`white`ループの中にありますが，ループ初回では`a-1`は`-1`ではありませんか？それはまずいです．これがファイルクローズエラーの原因かも．

- 上の`a`もそうですが，いろんな変数名が1文字なのはやめましょう．どんな変数なのかわかるような名前にしてください．

