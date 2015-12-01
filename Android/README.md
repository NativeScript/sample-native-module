# Native module for Android

This is a simple project that shows how to create native module for NativeScript for Android. Every native module should export `NSMain` function as follows

```C++
extern "C" void NSMain(const v8::FunctionCallbackInfo<v8::Value>& args)
{
   // args[0] = module object
   // args[1] = module.exports object
   // args[2] = require function
   // args[3] = __filename variable
   // args[4] = __dirname variable
}
```

See [Calc.cpp](https://github.com/NativeScript/sample-native-module/blob/master/Android/CalcLib/jni/Calc.cpp) for full implementation.
