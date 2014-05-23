/*
 * Ponto.cpp
 *
 *  Created on: May 19, 2014
 *      Author: pim
 */

#include "Ponto.h"
#include <math.h>

Ponto::Ponto(double x,double y,double z) {
	this->x=x;
	this->y=y;
	this->z=z;

}

Ponto::~Ponto() {
	// TODO Auto-generated destructor stub
}
double Ponto::getTamanho(){
    return sqrt( (x * x) + (y * y) + (z * z) );
}
