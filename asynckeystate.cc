#include <napi.h>
#include <windows.h>
Napi::Value NodeGetAsyncKeyState(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  int keyCode = info[0].As<Napi::Number>().Uint32Value();
  return Napi::Boolean::New(env, GetAsyncKeyState(keyCode));
}
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "getAsyncKeyState"), Napi::Function::New(env, NodeGetAsyncKeyState));
  return exports;
}
NODE_API_MODULE(addon, Init)