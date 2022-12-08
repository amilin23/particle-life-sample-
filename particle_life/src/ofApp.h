#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <sdlt/sdlt.h>


// use a SOA that represents a group of particles with the same color
struct colorGroup {
	std::vector<ofVec2f> pos;
	std::vector<ofVec2f> vel;
	ofColor color;
};

class ofApp final : public ofBaseApp
{
public:
	void setup() override;
	void update() override;
	void draw() override;
	void keyPressed(int key) override;
	void restart();
	void random();
	void saveSettings();
	void loadSettings();
	void interaction(colorGroup& Group1, const colorGroup& Group2, const float G, const float radius, bool boundsToggle) const;

	static float RandomFloat(const float a, const float b) { return a + (ofRandomuf() * (b - a)); }

	void Draw(colorGroup group)
	{
		ofSetColor(group.color);
		vbo.setVertexData(group.pos.data(), group.pos.size(), GL_STATIC_DRAW);
		vbo.draw(GL_POINTS, 0, group.pos.size());

	}
	
	ofxPanel gui;
	ofVbo vbo;


#pragma region guigroup
	ofxGuiGroup globalGroup;
	ofxGuiGroup qtyGroup;
	ofxGuiGroup redGroup;
	ofxGuiGroup greenGroup;
	ofxGuiGroup blueGroup;
	ofxGuiGroup whiteGroup;
#pragma endregion guigroup

	ofxButton resetButton;
	ofxButton selectButton;
	ofxButton randomChoice;
	ofxButton save;
	ofxButton load;

	ofxToggle boundsToggle;
	ofxToggle modelToggle;

#pragma region some experimental features
	ofxGuiGroup expGroup;
	ofxToggle evoToggle;
	ofxFloatSlider evoProbSlider;
	ofxFloatSlider evoAmountSlider;
	float evoChance = 1;
	float evoAmount = 1;
	ofxToggle radiusToogle;
	ofxLabel physicLabel;
	ofxIntSlider probabilitySlider;
	unsigned int probability = 100;
	ofxToggle motionBlurToggle;
#pragma endregion some experimental features



#pragma region slider
	ofxIntSlider numberSliderR;
	ofxIntSlider numberSliderG;
	ofxIntSlider numberSliderW;
	ofxIntSlider numberSliderB;

	ofxFloatSlider viscoSlider;
	ofxFloatSlider gravitySlider;
	ofxFloatSlider wallRepelSlider;

	ofxFloatSlider powerSliderRR;
	ofxFloatSlider powerSliderRG;
	ofxFloatSlider powerSliderRW;
	ofxFloatSlider powerSliderRB;
	ofxFloatSlider powerSliderGR;
	ofxFloatSlider powerSliderGG;
	ofxFloatSlider powerSliderGW;
	ofxFloatSlider powerSliderGB;
	ofxFloatSlider powerSliderWR;
	ofxFloatSlider powerSliderWG;
	ofxFloatSlider powerSliderWW;
	ofxFloatSlider powerSliderWB;
	ofxFloatSlider powerSliderBR;
	ofxFloatSlider powerSliderBG;
	ofxFloatSlider powerSliderBW;
	ofxFloatSlider powerSliderBB;
	ofxFloatSlider vSliderRR;
	ofxFloatSlider vSliderRG;
	ofxFloatSlider vSliderRW;
	ofxFloatSlider vSliderRB;
	ofxFloatSlider vSliderGR;
	ofxFloatSlider vSliderGG;
	ofxFloatSlider vSliderGW;
	ofxFloatSlider vSliderGB;
	ofxFloatSlider vSliderWR;
	ofxFloatSlider vSliderWG;
	ofxFloatSlider vSliderWW;
	ofxFloatSlider vSliderWB;
	ofxFloatSlider vSliderBR;
	ofxFloatSlider vSliderBG;
	ofxFloatSlider vSliderBW;
	ofxFloatSlider vSliderBB;

	vector<ofxFloatSlider*> powersliders = {
		&powerSliderRR, &powerSliderRG, &powerSliderRB, &powerSliderRW,
		&powerSliderGR, &powerSliderGG, &powerSliderGB, &powerSliderGW,
		&powerSliderBR, &powerSliderBG, &powerSliderBB, &powerSliderBW,
		&powerSliderWR, &powerSliderWG, &powerSliderWB, &powerSliderWW,
	};

	vector<ofxFloatSlider*> vsliders = {
		&vSliderRR, &vSliderRG, &vSliderRB, &vSliderRW,
		&vSliderGR, &vSliderGG, &vSliderGB, &vSliderGW,
		&vSliderBR, &vSliderBG, &vSliderBB, &vSliderBW,
		&vSliderWR, &vSliderWG, &vSliderWB, &vSliderWW,
	};

#pragma endregion slider

#pragma region slider values
	int pnumberSliderR = 1000;
	int pnumberSliderG = 1000;
	int pnumberSliderW = 1000;
	int pnumberSliderB = 1000;

	float ppowerSliderRR = 0;
	float ppowerSliderRG = 0;
	float ppowerSliderRW = 0;
	float ppowerSliderRB = 0;
	float ppowerSliderGR = 0;
	float ppowerSliderGG = 0;
	float ppowerSliderGW = 0;
	float ppowerSliderGB = 0;
	float ppowerSliderWR = 0;
	float ppowerSliderWG = 0;
	float ppowerSliderWW = 0;
	float ppowerSliderWB = 0;
	float ppowerSliderBR = 0;
	float ppowerSliderBG = 0;
	float ppowerSliderBW = 0;
	float ppowerSliderBB = 0;
	float pvSliderRR = 180;
	float pvSliderRG = 180;
	float pvSliderRW = 180;
	float pvSliderRB = 180;
	float pvSliderGR = 180;
	float pvSliderGG = 180;
	float pvSliderGW = 180;
	float pvSliderGB = 180;
	float pvSliderWR = 180;
	float pvSliderWG = 180;
	float pvSliderWW = 180;
	float pvSliderWB = 180;
	float pvSliderBR = 180;
	float pvSliderBG = 180;
	float pvSliderBW = 180;
	float pvSliderBB = 180;
#pragma endregion slider values

	ofxLabel labelG;
	ofxLabel labelR;
	ofxLabel labelW;
	ofxLabel labelB;
	ofxLabel aboutL1;
	ofxLabel aboutL2;
	ofxLabel aboutL3;
	ofxLabel fps;

	std::string fps_text;
	std::string physic_text;


	// simulation bounds
	int boundWidth = 1600;
	int boundHeight = 900;

	float viscosity = 0.5F;
	float worldGravity = 0.0F;
	float forceVariance = 0.8F;
	float radiusVariance = 0.6F;
	float wallRepel = 10.0F;
};
