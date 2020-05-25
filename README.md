# Display 7 segments

## Usage

### Initialize
```
int d1 = 9;
int d2 = 10;
int d3 = 11;
int d4 = 12;

int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

int pins[] = {a,b,c,d,e,f,g};

DISPLAY display(pins, ANODE_MODE, d1, d2, d3, d4);
```

### ShowDigit
```
display.showDigit(1234);
```

### 4 digits length
The method `showDigit` has to be in the `loop` method to refresh its 4 digits in a correct rate. It had to be implemented on the main loop, so it doesn't became blocking code.

### Only one digit length

For hardwares with only one digit length, you can initialise the library this way:

#### Initialize
```
digit = 9;
DISPLAY display(pins, ANODE_MODE, digit);
```

#### ShowDigit

```
display.showDigit(1);
```

The one digit case doesn't need to be at any loop, you can just set it on time, and the number will stay active.