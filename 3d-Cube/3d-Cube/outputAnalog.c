#include "outputAnalog.h"

#ifndef _WIN32
#include <p32xxxx.h>
#else
#include <Windows.h>
int x, y;
extern HWND myconsole;
extern HDC mydc1;
#endif

void setAnalogValue(int value, int channel)
{
#ifdef _WIN32
	if (myconsole == NULL)
	{
		myconsole = GetConsoleWindow();
		mydc1 = GetDC(myconsole);
	}
	if (channel == 5)
		x = value;
	else
		y = value;
	SetPixel(mydc1, x, y, RGB(0xff, 0xff, 0xff));
#else
	int td = TRISD, te = TRISE, tf = TRISF;
	int pd = PORTD, pe = PORTE, pf = PORTF;
	initPortD();
	initPortE();
	initPortF();

	PORTF = channel;
	PORTE = value;
	PORTDbits.RD4 = 1;
	PORTDbits.RD4 = 0;
#endif
}

float lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}

void setLine(vec3 point1, vec3 point2, int steps)
{
	int i;
	point1 = vec3Plus(point1, VEC3(1, 1, 0));
	point2 = vec3Plus(point2, VEC3(1, 1, 0));

	point1 = multyVec3Scalar(point1, 0.5f);
	point2 = multyVec3Scalar(point2, 0.5f);

	for (i = 0; i < steps; i++)
	{
		float temp;
		temp = lerp(point1.X_, point2.X_, (float)i / steps);
		setAnalogValue((int)(temp * 0x100), 5);

		temp = lerp(point1.Y_, point2.Y_, (float)i / steps);
		setAnalogValue((int)(temp * 0x100), 6);
	}
}

#ifndef _WIN32
void initAnalogPortD(void)
{
	unsigned int portMap;

	portMap = TRISD;
	portMap &= 0xFFFFFF4F;
	TRISD = portMap;
	PORTDbits.RD4 = 0;
	PORTDbits.RD5 = 0;
}

void initAnalogPortE(void)
{
	unsigned int portMap;

	portMap = TRISE;
	portMap &= 0xFFFFFF00;
	TRISE = portMap;
	PORTE = 0x00;
}

void initAnalogPortF(void)
{
	unsigned int portMap;

	portMap = TRISF;
	portMap &= 0xFFFFFEF8;
	TRISF = portMap;
	PORTFbits.RF8 = 1;
}
#endif

void initAnalogScope()
{
#ifndef _WIN32
	initAnalogPortD();
	initAnalogPortE();
	initAnalogPortF();
#endif
}


