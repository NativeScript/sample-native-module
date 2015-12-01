# sample-native-module

This repo contains example of NativeScript native module. Regular {N} modules are created in JavaScript and you consume it as follows:

```JavaScript
var myModule = require('./myModule.js');
```

NativeScript native modules are similar to [Node.js addons](https://nodejs.org/api/addons.html). Native modules provide glue to C and C++ libraries. They are consumed as regular JavaScript modules.

```JavaScript
var myModule = require('./libCalc.so');
```
Because native modules are architecture specific (e.g. ARM, x86, etc.) it is good practice to convey them with regular JavaScript ones that hide the details.

Native modules are useful in performance sensitive scenarios because they avoid JavaScript-to-Java marshalling. Good examples are OpenGL libraries.

You can see Android implementation [here](https://github.com/NativeScript/sample-native-module/tree/master/Android).
