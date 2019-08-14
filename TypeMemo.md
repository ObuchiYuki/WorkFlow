#  Typeについて



- 全てのタイプは`wf::type::Type`である。
- `Expression`は`returnType: Type`を持つ
- `Type`は`properties`、`methods`、`class`を持つ
- `Type::global: GlobalType` グローバル関数・変数・クラスを格納する
- `static`な値、例えば

```
class Int {
	@static 
	def + (left:Int, right: Int) -> Int {...}
}
```

は`Type::global.methods` の中に`Method("+", [Argument(Int), Argument(Int)], Int)`

で保管

1. `AST` 作る
2. クラス構文を見に行く
3. `extention` 見に行く
4. 全ての`Type`を作成
5. `Var` の 型推論
6. 


