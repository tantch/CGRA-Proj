/*
 * Ponto.h
 *
 *  Created on: May 19, 2014
 *      Author: pim
 */

#ifndef PONTO_H_
#define PONTO_H_

class Ponto {
public:
	double x,y,z;
	Ponto(double x,double y,double z);
	double getTamanho();
	virtual ~Ponto();
};

#endif /* PONTO_H_ */
