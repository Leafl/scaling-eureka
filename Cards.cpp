/*
 * File:   Cards.cpp
 * Author: Suzuka/Emma
 *
 * Date: October 30, 2017, 6:53 PM
 */

#include "Cards.h"

Cards::Cards()
{
    assert(false&&"Do not use default Cards constructor.");
}

/**
 * "Bold semi basic" constructor for Rectangular Prisim
 * 
 * @param _e	    e
 * @param _f	    f
 * @param _b	    b
 * @param _c	    c
 * @param val	    the value associated with the card
 * @param fdTex	    will be the face down texture, back of card
 * @param fuTex	    will be the face up texture, front of card the part with the seal/crest
 */
Cards::Cards(vec3 _e, vec3 _f, vec3 _b, vec3 _c, int val, Texture* fdTex, Texture* fuTex)
{
	//draw in e, f, b, c
	e = _e;
	f = _f;
	b = _b;
	c = _c;
	value =val
	
	facedownTexture=fdTex;
	faceupTexture=fuTex;
	
	//initalize the remaining cornners
	initalizeRemainingPoints(_e, _f, _b, _c);
	buildRectangularPrisim1();
}
/**
 * returns the value of the card
 */
void Cards::getValue()
{
	return value;
}

/**
 * Initalizes the rest of the ponts that aren't already
 * initalized.
 */
void Cards::initalizeRemainingPoints(vec3 _e, vec3 _f, vec3 _b, vec3 _c)
{
	g = vec3(e.x, (e.y+depth), e.z);
	h = vec3(f.x, (f.y+depth), f.z);
	a = vec3(b.x, (b.y+depth), b.z);
	d = vec3(c.x, (c.y+depth), c.z);
}
/**
 * build Cards();
 * @pre: remaining points have been initalized correctly? hopefully?
 *
 */
void Cards::buildCards()
{
	//ueses Quad1 class to build the quads, (triangle fan)
	//first point in Quad1 is the hub in terms of tirangle fan
	ein=new Quad1(h, f, b, a);// side
	zwei=new Quad1(a, b, c, d);// side
	drei=new Quad1(d, c, e, g);// side
	vier=new Quad1(g, e, f, h);//side
	fuenf=new Quad1(g, h, a, d); //face down back of card
	sechs=new Quad1(e, f, b, c); //face of card shows the seal

	ein->setFillColor(fillColor);
	zwei->setFillColor(fillColor);
	drei->setFillColor(fillColor);
	vier->setFillColor(fillColor);
	fuenf->setFillColor(fillColor);
	sechs->setFillColor(fillColor);

	ein->setBorderColor(borderColor);
	zwei->setBorderColor(borderColor);
	drei->setBorderColor(borderColor);
	vier->setBorderColor(borderColor);
	fuenf->setBorderColor(borderColor);
	sechs->setBorderColor(borderColor);
}

/**
 * draws the Quads
 * @param s
 */
void Cards::draw(Shader* s)
{
	// Draw each Quad1
	ein->draw(s,NULL);
	zwei->draw(s,NULL);
	drei->draw(s,NULL);
	vier->draw(s,NULL);
	fuenf->draw(s,facedownTexture);
	sechs->draw(s,faceupTexture);
}

Cards::Cards(const Cards& orig)
{
    
}

Cards::~Cards()
{
	delete ein;
	delete zwei;
	delete drei;
	delete vier;
	delete fuenf;
	delete sechs;
	
	delete facedownTexture;
	delete faceupTexture;
}


