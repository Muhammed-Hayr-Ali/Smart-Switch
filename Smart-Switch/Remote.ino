// SAMSUNG CODES //

#define Power         0xE0E040BF
#define Home          0xE0E09E61
#define Back          0xE0E01AE5
#define Pause         0xE0E09D62
#define A123          0xE0E04BB4
#define Extra         0xE0E0738C

#define CH_List       0xE0E0F20D
#define CH_UP         0xE0E048B7
#define CH_DOWN       0xE0E008F7

#define Mute          0xE0E0F00F
#define VOL_UP        0xE0E0E01F
#define VOL_DOWN      0xE0E0D02F

#define OK            0xE0E016E9
#define UP            0xE0E006F9
#define Down          0xE0E08679
#define Right         0xE0E046B9
#define Left          0xE0E0A659

#define source        0xE0E0807F
#define txt_max       0xE0E034CB
#define pre_ch        0xE0E0C837
#define ch_list       0xE0E0D629
#define menu          0xE0E058A7
#define mediap        0xE0E031CE
#define guide         0xE0E0F20D
#define info          0xE0E0F807
#define tools         0xE0E0D22D

#define Return        0xE0E01AE5
#define Exit          0xE0E0B44B
#define e_manual      0xE0E0FC03
#define pic_Size      0xE0E07C83
#define ad_subt       0xE0E0A45B
#define Stop          0xE0E0629D
#define play          0xE0E0E21D
#define pause         0xE0E052AD
#define Rewind        0xE0E0A25D
#define Forward       0xE0E012ED
#define Aa            0xE0E036C9
#define Bb            0xE0E028D7
#define Cc            0xE0E0A857
#define Dd            0xE0E06897

#define CH0           0xE0E08877
#define CH1           0xE0E020DF
#define CH2           0xE0E0A05F
#define CH3           0xE0E0609F
#define CH4           0xE0E010EF
#define CH5           0xE0E0906F
#define CH6           0xE0E050AF
#define CH7           0xE0E030CF
#define CH8           0xE0E0B04F
#define CH9           0xE0E0708F


BLYNK_WRITE(Remote)
{
  int pinValue = param.asInt();

  switch (pinValue) {

    case 1:
      irsend.sendSAMSUNG(Power);
      //  Serial.println("Power");
      break;

    case 2:
      irsend.sendSAMSUNG(source);
      break;

    case 3:
      irsend.sendSAMSUNG(CH1);
      break;

    case 4:
      irsend.sendSAMSUNG(CH2);
      break;

    case 5:
      irsend.sendSAMSUNG(CH3);
      break;

    case 6:
      irsend.sendSAMSUNG(CH4);
      break;

    case 7:
      irsend.sendSAMSUNG(CH5);
      break;

    case 8:
      irsend.sendSAMSUNG(CH6);
      break;

    case 9:
      irsend.sendSAMSUNG(CH7);
      break;

    case 10:
      irsend.sendSAMSUNG(CH8);
      break;

    case 11:
      irsend.sendSAMSUNG(CH9);
      break;

    case 12:
      irsend.sendSAMSUNG(CH0);
      break;

    case 13:
      irsend.sendSAMSUNG(txt_max);
      break;

    case 14:
      irsend.sendSAMSUNG(pre_ch);
      break;

    case 15:
      irsend.sendSAMSUNG(Mute);
      break;

    case 16:
      irsend.sendSAMSUNG(CH_List);
      break;

    case 17:
      irsend.sendSAMSUNG(menu);
      break;

    case 18:
      irsend.sendSAMSUNG(tools);
      break;

    case 19:
      irsend.sendSAMSUNG(guide);
      break;

    case 20:
      irsend.sendSAMSUNG(info);
      break;

    case 21:
      irsend.sendSAMSUNG(OK);
      Serial.println("OK");
      break;

    case 22:
      irsend.sendSAMSUNG(UP);
      break;

    case 23:
      irsend.sendSAMSUNG(Down);
      break;

    case 24:
      irsend.sendSAMSUNG(Right);
      break;

    case 25:
      irsend.sendSAMSUNG(Left);
      break;

    case 26:
      irsend.sendSAMSUNG(Return);
      break;

    case 27:
      irsend.sendSAMSUNG(Exit);
      break;

    case 28:
      irsend.sendSAMSUNG(Aa);
      break;

    case 29:
      irsend.sendSAMSUNG(Bb);
      break;

    case 30:
      irsend.sendSAMSUNG(Cc);
      break;

    case 31:
      irsend.sendSAMSUNG(Dd);
      break;

    case 32:
      irsend.sendSAMSUNG(Rewind);
      break;

    case 33:
      irsend.sendSAMSUNG(play);
      break;

    case 34:
      irsend.sendSAMSUNG(pause);
      break;

    case 35:
      irsend.sendSAMSUNG(Forward);
      break;

    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }

}

BLYNK_WRITE(Volume)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    irsend.sendSAMSUNG(VOL_UP);
  }
  else if (pinValue == 0) {
    irsend.sendSAMSUNG(VOL_DOWN);
  }
}

BLYNK_WRITE(Channel)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    irsend.sendSAMSUNG(CH_UP);
  }
  else if (pinValue == 0) {
    irsend.sendSAMSUNG(CH_DOWN);
  }
}
