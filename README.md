# 42cursus-ft_printf

## 日本語
### 概要
*  メモリーリーク厳禁!!
* c言語の printf関数を自分で実装する。

### 対応している設定
* 精度とフィールド幅
* フラグ ("-", "0", "#")
* いくつか未定義処理(main.c参照)
* フォーマット("%d", "%i" , "%c", "%s","%u", "%o", "%p", "%x", "%X", "%") 

※ 自分が考慮しているケースは、ある程度は、main.cにまとめている。

### コンパイル方法
1. Makefileのディレクトリで make all コマンドを行う。
2. libftprintf.aが作成される。
3. gcc -Wall -Wextra -Werror main.c libftprintf.a
4. ./a.outをすると、main.cのケースが標準と比較されながら、標準出力される。

## English
### Summary
* Strictly no memory leaks!
* Implement the printf function of c language by yourself.

### Supported settings.
* Precision and field width.
* Flags ("-", "0", "#").
* Some undefined processing (see main.c)
* Format ("%d", "%i", "%c", "%s", "%u", "%o", "%p", "%x", "%X", "%") 

* The cases I am considering are summarized in main.c to some extent.

### How to compile.
1. make all command in the Makefile directory. 2.
2. libftprintf.a will be created. 3.
3. gcc -Wall -Wextra -Werror main.c libftprintf.a 4. .
4. . /a.out, the case of main.c will be compared with the standard and printed to the standard output.
