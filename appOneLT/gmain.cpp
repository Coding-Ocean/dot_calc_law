#include"libOne.h"
void mathSegment(const VECTOR& a, const VECTOR& b, const COLOR& c, float w)
{
	strokeWeight(w);
	stroke(c);
	mathLine(a.x, a.y, b.x, b.y);
}
void mathArrow(const VECTOR& a, const VECTOR& b, const COLOR& c, float w)
{
	strokeWeight(w);
	stroke(c);
	mathArrow(a.x, a.y, b.x, b.y);
}
void mathPoint(const VECTOR& p, const COLOR& c, float w)
{
	strokeWeight(w);
	stroke(c);
	mathPoint(p.x, p.y);
}
void mathClear()
{
	clear();
	noStroke();
	fill(180, 255, 60, 255);
	rect(0, 0, width, height);
	mathAxis(5.1f, 128);
	fill(255);
}
void textInfo(const VECTOR& a, const VECTOR& b, const VECTOR& c)
{
	printSize(30);
	print("���ρE�v�Z�@��");
	print((let)"a(" + a.x + "," + a.y + ")");
	print((let)"b(" + b.x + "," + b.y + ")");
	print((let)"c(" + c.x + "," + c.y + ")");
	print("");
	print((let)"�����@�� " +
		"dot(a,b)=" + dot(a, b) + "   " +
		"dot(b,a)=" + dot(b, a)
	);
	print("");
	print((let)"�萔�{   " +
		"dot(a,3*b)=" + dot(a, 3 * b) + " " +
		"3*dot(a,b)=" + 3 * dot(a, b)
	);
	print("");
	print((let)"���z�@�� " +
		"dot(a,b+c)=" + dot(a, b + c) + " " +
		"dot(a,b)+dot(a,c)=" + (dot(a, b) + dot(a, c))
	);
}
void gmain()
{
	window("math",1280, 1080,full);
	angleMode(DEGREES);
	colorMode(HSV);	
	float satu = 80;
	float value = 255;
	COLOR red(0, satu, value);
	COLOR green(90, satu, value);
	COLOR yellow(60, satu, value);
	COLOR blue(210, satu, value);
	while (notQuit)
	{
		mathClear();
		VECTOR o(0, 0);
		VECTOR a(4, 1);
		VECTOR b(2, 2);
		VECTOR c(2, 1);
		a.set(mathMouseX, mathMouseY);
		textInfo(a, b, c);

		mathArrow(o, a, red, 6);
		mathArrow(o, b, blue, 6);
		/*
		* b����a�ɐ��������낵���_��mp�Ƃ���B
		* a�̑傫�����P�Ƃ����Ƃ��A���_����mp�܂ł̑傫���̔�����Ƃ���
		* mp�͎��̎��ŋ��߂���B
		* mp = a * m
		* �ł�m�����߂Ă����܂��傤�B���̂��߂Ɏ��̎��𗧂Ă܂��B
		* dot(a,b-mp)=0
		* dot(a,b-a*m)=0
		* dot(a,b) + dot(a,-a*m) = 0
		* dot(a,b) + m * -dot(a,a)= 0
		* m = -dot(a,b) / -dot(a,a)
		* m = dot(a,b) / dot(a,a)
		* m = dot(a,b) / |a||a|
		*/
		float m = dot(a, b) / a.magSq();
		VECTOR mp = a * m;
		mathArrow(o, mp, yellow, 3);
		mathSegment(b, mp, yellow, 3);
	}
}
