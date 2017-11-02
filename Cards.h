/*
 * File:   Cards.h
 * Author: Suzuka/Emam
 *
 * Date: October 30, 2017, 6:53 PM
 *
 * Rectangular Prisim uses Quad1 (Triangle fans)
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

	//give the bottom points build a rectangular prisim
	Cards(vec3 _e, vec3 _f, vec3 _b, vec3 _c,float  _depth);

	//additional params: fill color, border color, texture
	Cards(vec3 _e, vec3 _f, vec3 _b, vec3 _c, float _depth, vec3 fc, vec3 bc, Texture* tex= NULL);

	void setTexture(Texture*);

	// The draw function
	void draw(Shader*);//draw the rectangular prisim

	virtual ~Cards();

private:
	void buildRectangularPrisim1();
	void initalizeRemainingPoints(vec3 _e, vec3 _f, vec3 _b, vec3 _c, float _depth);
	
	float depth;

	//uses triangle fan to build the quads1
	Quad1* ein;
	Quad1* zwei;
	Quad1* drei;
	Quad1* vier;
	Quad1* fuenf;
	Quad1* sechs;
	Texture* texture;

	// Colors
	vec3 fillColor;
	vec3 borderColor;

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

