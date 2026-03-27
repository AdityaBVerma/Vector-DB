#include <napi.h>
#include "vector_engine.h"

VectorEngine engine;

Napi::Value Insert(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    Napi::Array arr = info[0].As<Napi::Array>();
    std::string text = info[1].As<Napi::String>();

    std::vector<float> vec;

    for (uint32_t i = 0; i < arr.Length(); i++) {
        vec.push_back(arr.Get(i).As<Napi::Number>().FloatValue());
    }

    engine.insert(vec, text);

    return env.Null();
}

Napi::Value Search(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    Napi::Array arr = info[0].As<Napi::Array>();
    std::vector<float> vec;

    for (uint32_t i = 0; i < arr.Length(); i++) {
        vec.push_back(arr.Get(i).As<Napi::Number>().FloatValue());
    }

    std::vector<std::string> result = engine.search(vec);

    Napi::Array jsResult = Napi::Array::New(env, result.size());

    for (size_t i = 0; i < result.size(); i++) {
        jsResult.Set(i, Napi::String::New(env, result[i]));
    }

    return jsResult;
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("insert", Napi::Function::New(env, Insert));
    exports.Set("search", Napi::Function::New(env, Search));
    return exports;
}

NODE_API_MODULE(vector_engine, Init)