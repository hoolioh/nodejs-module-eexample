#include <node.h>

void Fooficate(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  v8::String::Utf8Value str(isolate, args[0]);
  std::string cstr(*str);
  cstr.insert(0, "foo");
  
  auto result = v8::String::NewFromUtf8(isolate, cstr.c_str());

  args.GetReturnValue().Set(result.ToLocalChecked());
}

void Initialize(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "fooficate", Fooficate);
}

NODE_MODULE(module_name, Initialize)
