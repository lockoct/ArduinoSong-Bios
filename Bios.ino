#include <avr/pgmspace.h>
#define PAUSE -20000
#define NTC3 131
#define NTG3 196
#define NTC4 262
#define NTD4 294
#define NTF4 349
#define NTG4 392
#define NTD5 587
#define NTF5 698
#define NTA5 880
#define NTC6 1047
#define NTD6 1175
#define NTE6 1319
#define NTF6 1397
#define NTG6 1568
#define NTA6 1760
#define NTB6 1976
#define NTC7 2093
#define NTD7 2349
#define NTE7 2637

#define NTAH3 233
#define NTDH4 311
#define NTAH4 466
#define NTDH5 622
#define NTAH5 932
#define NTDH6 1245
#define NTAH6 1865
#define NTDH7 2489

int buzzerPin=8;
int length; 
int tune[] = {/**/
  NTC3,NTG3,NTC4,NTG3,NTAH3,NTC4,NTC4,NTG4,NTF4,NTC4,NTF4,NTDH4,NTD4,NTDH4,NTF4,NTG4,
  NTC3,NTG3,NTC4,NTG3,NTAH3,NTC4,NTC4,NTG4,NTF4,NTC4,NTF4,NTDH4,NTD4,NTDH4,NTF4,NTG4,
  NTC3,NTAH4,PAUSE,NTAH4,NTDH5,PAUSE,NTDH5,NTD5,PAUSE,NTD5,NTAH4,PAUSE,NTAH4,NTF5,PAUSE,
  NTC3,NTAH4,PAUSE,NTAH4,NTDH5,PAUSE,NTDH5,NTD5,PAUSE,NTD5,NTAH4,PAUSE,NTAH4,NTF5,PAUSE,
  NTC6,NTAH5,NTF6,NTAH5,NTDH6,NTF6,NTAH5,NTF6,NTAH5,
  NTC6,NTAH5,NTF6,NTAH5,NTDH6,NTF6,NTAH5,NTF6,NTAH5,
  NTC6,NTAH5,NTF6,NTAH5,NTDH6,NTF6,NTAH5,NTF6,NTAH5,
  NTC6,NTAH5,NTF6,NTAH5,NTDH6,NTF6,NTAH5,NTF6,NTAH5,NTF6,NTAH6,PAUSE,
  
	NTC6,NTDH6,NTF6,NTC6,NTDH6,NTF6,NTG6,NTAH6,NTC7,NTF6, //ei~
	NTDH6,NTD6,NTC6,PAUSE,NTC6,NTAH5,NTDH6,NTD6,NTF6,NTC6,PAUSE,NTC6,NTG6,NTC6,PAUSE,NTAH5,PAUSE, //~ei
  NTC6,NTG6,NTF6,NTG6,PAUSE,NTDH6,PAUSE,NTD6,NTDH6,NTF6,NTD6,PAUSE, //die Ruinenstadt ist immer noch schön
  NTC6,NTG6,NTF6,NTG6,PAUSE,NTDH6,PAUSE,NTD6,NTDH6,NTF6,NTD6,NTC6,PAUSE, //ich warte lange Zeit auf deine Rückkehr
  NTAH5,NTDH6,NTD6,PAUSE, //in der Hand
  NTD6,NTDH6,NTF6,PAUSE,NTC6,PAUSE,NTC6,PAUSE,//ein Vergissmeinnicht
  
  NTC6,NTC7,NTB6,NTC7,NTG6,NTC6,NTA6,NTG6,PAUSE, //Regentropfen sind meine Tränen
  NTC6,NTC7,NTB6,NTC7,NTG6,NTE6,NTA6,PAUSE,NTA6,NTB6,NTG6,PAUSE, //Wind ist mein Atem und mein Erzählung
  NTG6,PAUSE,NTG6,NTF6,PAUSE,NTF6,NTE6,PAUSE,NTE6,PAUSE,NTC6,NTA5,NTD6,NTC6,PAUSE, //Zweige und Blätter sind meine Hände
  NTC6,NTG6,PAUSE,NTG6,NTF6,PAUSE,NTF6,NTE6,PAUSE,NTE6,PAUSE,NTD6,NTC6,NTD6,PAUSE, //denn mein Körper ist in Wurzeln gehüllt
  NTC6,NTC7,NTB6,NTC7,NTG6,NTE6,NTA6,PAUSE,NTA6,NTG6,PAUSE, //wenn die Jahreszeit des Tauens kommt
  NTC6,NTC7,NTB6,NTC7,NTD7,NTG6,NTD7,PAUSE,NTD7,NTE7,PAUSE, //werde ich wach und singe ein Lied
  NTG6,PAUSE,NTF6,NTE6,NTF6,NTG6,PAUSE, //das Vergissmeinnicht
  NTC6,NTG6,NTA6,PAUSE,NTB6,NTC7,NTB6,NTG6,PAUSE,NTE6,NTD6,PAUSE, //das du mir gegeben hast, ist hier
  
  NTAH5,NTC6,NTDH6,NTF6,NTAH5,PAUSE,NTAH5,NTC6,NTDH6,NTF6,NTAH5,PAUSE, //erinnerst du dich noch*2
  NTG6,NTF6,PAUSE,NTF6,NTDH6,NTD6,PAUSE,NTD6,NTDH6,NTD6,NTAH5,PAUSE,//an dein Wort,das du mir gegeben hast
  NTAH5,NTC6,NTDH6,NTF6,NTAH5,PAUSE,NTAH5,NTC6,NTDH6,NTF6,NTAH5,PAUSE, //erinnerst du dich noch*2
  NTG6,NTF6,PAUSE,NTF6,NTDH6,NTD6,PAUSE,NTD6,NTDH6,PAUSE, //erinnerst du dich noch an den Tag,an dem du mir
  
  NTAH6,NTC7,NTAH6,NTG6,NTAH6,PAUSE,NTDH6,PAUSE,NTDH6,NTF6,NTG6,NTC7,NTAH6,PAUSE, //wenn die Jahreszeit des Vergissmeinnichts kommt
  NTG6,NTAH6,PAUSE,NTAH6,NTG6,NTAH6,PAUSE,NTDH6,NTD6,NTDH6,NTF6,NTG6,NTAH6,PAUSE, //singe ich ein Lied
  NTAH6,NTC7,NTAH6,NTG6,NTAH6,PAUSE,NTDH6,PAUSE,NTDH6,NTF6,NTG6,NTC7,NTD7,PAUSE, //wenn die Jahreszeit des Vergissmeinnichts kommt
  NTG6,NTAH6,NTDH7,NTD7,NTAH6,PAUSE, //rufe ich dich
  
};

