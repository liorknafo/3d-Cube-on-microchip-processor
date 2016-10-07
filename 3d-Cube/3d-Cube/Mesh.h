#ifndef __MESH__H
#define __MESH__H
#include "outputAnalog.h"

#define MAX_POINTS 15
#define MAX_LINES 30

typedef struct
{
	vec3 points[MAX_POINTS];
	int num_of_points;
	int lines[MAX_LINES][2];
	int num_of_lines;
}Mesh;

void drawLine(vec3 point1, vec3 point2);
void drawMesh(Mesh* mesh, mat4 transMatrix);
void addPoint(Mesh* mesh , vec3 point);
void addLine(Mesh* mesh ,int point1, int point2);
Mesh initMesh();

#endif
