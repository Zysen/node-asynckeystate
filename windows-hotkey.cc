#include <node.h>
#include <windows.h>
using namespace v8;
using v8::Function;
using v8::FunctionCallbackInfo;

void getAsyncKeyState(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();  
  int keyCode = (int)args[0]->IntegerValue();
  args.GetReturnValue().Set(Boolean::New(isolate, GetAsyncKeyState(keyCode)));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "getAsyncKeyState", getAsyncKeyState);
}

NODE_MODULE(addon, init)
