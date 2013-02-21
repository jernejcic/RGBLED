#ifndef RGBLED_h
#define RGBLED_h

#include <inttypes.h>

class RGBLED {
	public:
		enum Channel {
			red = 1,
			green = 2,
			blue = 4
		};
		
		enum State {
			manual = 1,
			cycle = 2
		};
		
		enum CycleState {
			blueToViolet,
			violetToRed,
			redToYellow,
			yellowToGreen,
			greenToTeal,
			tealToBlue
		};
	
		RGBLED(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, uint8_t minValue, uint8_t maxValue, uint8_t increment, uint16_t updateSpeed);
		void process();
		void setIntensity(Channel channel, uint8_t channelIntensity);
		void incrementChannel(Channel channel);
		void decrementChannel(Channel channel);
		void setCycle(bool toCycle);

	private:
		void cycleLights();
		
		const int redPin_;
		const int greenPin_;
		const int bluePin_;

		uint8_t redValue_;
		uint8_t greenValue_;
		uint8_t blueValue_;
		
		uint8_t increment_;
		unsigned long lastCycle_;
		uint8_t minValue_;
		uint8_t maxValue_;
		uint16_t updateSpeed_;
		
		int state_;
		int cycleState_;
};

#endif