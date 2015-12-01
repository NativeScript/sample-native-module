#include <jni.h>
#include "include\v8.h"

void AddFuncCallback(const v8::FunctionCallbackInfo<v8::Value>& args);

extern "C" void NSMain(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	auto isolate = args.GetIsolate();

	auto len = args.Length();

	if (len != 5)
	{
		auto errMsg = v8::String::NewFromUtf8(isolate, "Wrong number of arguments (expected 5)");
		auto err = v8::Exception::Error(errMsg);
		isolate->ThrowException(err);
		return;
	}

	auto exports = args[1].As<v8::Object>();

	auto ft = v8::FunctionTemplate::New(isolate, AddFuncCallback);
	auto ctx = isolate->GetCurrentContext();
	auto maybeFunc = ft->GetFunction(ctx);
	if (maybeFunc.IsEmpty())
	{
		auto errMsg = v8::String::NewFromUtf8(isolate, "Cannot create 'add' function");
		auto err = v8::Exception::Error(errMsg);
		isolate->ThrowException(err);
		return;
	}

	auto func = maybeFunc.ToLocalChecked();

	auto propName = v8::String::NewFromUtf8(isolate, "add");
	exports->Set(ctx, propName, func);
}

void AddFuncCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	int result = 0;

	auto len = args.Length();

	if ((len == 2) && args[0]->IsInt32() && args[1]->IsInt32())
	{
		result = args[0]->Int32Value() + args[1]->Int32Value();
	}

	args.GetReturnValue().Set(result);
}
