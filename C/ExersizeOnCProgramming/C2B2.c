/*
 * @Author       : Darcy
 * @Date         : 2021-01-14 23:00:59
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-01-28 00:30:05
 * @FilePath     : \Practices\C\chapter\C2B2.c
 * @Description  : <(￣︶￣)↗[GO!]
 */
#include <stdio.h>

#define PI 3.1415f

int main(void)
{
	float volume, radius;
	radius = 10.0f;
	volume = (4.0f / 3.0f) * PI * radius * radius * radius;
	printf("If radius equals 10 meters, the volume of a ball will be %.2f cubic meters.\n", volume);
	return 0;
}
