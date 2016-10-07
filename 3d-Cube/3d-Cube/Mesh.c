#include "Mesh.h"

#ifdef _WIN32
#include <Windows.h>
HWND myconsole;
HDC mydc1;
#endif

void drawLine(vec3 point1, vec3 point2)
{
	setLine(point1 , point2 , 30);
}
void drawMesh(Mesh* mesh, mat4 transMatrix)
{
	vec3 screenPoints[MAX_POINTS];
	int i , j;
	for (i = 0; i < mesh->num_of_points;i++)
	{
		screenPoints[i] = vec4to3(multyMat4vec(transMatrix, vec3to4(mesh->points[i], 1)));
		screenPoints[i].X_ /= screenPoints[i].Z_;
		screenPoints[i].Y_ /= screenPoints[i].Z_;
	}
	for (i = 0; i < mesh->num_of_lines; i++)
	{
		drawLine(screenPoints[mesh->lines[i][0]], screenPoints[mesh->lines[i][1]]);
	}
#ifdef _WIN32
	if (myconsole == NULL)
	{
		myconsole = GetConsoleWindow();
		mydc1 = GetDC(myconsole);
	}
	for (i = 0; i < 0x100; i++)
		for (j = 0; j < 0x100; j++)
			SetPixel(mydc1, i, j, RGB(0, 0, 0));
#endif
}
void addPoint(Mesh* mesh, vec3 point)
{
	mesh->points[mesh->num_of_points++] = point;
}
void addLine(Mesh* mesh, int point1, int point2)
{
	mesh->lines[mesh->num_of_lines][0] = point1;
	mesh->lines[mesh->num_of_lines][1] = point2;
	mesh->num_of_lines++;
}

Mesh initMesh()
{
	Mesh mesh;
	mesh.num_of_lines = 0;
	mesh.num_of_points = 0;
	return mesh;
}