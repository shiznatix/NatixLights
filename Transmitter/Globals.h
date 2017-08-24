const int RF69_FREQ = 433.0;
const int DEST_ADDRESS = 1;
const int MY_ADDRESS = 2;
const int RFM69_CS = 8;
const int RFM69_INT = 3;
const int RFM69_RST = 4;

uint8_t RADIO_ENCRYPTION_KEY[] = {
  0x05, 0x02, 0x07, 0x03, 0x03, 0x01, 0x06, 0x08, 0x02, 0x05, 0x03, 0x06, 0x05, 0x04, 0x04, 0x05
};

RH_RF69 mRf69(RFM69_CS, RFM69_INT);
RHReliableDatagram mRf69Manager(mRf69, MY_ADDRESS);

uint8_t mRadioBuffer[RH_RF69_MAX_MESSAGE_LEN];
uint8_t mRadioBufferLength = sizeof(mRadioBuffer);

// switches / buttongs
const int LEFT_TURN_PIN = A1;
const int RIGHT_TURN_PIN = A2;
const int STOP_ONE_PIN = A3;
const int STOP_TWO_PIN = A4;
const int HAPPY_PIN = A5;

const byte SIGNAL_THRESHOLD = 255;

const String RADIO_SIGNAL_PREFIX = "Signal";

const char ANIM_TYPE_NONE = '0';
const char ANIM_TYPE_CAUTION = '1';
const char ANIM_TYPE_LEFT_TURN = '2';
const char ANIM_TYPE_RIGHT_TURN = '3';
const char ANIM_TYPE_STOP = '4';
const char ANIM_TYPE_HAPPY = '5';
const char ANIM_TYPE_STOP_LEFT_TURN = '6';
const char ANIM_TYPE_STOP_RIGHT_TURN = '7';