#ifndef COLORCODEDCLOCK_H_
#define COLORCODEDCLOCK_H_

 void timeDisplay(byte h, byte m, byte s) {
	for (int i = 62; i < 68; i++) {
		leds[i] = CRGB(0, 0, 0);
	}
	//first digit
	int first = h/10;
	//second digit
	int last = h % 10;
	leds[62] = rainbow_colors[first];
	leds[63] = rainbow_colors[last];
	first = m/10;
	last = m % 10;
	leds[64] = rainbow_colors[first];
	leds[65] = rainbow_colors[last];
	first = s/10;
	last = s % 10;
	leds[66] = rainbow_colors[first];
	leds[67] = rainbow_colors[last];
	}

#endif /* COLORCODEDCLOCK_H_ */
