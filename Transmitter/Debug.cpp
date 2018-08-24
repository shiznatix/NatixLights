#include "Debug.h"

bool Debug::IS_DEBUG;
int Debug::MIN_LEVEL;

void Debug::setup(bool isDebug) {
	Debug::IS_DEBUG = isDebug;
	Debug::MIN_LEVEL = -1;

	if (Debug::IS_DEBUG) {
		Serial.begin(9600);
	}
}

void Debug::setup(bool isDebug, int minLevel) {
	Debug::IS_DEBUG = isDebug;
	Debug::MIN_LEVEL = minLevel;

	if (Debug::IS_DEBUG) {
		Serial.println(9600);
	}
}

// String
void Debug::print(String out) {
	Debug::print(out, Debug::DEBUG);
}

void Debug::print(String out, int level) {
	if (Debug::IS_DEBUG && Debug::MIN_LEVEL <= level) {
		Serial.print(out);
	}
}

void Debug::println(String out) {
	Debug::println(out, Debug::DEBUG);
}

void Debug::println(String out, int level) {
	if (Debug::IS_DEBUG && Debug::MIN_LEVEL <= level) {
		Serial.println(out);
	}
}

// Integer
void Debug::print(int out) {
	Debug::print(out, Debug::DEBUG);
}

void Debug::print(int out, int level) {
	if (Debug::IS_DEBUG && Debug::MIN_LEVEL <= level) {
		Serial.print(out);
	}
}

void Debug::println(int out) {
	Debug::println(out, Debug::DEBUG);
}

void Debug::println(int out, int level) {
	if (Debug::IS_DEBUG && Debug::MIN_LEVEL <= level) {
		Serial.println(out);
	}
}

// Unsigned Int 32
void Debug::print(uint32_t out) {
	Debug::print(out, Debug::DEBUG);
}

void Debug::print(uint32_t out, int level) {
	if (Debug::IS_DEBUG && Debug::MIN_LEVEL <= level) {
		Serial.print(out);
	}
}

void Debug::println(uint32_t out) {
	Debug::println(out, Debug::DEBUG);
}

void Debug::println(uint32_t out, int level) {
	if (Debug::IS_DEBUG && Debug::MIN_LEVEL <= level) {
		Serial.println(out);
	}
}

// Char
void Debug::print(char out) {
	Debug::print(out, Debug::DEBUG);
}

void Debug::print(char out, int level) {
	if (Debug::IS_DEBUG && Debug::MIN_LEVEL <= level) {
		Serial.print(out);
	}
}

void Debug::println(char out) {
	Debug::println(out, Debug::DEBUG);
}

void Debug::println(char out, int level) {
	if (Debug::IS_DEBUG && Debug::MIN_LEVEL <= level) {
		Serial.println(out);
	}
}
