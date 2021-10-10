#include<iostream>

int main(void)
{
	// auto �ϐ��� = [ �L���v�`�� ]( �������X�g ) -> �߂�l�̌^ { �������e };
	auto func = [](int a, int b) -> int { return a + b; };  // int ��2�󂯎��A���������ʂ�Ԃ������_��

	int result = func(4, 6);
	std::cout << result << std::endl;  // 10

	int init = 5;

	// �L���v�`�����w�肷�邱�Ƃ� {} ���ŕϐ� init ���g�����Ƃ��ł���
	auto f = [init](int a, int b) { return init + a * b; };   // �R�s�[�L���v�`��
	auto g = [&init](int a, int b) { return init + a * b; };  // �Q�ƃL���v�`��

	init = 0;

	// �y�R�s�[�L���v�`���̏ꍇ�z
	//    �����_���̒�`���_�� init ���R�s�[����Ă���̂ŁA�����_������ init �� 5
	int result_copy = f(2, 4);
	std::cout << result_copy << std::endl;  // 13

	// �y�Q�ƃL���v�`���̏ꍇ�z
	//    �����_�����s���� init �̒l���Q�Ƃ����̂ŁA�����_������ init �� 0
	int result_ref = g(2, 4);
	std::cout << result_ref << std::endl;   // 8

	auto func1 = [](int x) -> int { return x * x; };  // int �������Ƃ���
	auto func2 = []() -> int { return 400; };         // �����Ȃ�
	auto func3 = [] { return 400; };                  // �߂�l�̌^�̋L�q���ȗ������ꍇ�A () ���Əȗ��\

	auto func4 = [](int a, int b) { return a + b; };  // a, b �͋��� int �Ȃ̂ŁA�߂�l�� int �Ɛ��_�����

	int (*fp)(int, int) = [](int x, int y) { return x + y; };//�֐��|�C���^�ɈÖٕϊ�


	return 1;
}