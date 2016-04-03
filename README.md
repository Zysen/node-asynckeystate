node-asynckeystate
====================================

1. Introduction
---------------
This module provides a wrapper for the windows function getAsyncKeyState.
See https://msdn.microsoft.com/en-us/library/windows/desktop/ms646293(v=vs.85).aspx for more information.

For a list of key codes see
https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx

2. Example
---------------

    var aks = require("asynckeystate");
    setInterval(function(){
        console.log("Space Pressed", aks.getAsyncKeyState(0x20));
    }, 100);
  
