#include "model.h"

int LoadOffFile(char* filePath, Object3D* object)
{
	InitEmptyObject(object);
	char off[10];
	FILE* file;

	#if _WIN32
		if (fopen_s(&file, filePath, "r") != 0) return 0;
	#elif __APPLE__
		file = fopen(filePath, "r");
		if (!file) return 0;
	#endif

	#if _WIN32
		if (fscanf_s(file, "%s %d %d %d", off, (unsigned int)sizeof(off), &object->numPoints, &object->numFaces, &object->numEdges) == 0) return 0;
	#elif __APPLE__
		if (fscanf(file, "%s %d %d %d", off, &object->numPoints, &object->numFaces, &object->numEdges) == 0) return 0;
	#endif

	object->vertexPoints = (Vector3*)malloc(object->numPoints * sizeof(Vector3));

	for (int i = 0; i < object->numPoints; i++)
	{
		#if _WIN32
		float x = 0.0f, y = 0.0f, z = 0.0f;
			if (fscanf_s(file, "%f %f %f", &x, &y, &z) == 0) return 0;
			object->vertexPoints[i].x = x;
			object->vertexPoints[i].y = y;
			object->vertexPoints[i].z = z;
		#elif __APPLE__
			if (fscanf(file, "%f %f %f", &object->vertexPoints[i].x, &object->vertexPoints[i].y, &object->vertexPoints[i].z) == 0) return 0;
		#endif
	}

	object->faceIndices = (Vector4*)malloc(object->numFaces * sizeof(Vector4));

	for (int i = 0; i < object->numFaces; i++)
	{
		#if _WIN32
		int x = 0, y = 0, z = 0, w = 0;
			if (fscanf_s(file, "%d %d %d %d", &x, &y, &z, &w) == 0) return 0;
			object->faceIndices[i].x = (float)x;
			object->faceIndices[i].y = (float)y;
			object->faceIndices[i].z = (float)z;
			object->faceIndices[i].w = (float)w;
		#elif __APPLE__
			if (fscanf(file, "%d %d %d %d", &object->faceIndices[i].x, &object->faceIndices[i].y, &object->faceIndices[i].z, &object->faceIndices[i].w) == 0) return 0;
		#endif
	}

	fclose(file);
	object->transform.Position = Vector3Zero;
	object->transform.Rotation = Vector3Zero;
	object->transform.Scale = Vector3One;
	return 1;
}

void InitEmptyObject(Object3D* object)
{
	object->numPoints = 0;
	object->numFaces = 0;
	object->numEdges = 0;
	object->transform.Position = Vector3Zero;
	object->transform.Rotation = Vector3Zero;
	object->transform.Scale = Vector3One;
}

void DrawOffFile(Object3D* object)
{
	for (int i = 0; i < object->numFaces; i++)
	{
		Vector4 f;
		f.x = object->faceIndices[i].x;
		f.y = object->faceIndices[i].y;
		f.z = object->faceIndices[i].z;

		glBegin(GL_TRIANGLES);
		glColor3f(RED);
		glVertex3f(object->vertexPoints[(int)f.x].x, object->vertexPoints[(int)f.x].y, object->vertexPoints[(int)f.x].z);
		glVertex3f(object->vertexPoints[(int)f.y].x, object->vertexPoints[(int)f.y].y, object->vertexPoints[(int)f.y].z);
		glVertex3f(object->vertexPoints[(int)f.z].x, object->vertexPoints[(int)f.z].y, object->vertexPoints[(int)f.z].z);
		glEnd();
	}
}
