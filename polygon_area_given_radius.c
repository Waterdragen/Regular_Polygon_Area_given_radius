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
	if(radius!=0){	//Regular area calculation
		sidenumt=sidenum;
		int_angle=2*pi/sidenum;
		if(rad_type=='c'){
			base=sin(int_angle/2)*radius*2;
			height=cos(int_angle/2)*radius;
		}
		else{
			base=tan(int_angle/2)*radius*2;
			height=radius;
		}
		triangle_area=base*height/2;
		area=triangle_area*sidenum;
		printf("The area of the polygon: %lf\n",area);
		do{
			printf("Show steps? [y/n] ");
			scanf(" %1[^\n]c",&yesorno);
		}while(yesorno!='y'&&yesorno!='n');
		if(yesorno=='y'){
			printf("\nInterior angle = 2 * pi / %d = %lf\n",sidenumt,int_angle);
			if(rad_type=='c'){
				printf("Base = sin(%lf / 2) * %lf * 2 = %lf\n",int_angle,radius,base);
				printf("Height = cos(%lf / 2) * %lf = %lf\n",int_angle,radius,height);
			}
			else{
				printf("Base = tan(%lf / 2) * %lf * 2 = %lf\n",int_angle,radius,base);
				printf("Height = radius = %lf\n",radius);
			}
			printf("Triangle area = %lf * %lf = %lf\n",base,height,triangle_area);
			printf("Polygon area = %lf * %d = %lf\n",triangle_area,sidenumt,area);
			delay(300);
		}
	}
	else{	//Showing general formula if radius = 0
		do{
			printf("\nShow general formula? [y/n] ");
			scanf(" %1[^\n]c",&yesorno);
		}while(yesorno!='y'&&yesorno!='n');
		if(yesorno=='y'){
			if(rad_type=='c'){
				printf("Let radius = r and no. of sides = x\n");
				printf("Interior angle = 2pi / x\n");
				printf("Base = sin(2pi / x * 1/2) * r * 2 = 2rsin(pi/x)\n");
				printf("Height = cos(2pi / x * 1/2) * r = rcos(pi/x)\n");
				printf("Triangle area = 2rsin(pi/x) * rcos(pi/x) * 1/2 = r^2 * sin(pi/2)cos(pi/2)\n");
				printf("Area = r^2 * xsin(pi/x)cos(pi/x)\n");
			}
			else{
				printf("Let radius = r and no. of sides = x\n");
				printf("Interior angle = 2pi / x\n");
				printf("Base = tan(2pi / x * 1/2) * r * 2 = 2rtan(pi/x)\n");
				printf("Height = radius = r\n");
				printf("Triangle area = 2rtan(pi/x) * r * 1/2 = r^2 * tan(pi/x)\n");
				printf("Area = r^2 * xtan(pi/x)\n");
			}
			delay(300);
		}
	}
	
}

void delay(int number_of_seconds){
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
