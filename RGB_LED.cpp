#include <Arduino.h>
#include "RGB_LED.h"

RGB_LED::RGB_LED(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, uint8_t minValue, uint8_t maxValue, uint8_t increment, uint16_t updateSpeed) 
	: redPin_(redPin),
		greenPin_(greenPin),
		bluePin_(bluePin),
		minValue_(minValue),
		maxValue_(maxValue),
		increment_(increment),
		updateSpeed_(updateSpeed)
{
	pinMode(redPin_, OUTPUT);
	pinMode(greenPin_, OUTPUT);
	pinMode(bluePin_, OUTPUT);
}

void RGB_LED::process() {
	switch (state_) {
		case manual:
			break;
		case cycle:
			if (millis() - lastCycle_ > updateSpeed_) {
				cycleLights();
				lastCycle_ = millis();
			}
			break;
	}
}

void RGB_LED::setCycle(bool toCycle) {
	if (toCycle) {
		state_ = cycle;
		cycleState_ = blueToViolet;
		setIntensity(red, 1);
		setIntensity(green, 1);
		setIntensity(blue, maxValue_);
	} else  {
		state_ = manual;
	}
}

void RGB_LED::cycleLights() {
	switch(cycleState_) {
		case blueToViolet:
			// Serial.println("Cycling blueToViolet");
			if (redValue_ < maxValue_) {
				setIntensity(red, redValue_ + 1);
			} else {
				cycleState_ = violetToRed;
			}
			break;
		case violetToRed:
			// Serial.println("Cycling violetToRed");
			if (blueValue_ > minValue_) {
				setIntensity(blue, blueValue_ - 1);
			} else {
				cycleState_ = redToYellow;
			}
			break;
		case redToYellow:
			// Serial.println("Cycling redToYellow");
			if (greenValue_ < maxValue_) {
				setIntensity(green, greenValue_ + 1);
			} else {
				cycleState_ = yellowToGreen;
			}
			break;
		case yellowToGreen:
			// Serial.println("Cycling yellowToGreen");
			if (redValue_ > minValue_) {
				setIntensity(red, redValue_ - 1);
			} else {
				cycleState_ = greenToTeal;
			}
			break;
		case greenToTeal:
			// Serial.println("Cycling greenToTeal");
			if (blueValue_ < maxValue_) {
				setIntensity(blue, blueValue_ + 1);
			} else {
				cycleState_ = tealToBlue;
			}
			break;
		case tealToBlue:
			// Serial.println("Cycling tealToBlue");
			if (greenValue_ > minValue_) {
				setIntensity(green, greenValue_ - 1);
			} else {
				cycleState_ = blueToViolet;
			}
			break;
	}
	return;
}

void RGB_LED::setIntensity(Channel channel, uint8_t channelIntensity) {
	switch(channel) {
		case red:
			redValue_ = channelIntensity;
			analogWrite(redPin_, redValue_);
			break;
		case green:
			greenValue_ = channelIntensity;
			analogWrite(greenPin_, greenValue_);
			break;
		case blue:
			blueValue_ = channelIntensity;
			analogWrite(bluePin_, blueValue_);
			break;
	}
}

void RGB_LED::incrementChannel(Channel channel) {
	switch(channel) {
		case red:
			if (redValue_ + increment_ <= maxValue_)
				setIntensity(red, redValue_ + increment_);
			else
				setIntensity(red, maxValue_);
			break;

		case green:
			if (greenValue_ + increment_ <= maxValue_)
				setIntensity(green, greenValue_ + increment_);
			else
				setIntensity(green, maxValue_);
			break;

		case blue:
			if (blueValue_ + increment_ <= maxValue_)
				setIntensity(blue, blueValue_ + increment_);
			else
				setIntensity(blue, maxValue_);
			break;
	}
}


void RGB_LED::decrementChannel(Channel channel) {
	switch(channel) {
		case red:
			if (redValue_ - increment_ >= minValue_)
				setIntensity(red, redValue_ - increment_);
			else
				setIntensity(red, minValue_);
			break;

		case green:
			if (greenValue_ - increment_ >= minValue_)
				setIntensity(green, greenValue_ - increment_);
			else
				setIntensity(green, minValue_);
			break;

		case blue:
			if (blueValue_ - increment_ >= minValue_)
				setIntensity(blue, blueValue_ - increment_);
			else
				setIntensity(blue, minValue_);
			break;
	}
}
