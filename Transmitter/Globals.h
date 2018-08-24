// battery
const int BATTERY_PIN = 9;
const float BATTERY_LOW_VOLTAGE = 3.4;

// radio
const int RF69_FREQ = 433.0;
const int DEST_ADDRESS = 1;
const int MY_ADDRESS = 2;
const int RFM69_CS = 8;
const int RFM69_INT = 3;
const int RFM69_RST = 4;

uint8_t RADIO_ENCRYPTION_KEY[] = {
  194, 81, 70, 225, 190, 197, 123, 157, 90, 202, 52, 129, 125, 178, 97, 85
};

RH_RF69 mRf69(RFM69_CS, RFM69_INT);
RHReliableDatagram mRf69Manager(mRf69, MY_ADDRESS);

uint8_t mRadioBuffer[RH_RF69_MAX_MESSAGE_LEN];
uint8_t mRadioBufferLength = sizeof(mRadioBuffer);

const String SIGNAL_PREFIX = "Signal";

const char RESPONSE_NONE = '0';
const char RESPONSE_OK = '1';
const char RESPONSE_LOW_BATTERY = '2';

// switches / buttons
const int LEFT_TURN_PIN = A1;
const int RIGHT_TURN_PIN = A3;
const int STOP_ONE_PIN = A4;
const int STOP_TWO_PIN = A5;
const int HAPPY_PIN = A0;

const byte SIGNAL_THRESHOLD = 255;

const char ANIM_TYPE_NONE = '0';
const char ANIM_TYPE_CAUTION = '1';
const char ANIM_TYPE_LEFT_TURN = '2';
const char ANIM_TYPE_RIGHT_TURN = '3';
const char ANIM_TYPE_STOP = '4';
const char ANIM_TYPE_HAPPY = '5';
const char ANIM_TYPE_STOP_LEFT_TURN = '6';
const char ANIM_TYPE_STOP_RIGHT_TURN = '7';

// status lights
const int NEOPIXEL_PIN = 10;
Adafruit_NeoPixel mStrip = Adafruit_NeoPixel(60, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

// setup our colors
const byte MAX_COLOR = 100;
const uint32_t COLOR_RED = mStrip.Color(MAX_COLOR, 0, 0);
const uint32_t COLOR_GREEN = mStrip.Color(0, MAX_COLOR, 0);
const uint32_t COLOR_BLUE = mStrip.Color(0, 0, MAX_COLOR);
const uint32_t COLOR_PURPLE = mStrip.Color(MAX_COLOR, 0, MAX_COLOR);
const uint32_t COLOR_YELLOW = mStrip.Color(MAX_COLOR, MAX_COLOR, 0);
const uint32_t COLOR_WHITE = mStrip.Color(MAX_COLOR, MAX_COLOR, MAX_COLOR);
const uint32_t COLOR_OFF = mStrip.Color(0, 0, 0);
