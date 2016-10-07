#include "Mesh.h"
#include "outputAnalog.h"

void initCube(Mesh* mesh);

void main()
{
	initAnalogScope();
	Mesh mesh = initMesh();
	mat4 pos, rot, scale, proj;
	int frame = 0;
	float size = 0.1f;
	initCube(&mesh);
	initAnalogScope();
	proj = setProjectionMatrix(1 , 80 , 0.2f , 1000);
	scale = mat4Scale(VEC3(size, size, size));
	pos = translate(VEC3(0, 0, 2));
	rot = rotateMat4(VEC3(1, 0, 0), 1);
	while (1)
	{
		pos = translate(VEC3(0,0,2 + (float)sin(frame)));
		mat4 mat = multyMat4Mat(proj, pos);	
		mat = multyMat4Mat(mat, rotateMat4(VEC3(1, 1, 1), frame * 0.1f));
		mat = multyMat4Mat(mat, rot);
		mat = multyMat4Mat(mat, scale);
		drawMesh(&mesh , mat);
		frame++;
	}
}

void initCube(Mesh* mesh)
{
	addPoint(mesh, VEC3(1, 1, 1));
	addPoint(mesh, VEC3(-1, 1, 1));
	addPoint(mesh, VEC3(-1, -1, 1));
	addPoint(mesh, VEC3(1, -1, 1));

	addPoint(mesh, VEC3(1, 1, -1));
	addPoint(mesh, VEC3(-1, 1, -1));
	addPoint(mesh, VEC3(-1, -1, -1));
	addPoint(mesh, VEC3(1, -1, -1));

	addLine(mesh, 0, 1);
	addLine(mesh, 1, 2);
	addLine(mesh, 2, 3);
	addLine(mesh, 3, 0);


	addLine(mesh, 4, 5);
	addLine(mesh, 5, 6);
	addLine(mesh, 6, 7);
	addLine(mesh, 7, 4);


	addLine(mesh, 0, 4);
	addLine(mesh, 1, 5);
	addLine(mesh, 2, 6);
	addLine(mesh, 3, 7);
}

void initTest(Mesh* mesh)
{
	addPoint(mesh, VEC3(1, 1, 1));
	addPoint(mesh, VEC3(0, 1, 3));
	addPoint(mesh, VEC3(5, -1, 3));
	addPoint(mesh, VEC3(0, 1, -3));
	addPoint(mesh, VEC3(-1.5f, 0, 0.5f));
	addPoint(mesh, VEC3(-1.5f, 0, -0.5f));
	addPoint(mesh, VEC3(-5, -1, -3));
	addPoint(mesh, VEC3(-3, 1, 0));
	addPoint(mesh, VEC3(0 , 0, -1));
	addPoint(mesh, VEC3(0 , 0, 1));
	addPoint(mesh, VEC3(0 , 1.5f, 0));

	addLine(mesh, 0, 1);
	addLine(mesh, 0, 9);
	addLine(mesh, 0, 10);
	addLine(mesh, 0, 8);
	addLine(mesh, 0, 7);
	addLine(mesh, 1, 9);
	addLine(mesh, 1, 2);
	addLine(mesh, 2, 9);
	addLine(mesh, 2, 4);
	addLine(mesh, 3, 9);
	addLine(mesh, 3, 4);
	addLine(mesh, 3, 5);
	addLine(mesh,3,10);
	addLine(mesh,4,9);
	addLine(mesh,4,5);
	addLine(mesh,5,8);
	addLine(mesh,5,6);
	addLine(mesh,6,8);
	addLine(mesh,6,7);
	addLine(mesh,7,8);
	addLine(mesh,0,10);
	addLine(mesh,8,10);
	addLine(mesh,9,10);
}