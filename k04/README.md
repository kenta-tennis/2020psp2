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
bb35319024@DESKTOP-N8LSJ1E MINGW64 ~/Desktop/2020psp2/k04 (master)
$ ./k04.exe
input the filename of sample heights ?:C:\Users\bb35319024\Desktop\2020psp2\sample\heights.csv
the filename of sample heights: C:\Users\bb35319024\Desktop\2020psp2\sample\heights.csv
input the filename of sample ID ?:C:\Users\bb35319024\Desktop\2020psp2\sample\IDs.csv
the filename of sample ID: C:\Users\bb35319024\Desktop\2020psp2\sample\IDs.csv
Which ID's data do you want ?:45313125
---
ID : 45313125
gender : Female
heights : 165.62
```

例えば，ID 45313124のデータを調べたいとき，

```
（ここに結果をコピペしてね）
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴

[comment #20200721 sonoda]

```
sample[a-1].gender = g;
```

というのが`white`ループの中にありますが，ループ初回では`a-1`は`-1`ではありませんか？それはまずいです．これがファイルクローズエラーの原因かも．

- 上の`a`もそうですが，いろんな変数名が1文字なのはやめましょう．どんな変数なのかわかるような名前にしてください．

[comment #20200722 sonoda]
- (k04.c#L30) `if(fp = NULL)`では，fpにNULLが代入されてしまいます．`if(fp == NULL)`ではないでしょうか．
- `int num = 15;`としていますが，15って何ですか．意味不明です．人数は14人です．
- 各ループの最終回で配列の四角カッコの中の数字はどうなっていますか？定義した個数を超えてはいませんか？

[comment #20200729 sonoda]
- レポートの入出力例を整理しました．答えが間違っています．
  https://github.com/kenta-tennis/2020psp2#%E6%BC%94%E7%BF%92%E8%AA%B2%E9%A1%8C
  を見ると，IDが45313125の女性の身長は152.4です．

[comment #20200731 sonoda]
- ```
  int num = 14;
  struct data sample[num];
  ```
  としているので，`sample`の配列の要素数は14個ですが，`sample[0]` ~　`sample[13]`で14個です．`sample[14]`は存在しません．
  
  しかし，while文の中で値が代入される先の`sample[a]`は`a=a+1;`しているから`sample[1]`~`sample[14]`になっています．`a=a+1;`が無ければ`sample[0]` ~　`sample[13]`です．
  
  確保されていないメモリ領域を使おうとすると，バグります．
  
- というわけで，ためしに，`int num = 20;`などと余裕を持たせた上で，データを2つのファイルから読み取り終えたあとに，
  ```
  for (a=0; a< 20; a++){
    printf("[%d] ID:%d, gender:%d, height:%lf\n, a, sample[a].ID, sample[a].gender, sample[a].heights);
  }
  ```
  を追加して，構造体の中身を確認してみてください．
  
  https://github.com/kenta-tennis/2020psp2#%E6%BC%94%E7%BF%92%E8%AA%B2%E9%A1%8C
  
  と比べてみて，ずれていませんか？
  
  また，後ろのほうは与えられたデータが入っていないと思いますが，データが入っている配列の要素番号`a`が後ろに続くID探索のときの`j`の範囲を超えていませんか？
- ずれの原因は，heights.csvの1行目はデータが書かれておらず，2行目からデータが書かれているからです．1行目も取り込んでしまっているからです．
　heights.csvを読むwhile文の直前に，`fgets(buf,sizeof(buf),fp);`を追加すると，この部分で空読み（読んだものは使われない）になってくれます．
 
- 後ろのほうのIDを探索するfor文の中の j と n　の働きがよくわかりません．説明を加えてください．
