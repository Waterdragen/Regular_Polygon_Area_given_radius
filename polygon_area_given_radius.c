#include <stdio.h>
#include <math.h>
#include <time.h>
#define pi 3.14159265359

void delay(int number_of_seconds);

int main(){
	double radius, int_angle, base, height, triangle_area, area;
	int sidenum, sidenumt;
	char yesorno='?',rad_type;
	do{
		printf("Choose radius type: Circumcircle or Incircle [c/i] ");
		scanf(" %1[^/n]c",&rad_type);
	}while(rad_type!='c'&&rad_type!='i');
	do{
		printf("Enter the radius length: ");
		scanf(" %lf",&radius);
	}while(radius<0);
	do{
		printf("Enter the regular polygon side number: ");
		scanf(" %d",&sidenum);
	}while(sidenum<3);
	sidenumt=sidenum;
	int_angle=2*pi/sidenum;
	
	if(rad_type=='i'){
		radius/=cos(int_angle/2);
	}
	
	base=sin(int_angle/2)*radius*2;
	height=cos(int_angle/2)*radius;
	triangle_area=base*height/2;
	area=triangle_area*sidenum;
	printf("The area of the polygon: %lf\n",area);
	do{
		printf("Show steps? [y/n] ");
		scanf(" %1[^\n]c",&yesorno);
	}while(yesorno!='y'&&yesorno!='n');
	if(yesorno=='y'){
		if(rad_type=='i'){
			printf("\nCircumcircle radius = %lf / cos(%lf) = %lf",radius*cos(int_angle/2),int_angle,radius);
		}
		printf("\nInterior angle = 2 * pi / %d = %lf\n",sidenumt,int_angle);
		printf("Base = sin(%lf / 2) * %lf * 2 = %lf\n",int_angle,radius,base);
		printf("Height = cos(%lf / 2) * %lf = %lf\n",int_angle,radius,height);
		printf("Triangle area = %lf * %.6lf = %lf\n",base,height,triangle_area);
		printf("Polygon area = %lf * %d = %lf\n",triangle_area,sidenumt,area);
		delay(300);
	}
}

void delay(int number_of_seconds){
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
