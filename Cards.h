/*
 * File:   Cards.h
 * Author: Suzuka/Emam
 *
 * Date: October 30, 2017, 6:53 PM
 *
 * Cards uses Quad1 (Triangle fans)
 * Almost identical to Rectangular Prisim1
 */

#ifndef CARDS_H
#define CARDS_H

#include <glm/glm.hpp>
#include <stdio.h>

#include "Cards.h"
#include "DrawableObject.h"
#include "Texture.hpp"
#include "Shader.hpp"
#include "Quad1.h"

using glm::vec3;

class Cards: public DrawableObject
{
public:
	Cards();
	Cards(const Cards& orig);

	//give the bottom points build a rectangular prisim, adds a face up and face down texture
	Cards(vec3 _e, vec3 _f, vec3 _b, vec3 _c, Texture* fdTex= NULL, Texture* fuTex= NULL);

	void setTexture(Texture*);

	// The draw function
	void draw(Shader*);//draw the rectangular prisim

	virtual ~Cards();

private:
	foat depth = 1;
	void buildRectangularPrisim1();
	void initalizeRemainingPoints(vec3 _e, vec3 _f, vec3 _b, vec3 _c);

	//uses quads1 fan to build the Cards
	Quad1* ein;
	Quad1* zwei;
	Quad1* drei;
	Quad1* vier;
	Quad1* fuenf;
	Quad1* sechs;
	Texture* facedownTexture;
	Texture* faceupTexture;

	// Colors
	vec3 fillColor = vec3 (1,1,1);	//white
	vec3 borderColor = vec3 (0,0,0); //black

	//the rectangular prisim points
	vec3 a;
	vec3 b;
	vec3 c;
	vec3 d;
	vec3 e;
	vec3 f;
	vec3 g;
	vec3 h;
};
#endif /* CARDS_H */

