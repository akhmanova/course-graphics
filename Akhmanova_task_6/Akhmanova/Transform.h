#pragma once
#include "Matrix.h"
#include <math.h>

mat3 translate(float Tx, float Ty) {
	mat3 *res = new mat3(1.f); // создали единичную матрицу
	(*res)[0][2] = Tx; // поменяли
	(*res)[1][2] = Ty; // значения в последнем столбце
	return *res;
}mat3 scale(float Sx, float Sy) {
	mat3 *res = new mat3(1.f); // создали единичную матрицу
	(*res)[0][0] = Sx; // поменяли
	(*res)[1][1] = Sy; // значения на главной диагонали
	return *res;
}
mat3 scale(float S) {
	return scale(S, S);
}
mat3 rotate(float theta) {
	mat3 *res = new mat3(1.f); // создали единичную матрицу
	(*res)[0][0] = (*res)[1][1] = (float)cos(theta); // заполнили главную диагональ
	(*res)[0][1] = (float)sin(theta); // синус в первой строке (с плюсом)
	(*res)[1][0] = -(*res)[0][1]; // синус во второй строке (с минусом)
	return *res;
}mat3 mirrorX() {
	mat3 *res = new mat3(1.f); // создаем единичную матрицу
	(*res)[0][0] = 1; // заполняем главную диагональ 
	(*res)[1][1] = -1;
	(*res)[2][2] = 1;
	return *res;
}

mat3 mirrorY() {
	mat3 *res = new mat3(1.f); // создаем единичную матрицу
	(*res)[0][0] = 1; // заполняем главную диагональ 
	(*res)[1][1] = -1;
	(*res)[2][2] = -1;
	return *res;
}

mat4 translate(float Tx, float Ty, float Tz) {
	mat4 *res = new mat4(1.f); // создали единичную матрицу
	(*res)[0][3] = Tx; // поменяли
	(*res)[1][3] = Ty; // значения в последнем столбце
	(*res)[2][3] = Tz;
	return *res;
}
mat4 scale(float Sx, float Sy, float Sz) {
	mat4 *res = new mat4(1.f); // создали единичную матрицу
	(*res)[0][0] = Sx; // поменяли
	(*res)[1][1] = Sy; // значения на главной диагонали
	(*res)[2][2] = Sz;
	return *res;}mat4 rotate(float theta, vec3 n) {
	mat3 crossMn = crossM(n);
	mat3 res = mat3(1.f) + crossMn * sin(theta);
	mat3 crossMn2 = crossMn * crossMn;
	res += crossMn2 * (1.f - cos(theta));
	return mat4(vec4(res.row1, 0.f), vec4(res.row2, 0.f), vec4(res.row3, 0.f), vec4(0.f, 0.f, 0.f, 1.f));
}
mat4 rotateP(float theta, vec3 n, vec3 P) {
	return translate(P.x, P.y, P.z) *
		(rotate(theta, n) * translate(-P.x, -P.y, -P.z));
}
mat4 lookAt(vec3 S, vec3 P, vec3 u) {
	vec3 e3 = norm(S - P);
	vec3 e1 = norm(cross(u, e3));
	vec3 e2 = norm(cross(e3, e1));
	mat4 R = mat4(vec4(e1, 0.f), vec4(e2, 0.f), vec4(e3, 0.f), vec4(0.f, 0.f, 0.f, 1.f));
	mat4 T = mat4(vec4(1.f, 0.f, 0.f, -S.x), vec4(0.f, 1.f, 0.f, -S.y), vec4(0.f, 0.f, 1.f, -S.z), vec4(0.f, 0.f, 0.f, 1.f));
	return R * T;
}
mat4 ortho(float l, float r, float b, float t, float zn, float zf) {
	return mat4(vec4(2.f / (r - l), 0.f, 0.f, -(r + l) / (r - l)),
		vec4(0.f, 2.f / (t - b), 0.f, -(t + b) / (t - b)),
		vec4(0.f, 0.f, -2 / (zf - zn), -(zf + zn) / (zf - zn)),
		vec4(0.f, 0.f, 0.f, 1.f));
}mat4 frustum(float l, float r, float b, float t, float n, float f) {
	return mat4(vec4((2.f * n) / (r - l), 0.f, (r + l) / (r - l), 0.f),
		vec4(0.f, (2.f * n) / (t - b), (t + b) / (t - b), 0.f),
		vec4(0.f, 0.f, -(f + n) / (f - n), (-2.f * f * n) / (f - n)),
		vec4(0.f, 0.f, -1.f, 0.f));
}
mat4 perspective(float fovy, float aspect, float n, float f) {
	return mat4(vec4((1.f / aspect) * (1.f / tan(fovy / 2.f)), 0.f, 0.f, 0.f),
		vec4(0.f, 1.f / tan(fovy / 2.f), 0.f, 0.f),
		vec4(0.f, 0.f, -(f + n) / (f - n), (-2.f * f * n) / (f - n)),
		vec4(0.f, 0.f, -1.f, 0.f));
}
mat3 cadrRL(vec2 Vc, vec2 V, vec2 Wc, vec2 W) {
	return translate(Wc.x, Wc.y) *
		(scale(W.x / V.x, -W.y / V.y) * translate(-Vc.x, -Vc.y));
}