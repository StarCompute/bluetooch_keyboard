#include <Arduino.h>
#include "BleKeyboard.h"

BleKeyboard bleKeyboard("ESP蓝牙键盘模拟", "Espressif", 100);

// put function declarations here:
int myFunction(int, int);

void setup()
{
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(115200);
  Serial.println("开始蓝牙键盘模拟");
  bleKeyboard.begin();

 
} 

void loop()
{
  // put your main code here, to run repeatedly:
  if (bleKeyboard.isConnected())
  {
    Serial.println("蓝牙已经链接上. ");
    delay(20000);
 
 

    bleKeyboard.write(KEY_MEDIA_STOP);
    delay(2000);

    bleKeyboard.write(KEY_END);
    bleKeyboard.write(59);
    bleKeyboard.write(KEY_RETURN);
    bleKeyboard.write(KEY_DOWN_ARROW);

    bleKeyboard.write(KEY_END);
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(48);
    delay(100);
    bleKeyboard.releaseAll();
    bleKeyboard.write(59);
    bleKeyboard.write(KEY_RETURN);
    bleKeyboard.write(KEY_DOWN_ARROW);
    bleKeyboard.write(KEY_END);

    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(34);
    delay(100);
    bleKeyboard.releaseAll();
   
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(48);
    delay(100);
    bleKeyboard.releaseAll();

    bleKeyboard.write(59);
    bleKeyboard.write(KEY_RETURN);
    bleKeyboard.write(KEY_DOWN_ARROW);

    // Serial.println("这行实现自动添加分号换行");

    // Serial.println("这行实现自动补充括号后添加分号换行换行");

    // Serial.println("这行实现自动添加双引号，括号和分号后换行");
    


   delay(200000);
  };

 
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}