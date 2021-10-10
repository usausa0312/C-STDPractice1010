#include<iostream>

int main(void)
{
	// auto 変数名 = [ キャプチャ ]( 引数リスト ) -> 戻り値の型 { 処理内容 };
	auto func = [](int a, int b) -> int { return a + b; };  // int を2つ受け取り、足した結果を返すラムダ式

	int result = func(4, 6);
	std::cout << result << std::endl;  // 10

	int init = 5;

	// キャプチャを指定することで {} 内で変数 init を使うことができる
	auto f = [init](int a, int b) { return init + a * b; };   // コピーキャプチャ
	auto g = [&init](int a, int b) { return init + a * b; };  // 参照キャプチャ

	init = 0;

	// 【コピーキャプチャの場合】
	//    ラムダ式の定義時点で init がコピーされているので、ラムダ式内の init は 5
	int result_copy = f(2, 4);
	std::cout << result_copy << std::endl;  // 13

	// 【参照キャプチャの場合】
	//    ラムダ式実行時の init の値が参照されるので、ラムダ式内の init は 0
	int result_ref = g(2, 4);
	std::cout << result_ref << std::endl;   // 8

	auto func1 = [](int x) -> int { return x * x; };  // int を引数とする
	auto func2 = []() -> int { return 400; };         // 引数なし
	auto func3 = [] { return 400; };                  // 戻り値の型の記述を省略した場合、 () ごと省略可能

	auto func4 = [](int a, int b) { return a + b; };  // a, b は共に int なので、戻り値も int と推論される

	int (*fp)(int, int) = [](int x, int y) { return x + y; };//関数ポインタに暗黙変換


	return 1;
}