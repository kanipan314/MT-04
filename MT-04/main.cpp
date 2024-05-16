#include <Novice.h>
#include <assert.h>
#define _USE_MATH_DEFINES
#include <cmath>

const char kWindowTitle[] = "学籍番号";


static const int kRowHeigth = 20;
static const int kColumWidth = 60;

struct Vector3
{
	float x;
	float y;
	float z;
};

struct Matrix4x4 {
	float m[4][4];
};



void MatrixScrennPrint(int x, int y, const Matrix4x4& matrix, const char* label) {

	Novice::ScreenPrintf(x, y, "%s", label);
	for (int row = 0; row < 4; row++) {
		for (int colum = 0; colum < 4; colum++) {
			Novice::ScreenPrintf(x + colum * kColumWidth, y + (row + 1) * kRowHeigth, "%6.02f", matrix.m[row][colum]);
		}
	}
}

Matrix4x4 Multi(Matrix4x4 m1, Matrix4x4 m2) {
	Matrix4x4 answer;

	answer.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] +
		m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0];
	answer.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] +
		m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1];
	answer.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] +
		m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2];
	answer.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] +
		m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3];

	answer.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] +
		m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0];
	answer.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] +
		m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1];
	answer.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] +
		m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2];
	answer.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] +
		m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3];

	answer.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] +
		m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0];
	answer.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] +
		m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1];
	answer.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] +
		m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2];
	answer.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] +
		m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3];

	answer.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] +
		m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0];
	answer.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] +
		m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1];
	answer.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] +
		m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2];
	answer.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] +
		m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3];

	return answer;
}

Matrix4x4 rotate_XMatrix(float theta) {

	Matrix4x4 rotetaMatrix_X;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			rotetaMatrix_X.m[i][j] = 0;
			if (i == j) {
				rotetaMatrix_X.m[i][j] = 1;
			}
		}
	}

	rotetaMatrix_X.m[1][1] = cosf(theta);
	rotetaMatrix_X.m[1][2] = sinf(theta);
	rotetaMatrix_X.m[2][1] = -sinf(theta);
	rotetaMatrix_X.m[2][2] = cosf(theta);

	return rotetaMatrix_X;
}

Matrix4x4 rotate_YMatrix(float theta) {
	Matrix4x4 rotetaMatrix_Y;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			rotetaMatrix_Y.m[i][j] = 0;
			if (i == j) {
				rotetaMatrix_Y.m[i][j] = 1;
				
			}
		}
	}

	rotetaMatrix_Y.m[0][0] = cosf(theta);
	rotetaMatrix_Y.m[0][2] = -sinf(theta);
	rotetaMatrix_Y.m[2][0] = sinf(theta);
	rotetaMatrix_Y.m[2][2] = cosf(theta);

	return rotetaMatrix_Y;
}

Matrix4x4 rotata_ZMatrix(float theta){
	Matrix4x4 rotetaMatrix_Z;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			rotetaMatrix_Z.m[i][j] = 0;
			if (i == j) {
				rotetaMatrix_Z.m[i][j] = 1;
			}
		}
	}

	rotetaMatrix_Z.m[0][0] = cosf(theta);
	rotetaMatrix_Z.m[0][1] = sinf(theta);
	rotetaMatrix_Z.m[1][1] = cosf(theta);
	rotetaMatrix_Z.m[1][0] = -sinf(theta);

	return rotetaMatrix_Z;
}

Matrix4x4 rotataMatrix(Matrix4x4 rotateX,Matrix4x4 rotateY,Matrix4x4 rotateZ) {

	Matrix4x4 answer;

	answer = Multi(rotateX, Multi(rotateY, rotateZ));
	return answer;
}


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		Vector3 rotate{ 0.4f,1.43f,-0.8f };
		Matrix4x4 rotateMatrixX = rotate_XMatrix(rotate.x);
		Matrix4x4 rotateMatrixY = rotate_YMatrix(rotate.y);
		Matrix4x4 rotateMatrixZ = rotata_ZMatrix(rotate.z);

		Matrix4x4 rotateXYZMatrix = rotataMatrix(rotateMatrixX, rotateMatrixY, rotateMatrixZ);
 
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		MatrixScrennPrint(0, 0, rotateMatrixX, "rotateXMatrix");
		MatrixScrennPrint(0, kRowHeigth * 5, rotateMatrixY, "rotateYMatrix");
		MatrixScrennPrint(0, kRowHeigth * 10, rotateMatrixZ, "rotateZMatrix");
		MatrixScrennPrint(0, kRowHeigth * 15, rotateXYZMatrix, "rotateXYZMatrix");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