const float duration[] PROGMEM = {/**/
  0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,
  0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,
  0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.4  ,0.3  ,0.3  ,0.3  ,
  0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,0.4  ,0.3  ,0.3  ,0.3  ,
  0.6  ,0.6  ,0.6  ,0.3  ,0.6  ,0.6  ,0.3  ,0.6  ,0.6  ,
  0.6  ,0.6  ,0.6  ,0.3  ,0.6  ,0.6  ,0.3  ,0.6  ,0.6  ,
  0.6  ,0.6  ,0.6  ,0.3  ,0.6  ,0.6  ,0.3  ,0.6  ,0.6  ,
  0.6  ,0.6  ,0.6  ,0.3  ,0.6  ,0.6  ,0.3  ,0.3  ,0.3  ,0.3  ,0.3  ,1    ,

	2.3  ,1    ,1    ,2    ,1    ,1    ,2    ,1    ,1    ,1.6  , //ei~
  1    ,1    ,1    ,1    ,1    ,1    ,2    ,1    ,1    ,1    ,1    ,1    ,1    ,1    ,1    ,1.8  ,2.5  , //~ei
	0.6  ,0.6  ,0.6  ,0.6  ,0.4  ,0.8  ,0.3  ,0.8  ,0.8  ,0.8  ,0.8  ,2    , //die Ruinenstadt ist immer noch schön
  0.5  ,0.5  ,0.5  ,0.5  ,0.3  ,0.8  ,0.3  ,0.8  ,0.8  ,0.7  ,0.7  ,0.7  ,2    , //ich warte lange Zeit auf deine Rückkehr
  0.6  ,0.6  ,1.2  ,1.6  , //in der Hand
  0.6  ,0.6  ,0.6  ,0.1  ,0.7  ,0.05 ,1.5  ,3    ,//ein Vergissmeinnicht

  0.6  ,0.5  ,1    ,1    ,0.8  ,0.7  ,0.6  ,2    ,0.8   ,//Regentropfen sind meine Tränen
  0.7  ,0.6  ,1    ,1    ,0.7  ,0.7  ,0.7  ,0.05 ,0.6  ,0.6  ,1.5  ,0.8  , //Wind ist mein Atem und mein Erzählung
  0.6  ,0.05 ,0.6  ,0.6  ,0.05 ,0.6  ,0.6  ,0.05 ,1.2  ,0.1  ,0.7  ,0.7  ,0.8  ,0.8  ,1    ,//Zweige und Blätter sind meine Hände
  0.8  ,0.6  ,0.05 ,0.6  ,0.6  ,0.05 ,0.6  ,0.6  ,0.05 ,1.2  ,0.1  ,0.7  ,0.6  ,2    ,0.8  ,//denn mein Körper ist in Wurzeln gehüllt
  0.7  ,0.6  ,1    ,1    ,0.8  ,0.7  ,0.6  ,0.05 ,0.6  ,2    ,0.8  , //wenn die Jahreszeit des Tauens kommt
  0.7  ,0.6  ,1    ,1    ,0.8  ,0.7  ,0.6  ,0.05 ,1.5  ,2    ,0.8  , //werde ich wach und singe ein Lied
  2.5  ,0.1  ,0.7  ,0.7  ,0.7  ,1    ,1    ,//das Vergissmeinnicht
  0.6  ,0.7  ,0.5  ,0.4  ,0.6  ,0.6  ,0.5  ,1.7  ,0.1  ,0.7  ,2.5  ,1    ,//das du mir gegeben hast, ist hier
  
  1    ,1    ,1    ,0.6  ,0.5  ,0.05 ,1    ,1    ,0.6  ,0.5  ,0.5  ,0.5  ,//erinnerst du dich noch*2
  1    ,0.8  ,0.1  ,0.8  ,0.6  ,0.6  ,0.1  ,0.7  ,1    ,1    ,0.7  ,0.5  ,//an dein Wort,das du mir gegeben hast
  1    ,1    ,1    ,0.6  ,0.5  ,0.05 ,1    ,1    ,0.6  ,0.5  ,0.5  ,0.5  ,//erinnerst du dich noch*2
  1    ,0.8  ,0.1  ,0.8  ,0.7  ,0.6  ,0.05 ,0.6  ,0.6  ,2    ,//erinnerst du dich noch an den Tag,an dem du mir
  
  0.6  ,0.6  ,1.5  ,0.6  ,1.1  ,0.7  ,0.5  ,0.05 ,0.6  ,0.6  ,0.6  ,0.6  ,0.6  ,0.5  ,//wenn die Jahreszeit des Vergissmeinnichts kommt
  0.6  ,0.5  ,0.05 ,1.5  ,0.6  ,1.2  ,0.2  ,0.6  ,0.6  ,0.6  ,0.6  ,0.6  ,0.6  ,0.7  ,//singe ich ein Lied
  0.6  ,0.6  ,1.5  ,0.6  ,1.1  ,0.7  ,0.5  ,0.05 ,0.6  ,0.6  ,0.6  ,0.6  ,0.6  ,0.5  ,//wenn die Jahreszeit des Vergissmeinnichts kommt
  0.6  ,0.6  ,2    ,2    ,2    ,1    ,//rufe ich dich
  
};

void setup() {
  pinMode(buzzerPin,OUTPUT);
  length=sizeof(tune)/sizeof(tune[0]);
}

void loop() {
  for(int i = 0; i < length; i++) {
    tone(buzzerPin,tune[i]);
    delay(pgm_read_float(&duration[i]) * 500);
  }
}
