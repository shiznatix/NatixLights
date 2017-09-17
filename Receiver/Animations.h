//animations
const int ANIM_FRAMES = 5;
const int PIXEL_COUNT = 140;

const char _ = '_';
const char r = 'r';
const char o = 'o';
const char y = 'y';
const char g = 'g';
const char b = 'b';
const char p = 'p';
const char w = 'w';

//animations are always shown in a single color to be determined by the function params
const char IMAGE_CAUTION[ANIM_FRAMES][PIXEL_COUNT] = {
	{ _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, _, r, r, r, _, _, _, _,
	  _, _, _, _, r, r, r, _, _, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, _, r, r, r, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _ },

	{ _, _, _, r, r, r, r, r, _, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, r, _, _, _, r, _, _, _,
	  _, _, _, r, _, _, _, r, _, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, r, _, _, _, r, _, _, _,
	  _, _, _, r, r, r, r, r, _, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _ },

	{ _, _, r, r, r, _, r, r, r, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, r, _, _, _, _, _, r, _, _,
	  _, _, r, _, _, _, _, _, r, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, r, _, _, _, _, _, r, _, _,
	  _, _, r, r, r, _, r, r, r, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _ },

	{ _, r, r, r, _, _, _, r, r, r, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, r, _, _, _, _, _, _, _, r,
	  _, r, _, _, _, _, _, _, _, r, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, r, _, _, _, _, _, _, _, r,
	  _, r, r, r, _, _, _, r, r, r, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _ },

	{ r, r, r, _, _, _, _, _, r, r, r, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, r, _, _, _, r, _, r, _, _, _, r,
	  r, _, _, _, _, r, _, _, _, _, r, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, r, _, _, _, r, _, r, _, _, _, r,
	  r, r, r, _, _, _, _, _, r, r, r, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
	  _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _ },
};

//static images
const char IMAGE_LEFT_TURN[PIXEL_COUNT] = {
	_, _, _, _, _, _, b, b, _, _, _, _, _, _, _, _, _, _, _, _,
	_, _, _, _, _, _, _, _, _, _, _, _, b, b, b, b, _, _, _, _,
	_, _, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b,
	b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b,
	_, _, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b,
	_, _, _, _, _, _, _, _, _, _, _, _, b, b, b, b, _, _, _, _,
	_, _, _, _, _, _, b, b, _, _, _, _, _, _, _, _, _, _, _, _
};

const char IMAGE_STOP_LEFT_TURN[PIXEL_COUNT] = {
	_, _, _, _, _, _, r, r, _, _, _, _, _, _, _, _, _, _, _, _,
	_, _, _, _, _, _, _, _, _, _, _, _, r, r, r, r, _, _, _, _,
	_, _, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r,
	r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r,
	_, _, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r,
	_, _, _, _, _, _, _, _, _, _, _, _, r, r, r, r, _, _, _, _,
	_, _, _, _, _, _, r, r, _, _, _, _, _, _, _, _, _, _, _, _
};

const char IMAGE_RIGHT_TURN[PIXEL_COUNT] = {
	_, _, _, _, _, _, _, _, _, _, _, _, b, b, _, _, _, _, _, _,
	_, _, _, _, b, b, b, b, _, _, _, _, _, _, _, _, _, _, _, _,
	b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, _, _,
	b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b,
	b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, _, _,
	_, _, _, _, b, b, b, b, _, _, _, _, _, _, _, _, _, _, _, _,
	_, _, _, _, _, _, _, _, _, _, _, _, b, b, _, _, _, _, _, _
};

const char IMAGE_STOP_RIGHT_TURN[PIXEL_COUNT] = {
	_, _, _, _, _, _, _, _, _, _, _, _, r, r, _, _, _, _, _, _,
	_, _, _, _, r, r, r, r, _, _, _, _, _, _, _, _, _, _, _, _,
	r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, _, _,
	r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r,
	r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, _, _,
	_, _, _, _, r, r, r, r, _, _, _, _, _, _, _, _, _, _, _, _,
	_, _, _, _, _, _, _, _, _, _, _, _, r, r, _, _, _, _, _, _
};

const char IMAGE_STOP[PIXEL_COUNT] = {
	y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y,
	r, r, r, r, _, r, r, r, r, _, r, r, r, r, r, _, r, r, r, r,
	r, _, _, _, _, _, _, r, _, _, _, r, _, _, r, _, r, _, _, r,
	r, r, r, r, _, r, _, _, r, _, _, _, r, _, _, _, r, r, r, r,
	_, _, _, r, _, _, _, r, _, _, _, r, _, _, r, _, r, _, _, _,
	_, _, _, r, _, r, r, r, r, _, _, _, r, _, _, _, r, r, r, r,
	y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y
};

const char IMAGE_HAPPY[PIXEL_COUNT] = {
	r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r,
	o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
	y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y,
	g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g,
	b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b,
	p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,
	w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w
};

const char IMAGE_ESTONIA_CROSS[PIXEL_COUNT] = {
	b, b, b, b, b, _, w, _, b, b, b, b, b, b, b, b, b, b, b, b,
	b, b, b, b, b, b, b, b, b, b, b, b, _, w, _, b, b, b, b, b,
	_, _, _, _, _, _, w, _, _, _, _, _, _, _, _, _, _, _, _, _,
	w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w,
	_, _, _, _, _, _, w, _, _, _, _, _, _, _, _, _, _, _, _, _,
	b, b, b, b, b, b, b, b, b, b, b, b, _, w, _, b, b, b, b, b,
	b, b, b, b, b, _, w, _, b, b, b, b, b, b, b, b, b, b, b, b
};

const char IMAGE_USA[PIXEL_COUNT] = {
	b, w, b, w, b, w, b, b, r, r, r, r, r, r, r, r, r, r, r, r,
	w, w, w, w, w, w, w, w, w, w, w, w, b, w, b, w, b, w, b, b,
	b, w, b, w, b, w, b, b, r, r, r, r, r, r, r, r, r, r, r, r,
	w, w, w, w, w, w, w, w, w, w, w, w, b, w, b, w, b, w, b, b,
	r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r,
	w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w,
	r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r, r
};
