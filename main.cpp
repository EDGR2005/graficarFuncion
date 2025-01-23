#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include<math.h>

int main() {
	int gm, gd;
	gd = DETECT;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	setbkcolor(15);
	cleardevice();
	setcolor(4);
	

    int xmin, ymin, xmax, ymax;
    int xpmin, ypmin, xpmax, ypmax;
    int xpc, ypc;
    float deltaX, deltaY;
    float x, xp, yp;
    float incremento;

    // Definici�n de los l�mites del sistema de coordenadas personal
    xmin = ymin = -10;
    xmax = ymax = 10;

    // Definici�n de los l�mites de las coordenadas de la pantalla gr�fica
    xpmin = ypmin = 0;
    xpmax = getmaxx();
    ypmax = getmaxy();
    



    // C�lculo del centro de la pantalla gr�fica
    xpc = (xpmax - xpmin) / 2;
    ypc = (ypmax - ypmin) / 2;

    // C�lculo de los deltas para mapeo de coordenadas
    deltaX = (float)(xpmax - xpmin) / (xmax - xmin);
    deltaY = (float)(ypmax - ypmin) / (ymax - ymin);

    // Declaraci�n del incremento
    incremento = 1;
	//Dibujamos ejes
    line(xpmin, ypc, xpmax, ypc);
	line(xpc, ypmin, xpc, ypmax);
	
    // Inicializaci�n de x y bucle while para dibujar puntos
    x = xmin;
    float xp1=xpc + (x* deltaX);
    float yp1 = ypc - (x*x * deltaY);
    while (x <= xmax) {
    	
        xp = xpc + (x* deltaX);
        yp = ypc - (x*x * deltaY);  // Nota: el eje Y en gr�ficos suele ser invertido
        setcolor(14);
        line(xp1-1, yp1-1, xp-1, yp-1);
        putpixel((int)xp, (int)yp, 1);
        
        xp1=xp;
        yp1=yp;
        x += incremento;
    }

    getch();  // Pausa para ver el resultado
    closegraph();  // Cierra el modo gr�fico
    return 0;
}
